#include <stdio.h>
#include <string.h>
#include "include/cJSON.h"

int main()
{
  // lecture du fichier json
  FILE *fp;
  char buffer[10000];
  cJSON *parsed_json;
  fp = fopen("graph.json", "r");
  fread(buffer, 10000, 1, fp);
  fclose(fp);

  // parsing du fichier json
  parsed_json = cJSON_Parse(buffer);
  if (parsed_json == NULL)
  {
    printf("Error parsing JSON");
    return 1;
  }

  // récupération des données
  cJSON *cells = cJSON_GetObjectItem(parsed_json, "cells");
  int cells_count = cJSON_GetArraySize(cells);

  FILE *write;
  write = fopen("matrices.csv", "w");
  int number_bus = 0;
  int number_slack = 0;
  int number_generator = 0;
  int number_load = 0;
  int number_line = 0;
  int number_transformer = 0;
  cJSON *bus_array = cJSON_CreateArray();

  // Parcours de la liste
  for (int i = 0; i < cells_count; i++)
  {
    // Get the JSON element and then get the values as before
    cJSON *cell = cJSON_GetArrayItem(cells, i);
    char *type = cJSON_GetObjectItem(cell, "type")->valuestring;
    cJSON *data = cJSON_GetObjectItem(cell, "data");
    // get number of bus
    if (strcmp(type, "busV") == 0 || strcmp(type, "busH") == 0)
    {
      number_bus++;
      char *id = cJSON_GetObjectItem(cell, "id")->valuestring;
      char *name = cJSON_GetObjectItem(data, "busName")->valuestring;
      char *niveau_tension = cJSON_GetObjectItem(data, "busNiveauTension")->valuestring;
      char *vref_tension = cJSON_GetObjectItem(data, "busTensionVref")->valuestring;
      char *initial_tension = cJSON_GetObjectItem(data, "busTensionInit")->valuestring;
      char *initial_angle = cJSON_GetObjectItem(data, "busAngleInit")->valuestring;
      char *phase_default = cJSON_GetObjectItem(data, "busPhaseDefault")->valuestring;
      char *courant_cc_max = cJSON_GetObjectItem(data, "busCourantCcMax")->valuestring;
      char *temps_simulation = cJSON_GetObjectItem(data, "busTempsSimulation")->valuestring;
      char *alias = cJSON_GetObjectItem(data, "busAlias")->valuestring;
      char *zone = cJSON_GetObjectItem(data, "busZone")->valuestring;
      char *substation = cJSON_GetObjectItem(data, "busSubstation")->valuestring;
      char *etat = cJSON_GetObjectItem(data, "busEtat")->valuestring;

      cJSON *data_bus = cJSON_CreateObject();
      cJSON_AddItemToObject(data_bus, "bus", data);
      cJSON_AddItemToArray(bus_array, data_bus);
    }
    if (strcmp(type, "line") == 0)
    {
      number_line++;
    }
    // get number of slack
    if (strcmp(type, "slack") == 0)
    {
      number_slack++;
      char *id = cJSON_GetObjectItem(cell, "id")->valuestring;
      char *name = cJSON_GetObjectItem(data, "slackGeneratorName")->valuestring;
      char *niveau_tension = cJSON_GetObjectItem(data, "slackGeneratorNiveauTension")->valuestring;
      // char *name = cJSON_GetObjectItem(data, "slackGeneratorName")->valuestring;
      char *tension_u = cJSON_GetObjectItem(data, "slackGeneratorTensionU")->valuestring;
      char *dephasage = cJSON_GetObjectItem(data, "slackGeneratorDephasage")->valuestring;
      char *phase = cJSON_GetObjectItem(data, "slackGeneratorPhase")->valuestring;
      char *mise_a_la_terre = cJSON_GetObjectItem(data, "slackGeneratorTerre")->valuestring;
      char *puissance_cc = cJSON_GetObjectItem(data, "slackGeneratorPccSk")->valuestring;
      char *ratio_rx = cJSON_GetObjectItem(data, "slackGeneratorRatioRX")->valuestring;
      char *tension_sk = cJSON_GetObjectItem(data, "slackGeneratorTensionSk")->valuestring;
      char *ratio_impedance = cJSON_GetObjectItem(data, "slackGeneratorRatioZOZI")->valuestring;
      char *ration_res_react = cJSON_GetObjectItem(data, "slackGeneratorRatioResReact")->valuestring;
      char *min_p = cJSON_GetObjectItem(data, "slackGeneratorMinP")->valuestring;
      char *max_p = cJSON_GetObjectItem(data, "slackGeneratorMaxP")->valuestring;
      char *min_q = cJSON_GetObjectItem(data, "slackGeneratorMinQ")->valuestring;
      char *max_q = cJSON_GetObjectItem(data, "slackGeneratorMaxQ")->valuestring;
      char *alias = cJSON_GetObjectItem(data, "slackGeneratorAlias")->valuestring;
      char *zone = cJSON_GetObjectItem(data, "slackGeneratorZone")->valuestring;
      char *substation = cJSON_GetObjectItem(data, "slackGeneratorSubstation")->valuestring;
      char *etat = cJSON_GetObjectItem(data, "slackGeneratorEtat")->valuestring;

      fprintf(write, "%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", id, name, niveau_tension, tension_u, dephasage, phase, mise_a_la_terre, puissance_cc, ratio_rx, tension_sk, ratio_impedance, ration_res_react, min_p, max_p, min_q, max_q, alias, zone, substation, etat);
    }
    // get number of generator
    if (strcmp(type, "generator") == 0)
    {
      number_generator++;
      char *id = cJSON_GetObjectItem(cell, "id")->valuestring;
      char *name = cJSON_GetObjectItem(data, "standardGeneratorName")->valuestring;
      char *source = cJSON_GetObjectItem(data, "standardGeneratorSource")->valuestring;
      char *niveau_tension = cJSON_GetObjectItem(data, "standardGeneratorNiveauTension")->valuestring;
      char *type = cJSON_GetObjectItem(data, "standardGeneratorType")->valuestring;
      char *puissance_apparente = cJSON_GetObjectItem(data, "standardGeneratorPuissanceApparente")->valuestring;
      char *tension_operation = cJSON_GetObjectItem(data, "standardGeneratorTensionOperation")->valuestring;
      char *resistance_reactance = cJSON_GetObjectItem(data, "standardGeneratorResistanceReactance")->valuestring;
      char *internal_reactance = cJSON_GetObjectItem(data, "standardGeneratorInternalReactance")->valuestring;
      char *tension_max = cJSON_GetObjectItem(data, "standardGeneratorTensionMax")->valuestring;
      char *facteur_puissance = cJSON_GetObjectItem(data, "standardGeneratorFacteurPuissance")->valuestring;
      char *tension = cJSON_GetObjectItem(data, "standardGeneratorTension")->valuestring;
      char *stock_energie = cJSON_GetObjectItem(data, "standardGeneratorStockageEnergie")->valuestring;
      char *dephasage_tension = cJSON_GetObjectItem(data, "standardGeneratorDephasageTension")->valuestring;
      char *type_simulation = cJSON_GetObjectItem(data, "standardGeneratorTypeSimu")->valuestring;
      char *min_p = cJSON_GetObjectItem(data, "standardGeneratorMinP")->valuestring;
      char *max_p = cJSON_GetObjectItem(data, "standardGeneratorMaxP")->valuestring;
      char *min_q = cJSON_GetObjectItem(data, "standardGeneratorMinQ")->valuestring;
      char *max_q = cJSON_GetObjectItem(data, "standardGeneratorMaxQ")->valuestring;
      char *apparente_unit = cJSON_GetObjectItem(data, "puissanceApparenteUnit")->valuestring;
      char *operation_unit = cJSON_GetObjectItem(data, "tensionOperationUnit")->valuestring;
      char *sustained_sce = cJSON_GetObjectItem(data, "standardGeneratorSustainedSce")->valuestring;
      char *ssr = cJSON_GetObjectItem(data, "standardGeneratorSsr")->valuestring;
      char *ssr_bis = cJSON_GetObjectItem(data, "standardGeneratorSsrBis")->valuestring;
      char *alias = cJSON_GetObjectItem(data, "standardGeneratorAlias")->valuestring;
      char *zone = cJSON_GetObjectItem(data, "standardGeneratorZone")->valuestring;
      char *etat = cJSON_GetObjectItem(data, "standardGeneratorEtat")->valuestring;

      fprintf(write, "%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", id, name, source, niveau_tension, type, puissance_apparente, tension_operation, resistance_reactance, internal_reactance, tension_max, facteur_puissance, tension, stock_energie, dephasage_tension, type_simulation, min_p, max_p, min_q, max_q, apparente_unit, operation_unit, sustained_sce, ssr, ssr_bis, alias, zone, etat);
    }
    // get number of load
    if (strcmp(type, "charge") == 0)
    {
      number_load++;
    }
    // get number of transformer
    if (strcmp(type, "transformer") == 0)
    {
      number_transformer++;
      char *id = cJSON_GetObjectItem(cell, "id")->valuestring;
      char *name = cJSON_GetObjectItem(data, "transformerName")->valuestring;
      char *start_noeud = cJSON_GetObjectItem(data, "transformerNoeudStart")->valuestring;
      char *end_noeud = cJSON_GetObjectItem(data, "transformerNoeudEnd")->valuestring;
      char *niveau_tension = cJSON_GetObjectItem(data, "transformerNiveauTension")->valuestring;
      char *phase = cJSON_GetObjectItem(data, "transformerPhase")->valuestring;
      char *tnp = cJSON_GetObjectItem(data, "transformerTnp")->valuestring;
      char *tns = cJSON_GetObjectItem(data, "transformerTns")->valuestring;
      char *pan = cJSON_GetObjectItem(data, "transformerPan")->valuestring;
      char *tension_cc = cJSON_GetObjectItem(data, "transformerTensionCcUcc")->valuestring;
      char *perte_cuivre = cJSON_GetObjectItem(data, "transformerPerteCuivre")->valuestring;
      char *pert_fer = cJSON_GetObjectItem(data, "transformerPerteFer")->valuestring;
      char *courant_a_vide = cJSON_GetObjectItem(data, "transformerCourantVide")->valuestring;
      char *dephasage_phi = cJSON_GetObjectItem(data, "transformerDephasagePhi")->valuestring;
      char *groupe_vecteur = cJSON_GetObjectItem(data, "transformerGroupVecteur")->valuestring;
      char *capacite_c1 = cJSON_GetObjectItem(data, "transformerCapaciteC1")->valuestring;
      char *capacite_c2 = cJSON_GetObjectItem(data, "transformerCapaciteC2")->valuestring;
      char *rihd = cJSON_GetObjectItem(data, "transformerRihd")->valuestring;
      char *rrrh = cJSON_GetObjectItem(data, "transformerRrrh")->valuestring;
      char *alias = cJSON_GetObjectItem(data, "transformerAlias")->valuestring;
      char *zone = cJSON_GetObjectItem(data, "stransformerZone")->valuestring;
      char *substation = cJSON_GetObjectItem(data, "transformerSubstation")->valuestring;
      char *etat = cJSON_GetObjectItem(data, "transformerEtat")->valuestring;

      fprintf(write, "%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", id, name, start_noeud, end_noeud, niveau_tension, phase, tnp, tns, pan, tension_cc, perte_cuivre, pert_fer, courant_a_vide, dephasage_phi, groupe_vecteur, capacite_c1, capacite_c2, rihd, rrrh, alias, zone, substation, etat);
    }
  }
  fprintf(write, "number_bus=%d\n number_line=%d\n number_slack=%d\n number_transformer=%d\n number_generator=%d\n number_charge=%d\n number_transformer=%d\n ", number_bus, number_line, number_slack, number_transformer, number_generator, number_load, number_transformer);
  // for (int i = 0; i < cJSON_GetArraySize(bus_array); i++)
  // {
  //   cJSON *cell = cJSON_GetArrayItem(bus_array, i);
  //   cJSON *data = cJSON_GetObjectItem(cell, "bus");
  //   char *id = cJSON_GetObjectItem(cell, "id")->valuestring;
  //   char *name = cJSON_GetObjectItem(data, "busName")->valuestring;
  //   char *niveau_tension = cJSON_GetObjectItem(data, "busNiveauTension")->valuestring;
  //   char *vref_tension = cJSON_GetObjectItem(data, "busTensionVref")->valuestring;
  //   char *initial_tension = cJSON_GetObjectItem(data, "busTensionInit")->valuestring;
  //   char *initial_angle = cJSON_GetObjectItem(data, "busAngleInit")->valuestring;
  //   char *phase_default = cJSON_GetObjectItem(data, "busPhaseDefault")->valuestring;
  //   char *courant_cc_max = cJSON_GetObjectItem(data, "busCourantCcMax")->valuestring;
  //   char *temps_simulation = cJSON_GetObjectItem(data, "busTempsSimulation")->valuestring;
  //   char *alias = cJSON_GetObjectItem(data, "busAlias")->valuestring;
  //   char *zone = cJSON_GetObjectItem(data, "busZone")->valuestring;
  //   char *substation = cJSON_GetObjectItem(data, "busSubstation")->valuestring;
  //   char *etat = cJSON_GetObjectItem(data, "busEtat")->valuestring;
  //   fprintf(write, "%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", id, name, niveau_tension, vref_tension, initial_tension, initial_angle, phase_default, courant_cc_max, temps_simulation, alias, zone, substation, etat);
  // }
    char *str_bus = cJSON_Print(bus_array);
    fprintf(write, "%s\n", str_bus);
    fclose(write);
  }
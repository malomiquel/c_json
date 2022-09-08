#include <stdio.h>
#include <string.h>
#include "../include/cJSON.h"
#include "functions.h"

void bus(cJSON *data, cJSON *bus_object)
{
  // Incrémentation du nombre de bus
  number_bus++;
  // Récupération des données
  char *name = cJSON_GetObjectItem(data, "busName")->valuestring;
  char *tension_init = cJSON_GetObjectItem(data, "busTensionInit")->valuestring;
  char *angle_init = cJSON_GetObjectItem(data, "busAngleInit")->valuestring;
  // char *vref_tension = cJSON_GetObjectItem(data, "busTensionVref")->valuestring;
  // char *initial_tension = cJSON_GetObjectItem(data, "busTensionInit")->valuestring;
  // char *initial_angle = cJSON_GetObjectItem(data, "busAngleInit")->valuestring;
  // char *phase_default = cJSON_GetObjectItem(data, "busPhaseDefault")->valuestring;
  // char *courant_cc_max = cJSON_GetObjectItem(data, "busCourantCcMax")->valuestring;
  // char *temps_simulation = cJSON_GetObjectItem(data, "busTempsSimulation")->valuestring;
  // char *alias = cJSON_GetObjectItem(data, "busAlias")->valuestring;
  // char *zone = cJSON_GetObjectItem(data, "busZone")->valuestring;
  // char *substation = cJSON_GetObjectItem(data, "busSubstation")->valuestring;
  // char *etat = cJSON_GetObjectItem(data, "busEtat")->valuestring;

  // Variable pour transformer le nombre en string
  char str[100];
  // Méthode permettant de transformer un nombre en string
  sprintf(str, "%d", number_bus);
  // Variable pour stocker le nom du bus
  char *test = "bus";
  // Méthode permettant de concaténer le nombre du bus avec le nom de bus
  strcat(str, test);
  // Création de la liste
  cJSON *data_bus = cJSON_CreateArray();
  // Ajout des données dans la liste
  cJSON_AddItemToArray(data_bus, cJSON_CreateString(name));
  cJSON_AddItemToArray(data_bus, cJSON_CreateString(tension_init));
  cJSON_AddItemToArray(data_bus, cJSON_CreateString(angle_init));
  // cJSON_AddItemToArray(data_bus, cJSON_CreateString(vref_tension));
  // cJSON_AddItemToArray(data_bus, cJSON_CreateString(initial_tension));
  // cJSON_AddItemToArray(data_bus, cJSON_CreateString(initial_angle));
  // cJSON_AddItemToArray(data_bus, cJSON_CreateString(phase_default));
  // cJSON_AddItemToArray(data_bus, cJSON_CreateString(courant_cc_max));
  // cJSON_AddItemToArray(data_bus, cJSON_CreateString(temps_simulation));
  // cJSON_AddItemToArray(data_bus, cJSON_CreateString(alias));
  // cJSON_AddItemToArray(data_bus, cJSON_CreateString(zone));
  // cJSON_AddItemToArray(data_bus, cJSON_CreateString(substation));
  // cJSON_AddItemToArray(data_bus, cJSON_CreateString(etat));
  // Ajout de la liste dans l'objet
  cJSON_AddItemToObject(bus_object, str, data_bus);
}

void line(cJSON *data, cJSON *line_object)
{
  number_line++;
  char *depart_node = cJSON_GetObjectItem(data, "ligneNoeudDepart")->valuestring;
  char *arrive_node = cJSON_GetObjectItem(data, "ligneNoeudArrive")->valuestring;
  char *longueur = cJSON_GetObjectItem(data, "ligneLongueurL")->valuestring;
  char *resistance = cJSON_GetObjectItem(data, "ligneResistanceR")->valuestring;
  char *reactance = cJSON_GetObjectItem(data, "ligneReactance")->valuestring;
  char *capacitance = cJSON_GetObjectItem(data, "ligneCapacitance")->valuestring;
  char *frequence = cJSON_GetObjectItem(data, "ligneFrequence")->valuestring;
  // char *nb_line = cJSON_GetObjectItem(data, "ligneNombreLigne")->valuestring;
  // char *longueur = cJSON_GetObjectItem(data, "ligneLongueurL")->valuestring;
  // char *resistance = cJSON_GetObjectItem(data, "ligneResistanceR")->valuestring;
  // char *reactance = cJSON_GetObjectItem(data, "ligneReactance")->valuestring;
  // char *capacitance = cJSON_GetObjectItem(data, "ligneCapacitance")->valuestring;
  // char *tension = cJSON_GetObjectItem(data, "ligneTension")->valuestring;
  // char *taux_charge = cJSON_GetObjectItem(data, "ligneTauxCharge")->valuestring;
  // char *courant_cc = cJSON_GetObjectItem(data, "ligneCourantCc")->valuestring;
  // char *perte_terre = cJSON_GetObjectItem(data, "lignePerteTerre")->valuestring;
  // char *frequence = cJSON_GetObjectItem(data, "ligneFrequence")->valuestring;
  // char *section_cable = cJSON_GetObjectItem(data, "ligneSectionCable")->valuestring;
  // char *temperature = cJSON_GetObjectItem(data, "ligneTemperature")->valuestring;
  // char *localisation = cJSON_GetObjectItem(data, "ligneLocalisation")->valuestring;
  // char *alias = cJSON_GetObjectItem(data, "ligneAlias")->valuestring;
  // char *zone = cJSON_GetObjectItem(data, "ligneZone")->valuestring;
  // char *substation = cJSON_GetObjectItem(data, "ligneSubstation")->valuestring;
  // char *switch_depart = cJSON_GetObjectItem(data, "ligneSwitchDepart")->valuestring;
  // char *switch_arrive = cJSON_GetObjectItem(data, "ligneSwitchArrive")->valuestring;
  // char *etat = cJSON_GetObjectItem(data, "ligneEtat")->valuestring;

  char str[100];
  sprintf(str, "%d", number_line);
  char *test = "line";
  strcat(str, test);
  cJSON *data_line = cJSON_CreateArray();
  cJSON_AddItemToArray(data_line, cJSON_CreateString(depart_node));
  cJSON_AddItemToArray(data_line, cJSON_CreateString(arrive_node));
  cJSON_AddItemToArray(data_line, cJSON_CreateString(longueur));
  cJSON_AddItemToArray(data_line, cJSON_CreateString(resistance));
  cJSON_AddItemToArray(data_line, cJSON_CreateString(reactance));
  cJSON_AddItemToArray(data_line, cJSON_CreateString(capacitance));
  cJSON_AddItemToArray(data_line, cJSON_CreateString(frequence));
  // cJSON_AddItemToArray(data_line, cJSON_CreateString(nb_line));
  // cJSON_AddItemToArray(data_line, cJSON_CreateString(longueur));
  // cJSON_AddItemToArray(data_line, cJSON_CreateString(resistance));
  // cJSON_AddItemToArray(data_line, cJSON_CreateString(reactance));
  // cJSON_AddItemToArray(data_line, cJSON_CreateString(capacitance));
  // cJSON_AddItemToArray(data_line, cJSON_CreateString(tension));
  // cJSON_AddItemToArray(data_line, cJSON_CreateString(taux_charge));
  // cJSON_AddItemToArray(data_line, cJSON_CreateString(courant_cc));
  // cJSON_AddItemToArray(data_line, cJSON_CreateString(perte_terre));
  // cJSON_AddItemToArray(data_line, cJSON_CreateString(frequence));
  // cJSON_AddItemToArray(data_line, cJSON_CreateString(section_cable));
  // cJSON_AddItemToArray(data_line, cJSON_CreateString(temperature));
  // cJSON_AddItemToArray(data_line, cJSON_CreateString(localisation));
  // cJSON_AddItemToArray(data_line, cJSON_CreateString(alias));
  // cJSON_AddItemToArray(data_line, cJSON_CreateString(zone));
  // cJSON_AddItemToArray(data_line, cJSON_CreateString(substation));
  // cJSON_AddItemToArray(data_line, cJSON_CreateString(switch_depart));
  // cJSON_AddItemToArray(data_line, cJSON_CreateString(switch_arrive));
  // cJSON_AddItemToArray(data_line, cJSON_CreateString(etat));
  cJSON_AddItemToObject(line_object, str, data_line);
};

void slack(cJSON *data, cJSON *slack_object)
{
  number_slack++;
  char *name = cJSON_GetObjectItem(data, "slackGeneratorName")->valuestring;
  char *tension = cJSON_GetObjectItem(data, "slackGeneratorTension")->valuestring;
  char *dephasage = cJSON_GetObjectItem(data, "slackGeneratorDephasage")->valuestring;
  char *puissance_cc = cJSON_GetObjectItem(data, "slackGeneratorPccMax")->valuestring;
  char *ratio_rx = cJSON_GetObjectItem(data, "slackGeneratorRatioRXMax")->valuestring;
  char *tension_sk = cJSON_GetObjectItem(data, "slackGeneratorTensionSk")->valuestring;
  // char *phase = cJSON_GetObjectItem(data, "slackGeneratorPhase")->valuestring;
  // char *mise_a_la_terre = cJSON_GetObjectItem(data, "slackGeneratorTerre")->valuestring;
  // char *puissance_cc = cJSON_GetObjectItem(data, "slackGeneratorPccSk")->valuestring;
  // char *ratio_rx = cJSON_GetObjectItem(data, "slackGeneratorRatioRX")->valuestring;
  // char *tension_sk = cJSON_GetObjectItem(data, "slackGeneratorTensionSk")->valuestring;
  // char *ratio_impedance = cJSON_GetObjectItem(data, "slackGeneratorRatioZOZI")->valuestring;
  // char *ration_res_react = cJSON_GetObjectItem(data, "slackGeneratorRatioResReact")->valuestring;
  // char *min_p = cJSON_GetObjectItem(data, "slackGeneratorMinP")->valuestring;
  // char *max_p = cJSON_GetObjectItem(data, "slackGeneratorMaxP")->valuestring;
  // char *min_q = cJSON_GetObjectItem(data, "slackGeneratorMinQ")->valuestring;
  // char *max_q = cJSON_GetObjectItem(data, "slackGeneratorMaxQ")->valuestring;
  // char *alias = cJSON_GetObjectItem(data, "slackGeneratorAlias")->valuestring;
  // char *zone = cJSON_GetObjectItem(data, "slackGeneratorZone")->valuestring;
  // char *substation = cJSON_GetObjectItem(data, "slackGeneratorSubstation")->valuestring;
  // char *etat = cJSON_GetObjectItem(data, "slackGeneratorEtat")->valuestring;

  char str[100];
  sprintf(str, "%d", number_slack);
  char *test = "slack";
  strcat(str, test);
  cJSON *data_slack = cJSON_CreateArray();
  cJSON_AddItemToArray(data_slack, cJSON_CreateString(name));
  cJSON_AddItemToArray(data_slack, cJSON_CreateString(tension));
  cJSON_AddItemToArray(data_slack, cJSON_CreateString(dephasage));
  cJSON_AddItemToArray(data_slack, cJSON_CreateString(puissance_cc));
  cJSON_AddItemToArray(data_slack, cJSON_CreateString(ratio_rx));
  cJSON_AddItemToArray(data_slack, cJSON_CreateString(tension_sk));
  // cJSON_AddItemToArray(data_slack, cJSON_CreateString(mise_a_la_terre));
  // cJSON_AddItemToArray(data_slack, cJSON_CreateString(puissance_cc));
  // cJSON_AddItemToArray(data_slack, cJSON_CreateString(ratio_rx));
  // cJSON_AddItemToArray(data_slack, cJSON_CreateString(tension_sk));
  // cJSON_AddItemToArray(data_slack, cJSON_CreateString(ratio_impedance));
  // cJSON_AddItemToArray(data_slack, cJSON_CreateString(ration_res_react));
  // cJSON_AddItemToArray(data_slack, cJSON_CreateString(min_p));
  // cJSON_AddItemToArray(data_slack, cJSON_CreateString(max_p));
  // cJSON_AddItemToArray(data_slack, cJSON_CreateString(min_q));
  // cJSON_AddItemToArray(data_slack, cJSON_CreateString(max_q));
  // cJSON_AddItemToArray(data_slack, cJSON_CreateString(alias));
  // cJSON_AddItemToArray(data_slack, cJSON_CreateString(zone));
  // cJSON_AddItemToArray(data_slack, cJSON_CreateString(substation));
  // cJSON_AddItemToArray(data_slack, cJSON_CreateString(etat));
  cJSON_AddItemToObject(slack_object, str, data_slack);
};

void generator(cJSON *data, cJSON *generator_object)
{
  number_generator++;
  char *node = cJSON_GetObjectItem(data, "standardGeneratorNode")->valuestring;
  char *type = cJSON_GetObjectItem(data, "standardGeneratorType")->valuestring;
  char *puissance_apparente = cJSON_GetObjectItem(data, "standardGeneratorPuissanceApparente")->valuestring;
  char *tension_operation = cJSON_GetObjectItem(data, "standardGeneratorTensionOperation")->valuestring;
  char *facteur_puissance = cJSON_GetObjectItem(data, "standardGeneratorFacteurPuissance")->valuestring;
  char *niveau_tension = cJSON_GetObjectItem(data, "standarGeneratorNiveauTension")->valuestring;
  char *dephasage_tension = cJSON_GetObjectItem(data, "standardGeneratorDephasageTension")->valuestring;
  char *puissance_reactive_max = cJSON_GetObjectItem(data, "standardGeneratorPuissanceReactiveMax")->valuestring;
  char *puissance_reactive_min = cJSON_GetObjectItem(data, "standardGeneratorPuissanceReactiveMin")->valuestring;
  // char *tension_max = cJSON_GetObjectItem(data, "standardGeneratorTensionMax")->valuestring;
  // char *facteur_puissance = cJSON_GetObjectItem(data, "standardGeneratorFacteurPuissance")->valuestring;
  // char *tension = cJSON_GetObjectItem(data, "standardGeneratorTension")->valuestring;
  // char *stock_energie = cJSON_GetObjectItem(data, "standardGeneratorStockageEnergie")->valuestring;
  // char *dephasage_tension = cJSON_GetObjectItem(data, "standardGeneratorDephasageTension")->valuestring;
  // char *type_simulation = cJSON_GetObjectItem(data, "standardGeneratorTypeSimu")->valuestring;
  // char *min_p = cJSON_GetObjectItem(data, "standardGeneratorMinP")->valuestring;
  // char *max_p = cJSON_GetObjectItem(data, "standardGeneratorMaxP")->valuestring;
  // char *min_q = cJSON_GetObjectItem(data, "standardGeneratorMinQ")->valuestring;
  // char *max_q = cJSON_GetObjectItem(data, "standardGeneratorMaxQ")->valuestring;
  // char *apparente_unit = cJSON_GetObjectItem(data, "puissanceApparenteUnit")->valuestring;
  // char *operation_unit = cJSON_GetObjectItem(data, "tensionOperationUnit")->valuestring;
  // char *sustained_sce = cJSON_GetObjectItem(data, "standardGeneratorSustainedSce")->valuestring;
  // char *ssr = cJSON_GetObjectItem(data, "standardGeneratorSsr")->valuestring;
  // char *ssr_bis = cJSON_GetObjectItem(data, "standardGeneratorSsrBis")->valuestring;
  // char *alias = cJSON_GetObjectItem(data, "standardGeneratorAlias")->valuestring;
  // char *zone = cJSON_GetObjectItem(data, "standardGeneratorZone")->valuestring;
  // char *etat = cJSON_GetObjectItem(data, "standardGeneratorEtat")->valuestring;

  char str[100];
  sprintf(str, "%d", number_generator);
  char *test = "generator";
  strcat(str, test);
  cJSON *data_generator = cJSON_CreateArray();
  cJSON_AddItemToArray(data_generator, cJSON_CreateString(node));
  cJSON_AddItemToArray(data_generator, cJSON_CreateString(type));
  cJSON_AddItemToArray(data_generator, cJSON_CreateString(puissance_apparente));
  cJSON_AddItemToArray(data_generator, cJSON_CreateString(tension_operation));
  cJSON_AddItemToArray(data_generator, cJSON_CreateString(facteur_puissance));
  cJSON_AddItemToArray(data_generator, cJSON_CreateString(niveau_tension));
  cJSON_AddItemToArray(data_generator, cJSON_CreateString(dephasage_tension));
  cJSON_AddItemToArray(data_generator, cJSON_CreateString(puissance_reactive_max));
  cJSON_AddItemToArray(data_generator, cJSON_CreateString(puissance_reactive_min));
  // cJSON_AddItemToArray(data_generator, cJSON_CreateString(tension_max));
  // cJSON_AddItemToArray(data_generator, cJSON_CreateString(facteur_puissance));
  // cJSON_AddItemToArray(data_generator, cJSON_CreateString(tension));
  // cJSON_AddItemToArray(data_generator, cJSON_CreateString(stock_energie));
  // cJSON_AddItemToArray(data_generator, cJSON_CreateString(dephasage_tension));
  // cJSON_AddItemToArray(data_generator, cJSON_CreateString(type_simulation));
  // cJSON_AddItemToArray(data_generator, cJSON_CreateString(min_p));
  // cJSON_AddItemToArray(data_generator, cJSON_CreateString(max_p));
  // cJSON_AddItemToArray(data_generator, cJSON_CreateString(min_q));
  // cJSON_AddItemToArray(data_generator, cJSON_CreateString(max_q));
  // cJSON_AddItemToArray(data_generator, cJSON_CreateString(apparente_unit));
  // cJSON_AddItemToArray(data_generator, cJSON_CreateString(operation_unit));
  // cJSON_AddItemToArray(data_generator, cJSON_CreateString(sustained_sce));
  // cJSON_AddItemToArray(data_generator, cJSON_CreateString(ssr));
  // cJSON_AddItemToArray(data_generator, cJSON_CreateString(ssr_bis));
  // cJSON_AddItemToArray(data_generator, cJSON_CreateString(alias));
  // cJSON_AddItemToArray(data_generator, cJSON_CreateString(zone));
  // cJSON_AddItemToArray(data_generator, cJSON_CreateString(etat));
  cJSON_AddItemToObject(generator_object, str, data_generator);
};

void transformer(cJSON *data, cJSON *transformer_object)
{
  number_transformer++;
  char *start_noeud = cJSON_GetObjectItem(data, "transformerNoeudStart")->valuestring;
  char *end_noeud = cJSON_GetObjectItem(data, "transformerNoeudEnd")->valuestring;
  char *tension_nominal_primary = cJSON_GetObjectItem(data, "transformerTnp")->valuestring;
  char *tension_nominal_secondary = cJSON_GetObjectItem(data, "transformerTns")->valuestring;
  char *puissance_apparente = cJSON_GetObjectItem(data, "transformerPan")->valuestring;
  char *tension_cc = cJSON_GetObjectItem(data, "transformerTensionCcUcc")->valuestring;
  char *perte_cuivre = cJSON_GetObjectItem(data, "transformerPerteCuivre")->valuestring;
  char *perte_fer = cJSON_GetObjectItem(data, "transformerPerteFer")->valuestring;
  char *courant_a_vide = cJSON_GetObjectItem(data, "transformerCourantVide")->valuestring;
  // char *tension_cc = cJSON_GetObjectItem(data, "transformerTensionCcUcc")->valuestring;
  // char *perte_cuivre = cJSON_GetObjectItem(data, "transformerPerteCuivre")->valuestring;
  // char *pert_fer = cJSON_GetObjectItem(data, "transformerPerteFer")->valuestring;
  // char *courant_a_vide = cJSON_GetObjectItem(data, "transformerCourantVide")->valuestring;
  // char *dephasage_phi = cJSON_GetObjectItem(data, "transformerDephasagePhi")->valuestring;
  // char *groupe_vecteur = cJSON_GetObjectItem(data, "transformerGroupVecteur")->valuestring;
  // char *capacite_c1 = cJSON_GetObjectItem(data, "transformerCapaciteC1")->valuestring;
  // char *capacite_c2 = cJSON_GetObjectItem(data, "transformerCapaciteC2")->valuestring;
  // char *rihd = cJSON_GetObjectItem(data, "transformerRihd")->valuestring;
  // char *rrrh = cJSON_GetObjectItem(data, "transformerRrrh")->valuestring;
  // char *alias = cJSON_GetObjectItem(data, "transformerAlias")->valuestring;
  // char *zone = cJSON_GetObjectItem(data, "stransformerZone")->valuestring;
  // char *substation = cJSON_GetObjectItem(data, "transformerSubstation")->valuestring;
  // char *etat = cJSON_GetObjectItem(data, "transformerEtat")->valuestring;

  char str[100];
  sprintf(str, "%d", number_transformer);
  char *test = "transformer";
  strcat(str, test);
  cJSON *data_transformer = cJSON_CreateArray();
  cJSON_AddItemToArray(data_transformer, cJSON_CreateString(start_noeud));
  cJSON_AddItemToArray(data_transformer, cJSON_CreateString(end_noeud));
  cJSON_AddItemToArray(data_transformer, cJSON_CreateString(tension_nominal_primary));
  cJSON_AddItemToArray(data_transformer, cJSON_CreateString(tension_nominal_secondary));
  cJSON_AddItemToArray(data_transformer, cJSON_CreateString(puissance_apparente));
  cJSON_AddItemToArray(data_transformer, cJSON_CreateString(tension_cc));
  cJSON_AddItemToArray(data_transformer, cJSON_CreateString(perte_cuivre));
  cJSON_AddItemToArray(data_transformer, cJSON_CreateString(perte_fer));
  cJSON_AddItemToArray(data_transformer, cJSON_CreateString(courant_a_vide));
  // cJSON_AddItemToArray(data_transformer, cJSON_CreateString(tension_cc));
  // cJSON_AddItemToArray(data_transformer, cJSON_CreateString(perte_cuivre));
  // cJSON_AddItemToArray(data_transformer, cJSON_CreateString(pert_fer));
  // cJSON_AddItemToArray(data_transformer, cJSON_CreateString(courant_a_vide));
  // cJSON_AddItemToArray(data_transformer, cJSON_CreateString(dephasage_phi));
  // cJSON_AddItemToArray(data_transformer, cJSON_CreateString(groupe_vecteur));
  // cJSON_AddItemToArray(data_transformer, cJSON_CreateString(capacite_c1));
  // cJSON_AddItemToArray(data_transformer, cJSON_CreateString(capacite_c2));
  // cJSON_AddItemToArray(data_transformer, cJSON_CreateString(rihd));
  // cJSON_AddItemToArray(data_transformer, cJSON_CreateString(rrrh));
  // cJSON_AddItemToArray(data_transformer, cJSON_CreateString(alias));
  // cJSON_AddItemToArray(data_transformer, cJSON_CreateString(zone));
  // cJSON_AddItemToArray(data_transformer, cJSON_CreateString(substation));
  // cJSON_AddItemToArray(data_transformer, cJSON_CreateString(etat));
  cJSON_AddItemToObject(transformer_object, str, data_transformer);
};

void load(cJSON *data, cJSON *load_object)
{
  number_load++;
  char *node = cJSON_GetObjectItem(data, "chargeNode")->valuestring;
  char *tension = cJSON_GetObjectItem(data, "chargeTension")->valuestring;
  char *puissance_active = cJSON_GetObjectItem(data, "chargePo")->valuestring;
  char *puissance_reactive = cJSON_GetObjectItem(data, "chargeQo")->valuestring;
  // char *type = cJSON_GetObjectItem(data, "chargeType")->valuestring;
  // char *po = cJSON_GetObjectItem(data, "chargePo")->valuestring;
  // char *qo = cJSON_GetObjectItem(data, "chargeQo")->valuestring;
  // char *cosO = cJSON_GetObjectItem(data, "chargeCosO")->valuestring;
  // char *s = cJSON_GetObjectItem(data, "chargeS")->valuestring;
  // char *phase = cJSON_GetObjectItem(data, "chargePhase")->valuestring;
  // char *tension = cJSON_GetObjectItem(data, "chargeTension")->valuestring;
  // char *facteur_p = cJSON_GetObjectItem(data, "chargeFacteur-p")->valuestring;
  // char *facteur_q = cJSON_GetObjectItem(data, "chargeFacteur-q")->valuestring;
  // char *alias = cJSON_GetObjectItem(data, "chargeAlias")->valuestring;
  // char *zone = cJSON_GetObjectItem(data, "chargeZone")->valuestring;
  // char *substation = cJSON_GetObjectItem(data, "chargeSubstation")->valuestring;
  // char *etat = cJSON_GetObjectItem(data, "charge-etat")->valuestring;

  char str[100];
  sprintf(str, "%d", number_load);
  char *test = "load";
  strcat(str, test);
  cJSON *data_load = cJSON_CreateArray();
  cJSON_AddItemToArray(data_load, cJSON_CreateString(node));
  cJSON_AddItemToArray(data_load, cJSON_CreateString(tension));
  cJSON_AddItemToArray(data_load, cJSON_CreateString(puissance_active));
  cJSON_AddItemToArray(data_load, cJSON_CreateString(puissance_reactive));
  // cJSON_AddItemToArray(data_load, cJSON_CreateString(po));
  // cJSON_AddItemToArray(data_load, cJSON_CreateString(qo));
  // cJSON_AddItemToArray(data_load, cJSON_CreateString(cosO));
  // cJSON_AddItemToArray(data_load, cJSON_CreateString(s));
  // cJSON_AddItemToArray(data_load, cJSON_CreateString(phase));
  // cJSON_AddItemToArray(data_load, cJSON_CreateString(tension));
  // cJSON_AddItemToArray(data_load, cJSON_CreateString(facteur_p));
  // cJSON_AddItemToArray(data_load, cJSON_CreateString(facteur_q));
  // cJSON_AddItemToArray(data_load, cJSON_CreateString(alias));
  // cJSON_AddItemToArray(data_load, cJSON_CreateString(zone));
  // cJSON_AddItemToArray(data_load, cJSON_CreateString(substation));
  // cJSON_AddItemToArray(data_load, cJSON_CreateString(etat));
  cJSON_AddItemToObject(load_object, str, data_load);
};
#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "../include/cJSON.h"

int main()
{
  // lecture du fichier json
  FILE *fp;
  char buffer[100000];
  cJSON *parsed_json;
  fp = fopen("graph.json", "r");
  fread(buffer, 100000, 1, fp);
  fclose(fp);

  // parsing du fichier json
  parsed_json = cJSON_Parse(buffer);
  if (parsed_json == NULL)
  {
    printf("Error parsing JSON\n");
    return 1;
  }

  // récupération des données
  cJSON *cells = cJSON_GetObjectItem(parsed_json, "cells");
  int cells_count = cJSON_GetArraySize(cells);

  // Création et ouverture des fichiers csv et txt
  FILE *write_csv;
  write_csv = fopen("matrices.csv", "w");
  FILE *write_txt;
  write_txt = fopen("matrices.txt", "w");
  // Création des objets de chaque composant
  cJSON *bus_object = cJSON_CreateObject();
  cJSON *slack_object = cJSON_CreateObject();
  cJSON *generator_object = cJSON_CreateObject();
  cJSON *load_object = cJSON_CreateObject();
  cJSON *line_object = cJSON_CreateObject();
  cJSON *transformer_object = cJSON_CreateObject();

  // Parcours du json
  for (int i = 0; i < cells_count; i++)
  {
    // On récupère chaque cellule (composant)
    cJSON *cell = cJSON_GetArrayItem(cells, i);
    // On récupère le type de composant
    char *type = cJSON_GetObjectItem(cell, "type")->valuestring;
    // On récupère les données du composant
    cJSON *data = cJSON_GetObjectItem(cell, "data");
    if (strcmp(type, "busV") == 0 || strcmp(type, "busH") == 0)
    {
      bus(cell, data, bus_object);
    }
    if (strcmp(type, "line") == 0)
    {
      line(cell, data, line_object);
    }
    if (strcmp(type, "slack") == 0)
    {
      slack(cell, data, slack_object);
    }
    if (strcmp(type, "generator") == 0)
    {
      generator(cell, data, generator_object);
    }
    if (strcmp(type, "transformer") == 0)
    {
      transformer(cell, data, transformer_object);
    }
    if (strcmp(type, "charge") == 0)
    {
      load(cell, data, load_object);
    }
  }

  // Ecriture du nombre de composants
  fprintf(write_csv, "number_bus=%d\nnumber_line=%d\nnumber_slack=%d\nnumber_generator=%d\nnumber_transformer=%d\nnumber_charge=%d\nnumber_components=%d\n", number_bus, number_line, number_slack, number_generator, number_transformer, number_load, number_bus + number_line + number_slack + number_generator + number_transformer + number_load);
  fprintf(write_txt, "number_bus=%d\nnumber_line=%d\nnumber_slack=%d\nnumber_generator=%d\nnumber_transformer=%d\nnumber_charge=%d\nnumber_components=%d\n", number_bus, number_line, number_slack, number_generator, number_transformer, number_load, number_bus + number_line + number_slack + number_generator + number_transformer + number_load);

  // Ecriture des objets dans les fichiers csv et txt
  for (int i = 1; i < number_bus + 1; i++)
  {
    char str[256];
    sprintf(str, "%d", i);
    cJSON *data = cJSON_GetObjectItem(bus_object, strcat(str, "bus"));
    char *str_bus = cJSON_Print(data);
    fprintf(write_csv, "%s\n", str_bus);
    fprintf(write_txt, "%s\n", str_bus);
  }

  for (int i = 1; i < number_line + 1; i++)
  {
    char str[256];
    sprintf(str, "%d", i);
    cJSON *data = cJSON_GetObjectItem(line_object, strcat(str, "line"));
    char *str_line = cJSON_Print(data);
    fprintf(write_csv, "%s\n", str_line);
    fprintf(write_txt, "%s\n", str_line);
  }

  for (int i = 1; i < number_slack + 1; i++)
  {
    char str[256];
    sprintf(str, "%d", i);
    cJSON *data = cJSON_GetObjectItem(slack_object, strcat(str, "slack"));
    char *str_slack = cJSON_Print(data);
    fprintf(write_csv, "%s\n", str_slack);
    fprintf(write_txt, "%s\n", str_slack);
  }

  for (int i = 1; i < number_generator + 1; i++)
  {
    char str[256];
    sprintf(str, "%d", i);
    cJSON *data = cJSON_GetObjectItem(generator_object, strcat(str, "generator"));
    char *str_generator = cJSON_Print(data);
    fprintf(write_csv, "%s\n", str_generator);
    fprintf(write_txt, "%s\n", str_generator);
  }

  for (int i = 1; i < number_transformer + 1; i++)
  {
    char str[256];
    sprintf(str, "%d", i);
    cJSON *data = cJSON_GetObjectItem(transformer_object, strcat(str, "transformer"));
    char *str_transformer = cJSON_Print(data);
    fprintf(write_csv, "%s\n", str_transformer);
    fprintf(write_txt, "%s\n", str_transformer);
  }

  for (int i = 1; i < number_load + 1; i++)
  {
    char str[256];
    sprintf(str, "%d", i);
    cJSON *data = cJSON_GetObjectItem(load_object, strcat(str, "load"));
    char *str_load = cJSON_Print(data);
    fprintf(write_csv, "%s\n", str_load);
    fprintf(write_txt, "%s\n", str_load);
  }

  // Fermeture des fichiers
  fclose(write_csv);
  fclose(write_txt);
}
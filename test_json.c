#include <stdio.h>
#include <string.h>
#include "include/cJSON.h"

char *list_id_bus[2];

char *get_bus(cJSON *parsed_json)
{
  // récupération des données
  cJSON *cells = cJSON_GetObjectItem(parsed_json, "cells");
  int cells_count = cJSON_GetArraySize(cells);

  FILE *write;
  write = fopen("bus_matrice.csv", "w");
  int number_bus = 1;

  // Parcours de la liste
  for (int i = 0; i < cells_count; i++)
  {
    // Get the JSON element and then get the values as before
    cJSON *cell = cJSON_GetArrayItem(cells, i);
    char *type = cJSON_GetObjectItem(cell, "type")->valuestring;
    // save number of busV
    if (strcmp(type, "busV") == 0 || strcmp(type, "busH") == 0)
    {
      cJSON *id = cJSON_GetObjectItem(cell, "id");
      cJSON *data = cJSON_GetObjectItem(cell, "data");
      cJSON *busTensionInit = cJSON_GetObjectItem(data, "busTensionInit");
      cJSON *busAngleInit = cJSON_GetObjectItem(data, "busAngleInit");
      fprintf(write, "%d, %s, %s, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", number_bus, busTensionInit->valuestring, busAngleInit->valuestring, 0, 0, 0, 0, 0, 0, 3, 0, 0);
      list_id_bus[number_bus - 1] = id->valuestring;
      number_bus++;
    }
  }
  fclose(write);
}


char *get_connected_elements(cJSON *parsed_json)
{
  // récupération des données
  cJSON *cells = cJSON_GetObjectItem(parsed_json, "cells");
  int cells_count = cJSON_GetArraySize(cells);

  FILE *write;
  write = fopen("bus_matrice.csv", "a");
  int i;
  // Parcours de la liste
  for (i = 0; i < cells_count; i++)
  {
    // Get the JSON element and then get the values as before
    cJSON *cell = cJSON_GetArrayItem(cells, i);
    char *type = cJSON_GetObjectItem(cell, "type")->valuestring;
    // save number of busV
    if (strcmp(type, "link") == 0)
    {
      cJSON *target = cJSON_GetObjectItem(cell, "target");
      cJSON *id = cJSON_GetObjectItem(target, "id");
      for (int i = 0; i < sizeof(list_id_bus); i++)
      {
        if (strcmp(id->valuestring, list_id_bus[i]) == 0)
        {
          cJSON *source = cJSON_GetObjectItem(cell, "source");
          cJSON *type = cJSON_GetObjectItem(source, "type");
          fprintf(write, "%s\n", type->valuestring);
          fclose(write);
        }
      }
    }
  }
}

char *get_connected_links(cJSON *parsed_json)
{
  // récupération des données
  cJSON *cells = cJSON_GetObjectItem(parsed_json, "cells");
  int cells_count = cJSON_GetArraySize(cells);

  FILE *write;
  write = fopen("bus_matrice.csv", "a");
  int i;
  // Parcours de la liste
  for (i = 0; i < cells_count; i++)
  {
    // Get the JSON element and then get the values as before
    cJSON *cell = cJSON_GetArrayItem(cells, i);
    char *type = cJSON_GetObjectItem(cell, "type")->valuestring;
    // save number of busV
    if (strcmp(type, "charge") == 0)
    {
      cJSON *source = cJSON_GetObjectItem(cell, "source");
      cJSON *id = cJSON_GetObjectItem(source, "id");
      for (int i = 0; i < sizeof(list_id_bus); i++)
      {
        if (strcmp(id->valuestring, list_id_bus[i]) == 0)
        {
          cJSON *type = cJSON_GetObjectItem(cell, "type");
          fprintf(write, "%s\n", type->valuestring);
          fclose(write);
        }
      }
    }
  }
}

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

  get_bus(parsed_json);
  get_connected_elements(parsed_json);
  get_connected_links(parsed_json);
}
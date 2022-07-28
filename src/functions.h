#include "../include/cJSON.h"

// Initialisation de des variables globales
int number_bus;
int number_slack;
int number_generator;
int number_load;
int number_line;
int number_transformer;

// Appel des fonctions
void bus(cJSON *cell, cJSON *data, cJSON *bus_object);
void line(cJSON *cell, cJSON *data, cJSON *line_object);
void slack(cJSON *cell, cJSON *data, cJSON *slack_object);
void generator(cJSON *cell, cJSON *data, cJSON *generator_object);
void transformer(cJSON *cell, cJSON *data, cJSON *transformer_object);
void load(cJSON *cell, cJSON *data, cJSON *charge_object);
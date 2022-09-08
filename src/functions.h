#include "../include/cJSON.h"

// Initialisation de des variables globales
int number_bus;
int number_line;
int number_slack;
int number_generator;
int number_transformer;
int number_load;

// Appel des fonctions
void bus(cJSON *data, cJSON *bus_object);
void line(cJSON *data, cJSON *line_object);
void slack(cJSON *data, cJSON *slack_object);
void generator(cJSON *data, cJSON *generator_object);
void transformer(cJSON *data, cJSON *transformer_object);
void load(cJSON *data, cJSON *charge_object);
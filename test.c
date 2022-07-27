#include <stdio.h>
#include "include/cJSON.h"

int main(void)
{
    cJSON* cjson_test = NULL;
    cJSON* cjson_address = NULL;
    cJSON* cjson_skill = NULL;
    char* str = NULL;

    /* Create a JSON data object (list header) */
    cjson_test = cJSON_CreateObject();

    /* Add a string of JSON data (add a list node) */
    cJSON_AddStringToObject(cjson_test, "name", "mculover666");

    /* Add an integer of JSON data (add a list node) */
    cJSON_AddNumberToObject(cjson_test, "age", 22);

    /* Add a floating point JSON data (add a list node) */
    cJSON_AddNumberToObject(cjson_test, "weight", 55.5);

    /* Add a nested JSON data (add a list node) */
    cjson_address = cJSON_CreateObject();
    cJSON_AddStringToObject(cjson_address, "country", "China");
    cJSON_AddNumberToObject(cjson_address, "zip-code", 111111);
    cJSON_AddItemToObject(cjson_test, "address", cjson_address);

    /* Add an array of JSON data (add a list node) */
    cjson_skill = cJSON_CreateArray();
    cJSON_AddItemToArray(cjson_skill, cJSON_CreateString( "C" ));
    cJSON_AddItemToArray(cjson_skill, cJSON_CreateString( "Java" ));
    cJSON_AddItemToArray(cjson_skill, cJSON_CreateString( "Python" ));
    cJSON_AddItemToObject(cjson_test, "skill", cjson_skill);

    /* Add a Boolean JSON data value of False (add a list node) */
    cJSON_AddFalseToObject(cjson_test, "student");

    /* Prints all the data of the JSON object (the whole list) */
    str = cJSON_Print(cjson_test);
    printf("%s\n", str);

    return 0;
}
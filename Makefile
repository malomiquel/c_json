compile:
		gcc ./src/main.c include/cJSON.h include/cJSON.c ./src/functions.c -o ./src/main

run:
		start ./src/main.exe
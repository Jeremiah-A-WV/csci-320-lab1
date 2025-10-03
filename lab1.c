#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab1.h"
#define MAX_LINE_LENGTH 100
/*
 * readString - reads a line from a file given by
 * fileName and returns it as a c-string.  The line
 * return is removed from the string.
 * 
 * fileName is c-string representing the file to read.
 * 
 */
char* readString(char* fileName){
    FILE *file;
    char buffer[MAX_LINE_LENGTH];
    char *line;
    
    file = fopen(fileName, "r");
    if (file == NULL) {
        return NULL;
    }

    if (fgets(buffer, MAX_LINE_LENGTH, file) == NULL) {
        fclose(file);
        return NULL;
    }

    fclose(file);

    int len = strlen(buffer);

    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
        len--;
    }

    line = (char*)malloc(len + 1);
    if (line == NULL) {
        return NULL;
    }

    strcpy(line, buffer); 

    return line;

}

/*
 * mysteryExplode - takes a string of characters and explodes it
 * as follows:
 * 
 * A non-empty string such as "Code" is turned into "CCoCodCode".
 *
 *   Return a new string similar to the string given above.
 *
 *  Example:
 *   mysteryExplosion("Code") --> "CCoCodCode"
 *   mysteryExplosion("abc") --> "aababc"
 *   mysteryExplosion(":)") --> "::)"
 * 
 */
char* mysteryExplode(const char* str){
    if (str == NULL) {
        return NULL;
    }

    int len = strlen(str);
    
    size_t new_len = (len * (len + 1)) / 2;
    size_t total_size = new_len + 1;

    char *new_str = (char *)malloc(total_size);
    if (new_str == NULL) {
        return NULL; 
    }

    char *current_pos = new_str; 

    for (size_t i = 1; i <= len; i++) {
        memcpy(current_pos, str, i);

        current_pos += i;
    }
    

    *current_pos = '\0';

    return new_str;
}
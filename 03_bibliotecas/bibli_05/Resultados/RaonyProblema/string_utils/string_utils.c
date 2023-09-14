#include "string_utils.h"
#include <stdio.h>
#define ADJUST 'A' - 'a'
#define MAX 1001

int string_length(char *str) {
    if (str[0] == '\0') return 0;

    int count = 0, i = 0;
    for (i = 0; str[i] != '\0'; i++) {
        count++;
    }

    if (str[i] == '\0') count++;
    return count;
}

void string_copy(char *src, char *dest) {
    int i = 0;
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

void string_upper(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] += ADJUST; 
        }
    }
}

void string_lower(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] -= ADJUST; 
        }
    }
}

void string_reverse(char *str) {
    int i = 0, j = 0, length = string_length(str)-1;
    char temp[length+1];

    for (i = length-2, j = 0; 
         i >= 0, j < length; 
         i--, j++) {
        temp[j] = str[i];
    }

    temp[j] = '\0';
    string_copy(temp, str);
}


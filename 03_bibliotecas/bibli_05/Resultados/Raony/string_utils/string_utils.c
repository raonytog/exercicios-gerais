#include "string_utils.h"
#include <stdio.h>
#define ADJUST 'A' - 'a'

int string_length(char *str) {
    int i = 0;

    while (str[i]) {
        i++;
    }

    return i;
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
    int i = 0, j = 0, length = string_length(str);
    char temp[1];

    int stopCondition = 0;
    if (length%2 == 0)  stopCondition = length/2;
    else stopCondition = length/2+1;

    for (i = 0; i < stopCondition; i++) {
        length--;
        temp[0] = str[i];
        str[i] = str[length];
        str[length] = temp[0];
    }
}

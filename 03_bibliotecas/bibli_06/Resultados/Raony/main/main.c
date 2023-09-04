/*
Programa para converter as unidades de medida entre C, F e K usando a biblioteca criada
Raony Togneri 
02/09/2023
*/

#include <stdio.h>
#include "temperature_conversor.h"

int main () {
    float number = 0, converted = 0;
    char actual, toConverte;
    scanf("%f %c %c", &number, &actual, &toConverte);

    if (actual == 'c') {
        switch (toConverte) {
        case 'k':
            converted = convert_temperature(number, convert_celsius_to_kelvin);
            break;

        case 'f':
            converted = convert_temperature(number, convert_celsius_to_fahrenheit);
            break;
        }

    } else if (actual == 'f') {
        switch (toConverte) {
        case 'k':
            converted = convert_temperature(number, convert_fahrenheit_to_kelvin);
            break;

        case 'c':
            converted = convert_temperature(number, convert_fahrenheit_to_celsius);
            break;
        }

    } else if (actual == 'k') {
        switch (toConverte) {
        case 'c':
            converted = convert_temperature(number, convert_kelvin_to_celsius);
            break;

        case 'f':
            converted = convert_temperature(number, convert_kelvin_to_fahrenheit);
            break;
        }
    }

    printf("Temperature: %.2f%c", converted, toConverte + 'A'-'a');
    if (toConverte == 'c' || toConverte == 'f') printf("º");

    return 0;
}
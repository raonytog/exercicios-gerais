#include "temperature_conversor.h"
#define KELVIN 273.15
#define FIVE_DIV_NINE 5.0/9

float convert_celsius_to_kelvin(float temperature) {
    return temperature + KELVIN;
}

float convert_celsius_to_fahrenheit(float temperature) {
    return (temperature * 5.0/9) + 32;
}

float convert_kelvin_to_celsius(float temperature) {
    return temperature - KELVIN;
}

float convert_kelvin_to_fahrenheit(float temperature) {
    return ((temperature - KELVIN) * 9.0/5) + 32;
}


float convert_fahrenheit_to_celsius(float temperature) {
    return (temperature - 32) * (5.0/9);
}

float convert_fahrenheit_to_kelvin(float temperature) {
    return (temperature - 32) * (5.0/9) + KELVIN;
}

float convert_temperature(float temperature, float convert_func(float temperature)) {
    return convert_func(temperature);
}


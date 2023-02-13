#include <stdio.h>
#include <stdlib.h>


typedef struct Temperature{
    float temp_data;

}temperature;

void temperature_change(temperature *value, float new_temp);
void temperature_show(temperature *value);


int main()
{
    temperature value;
    int x = 100;
    temperature_change(&value, (int)x);
}



void temperature_change(temperature *value, float new_temp)
{
    value->temp_data = new_temp;
    temperature_show(value);
}
void temperature_show(temperature *value)
{

    printf("Value is: %f", value->temp_data);
}

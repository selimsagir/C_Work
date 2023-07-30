#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void functionOne(void);
void functionTwo(void);
void functionThree(void);
void functionFour(void);

typedef struct 
{
    void (*func)(void);
    int priority;
} FunctionEntry;
#define maxPrio  (10)
#define lowestPrio  (0)

FunctionEntry functionArray[] = {
    {functionOne, 5},
    {functionTwo, 10},
    {functionThree, 3},
    {functionFour, 2},

};

size_t numFunctions = sizeof(functionArray) / sizeof(functionArray[0]);

int remove_function(FunctionEntry *function, size_t idx){
    if(idx ==  numFunctions-1){
        numFunctions--;
        return 0;
    }
    for (size_t i = idx; i < numFunctions; i++)
    {
       function[idx] = function[idx+1];

    }
     numFunctions--;
     return 1;
}

int scheduler(void){
    Sleep(1000);
    int max_priority = functionArray[0].priority;
    int max_priority_index = 0;
    for(int i = 1; i < numFunctions; i++ ){  //start from 1
        if(functionArray[i].priority > max_priority  ) {
            max_priority = functionArray[i].priority;
            max_priority_index = i;
        }
    }
    functionArray[max_priority_index].func();
    remove_function(functionArray, max_priority_index);
    printf("remained function number is: %d\n",numFunctions);
    return numFunctions;
} 
int main()
{    
  
    
    while (scheduler())
    {
        
        
    } 
    printf("\n scheduler is empty \n");
}



void functionOne(void){
    printf("This is first function\n");
}
void functionTwo(void){

    printf("This is second function\n");
}

void functionThree(void){

    printf("This is three function\n");
}
void functionFour(void){

    printf("This is Four function\n");
}

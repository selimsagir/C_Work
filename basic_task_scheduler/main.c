#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_PROCESSES 32
#define MAX_NAME_LEN 32


/*
* Process control block
*/

struct pcb {
    int pid; // id
    int prio; // priority
    int attached;
    int *function;
    char name[MAX_NAME_LEN];
};

static struct pcb processList[MAX_PROCESSES];
int process0();
int process1();

int process_attach(char *name, int prio, void *function){
    int i = 0;
    int ret = -1;
    printf("[dbg] process attach\n");
    while(i < MAX_PROCESSES){
        if(strlen(name) > MAX_NAME_LEN){
            printf("name is long");
            return ret;
        }
        if(processList[i].attached != 1){
            printf("attach process at %d\n", i);
            processList[i].pid = i;
            strcpy(processList[i].name, name);
            processList[i].prio = prio;
            processList[i].function = function;
            processList[i].attached = 1;
            ret = 0;
            break;
        }
        i++;
    }
    return ret;
}

int process_detach(int pid){
    processList[pid].attached = 0;
    return 0;
}

int scheduler(){

    int i = 0;
    void (*p)(void);
    while(1) {
        for(int i = 0; i < MAX_PROCESSES; i++){
            if(processList[i].attached == 1){
                p = (void*)processList[i].function;
                (*p)();
            }
        }
    }
    return 0;
}
int process0()
{
	printf("0\n");
	return 0;
}
 
int process1()
{
	printf("1\n");
	return 0;
}
int main()
{

    printf("Scheduler start-up\n");
    process_attach("process0", 100, process0);
    process_attach("process1", 50, process1);
    scheduler();
    return 0;
}
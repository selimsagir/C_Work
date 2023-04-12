#include <stdio.h>
#include <stdlib.h>

typedef struct state_machine state_machine_t;
typedef struct state state_t;

struct state_machine {
    state_t* current_state;
};

struct state {
    void (*entry)();
    void (*exit)();
    state_t* parent;
};

void parent_state_entry() {
    printf("Parent state entered.\n");
}

void parent_state_exit() {
    printf("Parent state exited.\n");
}

void child_state_entry() {
    printf("Child state entered.\n");
}

void child_state_exit() {
    printf("Child state exited.\n");
}

void grandchild_state_entry() {
    printf("Grandchild state entered.\n");
}

void grandchild_state_exit() {
    printf("Grandchild state exited.\n");
}

void transition_to_child(state_machine_t* machine);

void transition_to_grandchild(state_machine_t* machine) {
    printf("Transitioning to grandchild state.\n");
    machine->current_state = (state_t*)malloc(sizeof(state_t));
    machine->current_state->entry = grandchild_state_entry;
    machine->current_state->exit = grandchild_state_exit;
    machine->current_state->parent = (state_t*)malloc(sizeof(state_t));
    machine->current_state->parent->entry = child_state_entry;
    machine->current_state->parent->exit = child_state_exit;
    machine->current_state->parent->parent = (state_t*)malloc(sizeof(state_t));
    machine->current_state->parent->parent->entry = parent_state_entry;
    machine->current_state->parent->parent->exit = parent_state_exit;
}

void transition_to_child(state_machine_t* machine) {
    printf("Transitioning to child state.\n");
    machine->current_state = (state_t*)malloc(sizeof(state_t));
    machine->current_state->entry = child_state_entry;
    machine->current_state->exit = child_state_exit;
    machine->current_state->parent = (state_t*)malloc(sizeof(state_t));
    machine->current_state->parent->entry = parent_state_entry;
    machine->current_state->parent->exit = parent_state_exit;
    transition_to_grandchild(machine);
}

int main() {
    state_machine_t machine;
    machine.current_state = (state_t*)malloc(sizeof(state_t));
    machine.current_state->entry = parent_state_entry;
    machine.current_state->exit = parent_state_exit;
    machine.current_state->parent = NULL;
    transition_to_child(&machine);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int val;
    struct node *next;
}node_t;

void print_list(node_t * head){
    node_t * current = head;
    while(current != NULL){
        printf("%d\n", current->val);
        current = current->next;
    }
}

void push(node_t *head, int val){

    node_t *current = head;
    while (current->next ==NULL)
    {
        current = current->next;
    }
    
    current->next = (node_t*)malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next =NULL;

}

void push_(node_t ** head, int val) {
    node_t * new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

int pop(node_t ** head){
    int retval = -1;
    node_t * next_node = NULL;

    if(*head == NULL){
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;
    return retval;

}

int remote_list(node_t * head){
    int retVal = 0;

    // check if here is one item
    if(head->next == NULL){
        retVal = head->val;
        free(head);
        return retVal;
    }
    
    node_t * current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    
    retVal = current->next->val;
    free(current->next);
    current->next = NULL;
    return retVal;

}

int remove_last(node_t* head){
    int retVal =0;
    // if there is only one item
    if(head->next == NULL){
        retVal = head->val;
        free(head);
        return retVal;
    }

    // get to second to last node in the list
    node_t* current = head;
    while(current->next->next != NULL){
        current = current->next;
    }

    // now current points to second to last item of the list
    // so let's remove current->next
    retVal = current->next->val;
    free(current->next);
    current->next = NULL;
    return retVal;
}

int remove_by_index(node_t ** head, int n){
    int i = 0;
    int retVal = -1;
    node_t * current = *head;
    node_t *temp_node = NULL;

    if (n == 0){
        return pop(head);
    }

    for(i = 0; i < (n-1); i++ ){
        if(current->next == NULL) {
            return -1;
        }
        current = current->next;
    }
    if(current->next ==  NULL){
        return -1;
    }

    temp_node = current->next;
    retVal = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);
    return retVal;

}
int main() {

    node_t * head;
    push_(&head, 10);
    push_(&head, 12);
    push_(&head, 13);
        push_(&head, 22);
    push_(&head, 33);
    push_(&head, 45);
    // print_list(head);
    int ret = pop(&head);
    // printf("%d\n",ret);
    remove_by_index(&head, 2);
    print_list(head);
    return 0;

}

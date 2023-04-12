// #include <stdio.h>
// #include <stdlib.h>

// int main(){

//     /**
//      * @brief Note structure
//      * 
//      */

//     struct node {
//         int data;
//         struct node *next;
//     };

//     // declaration of nodes

//     struct node *head, *middle, *last;

//     head = malloc(sizeof(struct node));
//     middle = malloc(sizeof(struct node));
//     last = malloc(sizeof(struct node));

//     //assign value
//     head->data =10;
//     middle->data =20;
//     last->data = 30;

//     // connect nodes  head -> middle -> last
//     head->next = middle;
//     middle->next = last;
//     last->next = NULL;

//     struct node *temp = head; // temp to reference head pointer

//     while(temp != NULL){
//         printf("%d->" , temp->data);
//         temp = temp->next;
//     }
//     printf("NULL");
//     return 0;
// }
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
  
// struct node *head = NULL;
void addFirst(struct node **head, int val)
{
      //create a new node
      struct node *newNode = malloc(sizeof(struct node));
      newNode->data = val;

      newNode->next = *head;

      *head = newNode;
}

void printList(struct node *head)
{
    struct node *temp = head;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}
void add_end(struct node **head, int val){
 
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;

    if(*head == NULL){
        *head = new_node;
    }
    else{
        struct node *last_node = *head;

        // last node's next address will be NULL
        while ( last_node->next != NULL)
        {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }
}

int searchNode(struct node *head, int val){
    struct node *temp = head;
    while(temp != NULL){
        if(temp->data == val){
            return 1;
        }
        else{
            temp = temp->next;
        }
    } 

    return -1;
}

int deleteNode(struct node ** head, int val){
    struct node *temp;
    if((*head)->data == val){
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    else{
        struct node *current = *head;
        while(current->next != NULL){
            if(current->next->data == val){
                temp = current->next;
                //disconnect the linked list
                current->next = current->next->next;
                free(temp);
                break;
            }
            else{
                // move forward
                current = current->next;
            }

        }
    }   
}
int main()
{
     struct node *head = NULL;

     addFirst(&head,10);
     addFirst(&head,20);
     addFirst(&head,30);
     addFirst(&head,40);
     printList(head);
    //  add_end(&head,99);
     deleteNode(&head, 20);
     printList(head);

    #ifdef DEBUG
     int ret = searchNode(head, 302);
    if (ret == 1) printf("key founded");
    else printf("key is not founded");
    #endif

     return 0;
}
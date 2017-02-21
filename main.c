/*
    Created by Richard Lynch 

*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>

typedef struct node node;

typedef struct node{
    int value;
    node* next;
} node;

typedef struct llist{
    node* head;
    node* tail;
} llist;

void addNode(llist* List, int value){
    if(List->head != NULL){ //if the list isnt empty
        List->tail->next = (node*)(malloc(sizeof(node)));   //allocate for the node at add to the end
        List->tail = List->tail->next;  //move the tail to the end
        List->tail->value = value;  //add the value to the new node 
        List->tail->next = NULL;    //make the new node point to null
    } else {    //if the list is empty              
        List->tail = (node*)malloc(sizeof(node));   //allocare a node at the end
        List->head = List->tail;    //the start and the end are the same
        List->tail->value = value;  //add the value to the new node
        List->tail->next = NULL;    //make the new node point to null
    }
}

void delNode(llist* List, int value){
    node* prev = NULL;
    node* curr = List->head;
    while(curr != NULL){
        if(curr->value == value){
            if(curr == List->head){
                List->head = curr->next;
            } else if ( curr == List->tail){
                prev->next = curr->next;
                List->tail = prev;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            return;
        } else {
            prev = curr;
            curr = curr->next;
        }  
    }
    printf("\n");
}

void printList(llist* List){
    node* curr = List->head;
    while(curr != NULL){
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

void revList(llist* List){
    List->tail = List->head;
    node* prev = NULL;
    node* curr = List->head;
    node* next = NULL;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    List->head = prev;
}



int main(int argc, char *argv[])
{
    llist List;
    List.head = NULL;
    List.tail = NULL;

    addNode(&List, 2);
    addNode(&List, 3);
    addNode(&List, 4);
    printList(&List);
    revList(&List);
    printList(&List);
    delNode(&List, 2);
    printList(&List);

// done
    printf("Goodbye\n\n");

    while(1){

    }

    return 0;
}
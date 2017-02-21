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
    node* prev = NULL;  //temp pointers
    node* curr = List->head;    //strt at the head
    while(curr != NULL){                        //while not at the end of the lsit
        if(curr->value == value){               //if we find the value
            if(curr == List->head){             //if the value is at the head
                List->head = curr->next;        //the new head is the next value
                if ( curr == List->tail){       //if also at the tail
                    List->tail = NULL           //then the list is empty and the tail is null ( head will already be NULL)
                }
            } else {                            //not at head
                if ( curr == List->tail){       //if we're at tail
                    List->tail = prev;          //tail equals the last value ( safe because we know we're not also at head )
                }
                prev->next = curr->next;        //bypass the current node ( if tail, the curr node will have been pointing at null anyway )
            }
            free(curr);                         //free the memory
            return;                             
        } else {    //otherwise iterate
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
    List->tail = List->head;    //move tail to the old head
    node* prev = NULL;          //prevs value
    node* curr = List->head;    //curr is the head
    node* next = NULL;          //next = null ( doesnt matter, it wont be used without being set)
    
    while(curr != NULL){        //while not at the end of the list
        next = curr->next;      //store the value of the next node
        curr->next = prev;      //point the curr node back at the last node
        prev = curr;            //iterate
        curr = next;
    }
    List->head = prev;          //at the end of the list, put head on the last value, and the list will be reversed
    //this is empty safe
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
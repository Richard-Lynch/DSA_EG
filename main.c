/*
    Created by Richard Lynch 

*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
int TABLE_SIZE = 101;
typedef struct node node;

typedef struct node{
    int value;
    node* next;
} node;

typedef struct table table;

typedef struct table {
    node* array;
    char** keys;
    int num_keys;
} table;

int hash(char* string){
    int total = 0; 
    for(int i = 0; i< strlen(string); i++){
        total += (int)string[i];
    }
    return total % TABLE_SIZE;
}

int addNode(char* key, int value, table* Table){
    Table->array[hash(key)].value = value;
    Table->keys[Table->num_keys] = key;
    Table->num_keys++;
    return Table->num_keys;
}

void printKeys(table* Table){
    for(int i = 0; i < Table->num_keys; i++){
        printf("Key[%d]: %s\n",i, Table->keys[i]);
    }
}

void printHashes(table* Table){
    for(int i = 0; i < Table->num_keys; i++){
        printf("Hash(\"%s\")(Key[%d]): %d\n",Table->keys[i],i, hash(Table->keys[i]));
    }
}

void printValues(table* Table){
    for(int i = 0; i < Table->num_keys; i++){
        printf("Key(%s): %d\n",Table->keys[i], Table->array[hash(Table->keys[i])].value);
    }
}


int main(int argc, char *argv[])
{
    int size = TABLE_SIZE;
    int stringMax = 255;
    table Table;
    Table.array = (node*)(malloc(sizeof(node)*size));
    Table.keys = (char**)(malloc(sizeof(char*)*size*stringMax));
    Table.num_keys = 0;
    char key1[] = "hello world";
    char key2[] = "goodbye world";
    char key3[] = "shutup world";
    char key4[] = "sorry world";
    printf("Keys: %d\n", addNode(key1, 2, &Table));
    printf("Keys: %d\n", addNode(key2, 3, &Table));
    printf("Keys: %d\n", addNode(key3, 4, &Table));
    printf("Keys: %d\n", addNode(key4, 5, &Table));
    printKeys(&Table);
    printf("Hello world value: %d\n", Table.array[hash("hello world")].value);
    printHashes(&Table);
    printValues(&Table);
    

// done
    printf("Goodbye\n\n");

    while(1){

    }

    return 0;
}
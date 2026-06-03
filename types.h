#ifndef TYPES_H
#define TYPES_H

#define MAX_ID        10
#define MAX_NAME      30
#define MAX_CATEGORY  20
#define MAX_LOCATION  20
#define MAX_STATUS    15
#define MAX_OWNER     25
#define MAX_PIC       25


typedef struct Item {
    char id[MAX_ID];
    char name[MAX_NAME];
    char category[MAX_CATEGORY];
    int  stock;
    char location[MAX_LOCATION];
    char status[MAX_STATUS];    
    char owner[MAX_OWNER];
    char pic[MAX_PIC];
} Item;

typedef struct Node {
    Item data;
    struct Node *next;
} Node;

#endif
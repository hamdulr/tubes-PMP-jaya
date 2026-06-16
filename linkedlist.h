#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "types.h"

void initList(Node** head);
void addNodeToList(Node** head, Item newItem, int* success);
void deleteNodeFromList(Node** head, char* targetId, int* success);
void findNodeById(Node* head, char* targetId, Node** result);
void countNodes(Node* head, int* count);
void freeAllNodes(Node** head);

#endif 
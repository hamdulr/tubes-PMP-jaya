#ifndef INVENTORY_H
#define INVENTORY_H

#include "types.h"

void addItem(Node **head);
void deleteItem(Node **head);
void searchItem(Node *head);
void updateStock(Node *head);
void updateStatus(Node *head);

#endif
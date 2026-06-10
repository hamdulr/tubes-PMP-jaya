#ifndef DISPLAY_H
#define DISPLAY_H

#include "types.h"

void printMenu(void);
void printItem(Node *node);
void printAllItems(Node *head);
void printInventorySummary(Node *head);
void printTableHeader(void);
void printSeparatorLine(void);

#endif
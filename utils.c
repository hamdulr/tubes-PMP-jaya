#include <stdio.h>
#include "linkedlist.h"
#include "utils.h"

void clearInputBuffer(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
    //kosong
    }
}

void checkMemoryWarning(Node* head)
{
    int count;

    countNodes(head, &count);

    if (count >= MAX_ITEMS * 0.8)
    {
        printf("\nPeringatan: kapasitas inventaris hampir penuh!\n");
        printf("Data tersimpan: %d dari %d\n", count, MAX_ITEMS);
    }
}
#include <stdio.h>
#include "linkedlist.h"
#include "utils.h"

void clearInputBuffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    //kosong
    }
}

void checkMemoryWarning(Node* head)
{
    int jumlahData;

    countNodes(head, &jumlahData);

    if (jumlahData >= MAX_ITEMS * 0.8)
    {
        printf("\nPeringatan: kapasitas inventaris hampir penuh!\n");
        printf("Data tersimpan: %d dari %d\n", jumlahData, MAX_ITEMS);
    }
}
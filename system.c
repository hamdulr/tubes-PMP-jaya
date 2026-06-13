#include <stdio.h>
#include "system.h"
#include "display.h"
#include "inventory.h"
#include "linkedlist.h"
#include "utils.h"

void startSystem(void) {
    Node *head = NULL;
    initList(&head);

    int choice = -1;
    while (choice != 0) {
        printMenu();
        
        // Pengecekan keamanan input
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer(); 
            printf("Error: Input tidak valid. Masukkan angka.\n");
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: 
                addItem(&head); 
                break;
            case 2: 
                deleteItem(&head); 
                break;
            case 3: 
                searchItem(head); 
                break;
            case 4: 
                updateStock(head); 
                break;
            case 5: 
                updateStatus(head); 
                break;
            case 6: 
                printAllItems(head); 
                break;
            case 0:
                printf("Menutup sistem. Membebaskan alokasi memori...\n");
                freeAllNodes(&head);
                break;
            default:
                printf("Error: Pilihan menu tidak tersedia.\n");
        }
        
        // Memeriksa kapasitas memori setelah setiap eksekusi
        if (choice != 0) {
            checkMemoryWarning(head);
        }
    }
}
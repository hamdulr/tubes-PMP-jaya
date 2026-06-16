#include <stdio.h>
#include "system.h"
#include "display.h"
#include "inventory.h"
#include "linkedlist.h"
#include "utils.h"

void startSystem(void) {
    // Inisialisasi linked list sebagai null
    Node *head = NULL;
    initList(&head);

    int choice = -1;
    while (choice != 0) {
        printMenu();
        
        // Input
        if (scanf("%d", &choice) != 1) {
            // Flush buffer input agar tidak loop
            clearInputBuffer(); 
            printf("ERROR: Input tidak valid. Masukkan input angka.\n");
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
                printf("Menutup sistem...\n");
                freeAllNodes(&head);
                printf("Sistem berhasil ditutup.\n");
                break;
            default:
                printf("ERROR: Pilihan menu tidak valid.\n");
        }
        
        // Memeriksa memori setelah tiap operasi
        if (choice != 0) {
            checkMemoryWarning(head);
        }
    }
}
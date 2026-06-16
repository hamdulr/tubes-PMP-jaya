/* ============================================================
 * linked_list.c
 * Implementasi modul operasi linked list — Sistem Inventarisasi Lab
 * ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

/* ----------------------------------------------------------
 * initList
 * ---------------------------------------------------------- */
void initList(Node** head) {
    if (head != NULL) {
        *head = NULL;
    }
}

/* ----------------------------------------------------------
 * addNodeToList
 * ---------------------------------------------------------- */
void addNodeToList(Node** head, Item newItem, int* success) {
    *success = 0; // Set status gagal sebagai default
    
    if (head == NULL) return;

    // Periksa kapasitas saat ini menggunakan countNodes
    int currentCount = 0;
    countNodes(*head, &currentCount);
    
    if (currentCount >= MAX_ITEMS) {
        return; // Gagal karena kapasitas maksimal tercapai
    }

    // Alokasi memori untuk node baru
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return; // Gagal karena malloc gagal alokasi
    }

    // Salin data ke node baru
    newNode->data = newItem;
    newNode->next = NULL;

    // Jika list masih kosong, jadikan node baru sebagai head
    if (*head == NULL) {
        *head = newNode;
    } else {
        // Jika tidak, traverse ke akhir list
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    *success = 1; // Berhasil
}

/* ----------------------------------------------------------
 * deleteNodeFromList
 * ---------------------------------------------------------- */
void deleteNodeFromList(Node** head, char* targetId, int* success) {
    *success = 0; // Set status gagal sebagai default
    
    if (head == NULL || *head == NULL || targetId == NULL) {
        return; // List kosong atau parameter invalid
    }

    Node* current = *head;
    Node* previous = NULL;

    // Linear traversal mencari ID target
    while (current != NULL) {
        if (strcmp(current->data.id, targetId) == 0) {
            
            // Kasus 1: Node yang akan dihapus adalah node pertama (head)
            if (previous == NULL) {
                *head = current->next;
            } 
            // Kasus 2 & 3: Node yang akan dihapus di tengah atau di akhir
            else {
                previous->next = current->next;
            }
            
            free(current); // Bebaskan memori
            *success = 1;  // Berhasil
            return;
        }
        
        // Maju ke node berikutnya
        previous = current;
        current = current->next;
    }
}

/* ----------------------------------------------------------
 * findNodeById
 * ---------------------------------------------------------- */
void findNodeById(Node* head, char* targetId, Node** result) {
    *result = NULL; // Set default null jika tidak ketemu
    
    if (targetId == NULL) return;

    Node* current = head;
    
    // Linear traversal mencari ID target
    while (current != NULL) {
        if (strcmp(current->data.id, targetId) == 0) {
            *result = current; // Ditemukan
            return;
        }
        current = current->next;
    }
}

/* ----------------------------------------------------------
 * countNodes
 * ---------------------------------------------------------- */
void countNodes(Node* head, int* count) {
    *count = 0;
    Node* current = head;
    
    while (current != NULL) {
        (*count)++;
        current = current->next;
    }
}

/* ----------------------------------------------------------
 * freeAllNodes
 * ---------------------------------------------------------- */
void freeAllNodes(Node** head) {
    if (head == NULL) return;

    Node* current = *head;
    Node* nextNode = NULL;

    // Bebaskan node satu per satu
    while (current != NULL) {
        nextNode = current->next; // Simpan pointer ke node selanjutnya
        free(current);            // Bebaskan node saat ini
        current = nextNode;       // Geser ke node selanjutnya
    }

    // Setel ulang head menjadi NULL
    *head = NULL;
}
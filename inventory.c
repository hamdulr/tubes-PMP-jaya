/* ============================================================
 * inventory.c
 * Implementasi modul operasi inventaris — Sistem Inventarisasi Lab
 * ============================================================ */

#include <stdio.h>
#include <string.h>

#include "inventory.h"
#include "linkedlist.h"
#include "display.h"
#include "utils.h"

void addItem(Node **head) {
    Item newItem;
    Node *found = NULL;
    int success = 0;

    printf("\n=== Tambah Barang ===\n");

    printf("ID Barang: ");
    scanf("%s", newItem.id);
    clearInputBuffer();

    findNodeById(*head, newItem.id, &found);
    if (found != NULL) {
        printf("Gagal: ID barang sudah ada.\n");
        return;
    }

    printf("Nama Barang: ");
    fgets(newItem.name, MAX_NAME, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0';

    printf("Kategori Barang: ");
    fgets(newItem.category, MAX_CATEGORY, stdin);
    newItem.category[strcspn(newItem.category, "\n")] = '\0';

    printf("Jumlah Stok: ");
    scanf("%d", &newItem.stock);
    clearInputBuffer();

    if (newItem.stock < 0) {
        return;
    }

    printf("Lokasi Penyimpanan: ");
    fgets(newItem.location, MAX_LOCATION, stdin);
    newItem.location[strcspn(newItem.location, "\n")] = '\0';

    printf("Status Barang: ");
    fgets(newItem.status, MAX_STATUS, stdin);
    newItem.status[strcspn(newItem.status, "\n")] = '\0';

    printf("Pemilik Barang: ");
    fgets(newItem.owner, MAX_OWNER, stdin);
    newItem.owner[strcspn(newItem.owner, "\n")] = '\0';

    printf("PIC Barang: ");
    fgets(newItem.pic, MAX_PIC, stdin);
    newItem.pic[strcspn(newItem.pic, "\n")] = '\0';

    addNodeToList(head, newItem, &success);

    if (success == 1) {
        printf("Barang berhasil ditambahkan\n");
    } 
    else {
        printf("Gagal menambahkan barang\n");
    }
}

void deleteItem(Node **head) {
    char targetId[MAX_ID];
    Node *found = NULL;
    int success = 0;

    printf("\n=== Hapus Barang ===\n");

    if (head == NULL || *head == NULL) {
        printf("Data inventaris kosong.\n");
        return;
    }

    printf("Masukkan ID barang: ");
    scanf("%s", targetId);
    clearInputBuffer();

    findNodeById(*head, targetId, &found);
    if (found == NULL) {
        printf("Gagal: ID barang tidak ditemukan\n");
        return;
    }

    deleteNodeFromList(head, targetId, &success);

    if (success == 1) {
        printf("Barang berhasil dihapus\n");
    } 
    else {
        printf("Gagal menghapus barang\n");
    }
}

void searchItem(Node *head) {
    char targetId[MAX_ID];
    Node *found = NULL;

    printf("\n=== Cari Barang ===\n");

    if (head == NULL) {
        printf("Data inventaris kosong\n");
        return;
    }

    printf("Masukkan ID barang: ");
    scanf("%s", targetId);
    clearInputBuffer();

    findNodeById(head, targetId, &found);

    if (found == NULL) {
        printf("ID barang tidak ditemukan\n");
    } 
    else {
        printf("Data barang ditemukan:\n");
        printItem(found);
    }
}

void updateStock(Node *head) {
    char targetId[MAX_ID];
    int newStock;
    Node *found = NULL;

    printf("\n=== Update Stok ===\n");

    if (head == NULL) {
        printf("Data inventaris kosong\n");
        return;
    }

    printf("Masukkan ID barang: ");
    scanf("%s", targetId);
    clearInputBuffer();

    findNodeById(head, targetId, &found);

    if (found == NULL) {
        printf("Gagal: ID barang tidak ditemukan.\n");
        return;
    }

    printf("Masukkan stok baru: ");
    scanf("%d", &newStock);
    clearInputBuffer();

    if (newStock < 0) {
        return;
    }

    found->data.stock = newStock;

    if (newStock == 0) {
        strcpy(found->data.status, "Habis");
    }

    printf("Stok berhasil diperbarui\n");
}

void updateStatus(Node *head) {
    char targetId[MAX_ID];
    Node *found = NULL;

    printf("\n=== Update Status ===\n");

    if (head == NULL) {
        printf("Data inventaris kosong\n");
        return;
    }

    printf("Masukkan ID barang: ");
    scanf("%s", targetId);
    clearInputBuffer();

    findNodeById(head, targetId, &found);

    if (found == NULL) {
        printf("Gagal: ID barang tidak ditemukan\n");
        return;
    }

    printf("Masukkan status baru: ");
    fgets(found->data.status, MAX_STATUS, stdin);
    found->data.status[strcspn(found->data.status, "\n")] = '\0';

    printf("Status berhasil diperbarui\n");
}
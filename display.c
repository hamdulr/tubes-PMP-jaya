#include <stdio.h>
#include "display.h"

void printSeparatorLine(void) {
    printf("----------------------------------------------------------------------------------------------------------------------------------\n");
}

void printTableHeader(void) {
    printSeparatorLine();
    // Lebar kolom disesuaikan dengan limit array di types.h
    printf("| %-8s | %-28s | %-18s | %-5s | %-18s | %-13s | %-23s | %-23s |\n",
           "ID", "Nama Barang", "Kategori", "Stok", "Lokasi", "Status", "Pemilik", "PIC");
    printSeparatorLine();
}

void printMenu(void) {
    printf("\n");
    printSeparatorLine();
    printf("SISTEM INVENTARIS LABORATORIUM\n");
    printSeparatorLine();
    printf("1. Tambah Data Barang\n");
    printf("2. Hapus Data Barang\n");
    printf("3. Cari Data Barang\n");
    printf("4. Perbarui Stok\n");
    printf("5. Perbarui Status\n");
    printf("6. Tampilkan Seluruh Data\n");
    printf("0. Keluar Sistem\n");
    printf("Pilih menu: ");
}

void printItem(Node *node) {
    if (node == NULL) return;
    
    printf("| %-8s | %-28s | %-18s | %-5d | %-18s | %-13s | %-23s | %-23s |\n",
           node->data.id,
           node->data.name,
           node->data.category,
           node->data.stock,
           node->data.location,
           node->data.status,
           node->data.owner,
           node->data.pic);
}

void printAllItems(Node *head) {
    // Memenuhi syarat pencegahan error untuk data kosong
    if (head == NULL) {
        printf("Database kosong. Tidak ada data inventaris untuk ditampilkan.\n");
        return;
    }

    printTableHeader();
    
    Node *current = head;
    while (current != NULL) {
        printItem(current);
        current = current->next;
    }
    
    printSeparatorLine();
}
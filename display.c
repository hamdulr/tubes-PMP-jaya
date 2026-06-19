#include <stdio.h>
#include <string.h>
#include "display.h"

void printSeparatorLine(void) {
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void printTableHeader(void) {
    printSeparatorLine();
    // Merujuk pada types.h yang memuat angka Max_ID = 10, Max_NAME = 30, dsb
    // dikurang 2 untuk padding spasi di kiri dan kanan
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
    printf("4. Update Stok Barang\n");
    printf("5. Update Status Barang\n");
    printf("6. Tampilkan Seluruh Data\n");
    printf("7. Tampilkan Rangkuman Data\n");
    printf("0. Keluar Sistem\n");
    printf("Pilih menu: ");
}

void printItem(Node *node) {
    if (node == NULL) return;
    // Sama persis dengan format printTableHeader
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
    // Cek apakah linked list kosong
    if (head == NULL) {
        printf("Database kosong.\n");
        return;
    }

    printTableHeader();

    // Traversal printItem linked list sampai habis
    Node *current = head;
    while (current != NULL) {
        printItem(current);
        current = current->next;
    }
    
    printSeparatorLine();
}

void printInventorySummary(Node *head) {
    // Cek apakah linked list kosong
    if (head == NULL) {
        printf("Database kosong.\n");
        return;
    }

    int totalJenisBarang = 0;
    int totalFisikBarang = 0;
    
    // Variabel internal untuk menghitung status barang
    int countTersedia = 0;
    int countDipinjam = 0;
    int countRusak = 0;
    int countHabis = 0;
    int countLainnya = 0;

    Node *current = head;
    
    while (current != NULL) {
        totalJenisBarang++;
        totalFisikBarang += current->data.stock;

        // Pengecekan kategori status dengan strstr
        if (strstr(current->data.status, "Tersedia") || strstr(current->data.status, "tersedia")) {
            countTersedia++;
        } else if (strstr(current->data.status, "Dipinjam") || strstr(current->data.status, "dipinjam")) {
            countDipinjam++;
        } else if (strstr(current->data.status, "Rusak") || strstr(current->data.status, "rusak")) {
            countRusak++;
        } else if (strstr(current->data.status, "Habis") || strstr(current->data.status, "habis") || current->data.stock == 0) {
            countHabis++;
        } else {
            countLainnya++;
        }

        current = current->next;
    }

    // Mencetak layar ringkasan
    printSeparatorLine();
    printf("RINGKASAN INVENTARIS LABORATORIUM\n");
    printSeparatorLine();
    printf("Total Jenis Komponen : %d jenis\n", totalJenisBarang);
    printf("Total Fisik Barang   : %d unit\n", totalFisikBarang);
    printf("\nRincian Status:\n");
    printf("- Tersedia           : %d\n", countTersedia);
    printf("- Dipinjam           : %d\n", countDipinjam);
    printf("- Rusak              : %d\n", countRusak);
    printf("- Habis              : %d\n", countHabis);
    
    if (countLainnya > 0) {
        printf("- Status Lainnya     : %d\n", countLainnya);
    }
    printSeparatorLine();
}
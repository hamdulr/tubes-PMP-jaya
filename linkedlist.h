/* ============================================================
 * linked_list.h
 * Header modul operasi linked list — Sistem Inventarisasi Lab
 * Mata Kuliah : EL2008 Pemecahan Masalah dengan Pemrograman
 *
 * Catatan: Seluruh fungsi bertipe void sesuai ketentuan soal.
 *          Nilai "kembalian" disampaikan melalui pointer output.
 * ============================================================ */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "types.h"

/* ----------------------------------------------------------
 * initList
 * Inisialisasi linked list dengan menyetel head ke NULL.
 * Wajib dipanggil sebelum operasi list lainnya.
 * ---------------------------------------------------------- */
void initList(Node** head);

/* ----------------------------------------------------------
 * addNodeToList
 * Menambahkan node baru ke akhir list.
 * - Memeriksa kapasitas (MAX_ITEMS) sebelum alokasi.
 * - Mengalokasikan memori dengan malloc().
 *
 * Parameter:
 *   head    [in/out] : pointer ke head list
 *   newItem [in]     : data item yang akan disimpan
 *   success [out]    : 1 = berhasil, 0 = gagal
 *                      (kapasitas penuh / malloc gagal)
 * Kompleksitas: O(n) waktu, O(1) ruang ekstra
 * ---------------------------------------------------------- */
void addNodeToList(Node** head, Item newItem, int* success);

/* ----------------------------------------------------------
 * deleteNodeFromList
 * Menghapus node berdasarkan ID. Menangani 3 kasus:
 *   Kasus 1 — Node Pertama  : head digeser ke next
 *   Kasus 2 — Node Tengah   : previous->next melompati node
 *   Kasus 3 — Node Terakhir : previous->next = NULL
 *
 * Parameter:
 *   head     [in/out] : pointer ke head list
 *   targetId [in]     : ID item yang akan dihapus
 *   success  [out]    : 1 = berhasil, 0 = gagal
 *                       (list kosong / ID tidak ditemukan)
 * Kompleksitas: O(n) waktu, O(1) ruang ekstra
 * ---------------------------------------------------------- */
void deleteNodeFromList(Node** head, char* targetId, int* success);

/* ----------------------------------------------------------
 * findNodeById
 * Mencari node berdasarkan ID secara linear traversal.
 *
 * Parameter:
 *   head     [in]  : head list (tidak dimodifikasi)
 *   targetId [in]  : ID yang dicari
 *   result   [out] : pointer ke node yang ditemukan,
 *                    NULL jika tidak ada
 * Kompleksitas: O(n) waktu, O(1) ruang ekstra
 * ---------------------------------------------------------- */
void findNodeById(Node* head, char* targetId, Node** result);

/* ----------------------------------------------------------
 * countNodes
 * Menghitung jumlah node dalam list.
 * Digunakan untuk pengecekan kapasitas dan ringkasan.
 *
 * Parameter:
 *   head  [in]  : head list (tidak dimodifikasi)
 *   count [out] : jumlah node dalam list
 * Kompleksitas: O(n) waktu, O(1) ruang ekstra
 * ---------------------------------------------------------- */
void countNodes(Node* head, int* count);

/* ----------------------------------------------------------
 * freeAllNodes
 * Membebaskan seluruh memori list node per node,
 * lalu menyetel head kembali ke NULL.
 * Wajib dipanggil saat program akan ditutup.
 *
 * Parameter:
 *   head [in/out] : pointer ke head list
 * Kompleksitas: O(n) waktu
 * ---------------------------------------------------------- */
void freeAllNodes(Node** head);

#endif 
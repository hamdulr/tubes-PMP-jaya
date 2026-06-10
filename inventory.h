/* ============================================================
 * inventory.h
 * Header modul operasi inventaris — Sistem Inventarisasi Lab
 * Mata Kuliah : EL2008 Pemecahan Masalah dengan Pemrograman
 *
 * Catatan: Seluruh fungsi bertipe void sesuai ketentuan soal.
 *          Operasi inventaris dilakukan melalui linked list.
 * ============================================================ */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "types.h"

/* ----------------------------------------------------------
 * addItem
 * Menambahkan data barang baru ke dalam inventaris.
 *
 * Alur:
 *   1. Menerima input data barang dari pengguna.
 *   2. Memeriksa apakah ID sudah digunakan.
 *   3. Jika ID unik, data ditambahkan ke linked list.
 *   4. Menampilkan status berhasil atau gagal.
 *
 * Parameter:
 *   head [in/out] : pointer ke head linked list
 *
 * Kompleksitas: O(n) waktu (pengecekan ID dan penambahan)
 * ---------------------------------------------------------- */
void addItem(Node **head);

/* ----------------------------------------------------------
 * deleteItem
 * Menghapus data barang berdasarkan ID yang dimasukkan pengguna.
 *
 * Alur:
 *   1. Menerima input ID barang.
 *   2. Mencari data berdasarkan ID.
 *   3. Jika ditemukan, node dihapus dari linked list.
 *   4. Menampilkan status berhasil atau gagal.
 *
 * Parameter:
 *   head [in/out] : pointer ke head linked list
 *
 * Kompleksitas: O(n) waktu
 * ---------------------------------------------------------- */
void deleteItem(Node **head);

/* ----------------------------------------------------------
 * searchItem
 * Mencari dan menampilkan data barang berdasarkan ID.
 *
 * Alur:
 *   1. Menerima input ID barang.
 *   2. Melakukan pencarian secara linear.
 *   3. Jika ditemukan, seluruh informasi barang ditampilkan.
 *   4. Jika tidak ditemukan, menampilkan pesan kesalahan.
 *
 * Parameter:
 *   head [in] : head linked list (tidak dimodifikasi)
 *
 * Kompleksitas: O(n) waktu
 * ---------------------------------------------------------- */
void searchItem(Node *head);

/* ----------------------------------------------------------
 * updateStock
 * Memperbarui jumlah stok suatu barang berdasarkan ID.
 *
 * Alur:
 *   1. Menerima input ID barang.
 *   2. Mencari barang pada linked list.
 *   3. Memperbarui nilai stok jika barang ditemukan.
 *   4. Menampilkan status berhasil atau gagal.
 *
 * Parameter:
 *   head [in] : head linked list
 *
 * Kompleksitas: O(n) waktu
 * ---------------------------------------------------------- */
void updateStock(Node *head);

/* ----------------------------------------------------------
 * updateStatus
 * Memperbarui status barang (tersedia, dipinjam, rusak, atau habis) berdasarkan ID barang.
 *
 * Alur:
 *   1. Menerima input ID barang.
 *   2. Mencari barang pada linked list.
 *   3. Memperbarui status barang jika ditemukan.
 *   4. Menampilkan status berhasil atau gagal.
 *
 * Parameter:
 *   head [in] : head linked list
 *
 * Kompleksitas: O(n) waktu
 * ---------------------------------------------------------- */
void updateStatus(Node *head);

#endif
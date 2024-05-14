#ifndef TES_H
#define TES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BARANG 100
#define MIN_BARANG 0

//Definisi struct yang dipakai dalam program
typedef struct Produk {
    char kode[10];
    char nama[100];
    float harga;
    int stok;
}Produk;

//Prototype semua fungsi yang digunakan dalam program
int Login();
void bacaDataBarang(Produk dataproduk[], int *jumlahproduk);
void tulisDataBarang(Produk dataproduk[], int jumlahproduk);
void tambahBarang(Produk dataproduk[], int *jumlahproduk);
void hapusBarang(Produk dataproduk[], int *jumlahproduk);
void tampilkanDaftarBarang(Produk dataproduk[], int jumlahproduk);
void pembayaran(Produk dataproduk[], int jumlahproduk);
void tambahStok(Produk dataproduk[], int jumlahproduk);
void kurangiStok(Produk dataproduk[], int jumlahproduk);

#endif

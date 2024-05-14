#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define MAX_BARANG 100

//Fungsi untuk menambahkan barang ke daftar barang
void tambahBarang(Produk dataproduk[], int *jumlahproduk){
    if (*jumlahproduk >= MAX_BARANG) {
        printf("Kapasitas daftar produk penuh!\n");
        return;
    }

    printf("-----------------------\n");
    printf("Masukkan kode produk: ");
    scanf("%s", dataproduk[*jumlahproduk].kode);
    printf("Masukkan nama produk: ");
    scanf("%s", dataproduk[*jumlahproduk].nama);
    printf("Masukkan harga produk: ");
    scanf("%f", &dataproduk[*jumlahproduk].harga);
    printf("Masukkan stok produk: ");
    scanf("%d", &dataproduk[*jumlahproduk].stok);
    printf("-------------------------\n");
    printf("Produk berhasil ditambah!\n");

    (*jumlahproduk)++;
}

//Fungsi untuk menghapus produk dari daftar produk
void kurangBarang(Produk dataproduk[], int *jumlahproduk) {
    if (*jumlahproduk <= MIN_BARANG) {
        printf("==Produk tidak dapat dikurang!==\n");
        return;
    }

    printf("-----------------------\n");
    printf("Masukkan kode produk: ");
    scanf("%s", dataproduk[*jumlahproduk].kode);
    printf("Masukkan nama produk: ");
    scanf("%s", dataproduk[*jumlahproduk].nama);
    printf("-----------------------\n");
    printf("Produk berhasil dihapus!\n");
   
    (*jumlahproduk)--;
}

//Fungsi untuk menulis data barang ke file eksternal
void tulisDataBarang(Produk dataproduk[], int jumlahproduk) {
    FILE *file;
    file = fopen("data_barang.txt", "w");
    if (file == NULL) {
        printf("File data_barang.txt tidak dapat dibuka.\n");
        exit(1);
    }

    for (int i = 0; i < jumlahproduk; i++) {
        fprintf(file, "%s %s %.2f %d\n", dataproduk[i].kode, dataproduk[i].nama, dataproduk[i].harga, dataproduk[i].stok);
    }

    fclose(file);
}
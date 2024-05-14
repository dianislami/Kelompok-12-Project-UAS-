#include "header.h"

//Fungsi untuk menambahkan stok barang
void tambahStok(Produk dataproduk[], int jumlahproduk){
    int jumlah;
    char kodeproduk[20];

    printf("-----------------------\n");
    printf("Masukkan kode produk: ");
    scanf("%s", kodeproduk);
    printf("Masukkan jumlah yang ingin ditambah: ");
    scanf("%d", &jumlah);

    for (int i = 0; i < jumlahproduk; i++) {
        if (strcmp(dataproduk[i].kode, kodeproduk) == 0) {
            dataproduk[i].stok += jumlah;
            printf("\n==Stok produk berhasil ditambahkan==\n");
            return;
        }
    }
    printf("==Kode produk tidak ditemukan==\n");
}

//Fungsi untuk mengurangkan stok barang
void kurangiStok(Produk dataproduk[], int jumlahproduk) {
    int jumlah;
    char kodeproduk[20];

    printf("-----------------------\n");
    printf("Masukkan kode produk: ");
    scanf("%s", kodeproduk);
    printf("Masukkan jumlah yang ingin dikurang: ");
    scanf("%d", &jumlah);
    
    for (int i = 0; i < jumlahproduk; i++) {
        if (strcmp(dataproduk[i].kode, kodeproduk) == 0) {
            if (jumlah > dataproduk[i].stok) {
                printf("Stok produk tidak mencukupi.\n");
            } else {
                dataproduk[i].stok -= jumlah;
                printf("\n==Stok produk berhasil dikurangi==\n");
            }
            return;
        }
    }
    printf("==Kode produk tidak ditemukan==\n");
}

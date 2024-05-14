#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

//Fungsi untuk melakukan pembayaran
void pembayaran(Produk dataproduk[], int jumlahproduk) {
    float totalBelanja = 0;
    float diskon10, diskon20, diskon25;
    char kodeproduk[10];
    int jumlah;

    while (1) {
        printf("Masukkan kode produk yang akan dibeli (ketik 'selesai' untuk selesai): ");
        scanf("%s", kodeproduk);

        if (strcmp(kodeproduk, "selesai") == 0) {
            break;
        }

        for (int i = 0; i < jumlahproduk; i++) {
            if (strcmp(dataproduk[i].kode, kodeproduk) == 0) {
                printf("Masukkan jumlah produk yang akan dibeli: ");
                scanf("%d", &jumlah);
                if (jumlah > dataproduk[i].stok) {
                    printf("\nStok produk tidak mencukupi.\n");
                } else {
                    totalBelanja += dataproduk[i].harga * jumlah;
                    dataproduk[i].stok -= jumlah;
                    printf("-------------------------------------------------\n");
                    printf("Produk berhasil ditambahkan ke keranjang belanja.\n");
                }
                break;
            }
            if (i == jumlahproduk - 1) {
                printf("\n==Kode produk tidak valid==\n");
            }
        }
    }
    printf("Total belanja Anda: %.2f\n", totalBelanja);

    //Menghitung diskon belanja
    diskon10 = totalBelanja - (totalBelanja*10/100);
    diskon20 = totalBelanja - (totalBelanja*20/100);
    diskon25 = totalBelanja - (totalBelanja*25/100);

    //Menentukan total belanja setelah diskon
    //Diskon sebesar 10%
    if ((totalBelanja >= 100000) && (totalBelanja < 500000)){
        printf("--------------------------------\n");
        printf("Selamat Anda mendapatkan diskon!\n");
        printf("Total belanja Anda setelah diskon adalah %.2f\n", diskon10);
    }   
    //Diskon sebesar 20%
    else if ((totalBelanja >= 500000) && (totalBelanja < 1000000)){
        printf("--------------------------------\n");
        printf("Selamat Anda mendapatkan diskon!\n");
        printf("Total belanja Anda setelah diskon adalah %.2f\n", diskon20);
    }
    //Diskon sebesar 25%
    else if ((totalBelanja >= 1000000) && (totalBelanja < 2000000)){
        printf("--------------------------------\n");
        printf("Selamat Anda mendapatkan diskon!\n");
        printf("Total belanja Anda setelah diskon adalah %.2f\n", diskon25);
    }
    //Tidak mendapat diskon
    else if (totalBelanja < 100000){
        printf("----------------------------------------------------------------------\n");
        printf("Maaf, Anda tidak mendapat diskon karena tidak mencapai minimal belanja\n");
    }
}
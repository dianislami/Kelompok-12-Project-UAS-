#include "header.h"

// Fungsi untuk menambahkan stok barang
// Parameter:
//    dataproduk: array dari struct produk yang menyimpan data produk
//    jumlahproduk: integer yang menyimpan jumlah produk saat ini
void tambahStok(Produk dataproduk[], int jumlahproduk){
    int jumlah;
    char kodeproduk[20];

    //Input data produk dari pengguna
    printf("-----------------------\n");
    printf("Masukkan kode produk: ");
    scanf("%s", kodeproduk);
    printf("Masukkan jumlah yang ingin ditambah: ");
    scanf("%d", &jumlah);

    // Cari produk berdasarkan kode
    for (int i = 0; i < jumlahproduk; i++) {
        //Jika kode  produk ditemukan
        if (strcmp(dataproduk[i].kode, kodeproduk) == 0) {
            // Tambahkan jumlah ke stok produk yang sesuai
            dataproduk[i].stok += jumlah;
            // Tampilkan pesan sukses
            printf("\n==Stok produk berhasil ditambahkan==\n");
            // Keluar dari fungsi setelah stok ditambahkan
            return;
        }
    }
    // Tampilkan pesan jika kode produk tidak ditemukan
    printf("==Kode produk tidak ditemukan==\n");
}

//Fungsi untuk mengurangkan stok barang
void kurangiStok(Produk dataproduk[], int jumlahproduk) {
    int jumlah;
    char kodeproduk[20];

    //Input data produk dari pengguna
    printf("-----------------------\n");
    printf("Masukkan kode produk: ");
    scanf("%s", kodeproduk);
    printf("Masukkan jumlah yang ingin dikurang: ");
    scanf("%d", &jumlah);

     // Cari produk berdasarkan kode
    for (int i = 0; i < jumlahproduk; i++) {
        // Jika kode produk ditemukan
        if (strcmp(dataproduk[i].kode, kodeproduk) == 0) {
            // Jika jumlah yang ingin dikurangi lebih besar dari stok yang tersedia
            if (jumlah > dataproduk[i].stok) {
                // Tampilkan pesan stok tidak mencukupi
                printf("Stok produk tidak mencukupi.\n");
            } else {
                // Kurangi jumlah dari stok produk yang sesuai
                dataproduk[i].stok -= jumlah;
                // Tampilkan pesan sukses
                printf("\n==Stok produk berhasil dikurangi==\n");
            }
            // Keluar dari fungsi setelah stok dikurangi atau jika stok tidak mencukupi
            return;
        }
    }
    // Tampilkan pesan jika kode produk tidak ditemukan
    printf("==Kode produk tidak ditemukan==\n");
}

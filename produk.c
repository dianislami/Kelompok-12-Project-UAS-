#include "header.h"

//Fungsi untuk menambahkan barang ke daftar barang
//Parameter:
//    dataproduk: array dari struct produk yang menyimpan data produk
//    jumlahproduk: pointer ke integer yang menyimpan jumlah produk saat ini
void tambahBarang(Produk dataproduk[], int *jumlahproduk){
    //cek apakah kapasitas daftar produk sudah penuh
    if (*jumlahproduk >= MAX_BARANG) {
        printf("Kapasitas daftar produk penuh!\n");
        return;
    }

    //input data produk dari pengguna
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

    //tambah jumlah produk
    (*jumlahproduk)++;
}

// Fungsi untuk menghapus produk dari daftar produk
// Parameter:
//    dataproduk: array dari struct Produk yang menyimpan data produk
//    jumlahproduk: pointer ke integer yang menyimpan jumlah produk saat ini
void hapusBarang(Produk dataproduk[], int *jumlahproduk) {
    //Cek apakah jumlah produk lebih dari batas minimum
    if (*jumlahproduk <= MIN_BARANG) {
        printf("==Produk tidak dapat dikurang!==\n");
        return;
    }

    char kodeproduk[10];
    printf("-----------------------\n");
    printf("Masukkan kode produk yang akan dihapus: ");
    scanf("%s", kodeproduk);

    //Cari produk berdasarkan kode
    int found = 0;
    for (int i = 0; i < *jumlahproduk; i++) {
        if (strcmp(dataproduk[i].kode, kodeproduk) == 0) {
            found = 1;
            //Geser produk berikutnya ke posisi produk yang dihapus
            for (int j = i; j < *jumlahproduk - 1; j++) {
                dataproduk[j] = dataproduk[j + 1];
            }

            //Kurangi jumlah produk
            (*jumlahproduk)--;
            printf("-----------------------\n");
            printf("Produk berhasil dihapus!\n");
            break;
        }
    }

    //jika kode produk tidak ditemukan
    if (!found) {
        printf("Kode produk tidak ditemukan!\n");
    }
}

//Fungsi untuk menulis data barang ke file eksternal
//Parameter:
//    dataproduk: array dari struct produk yang menyimpan data produk
//    jumlahproduk: integer yang menyimpan jumlah produk saat ini
void tulisDataBarang(Produk dataproduk[], int jumlahproduk) {
    FILE *file;
    //Buka file data_barang.txt dalam mode tulis
    file = fopen("data_barang.txt", "w");
    if (file == NULL) {
        printf("File data_barang.txt tidak dapat dibuka.\n");
        exit(1);
    }

    // Tulis data produk ke dalam file 
    for (int i = 0; i < jumlahproduk; i++) {
        fprintf(file, "%s %s %.2f %d\n", dataproduk[i].kode, dataproduk[i].nama, dataproduk[i].harga, dataproduk[i].stok);
    }

    // Tutup file
    fclose(file);
}

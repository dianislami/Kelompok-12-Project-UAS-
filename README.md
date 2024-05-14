# Kelompok 12 Project UAS
Fungsi-Fungsi yang akan kami gunakan pada project UAS ini:
## 1. header.h:
File ini berisi semua header yang akan digunakan dalam kode program yaitu stdio.h, stdlib.h, dan string.h serta definisi struct dan prototype dari semua fungsi yang digunakan dalam project uas ini.
   
       typedef struct Produk {
          char kode[10];
          char nama[100];
          float harga;
          int stok;
       }Produk;
   
Struct ini digunakan untuk merepresentasikan produk yang dikelola dalam program yang terdiri dari kode dan nama produk yang bertipe char, harga dengan tipe float, dan stok dengan tipe int.
     
       int Login();
       void bacaDataBarang(Produk dataproduk[], int *jumlahproduk);
       void tulisDataBarang(Produk dataproduk[], int jumlahproduk);
       ...
       
### Deskripsi fungsi: 
a)int Login: Fungsi untuk melakukan proses login oleh kasir. b)void bacaDataBarang(Produk dataproduk[], int *jumlahproduk): Fungsi untuk membaca data barang dari file eksternal txt dan menyimpannya dalam array dataproduk. c)void tulisDataBarang(Produk dataproduk[], int jumlahproduk): Fungsi untuk menulis data barang ke file eksternal txt dari array dataproduk. d)void tambahBarang(Produk dataproduk[], int *jumlahproduk): Fungsi untuk menambah barang baru ke dalam sistem. e)void hapusBarang(Produk dataproduk[], int *jumlahproduk): Fungsi untuk menghapus barang dari sistem. f)void tambahStok(Produk dataproduk[], int jumlahproduk): Fungsi untuk menambah stok barang yang ada. g)void kurangiStok(Produk dataproduk[], int jumlahproduk): Fungsi untuk mengurangi stok barang yang ada. h)void tampilkanDaftarBarang(Produk dataproduk[], int jumlahproduk): Fungsi untuk menampilkan daftar barang yang ada dalam sistem. i)void pembayaran(Produk dataproduk[], int jumlahproduk): Fungsi untuk melakukan proses pembayaran barang.

## 2. main.c

       #include "header.h"
       
Sintaks ini berfungsi untuk memasukkan file header header.h ke dalam program yang memungkinkan program utama mengakses semua header yang tertera dan definisi struct Produk serta semua prototype fungsi yang ada di header.h.

      Produk dataproduk[MAX_BARANG];
      int jumlahproduk = 0;
      int pilihan;
      int nilai;
      
### Deklarasi variabel: 
a)dataproduk[MAX_BARANG]: Array yang digunakan untuk menyimpan data produk. b)jumlahproduk: Variabel bertipe integer yang menyimpan jumlah produk yang ada. c)pilihan: Variabel bertipe integer untuk menyimpan pilihan menu dari user. d)nilai: Variabel bertipe integer untuk menyimpan hasil dari fungsi Login().

      bacaDataBarang(dataproduk, &jumlahproduk);
      
Fungsi ini membaca data barang dari file eksternal txt dan menyimpannya ke dalam array dataproduk dan menyimpan jumlah produk yang dibaca dalam variabel jumlahproduk.

      nilai = Login();
      
Fungsi ini digunakan untuk memverifikasi login user. Jika login berhasil, fungsi mengembalikan nilai 1, yang memungkinkan user melanjutkan ke menu kasir.

      while (nilai == 1) {
          printf("\n======= MENU KASIR =======\n");
          printf("1. Tambah Produk\n");
          printf("2. Hapus Produk\n");
          ...
          
Loop ini terus berjalan selama variabel nilai = 1 dan memungkinkan user untuk berinteraksi dengan menu kasir berulang kali hingga memilih untuk keluar.

      switch (pilihan) {
            case 1:
                tambahBarang(dataproduk, &jumlahproduk);
                tulisDataBarang(dataproduk, jumlahproduk);
                break;
                ...
                
### Deskripsi:
a)switch (pilihan): Struktur switch ini mengevaluasi nilai pilihan dan menjalankan blok kode yang sesuai. b)case 1 hingga case 6: Setiap case sesuai dengan pilihan menu pengguna dan memanggil fungsi yang sesuai untuk memproses permintaan tersebut. Setelah setiap operasi, data barang ditulis kembali ke file eksternal txt menggunakan fungsi 'tulisDataBarang'. c)case 7: Jika pengguna memilih untuk keluar, program akan berhenti dengan memanggil exit(0). d)default: Jika pilihan tidak valid, program menampilkan pesan kesalahan.

      exit(0);
      
Fungsi exit ini digunakan untuk menghentikan eksekusi program. Parameter 0 menunjukkan bahwa program berhenti tanpa error.
## 3. login.c
## 4. stok.c
## 5. produk.c
## 6. tampilan.c
## 7. transaksi.c
## 8. makefile

Untuk menampilkan semua fungsi yang kami gunakan di atas, kami menggunakan file (data_barang.txt)

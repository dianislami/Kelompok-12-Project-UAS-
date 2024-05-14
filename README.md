# Kelompok 12 Project UAS
Fungsi-Fungsi yang akan kami gunakan pada project UAS ini:
  1. header.h
     File ini berisi semua header yang akan digunakan dalam kode program yaitu stdio.h, stdlib.h, dan string.h serta
     definisi struct dan prototype dari semua fungsi yang digunakan dalam project uas ini.
     >>Definisi Struct Produk:
       Struct ini digunakan untuk merepresentasikan produk yang dikelola dalam program yang terdiri dari kode dan nama produk
       yang bertipe char, harga dengan tipe float, dan stok dengan tipe int.
     >>Deskripsi Fungsi:
       -int Login(): Fungsi untuk melakukan proses login oleh kasir.
       -void bacaDataBarang(Produk dataproduk[], int *jumlahproduk): Fungsi untuk membaca data barang dari file eksternal txt
        dan menyimpannya dalam array dataproduk.
       -void tulisDataBarang(Produk dataproduk[], int jumlahproduk): Fungsi untuk menulis data barang ke file eksternal txt
        dari array dataproduk.
       -void tambahBarang(Produk dataproduk[], int *jumlahproduk): Fungsi untuk menambah barang baru ke dalam sistem.
       -void hapusBarang(Produk dataproduk[], int *jumlahproduk): Fungsi untuk menghapus barang dari sistem.
       -void tambahStok(Produk dataproduk[], int jumlahproduk): Fungsi untuk menambah stok barang yang ada.
       -void kurangiStok(Produk dataproduk[], int jumlahproduk): Fungsi untuk mengurangi stok barang yang ada.
       -void tampilkanDaftarBarang(Produk dataproduk[], int jumlahproduk): Fungsi untuk menampilkan daftar barang yang ada
        dalam sistem.
       -void pembayaran(Produk dataproduk[], int jumlahproduk): Fungsi untuk melakukan proses pembayaran barang.
  2. main.c
     1)#include "header.h"
       Sintaks ini berfungsi untuk memasukkan file header header.h ke dalam program yang memungkinkan program utama
       mengakses semua header yang tertera dan definisi struct Produk serta semua prototype fungsi yang ada di header.h.
     2)Deklarasi variabel
       >dataproduk[MAX_BARANG]: Array yang digunakan untuk menyimpan data produk.
       >jumlahproduk: Variabel bertipe integer yang menyimpan jumlah produk yang ada.
       >pilihan: Variabel bertipe integer untuk menyimpan pilihan menu dari user.
       >nilai: Variabel bertipe integer untuk menyimpan hasil dari fungsi Login().
     3)Pemanggilan fungsi 'bacaDataBarang'
       Fungsi ini membaca data barang dari file eksternal txt dan menyimpannya ke dalam array dataproduk dan menyimpan
       jumlah produk yang dibaca dalam variabel jumlahproduk.
     4)Pemanggilan fungsi 'Login'
       Fungsi ini digunakan untuk memverifikasi login user. Jika login berhasil, fungsi mengembalikan nilai 1, yang
       memungkinkan user melanjutkan ke menu kasir.
     5)Penggunaan 'while' loop
       Loop ini terus berjalan selama variabel nilai = 1 dan memungkinkan user untuk berinteraksi dengan menu kasir
       berulang kali hingga memilih untuk keluar.
     6)Menampilkan menu dan meminta input user
       Bagian ini menampilkan menu kasir dan meminta user untuk memasukkan pilihan mereka.
     7)Penggunaan 'switch' untuk memproses pilihan user
       >switch (pilihan): Struktur switch ini mengevaluasi nilai pilihan dan menjalankan blok kode yang sesuai.
       >case 1 hingga case 6: Setiap case sesuai dengan pilihan menu pengguna dan memanggil fungsi yang sesuai untuk
        memproses permintaan tersebut. Setelah setiap operasi, data barang ditulis kembali ke file eksternal txt menggunakan
        fungsi 'tulisDataBarang'.
       >case 7: Jika pengguna memilih untuk keluar, program akan berhenti dengan memanggil exit(0).
       >default: Jika pilihan tidak valid, program menampilkan pesan kesalahan.
     8)Fungsi 'exit'
       Fungsi ini digunakan untuk menghentikan eksekusi program. Parameter 0 menunjukkan bahwa program berhenti tanpa error.
     9)Fungsi 'scanf' dan 'printf'
       >printf: Digunakan untuk mencetak teks ke layar.
       >scanf: Digunakan untuk membaca inputan dari user.
  4. login.c
  5. stok.c
  6. produk.c
  7. tampilan.c
  8. transaksi.c
  9. makefile

Untuk menampilkan semua fungsi yang kami gunakan di atas, kami menggunakan file (data_barang.txt)

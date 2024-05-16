# Kelompok 12 Project UAS
Fungsi-Fungsi yang akan kami gunakan pada project UAS ini adalah

## 1. header.h
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
a)int Login: Fungsi untuk melakukan proses login oleh kasir. 
b)void bacaDataBarang(Produk dataproduk[], int *jumlahproduk): Fungsi untuk membaca data barang dari file eksternal txt dan menyimpannya dalam array dataproduk.
c)void tulisDataBarang(Produk dataproduk[], int jumlahproduk): Fungsi untuk menulis data barang ke file eksternal txt dari array dataproduk.
d)void tambahBarang(Produk dataproduk[], int *jumlahproduk): Fungsi untuk menambah barang baru ke dalam sistem.
e)void hapusBarang(Produk dataproduk[], int *jumlahproduk): Fungsi untuk menghapus barang dari sistem.
f)void tambahStok(Produk dataproduk[], int jumlahproduk): Fungsi untuk menambah stok barang yang ada.
g)void kurangiStok(Produk dataproduk[], int jumlahproduk): Fungsi untuk mengurangi stok barang yang ada.
h)void tampilkanDaftarBarang(Produk dataproduk[], int jumlahproduk): Fungsi untuk menampilkan daftar barang yang ada dalam sistem.
i)void pembayaran(Produk dataproduk[], int jumlahproduk): Fungsi untuk melakukan proses pembayaran barang.

## 2. main.c

       #include "header.h"
       
Sintaks ini berfungsi untuk memasukkan file header header.h ke dalam program yang memungkinkan program utama mengakses semua header yang tertera dan definisi struct Produk serta semua prototype fungsi yang ada di header.h.

      Produk dataproduk[MAX_BARANG];
      int jumlahproduk = 0;
      int pilihan;
      int nilai;
      
### Deklarasi variabel: 
a)dataproduk[MAX_BARANG]: Array yang digunakan untuk menyimpan data produk.
b)jumlahproduk: Variabel bertipe integer yang menyimpan jumlah produk yang ada.
c)pilihan: Variabel bertipe integer untuk menyimpan pilihan menu dari user.
d)nilai: Variabel bertipe integer untuk menyimpan hasil dari fungsi Login().

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
a)switch (pilihan): Struktur switch ini mengevaluasi nilai pilihan dan menjalankan blok kode yang sesuai.
b)case 1 hingga case 6: Setiap case sesuai dengan pilihan menu pengguna dan memanggil fungsi yang sesuai untuk memproses permintaan tersebut. Setelah setiap operasi, data barang ditulis kembali ke file eksternal txt menggunakan fungsi 'tulisDataBarang'.
c)case 7: Jika pengguna memilih untuk keluar, program akan berhenti dengan memanggil exit(0).
d)default: Jika pilihan tidak valid, program menampilkan pesan kesalahan.

      exit(0);

Fungsi exit ini digunakan untuk menghentikan eksekusi program. Parameter 0 menunjukkan bahwa program berhenti tanpa error.
      
### Kesimpulan ###      
File main.c ini merupakan file utama dimana semua fungsi yang telah dibuat dapat dipilih dan dijalankan sesuai dengan inputan user.

## 3. login.c

       #include "header.h"
       
Sintaks ini berfungsi untuk memasukkan file header header.h ke dalam program yang memungkinkan login.c mengakses semua deklarasi yang ada di dalam file header tersebut, termasuk definisi struct dan prototype fungsi.

      // Fungsi untuk melakukan login sebelum memulai mesin kasir
      // Mendefinisikan beberapa variabel yang diperlukan
      int Login() {
      char Password[] = "klp12";
      char username[50];
      char password[50];

### Deklarasi variabel: ###
a) Password[]: Array karakter yang berisi password yang benar ("klp12").
b) username[50]: Array karakter untuk menyimpan username yang akan dimasukkan oleh pengguna.
c) password[50]: Array karakter untuk menyimpan password yang akan dimasukkan oleh pengguna.

      // Meminta user memasukkan nama dan password
      printf("\nLogin sebagai kasir\n");
      printf("Masukkan nama Anda: ");
      scanf("%s", username);
      printf("Masukkan password: ");
      scanf("%s", password);

Fungsi ini meminta pengguna memasukkan username dan password. Username dan password disimpan dalam variabel username dan password.

         // Pengecekan apakah password benar
         if (strcmp(password, Password) == 0) {
            printf("===============\n");
            printf("Login berhasil!\n");
            printf("Selamat datang %s!\n", username);
           
            // Return 1 jika password sesuai
            return 1;
         } else {
            printf("Password salah!\n");
           
            // Return 0 jika password tidak sesuai
            return 0;
            }
         }

### Deskripsi ###
a) if (strcmp(password, Password) == 0): Fungsi strcmp digunakan untuk membandingkan string password yang dimasukkan oleh pengguna dengan string Password yang benar. Jika hasilnya 0 (kedua string sama), maka kondisi ini terpenuhi.
b) printf("===============\n");: Menampilkan garis pemisah untuk memperjelas output.
c) printf("Login berhasil!\n");: Menampilkan pesan bahwa login berhasil.
d) printf("Selamat datang %s!\n", username);: Menampilkan pesan selamat datang kepada pengguna, menyertakan nama pengguna yang telah dimasukkan.
e) return 1;: Mengembalikan nilai 1 untuk menunjukkan bahwa login berhasil.
f) else: Jika password yang dimasukkan tidak cocok dengan password yang benar.
g) printf("Password salah!\n");: Menampilkan pesan bahwa password yang dimasukkan salah.
h) return 0;: Mengembalikan nilai 0 untuk menunjukkan bahwa login gagal.\

### Kesimpulan ###
Fungsi Login digunakan untuk mengautentikasi pengguna sebelum mereka dapat mengakses mesin kasir. Pengguna diminta untuk memasukkan username dan password. Password dibandingkan dengan nilai yang telah ditentukan ("klp12"). Jika password cocok, fungsi mengembalikan nilai 1 dan menampilkan pesan sukses. Jika password tidak cocok, fungsi mengembalikan nilai 0 dan menampilkan pesan kesalahan.

## 4. stok.c

      #include "header.h"

Sintaks ini berfungsi untuk memasukkan file header header.h ke dalam program yang memungkinkan stok.c mengakses semua deklarasi yang ada di dalam file header tersebut, termasuk definisi struct dan prototype fungsi.

      // Fungsi untuk menambahkan stok barang
      // Parameter:
      //    dataproduk: array dari struct produk yang menyimpan data produk
      //    jumlahproduk: integer yang menyimpan jumlah produk saat ini
      void tambahStok(Produk dataproduk[], int jumlahproduk) {
          int jumlah;
          char kodeproduk[20];

### Deklarasi Variabel ###
a) jumlah: Variabel bertipe integer untuk menyimpan jumlah stok yang ingin ditambahkan.
b) kodeproduk[20]: Array karakter untuk menyimpan kode produk yang akan ditambahkan stoknya.

          // Input data produk dari pengguna
          printf("-----------------------\n");
          printf("Masukkan kode produk: ");
          scanf("%s", kodeproduk);
          printf("Masukkan jumlah yang ingin ditambah: ");
          scanf("%d", &jumlah);

Fungsi ini meminta pengguna memasukkan kode produk dan jumlah stok yang ingin ditambahkan. Kode produk dan jumlah stok disimpan dalam variabel kodeproduk dan jumlah.

             // Cari produk berdasarkan kode
             for (int i = 0; i < jumlahproduk; i++) {
                 // Jika kode produk ditemukan
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

### Deskripsi ###
Deskripsi:
a) for (int i = 0; i < jumlahproduk; i++): Loop untuk mencari produk berdasarkan kode yang dimasukkan.
b) if (strcmp(dataproduk[i].kode, kodeproduk) == 0): Fungsi strcmp digunakan untuk membandingkan string kodeproduk dengan dataproduk[i].kode. Jika hasilnya 0 (kedua string sama), maka produk ditemukan.
c) dataproduk[i].stok += jumlah;: Menambahkan jumlah stok yang diinput pengguna ke stok produk yang sesuai.
d) printf("\n==Stok produk berhasil ditambahkan==\n");: Menampilkan pesan bahwa stok produk berhasil ditambahkan.
e) return;: Keluar dari fungsi setelah stok ditambahkan.
f) printf("==Kode produk tidak ditemukan==\n");: Menampilkan pesan jika kode produk tidak ditemukan.

         // Fungsi untuk mengurangkan stok barang
         void kurangiStok(Produk dataproduk[], int jumlahproduk) {
             int jumlah;
             char kodeproduk[20];

### Deklarasi Variabel ###
a) jumlah: Variabel bertipe integer untuk menyimpan jumlah stok yang ingin dikurangi.
b) kodeproduk[20]: Array karakter untuk menyimpan kode produk yang akan dikurangi stoknya.

             // Input data produk dari pengguna
             printf("-----------------------\n");
             printf("Masukkan kode produk: ");
             scanf("%s", kodeproduk);
             printf("Masukkan jumlah yang ingin dikurang: ");
             scanf("%d", &jumlah);

Fungsi ini meminta pengguna memasukkan kode produk dan jumlah stok yang ingin dikurangi. Kode produk dan jumlah stok disimpan dalam variabel kodeproduk dan jumlah.

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

### Deskripsi ###
a) for (int i = 0; i < jumlahproduk; i++): Loop untuk mencari produk berdasarkan kode yang dimasukkan.
b) if (strcmp(dataproduk[i].kode, kodeproduk) == 0): Fungsi strcmp digunakan untuk membandingkan string kodeproduk dengan dataproduk[i].kode. Jika hasilnya 0 (kedua string sama), maka produk ditemukan.
c) if (jumlah > dataproduk[i].stok): Memeriksa apakah jumlah yang ingin dikurangi lebih besar dari stok yang tersedia.
d) printf("Stok produk tidak mencukupi.\n");: Menampilkan pesan bahwa stok produk tidak mencukupi.
e) dataproduk[i].stok -= jumlah;: Mengurangi jumlah stok yang diinput pengguna dari stok produk yang sesuai.
f) printf("\n==Stok produk berhasil dikurangi==\n");: Menampilkan pesan bahwa stok produk berhasil dikurangi.
g) return;: Keluar dari fungsi setelah stok dikurangi atau jika stok tidak mencukupi.
h) printf("==Kode produk tidak ditemukan==\n");: Menampilkan pesan jika kode produk tidak ditemukan.

### Kesimpulan ###
Fungsi tambahStok digunakan untuk menambahkan stok produk berdasarkan kode produk yang dimasukkan pengguna. Fungsi kurangiStok digunakan untuk mengurangkan stok produk berdasarkan kode produk yang dimasukkan pengguna. Kedua fungsi melakukan pencarian produk berdasarkan kode, memodifikasi stok produk, dan menampilkan pesan sukses atau pesan kesalahan sesuai dengan kondisi yang terjadi.

## 5. produk.c

	  #include "header.h"

Sintaks ini berfungsi untuk memasukkan file header header.h ke dalam program yang memungkinkan stok.c mengakses semua deklarasi yang ada di dalam file header tersebut, termasuk definisi struct dan prototype fungsi.


	// Fungsi untuk menambahkan barang ke daftar barang
	// Parameter:
	//    dataproduk: array dari struct produk yang menyimpan data produk
	//    jumlahproduk: pointer ke integer yang menyimpan jumlah produk saat ini
	void tambahBarang(Produk dataproduk[], int *jumlahproduk){
	    // Cek apakah kapasitas daftar produk sudah penuh
	    if (*jumlahproduk >= MAX_BARANG) {
	        printf("Kapasitas daftar produk penuh!\n");
	        return;
	    }
	
	    // Input data produk dari pengguna
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
	
	    // Tambah jumlah produk
	    (*jumlahproduk)++;
	}

### Deskripsi ###
a) if (*jumlahproduk >= MAX_BARANG): Memeriksa apakah jumlah produk sudah mencapai batas maksimum. Jika iya, menampilkan pesan bahwa kapasitas daftar produk sudah penuh.
b) scanf: Mengambil input dari pengguna untuk kode produk, nama produk, harga produk, dan stok produk.
c) (*jumlahproduk)++;: Menambahkan jumlah produk setelah produk baru berhasil ditambahkan.

	// Fungsi untuk menghapus produk dari daftar produk
	// Parameter:
	//    dataproduk: array dari struct produk yang menyimpan data produk
	//    jumlahproduk: pointer ke integer yang menyimpan jumlah produk saat ini
	void hapusBarang(Produk dataproduk[], int *jumlahproduk) {
	    // Cek apakah jumlah produk lebih dari batas minimum
	    if (*jumlahproduk <= MIN_BARANG) {
	        printf("==Produk tidak dapat dikurang!==\n");
	        return;
	    }
	
	    char kodeproduk[10];
	    printf("-----------------------\n");
	    // Minta pengguna memasukkan kode produk yang akan dihapus
	    printf("Masukkan kode produk yang akan dihapus: ");
	    scanf("%s", kodeproduk);
	
	    // Cari produk berdasarkan kode
	    int found = 0;
	    for (int i = 0; i < *jumlahproduk; i++) {
	        if (strcmp(dataproduk[i].kode, kodeproduk) == 0) {
	            found = 1;
	            // Geser produk berikutnya ke posisi produk yang dihapus
	            for (int j = i; j < *jumlahproduk - 1; j++) {
	                dataproduk[j] = dataproduk[j + 1];
	            }
	
	            // Kurangi jumlah produk
	            (*jumlahproduk)--;
	            printf("-----------------------\n");
	            printf("Produk berhasil dihapus!\n");
	            break;
	        }
	    }
	
	    // Jika kode produk tidak ditemukan
	    if (!found) {
	        printf("Kode produk tidak ditemukan!\n");
	    }
	}

### Deskripsi ###
a) if (*jumlahproduk <= MIN_BARANG): Memeriksa apakah jumlah produk kurang dari atau sama dengan batas minimum. Jika iya, menampilkan pesan bahwa produk tidak dapat dikurangi.
b) scanf("%s", kodeproduk);: Mengambil input dari pengguna untuk kode produk yang akan dihapus.
c) for (int i = 0; i < *jumlahproduk; i++): Loop untuk mencari produk berdasarkan kode yang dimasukkan.
d) if (strcmp(dataproduk[i].kode, kodeproduk) == 0): Memeriksa apakah kode produk pada indeks saat ini cocok dengan kode produk yang dimasukkan.
e) for (int j = i; j < *jumlahproduk - 1; j++): Menggeser produk berikutnya ke posisi produk yang dihapus.
f) (*jumlahproduk)--;: Mengurangi jumlah produk setelah produk dihapus.

	// Fungsi untuk menulis data barang ke file eksternal
	// Parameter:
	//    dataproduk: array dari struct produk yang menyimpan data produk
	//    jumlahproduk: integer yang menyimpan jumlah produk saat ini
	void tulisDataBarang(Produk dataproduk[], int jumlahproduk) {
	    FILE *file;
	    // Buka file data_barang.txt dalam mode tulis
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

### Deskripsi ###
a) file = fopen("data_barang.txt", "w");:  Membuka file data_barang.txt dalam mode tulis. Jika file tidak dapat dibuka, program akan berhenti dan menampilkan pesan kesalahan.
b) fprintf(file, "%s %s %.2f %d\n", dataproduk[i].kode, dataproduk[i].nama, dataproduk[i].harga, dataproduk[i].stok);: Menulis data produk ke dalam file dengan format yang sesuai.
c) fclose(file);: Menutup file setelah selesai menulis.

### Kesimpulan ###
Fungsi tambahBarang digunakan untuk menambahkan barang ke daftar barang dengan meminta input dari pengguna. Fungsi hapusBarang digunakan untuk menghapus produk dari daftar barang berdasarkan kode produk yang dimasukkan pengguna. Fungsi tulisDataBarang digunakan untuk men

## 6. tampilan.c
## 7. transaksi.c
## 8. makefile

      main:
	      gcc -o main header.h main.c produk.c transaksi.c tampilan.c login.c stok.c 
	      ./main
       
Perintah diatas menggunakan gcc (GNU Compiler Collection) untuk mengompilasi dan menghubungkan beberapa file sumber C yaitu main.c, produk.c, transaksi.c, tampilan.c, login.c, stok.c bersama dengan file header yaitu header.h.

      -o main 

Menentukan bahwa output dari proses kompilasi ini adalah sebuah executable bernama main.
      
      ./main

Perintah ini menjalankan executable main yang baru saja dibuat.
## Kesimpulan
Makefile adalah sebuah berkas teks yang berisi serangkaian aturan untuk mengotomatisasi proses kompilasi dan pengelolaan proyek perangkat lunak. Makefile membantu mengelola proyek yang terdiri dari banyak file sumber dan dependensi, sehingga memudahkan dan mempercepat proses kompilasi.

Untuk menampilkan semua fungsi yang kami gunakan di atas, kami menggunakan file external txt yaitu data_barang.txt

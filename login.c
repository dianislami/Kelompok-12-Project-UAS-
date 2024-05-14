#include "header.h"

//Fungsi untuk melakukan login sebelum memulai mesin kasir
int Login() {
    char Password[] = "klp12";
    char username[50];
    char password[50];

    //Meminta user memasukkan nama dan password
    printf("\nLogin sebagai kasir\n");
    printf("Masukkan nama Anda: ");
    scanf("%s", username);
    printf("Masukkan password: ");
    scanf("%s", password);

    //Pengecekan apakah password benar
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

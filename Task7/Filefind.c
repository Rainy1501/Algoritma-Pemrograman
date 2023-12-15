/*
    namaTugas : Tugas ke 7
    namaProgrammer : Fattan Naufan Islami / 23343037
    kasus program : Membuat Pencarian File pada Sistem Operasi
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FileMaks 100 
#define NamaFilePanjang 256 
#define PathPanjang 1024 

void judul(){
printf(" __   ___       __        __                  ___         ___\n"); 
printf("|__) |__  |\\ | /  `  /\\  |__) |  /\\  |\\ |    |__  | |    |__ \n"); 
printf("|    |___ | \\| \\__, /~~\\ |  \\ | /~~\\ | \\|    |    | |___ |___\n"); 
printf("--------------------------------------------------------------\n");
printf("\n");
}

void daftarFileDiDirektori(const char *pathDirektori, const char *CarinamaFile) {
    char perintah[PathPanjang + 20]; 
    char *daftarFile[FileMaks]; 
    int jumlahFile = 0;

    sprintf(perintah, "dir /b \"%s\"", pathDirektori);

    FILE *direksi = popen(perintah, "r");

    if (direksi != NULL) {
        char baris[NamaFilePanjang];
        while (fgets(baris, sizeof(baris), direksi) != NULL && jumlahFile < FileMaks) {
            baris[strcspn(baris, "\n")] = '\0';

            daftarFile[jumlahFile] = malloc(strlen(baris) + 1);
            strcpy(daftarFile[jumlahFile], baris);
            jumlahFile++;
        }
        pclose(direksi);
    }

    printf("File di direktori '%s':\n", pathDirektori);
    int ditemukan = 0; 
    for (int i = 0; i < jumlahFile; i++) {
        printf("%s\n", daftarFile[i]);
        if (strcmp(daftarFile[i], CarinamaFile) == 0) {
            ditemukan = 1; 
            break;
        }
        free(daftarFile[i]);
    }

    if (ditemukan) {
        printf("File '%s' ditemukan dalam direktori.\n", CarinamaFile);
    } else {
        printf("File '%s' tidak ditemukan dalam direktori.\n", CarinamaFile);
    }
    printf("\n");
}

int main() {
    char pathDirektori[PathPanjang];
    char CariNamaFile[NamaFilePanjang];
    char repeat;

    judul();
    do {
        printf("Masukkan path direktori untuk memeriksa file: ");
        fgets(pathDirektori, sizeof(pathDirektori), stdin);
        pathDirektori[strcspn(pathDirektori, "\n")] = '\0'; 

        printf("Masukkan nama file yang ingin dicari (ex: Filefind.c): ");
        fgets(CariNamaFile, sizeof(CariNamaFile), stdin);
        CariNamaFile[strcspn(CariNamaFile, "\n")] = '\0';

        daftarFileDiDirektori(pathDirektori, CariNamaFile);

        printf("Apakah Anda ingin mencari file lagi? (Y/N): ");
        scanf(" %c", &repeat); 
        printf("\n");

        while (getchar() != '\n'); 
    } while (repeat == 'y' || repeat == 'Y');

    printf("Inisialisasi pengeluaran program...\n");
    return 0;
}

/*
    namaTugas : Tugas ke 7
    namaProgrammer : Fattan Naufan Islami / 23343037
    kasus program : Membuat Pengelolaan Struktur Organisasi Perusahaan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PanjangLabel 50
#define Maksubmenu 10

struct Pegawai {
    char nama[PanjangLabel];
    char jabatan[PanjangLabel];
    struct Pegawai *bawahan[Maksubmenu];
    int jumlah_bawahan;
};

struct Pegawai* buat_pegawai(const char *nama, const char *jabatan) {
    struct Pegawai *pegawai_baru = (struct Pegawai *)malloc(sizeof(struct Pegawai));
    snprintf(pegawai_baru->nama, sizeof(pegawai_baru->nama), "%s", nama);
    snprintf(pegawai_baru->jabatan, sizeof(pegawai_baru->jabatan), "%s", jabatan);
    pegawai_baru->jumlah_bawahan = 0;
    for (int i = 0; i < Maksubmenu; i++) {
        pegawai_baru->bawahan[i] = NULL;
    }
    return pegawai_baru;
}

void judul() {
printf(" __  ___  __            ___       __      __   __   __               __        __   \n"); 
printf("/__`  |  |__) |  | |__/  |  |  | |__)    /  \\ |__) / _`  /\\  |\\ | | /__`  /\\  /__` |\n"); 
printf(".__/  |  |  \\ \\__/ |  \\  |  \\__/ |  \\    \\__/ |  \\ \\__> /~~\\ | \\| | .__/ /~~\\ .__/ |\n"); 
printf("-------------------------------------------------------------------------------------\n");
printf("\n");                  
}

void tambah_bawahan(struct Pegawai *pegawai, const char *nama, const char *jabatan) {
    if (pegawai->jumlah_bawahan < Maksubmenu) {
        pegawai->bawahan[pegawai->jumlah_bawahan++] = buat_pegawai(nama, jabatan);
    } else {
        printf("Jumlah maksimum bawahan telah tercapai\n");
    }
}

void bangun_organisasi(struct Pegawai *pegawai) {
    int pilihan;
    printf("Masukkan jumlah bawahan untuk %s (%s): ", pegawai->nama, pegawai->jabatan);
    scanf("%d", &pilihan);
    getchar(); 

    if (pilihan == 0) {
        printf("\n");
        return;
    }

    if (pilihan > Maksubmenu) {
        printf("Jumlah bawahan melebihi batas\n");
        return;
    }

    for (int i = 0; i < pilihan; i++) {
        char nama[PanjangLabel];
        char jabatan[PanjangLabel];
        printf("Masukkan nama bawahan %d dari %s (%s): ", i + 1, pegawai->nama, pegawai->jabatan);
        fgets(nama, sizeof(nama), stdin);
        nama[strcspn(nama, "\n")] = '\0'; 
        printf("Masukkan jabatan bawahan %d: ", i + 1);
        fgets(jabatan, sizeof(jabatan), stdin);
        jabatan[strcspn(jabatan, "\n")] = '\0'; 
        tambah_bawahan(pegawai, nama, jabatan);
        bangun_organisasi(pegawai->bawahan[i]);
    }
}

void tampilkan_organisasi(struct Pegawai *pegawai, int kedalaman) {
    for (int i = 0; i < kedalaman; i++) {
        printf("\t");
    }
    printf("- %s (%s)\n", pegawai->nama, pegawai->jabatan);

    for (int i = 0; i < pegawai->jumlah_bawahan; i++) {
        tampilkan_organisasi(pegawai->bawahan[i], kedalaman + 1);
    }
}

void bebaskan_memori(struct Pegawai *pegawai) {
    if (pegawai == NULL) {
        return;
    }

    for (int i = 0; i < pegawai->jumlah_bawahan; i++) {
        bebaskan_memori(pegawai->bawahan[i]);
    }

    free(pegawai);
}

int main() {
    char nama_CEO[PanjangLabel];
    char jabatan_CEO[] = "CEO";
    char repeat; 

    judul();
    do {
        printf("Masukkan nama CEO : ");
        fgets(nama_CEO, sizeof(nama_CEO), stdin);
        nama_CEO[strcspn(nama_CEO, "\n")] = '\0'; 

        struct Pegawai *ceo = buat_pegawai(nama_CEO, jabatan_CEO);
        bangun_organisasi(ceo);

        printf("Struktur Organisasi CEO (%s) :\n", nama_CEO);
        printf("- %s (%s)\n", ceo->nama, ceo->jabatan);

        for (int i = 0; i < ceo->jumlah_bawahan; i++) {
            tampilkan_organisasi(ceo->bawahan[i], 1);
        }

        bebaskan_memori(ceo);

        printf("Ingin memasukkan data untuk perusahaan lain? (Y/N): ");
        scanf(" %c", &repeat); 
        fflush(stdin);

    } while (repeat == 'Y' || repeat == 'y');


    printf("Inisialisasi pengeluaran program...\n");
    return 0;
}
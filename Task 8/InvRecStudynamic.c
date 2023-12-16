/*
    namaTugas : Tugas ke 8
    namaProgrammer : Fattan Naufan Islami / 23343037
    kasus program : Manajemen Perekrutan Mahasiswa yang ikut BEM 
                            dengan Dynamic Allocation Memory
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define Batas_Pendaftar 3


struct mahapelamar {
    char nama[70];
    char jurusan[50];
    int NIM;
    float IPK;
    int HasilWawancara;
    int HasilTes;
    char AlasanMskBEM[50];
    bool StatusLulus;
    bool SdhplhPelamar;
};

struct mahapelamar *Calonbem = NULL;
int jmlhpelamar = 0;

void judul() {
    printf("                          ___        ___          __   ___  __   ___       __       ___               __   ___      \n");
    printf("|\\/|  /\\  |\\ |  /\\     | |__   |\\/| |__  |\\ |    |__) |__  |__) |__  |__/ |__) |  |  |   /\\  |\\ |    |__) |__   |\\/|\n");
    printf("|  | /~~\\ | \\| /~~\\ \\__/ |___  |  | |___ | \\|    |    |___ |  \\ |___ |  \\ |  \\ \\__/  |  /~~\\ | \\|    |__) |___  |  |\n");
    printf("---------------------------------------------------------------------------------------------------------------------\n");
}

void tambahpelamar() {
    if (jmlhpelamar >= Batas_Pendaftar) {
        printf("Batas jumlah pelamar telah tercapai (%d).\n", Batas_Pendaftar);
        return;
    }

    jmlhpelamar++;

    struct mahapelamar *temp = (struct mahapelamar *)realloc(Calonbem, jmlhpelamar * sizeof(struct mahapelamar));
    if (temp == NULL) {
        printf("Alokasi memori gagal.\n");
        exit(EXIT_FAILURE);
    }
    Calonbem = temp;

    struct mahapelamar *Pelamar = &Calonbem[jmlhpelamar - 1];

    printf("Masukkan nama dari Pelamar: ");
    if (fgets(Pelamar->nama, sizeof(Pelamar->nama), stdin) == NULL) {
        printf("Gagal membaca input.\n");
        return;
    }
    Pelamar->nama[strcspn(Pelamar->nama, "\n")] = '\0';

    printf("Masukkan Jurusan asal Pelamar: ");
    if (fgets(Pelamar->jurusan, sizeof(Pelamar->jurusan), stdin) == NULL) {
        printf("Gagal membaca input.\n");
        return;
    }
    Pelamar->jurusan[strcspn(Pelamar->jurusan, "\n")] = '\0';

    printf("Masukkan NIM Pelamar: ");
    if (scanf("%d", &Pelamar->NIM) != 1) {
        printf("Gagal membaca input.\n");
        return;
    }
    getchar(); 

    printf("Masukkan IPK Pelamar: ");
    if (scanf("%f", &Pelamar->IPK) != 1) {
        printf("Gagal membaca input.\n");
        return;
    }
    getchar(); 

    printf("Masukkan Nilai Wawancara Pelamar: ");
    if (scanf("%d", &Pelamar->HasilWawancara) != 1) {
        printf("Gagal membaca input.\n");
        return;
    }
    getchar(); 

    printf("Masukkan Nilai Tes Pelamar: ");
    if (scanf("%d", &Pelamar->HasilTes) != 1) {
        printf("Gagal membaca input.\n");
        return;
    }
    getchar(); 

    printf("Alasan Pelamar ingin memasuki BEM: ");
    if (fgets(Pelamar->AlasanMskBEM, sizeof(Pelamar->AlasanMskBEM), stdin) == NULL) {
        printf("Gagal membaca input.\n");
        return;
    }
    Pelamar->AlasanMskBEM[strcspn(Pelamar->AlasanMskBEM, "\n")] = '\0';

    Pelamar->SdhplhPelamar = false;
    printf("Data pelamar berhasil disimpan.\n");
}

void caripelamar(int NIM) {
    bool ditemukan = false;
    for (int i = 0; i < jmlhpelamar; i++) {
        if (Calonbem[i].NIM == NIM) {
            printf("Pelamar ditemukan:\n");
            printf("Nama: %s\n", Calonbem[i].nama);
            printf("Jurusan: %s\n", Calonbem[i].jurusan);
            printf("NIM: %d\n", Calonbem[i].NIM);
            printf("IPK: %.2f\n", Calonbem[i].IPK);
            printf("Nilai Wawancara: %d\n", Calonbem[i].HasilWawancara);
            printf("Nilai Tes: %d\n", Calonbem[i].HasilTes);
            printf("Alasan memasuki BEM: %s\n", Calonbem[i].AlasanMskBEM);
            if (Calonbem[i].SdhplhPelamar) {
            printf("Status Kelulusan: %s\n", Calonbem[i].StatusLulus ? "Lulus" : "Tidak Lulus");
            }
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        printf("Pelamar dengan NIM %d tidak ditemukan.\n", NIM);
    }
}


void perbaruipelamar(int editNIM) {
    bool ditemukan = false;
    for (int i = 0; i < jmlhpelamar; i++) {
        if (Calonbem[i].NIM == editNIM) {
            ditemukan = true;
            printf("Data sebelum diperbarui:\n");
            printf("Nama: %s\n", Calonbem[i].nama);
            printf("Jurusan: %s\n", Calonbem[i].jurusan);
            printf("NIM: %d\n", Calonbem[i].NIM);
            printf("IPK: %.2f\n", Calonbem[i].IPK);
            printf("Nilai Wawancara: %d\n", Calonbem[i].HasilWawancara);
            printf("Nilai Tes: %d\n", Calonbem[i].HasilTes);
            printf("Alasan memasuki BEM: %s\n", Calonbem[i].AlasanMskBEM);

            printf("Masukkan data baru:\n");
            printf("Nama: ");
            if (fgets(Calonbem[i].nama, sizeof(Calonbem[i].nama), stdin) == NULL) {
                printf("Gagal membaca input.\n");
                return;
            }
            Calonbem[i].nama[strcspn(Calonbem[i].nama, "\n")] = '\0';

            printf("Jurusan: ");
            if (fgets(Calonbem[i].jurusan, sizeof(Calonbem[i].jurusan), stdin) == NULL) {
                printf("Gagal membaca input.\n");
                return;
            }
            Calonbem[i].jurusan[strcspn(Calonbem[i].jurusan, "\n")] = '\0';

            printf("NIM: ");
            if (scanf("%d", &Calonbem[i].NIM) != 1) {
                printf("Gagal membaca input.\n");
                return;
            }
            getchar();

            printf("IPK: ");
            if (scanf("%f", &Calonbem[i].IPK) != 1) {
                printf("Gagal membaca input.\n");
                return;
            }
            getchar(); 

            printf("Nilai Wawancara: ");
            if (scanf("%d", &Calonbem[i].HasilWawancara) != 1) {
                printf("Gagal membaca input.\n");
                return;
            }
            getchar(); 

            printf("Nilai Tes: ");
            if (scanf("%d", &Calonbem[i].HasilTes) != 1) {
                printf("Gagal membaca input.\n");
                return;
            }
            getchar();

            printf("Alasan memasuki BEM: ");
            if (fgets(Calonbem[i].AlasanMskBEM, sizeof(Calonbem[i].AlasanMskBEM), stdin) == NULL) {
                printf("Gagal membaca input.\n");
                return;
            }
            Calonbem[i].AlasanMskBEM[strcspn(Calonbem[i].AlasanMskBEM, "\n")] = '\0';

            printf("Data berhasil diperbarui.\n");
            return;
        }
    }
    if (!ditemukan) {
        printf("Pelamar dengan NIM %d tidak ditemukan.\n", editNIM);
    }
}

void tampilpelamar() {
    if (jmlhpelamar == 0) {
        printf("Belum ada pelamar yang terdaftar.\n");
        return;
    }
    printf("Daftar Pelamar:\n");
    for (int i = 0; i < jmlhpelamar; i++) {
        printf("Pelamar %d:\n", i + 1);
        printf("Nama: %s\n", Calonbem[i].nama);
        printf("Jurusan: %s\n", Calonbem[i].jurusan);
        printf("NIM: %d\n", Calonbem[i].NIM);
        printf("IPK: %.2f\n", Calonbem[i].IPK);
        printf("Nilai Wawancara: %d\n", Calonbem[i].HasilWawancara);
        printf("Nilai Tes: %d\n", Calonbem[i].HasilTes);
        printf("Alasan memasuki BEM: %s\n", Calonbem[i].AlasanMskBEM);
        if (Calonbem[i].SdhplhPelamar) {
            printf("Status Kelulusan: %s\n", Calonbem[i].StatusLulus ? "Lulus" : "Tidak Lulus");
        }
        printf("\n");
    }
}

void hapuspelamar(int NIM) {
    int ind_ditemukan = -1;
    for (int i = 0; i < jmlhpelamar; i++) {
        if (Calonbem[i].NIM == NIM) {
            ind_ditemukan = i;
            break;
        }
    }
    if (ind_ditemukan == -1) {
        printf("Pelamar dengan NIM %d tidak ditemukan.\n", NIM);
        return;
    }

    for (int i = ind_ditemukan; i < jmlhpelamar - 1; i++) {
        Calonbem[i] = Calonbem[i + 1];
    }
    jmlhpelamar--;
    printf("Pelamar dengan NIM %d berhasil dihapus.\n", NIM);
}

void cekkelulusan(int NIM) {
    bool ditemukan = false;
    for (int i = 0; i < jmlhpelamar; i++) { 
        if (Calonbem[i].NIM == NIM) {
            ditemukan = true;
            if (Calonbem[i].HasilWawancara >= 75 && Calonbem[i].HasilTes >= 70) {
                Calonbem[i].StatusLulus = true;
                printf("Selamat! Pelamar dengan NIM %d dinyatakan lulus.\n", NIM);
            } else {
                Calonbem[i].StatusLulus = false;
                printf("Maaf, Pelamar dengan NIM %d tidak memenuhi syarat untuk diterima.\n", NIM);
            }
            Calonbem[i].SdhplhPelamar = true;
            break;
        }
    }
    if (!ditemukan) {
        printf("Pelamar dengan NIM %d tidak ditemukan.\n", NIM);
    }
}

int Bandingipk(const void *a, const void *b) {
    const struct mahapelamar *pelamarA = (struct mahapelamar *)a;
    const struct mahapelamar *pelamarB = (struct mahapelamar *)b;
    return (pelamarA->IPK - pelamarB->IPK);
}

void urutkanIPK() {
    if (jmlhpelamar == 0) {
        printf("Tidak ada pelamar yang terdaftar.\n");
        return;
    }

    qsort(Calonbem, jmlhpelamar, sizeof(struct mahapelamar), Bandingipk);

    printf("Daftar Pelamar Terurut Berdasarkan IPK:\n");
    for (int i = 0; i < jmlhpelamar; i++) {
        printf("Pelamar %d:\n", i + 1);
        printf("Nama: %s\n", Calonbem[i].nama);
        printf("Jurusan: %s\n", Calonbem[i].jurusan);
        printf("NIM: %d\n", Calonbem[i].NIM);
        printf("IPK: %.2f\n", Calonbem[i].IPK);
        printf("Nilai Wawancara: %d\n", Calonbem[i].HasilWawancara);
        printf("Nilai Tes: %d\n", Calonbem[i].HasilTes);
        printf("Alasan memasuki BEM: %s\n", Calonbem[i].AlasanMskBEM);
        if (Calonbem[i].SdhplhPelamar) {
            printf("Status Kelulusan: %s\n", Calonbem[i].StatusLulus ? "Lulus" : "Tidak Lulus");
        }
        printf("\n");
    }
}

int main() {
    int pilihan;

    judul();
    do {
        printf("\nMenu:\n");
        printf("1. Tambah Pelamar\n");
        printf("2. Cari Pelamar\n");
        printf("3. Ubah Data Pelamar\n");
        printf("4. Tampilkan seluruh pelamar\n");
        printf("5. Hapus Pelamar\n");
        printf("6. Pengecekan kelulusan Pelamar\n");
        printf("7. Urutkan IPK\n");
        printf("8. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1: ;
                tambahpelamar();
                break;
            case 2: ;
                int nim;
                printf("Masukkan NIM pelamar yang ingin dicari: ");
                if (scanf("%d", &nim) != 1) {
                    printf("Gagal membaca input.\n");
                    break;
                }
                getchar();
                caripelamar(nim);
                break;
            case 3:
                {
                int editNIM;
                printf("Masukkan NIM pelamar yang ingin diperbarui datanya: ");
                if (scanf("%d", &editNIM) != 1) {
                    printf("Gagal membaca input.\n");
                    break;
                }
                getchar(); 
                perbaruipelamar(editNIM);
                break;
            	}
            case 4:
                tampilpelamar();    
                break;
            case 5: ;
                int hapusNIM;
                printf("Masukkan NIM pelamar yang ingin dihapus: ");
                if (scanf("%d", &hapusNIM) != 1) {
                    printf("Gagal membaca input.\n");
                    break;
                }
                getchar(); 
                hapuspelamar(hapusNIM);
                break;
            case 6: ;
                int cekNIM;
                printf("Masukkan NIM pelamar yang ingin dicek kelulusannya: ");
                if (scanf("%d", &cekNIM) != 1) {
                    printf("Gagal membaca input.\n");
                    break;
                }
                getchar(); 
                cekkelulusan(cekNIM);
                break;
            case 7: ;
                urutkanIPK();
                break;
            case 8:
                printf("Inisialisasi pengeluaran program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih menu yang tersedia.\n");
                break;
        }
    } while (pilihan != 8);

    free(Calonbem);
    return 0;
}

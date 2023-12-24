/*
namaTugas : Tugas ke 6
namaProgrammer : Fattan Naufan Islami / 23343037
kasus program : Manajemen Perekrutan Mahasiswa yang ikut BEM
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define Batas_Pendaftar 3

// Membuat pengelompokan untuk pelamar
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

// Membuat pengelompokan menggunakan pengelompokan untuk pelamar
struct mahapelamar Calonbem[Batas_Pendaftar];
int jmlhpelamar = 0;

// Fungsi menampilkan Judul Program
void judul() {
    printf("                          ___        ___          __   ___  __   ___       __       ___               __   ___      \n");
    printf("|\\/|  /\\  |\\ |  /\\     | |__   |\\/| |__  |\\ |    |__) |__  |__) |__  |__/ |__) |  |  |   /\\  |\\ |    |__) |__   |\\/|\n");
    printf("|  | /~~\\ | \\| /~~\\ \\__/ |___  |  | |___ | \\|    |    |___ |  \\ |___ |  \\ |  \\ \\__/  |  /~~\\ | \\|    |__) |___  |  |\n");
}

// Fungsi menambah pelamar
void tambahpelamar(struct mahapelamar* Pelamar) {
    if (jmlhpelamar == Batas_Pendaftar) {
        printf("Jumlah pelamar sudah penuh, tidak bisa menambahkan pelamar baru.\n");
        return;
    }

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

// Mencari pelamar dengan menggunakan NIM
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

// Memperbarui data pelamar
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

// Fungsi untuk menampilkan daftar pelamar
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
    }
}

// Fungsi untuk menghapus pelamar dari data
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

// Fungsi untuk mengecek kelulusan pelamar
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

// Fungsi utama yang akan dijalankan
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
        printf("7. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1: ;
                tambahpelamar(&Calonbem[jmlhpelamar]);
                jmlhpelamar++;
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
            case 7:
                printf("Inisialisasi pengeluaran program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih menu yang tersedia.\n");
                break;
        }
    } while (pilihan != 7);

    return 0;
}

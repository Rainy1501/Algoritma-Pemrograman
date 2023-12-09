// Nama Programmer : Fattan Naufan Islami
// Tanggal Pembuatan Program : 26 Oktober 2023
/* Deskripsi Singkat Program : Sebuah program aplikasi manajemen inventaris yang berfungsi untuk menambahkan barang, mencari barang menggunakan kode, 
							   mencatat penjualan barang, melihat stok barang, dan juga melihat riwayat penjualan barang */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_GUDANG 2

// Variabel global untuk inventaris dan penjualan
int currentGudang = 0;
int currentPenjualan = 0;

// Fungsi untuk menampilkan judul
void judul() {
    printf("____ _  _ ___  ____ ____ _  _ ____ ____ _  _ ____ ___    ___ ____ ____ _   _\n");
    printf("[__  |  | |__] |___ |__/ |\\/| |__| |__/ |_/  |___  |      |  |__/ |___  \\_/ \n");
    printf("___] |__| |    |___ |  \\ |  | |  | |  \\ | \\_ |___  |      |  |  \\ |___   |  \n");
}

// Fungsu untuk menambah barang ke gudang
void tambahbrg(char Namabarang[][50], char produsen[][50], int tahunpembuatan[], char kodeitem[][50], int harga[], int jumlahbarang[], bool stok[]) {
    if (currentGudang == MAX_GUDANG) {
    printf("Gudang sudah penuh, tidak bisa menambahkan barang baru.\n");
    return;
}

    printf("Masukkan nama barang: ");
    if (fgets(Namabarang[currentGudang], 50, stdin) == NULL) {
        printf("Gagal membaca input.\n");
        return;
    }
    Namabarang[currentGudang][strcspn(Namabarang[currentGudang], "\n")] = '\0'; 

    printf("Masukkan nama produsen: ");
    if (fgets(produsen[currentGudang], 50, stdin) == NULL) {
        printf("Gagal membaca input.\n");
        return;
    }
    produsen[currentGudang][strcspn(produsen[currentGudang], "\n")] = '\0';

    printf("Masukkan tahun pembuatan: ");
    if (scanf("%d", &tahunpembuatan[currentGudang]) != 1) {
        printf("Gagal membaca input.\n");
        return;
    }
    getchar(); 

    printf("Masukkan kode item: ");
    if (fgets(kodeitem[currentGudang], 50, stdin) == NULL) {
        printf("Gagal membaca input.\n");
        return;
    }
    kodeitem[currentGudang][strcspn(kodeitem[currentGudang], "\n")] = '\0';

    printf("Masukkan harga: Rp");
    if (scanf("%d", &harga[currentGudang]) != 1)
    {
        printf("Gagal membaca input.\n");
        return;
    }
    getchar(); 

    printf("Masukkan jumlah barang: ");
    if (scanf("%d", &jumlahbarang[currentGudang]) != 1)
    {
        printf("Gagal membaca input.\n");
        return;
    }
    
    getchar(); 
    
    stok[currentGudang] = true; 

    currentGudang++;
    printf("Barang berhasil ditambahkan.\n");
}

// Fungsi untuk mencari barang yang ada di gudang
void caribrg(char Namabarang[][50], char produsen[][50], int tahunpembuatan[], char kodeitem[][50], int harga[], int jumlahbarang[], bool stok[]) {
    char itemfinder[30];
    int i;
    
    printf("Masukkan kode barang yang ingin dicari :");
    scanf("%s", itemfinder);

    for (int i = 0; i < currentGudang; i++) {
        if (strcmp(kodeitem[i], itemfinder) == 0) {
            printf("Nama Barang: %s\n", Namabarang[i]);
            printf("Nama Pembuat: %s\n", produsen[i]);
            printf("Tahun Pembuatan: %d\n", tahunpembuatan[i]);
            printf("Kode Barang: %s\n", kodeitem[i]);
            printf("Harga Barang: Rp.%d\n", harga[i]);
            printf("Jumlah Barang: %d\n", jumlahbarang[i]);

            if (jumlahbarang[i] > 0) {
                printf("Status: Tersedia\n");
            } else {
                printf("Status: Habis\n");
            }
            return; 
        }
    }
    
    printf("Barang dengan kode %s tidak ditemukan.\n", itemfinder);
}

// Fungsi untuk mencatat penjualan barang ke pembeli
void jualbrg(char Namabarang[][50], char produsen[][50], int tahunpembuatan[], char kodeitem[][50], int harga[], int jumlahbarang[] ,char Namapembeli[][50], int Tanggalpenjualan[][3], int jumlahTerjual[], bool stok[]) {
    char kodejitem[50];
    int JumlahTerjual, indeks = -1;
    bool found = false;
    
    if (currentPenjualan == 2) {
        printf("Data penjualan sudah mencapai batas maksimum.\n");
        return;
    }
    
    printf("Masukkan nama dari pembeli: ");
    if (fgets(Namapembeli[currentPenjualan], 50, stdin) == NULL) {
        printf("Gagal membaca input.\n");
        return;
    }
    Namapembeli[currentPenjualan][strcspn(Namapembeli[currentPenjualan], "\n")] = '\0';

    printf("Masukkan kode barang yang dijual: ");
    if (fgets(kodejitem, 50, stdin) == NULL) {
        printf("Gagal membaca input.\n");
        return;
    }
    kodejitem[strcspn(kodejitem, "\n")] = '\0';

    for (int i = 0; i < currentGudang; i++)
    {
        if (strcmp(kodeitem[i], kodejitem) == 0)
        {
            found = true;
            indeks = i;
            break;
        }
    }

    if (!found)
    {
        printf("Barang dengan kode %s tidak ditemukan.\n", kodejitem);
        return;
    }

    printf("Masukkan berapa jumlah barang yang akan dijual: ");
    if (scanf("%d", &JumlahTerjual) != 1)
    {
        printf("Gagal membaca input.\n");
        return;
    }
    getchar(); 

    printf("Masukkan tanggal penjualan (dd-mm-yyyy): ");
    if (scanf("%d-%d-%d", &Tanggalpenjualan[currentPenjualan][0], &Tanggalpenjualan[currentPenjualan][1], &Tanggalpenjualan[currentPenjualan][2]) != 3)
    {
        printf("Gagal membaca input.\n");
        return;
    }
    getchar();

    if (JumlahTerjual <= 0 || jumlahbarang[indeks] < JumlahTerjual)
    {
        printf("Jumlah barang yang dijual harus lebih dari 0 dan tidak melebihi jumlah barang tersedia.\n");
        return;
    }

    jumlahbarang[indeks] -= JumlahTerjual;
    if (jumlahbarang[indeks] <= 0) {
        stok[indeks] = false;
    }

    jumlahTerjual[currentPenjualan] = JumlahTerjual;
    printf("Barang berhasil dijual.\n");

    currentPenjualan++;
}

// Fungsi untuk menampilkan stok barang di gudang
void hitungStok(char Namabarang[][50], int jumlahbarang[], bool stok[]) {
    printf("Daftar Stok Barang:\n");
    for (int i = 0; i < currentGudang; i++) {
        printf("%d. %s (Jumlah: %d, Status: %s)\n", i+1, Namabarang[i], jumlahbarang[i], (stok[i])?"Tersedia":"Habis");
    }
}

// Fungsi untuk menampilkan riwayat penjualan
void riwayatPenjualan(char Namapembeli[][50], char kodeitem[][50], int jumlahbarang[], int harga[], int Tanggalpenjualan[][3], int jumlahTerjual[]) {
    printf("Daftar Penjualan:\n");
    for (int i = 0; i < currentPenjualan; i++) {
        printf("Nama Pelanggan: %s\n", Namapembeli[i]);
        printf("Tanggal Penjualan: %d-%d-%d\n", Tanggalpenjualan[i][0], Tanggalpenjualan[i][1], Tanggalpenjualan[i][2]);
        printf("Kode Barang: %s\n", kodeitem[i]);
        printf("Jumlah Terjual: %d\n", jumlahTerjual[i]);
        printf("Harga Terjual: Rp. %d\n", harga[i] * jumlahTerjual[i]);
        printf("\n");
    }
}

// Fungsi utama yang akan dijalankan
int main() {
    char itemname[MAX_GUDANG][50], producer[MAX_GUDANG][50], itemcode[MAX_GUDANG][50], customername[100][50];
    int yearofcreation[MAX_GUDANG], price[MAX_GUDANG], dateofsale, itemamount[MAX_GUDANG], Tanggalpenjualan[100][3], jumlahTerjual[100];
    bool stock[MAX_GUDANG];
    int pilihan;

    judul();
    do {
        printf("\nMenu:\n");
        printf("1. Tambah Barang\n");
        printf("2. Cari Barang\n");
        printf("3. Jual Barang\n");
        printf("4. Hitung Stok\n");
        printf("5. Riwayat penjualan\n");
        printf("6. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
                tambahbrg(itemname, producer, yearofcreation, itemcode, price, itemamount, stock);
                break;
            case 2:
                caribrg(itemname, producer, yearofcreation, itemcode, price, itemamount, stock);
                break;
            case 3:
                jualbrg(itemname, producer, yearofcreation, itemcode, price, itemamount, customername, Tanggalpenjualan, jumlahTerjual, stock);
                break;
            case 4:
                hitungStok(itemname, itemamount, stock);
                break;
            case 5:
                riwayatPenjualan(customername, itemcode, itemamount, price, Tanggalpenjualan, jumlahTerjual);
                break;
            case 6:
                printf("Terima kasih telah menggunakan program ini. Sampai bertemu lagi di lain waktu.\n");
                printf("Inisialisasi Pengeluaran program...");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 6);

    return 0;
}

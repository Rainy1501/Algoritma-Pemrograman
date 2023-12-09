// Nama Programmer : Fattan Naufan Islami
// Tanggal Pembuatan Program : 26 Oktober 2023
// Deskripsi Singkat Program : Sebuah program yang digunakan untuk menampilkan

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_GUDANG 100

int currentGudang = 0;

void judul() {
    printf("____ _  _ ___  ____ ____ _  _ ____ ____ _  _ ____ ___    ___ ____ ____ _   _\n");
    printf("[__  |  | |__] |___ |__/ |\\/| |__| |__/ |_/  |___  |      |  |__/ |___  \\_/ \n");
    printf("___] |__| |    |___ |  \\ |  | |  | |  \\ | \\_ |___  |      |  |  \\ |___   |  \n");
}

void tambahbrg(char Namabarang[], char produsen[], int tahunpembuatan[], char kodeitem[], int harga[], int jumlahbarang[], bool stok[]) {
    if (currentGudang >= MAX_GUDANG) {
        printf("Gudang sudah penuh, tidak bisa menambahkan barang baru.\n");
        return;
    }

    printf("Masukkan nama barang: ");
    if (fgets(Namabarang, 50, stdin) == NULL) {
        printf("Error reading input.\n");
        return;
    }
    Namabarang[strcspn(Namabarang, "\n")] = '\0'; // Remove the newline character.

    printf("Masukkan nama produsen: ");
    if (fgets(produsen, 50, stdin) == NULL) {
        printf("Error reading input.\n");
        return;
    }
    produsen[strcspn(produsen, "\n")] = '\0';

    printf("Masukkan tahun pembuatan: ");
    if (scanf("%d", &tahunpembuatan[currentGudang]) != 1) {
        printf("Error reading input.\n");
        return;
    }
    getchar(); // Consume the newline character left in the input buffer.

    printf("Masukkan kode item: ");
    if (fgets(kodeitem, 50, stdin) == NULL) {
        printf("Error reading input.\n");
        return;
    }
    kodeitem[strcspn(kodeitem, "\n")] = '\0';

    printf("Masukkan harga: ");
    if (scanf("%d", &harga[currentGudang]) != 1)
    {
        printf("Error reading input.\n");
        return;
    }
    getchar(); // Consume the newline character left in the input buffer.

    printf("Masukkan jumlah barang: ");
    if (scanf("%d", &jumlahbarang[currentGudang]) != 1)
    {
        printf("Error reading input.\n");
        return;
    }
    
    getchar(); // Consume the newline character left in the input buffer.
    
    stok[currentGudang] = true; // Initialize the stock to true.

    currentGudang++;
    printf("Barang berhasil ditambahkan.\n");
}

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
            printf("Harga Barang: Rp. %d\n", harga[i]);
            printf("Stok Barang: %d\n", jumlahbarang[i]);

            // Check if the item is in stock or not and print the message accordingly
            if (jumlahbarang[i] > 0) {
                printf("Stock : Masih Tersedia\n");
            } else {
                printf("Stock : Sudah Habis\n");
            }
            return; // Item found, so exit the function
        }
    }
    
    printf("Barang dengan kode %s tidak ditemukan.\n", itemfinder);
}

void jualbrg(char Namabarang[][50], char produsen[][50], int tahunpembuatan[], char kodeitem[][50], int harga[], int jumlahbarang[] ,char Namapembeli[50], int Tanggalpenjualan[]) {
    char kodejitem;
    int JumlahTerjual;
    printf("Masukkan nama dari pembeli: ");
    scanf("%s", Namapembeli);
    printf("Masukkan kode barang yang dijual: ");
    scanf("%d", &kodejitem);

    for (int i = 0; i < jumlahbarang; i++)
    {
       if (kodeitem == kodejitem)
       {
        printf("Masukkan berapa jumlah barang yang akan dijual: ");
        scanf("%d", &JumlahTerjual);

        if (JumlahTerjual > 0 && jumlahbarang >= JumlahTerjual)
        {
            printf("Masukkan tanggal penjualan (dd-mm-yyyy): ");
            scanf("%d-%d-%d", Tanggalpenjualan);

            if (jumlahbarang - JumlahTerjual <= 0)
            {
                stok = false; 
                }
                else
                {
                stok = true;
            }
            
            stok -= JumlahTerjual
            (*)
        }
        
       }
       
        
    }
    

}

int main() {
    char itemname[MAX_GUDANG][50], producer[MAX_GUDANG][50], itemcode[MAX_GUDANG][50], customername[50];
    int yearofcreation[MAX_GUDANG], price[MAX_GUDANG], dateofsale, itemamount[MAX_GUDANG];
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
        getchar(); // Consume the newline character left in the input buffer.

        switch (pilihan) {
            case 1:
                tambahbrg(itemname[currentGudang], producer[currentGudang], yearofcreation, itemcode[currentGudang], price, itemamount, stock);
                break;
            case 2:
                caribrg(itemname, producer, yearofcreation, itemcode, price, itemamount, stock);
                break;
            case 3:
                jualbrg(itemname, producer, yearofcreation, itemcode, price, itemamount, customername, dateofsale);
                break;
            case 4:

            case 6:
                printf("Terima kasih. Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 5);

    return 0;
}
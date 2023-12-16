/* namaTugas : Tugas ke 4
   namaProgrammer : Fattan Naufan Islami / 23343037
   kasus program : Membuat Menu
*/


#include <stdio.h>
#include <string.h>

int main() {

    char pilihanpaket, pilihanmakanan, pilihanminuman, ulangi;
    int hargaPaket = 0, hargaMakanan = 0, hargaMinuman = 0;
    char namaPaket[30], namaMakanan[30], namaMinuman[30]; 

    do {
    printf("Menu Pilihan Paket Warnet dengan Makanan dan Minuman\n");
    printf("-----------------------------------------------------\n\n");

    printf("Pilihlah paket warnet yang ingin anda beli!\n");
    printf("1) Paket 5000 (1 Jam) \n");
    printf("2) Paket 10000 (2 Jam) \n");
    printf("3) Paket 15000 (3 Jam) \n");
    printf("4) Paket 20000 (4 Jam) \n");
    printf("--------------------------------------------------\n");
    balikpilihan1:
    printf("Input Paket yang diinginkan : ");
    scanf(" %c", &pilihanpaket);

    switch (pilihanpaket) {
        case '1':
            printf("Paket yang kamu pilih adalah paket 5000\n");
            hargaPaket = 5000;
            strcpy(namaPaket, "Paket 5000 (1 Jam)");
            break;

        case '2':
            printf("Paket yang kamu pilih adalah paket 10000\n");
            hargaPaket = 10000;
            strcpy(namaPaket, "Paket 10000 (2 Jam)");
            break;

        case '3':
            printf("Paket yang kamu pilih adalah paket 15000\n");
            hargaPaket = 15000;
            strcpy(namaPaket, "Paket 15000 (3 Jam)");
            break;

        case '4':
            printf("Paket yang kamu pilih adalah paket 20000\n");
            hargaPaket = 20000;
            strcpy(namaPaket, "Paket 20000 (4 Jam)");
            break;

        default:
            printf("Input yang kamu masukkan tidak valid\n");
            goto balikpilihan1;
    }

    if (pilihanpaket >= '1' && pilihanpaket <= '4') {
        printf("\n-------------------------------------------------------\n");
        printf("Pilihlah dari menu ini makanan yang anda inginkan!\n");
        printf("1. Bakso (Rp100000)\n");
        printf("2. Mie ayam (Rp10000)\n");
        printf("3. Nasi goreng (Rp12000)\n");
        printf("4. Nasi uduk (Rp11000)\n");
        printf("5. Mie rebus (Rp10000)\n");
        printf("6. Pecel Ayam (Rp13000) \n");
        printf("7. Tidak ada (Rp0)\n");
        printf("-------------------------------------------------------\n");
        balikpilihan2:
        printf("Input makanan yang diinginkan : ");
        scanf(" %c", &pilihanmakanan);

    switch (pilihanmakanan) {
        case '1':
            printf("Menu makanan yang kamu pilih adalah Bakso\n");
            hargaMakanan = 10000;
            strcpy(namaMakanan, "Bakso");
            break;

        case '2':
            printf("Menu makanan yang kamu pilih adalah Mie ayam\n");
            hargaMakanan = 10000;
            strcpy(namaMakanan, "Mie ayam");
            break;

        case '3':
            printf("Menu makanan yang kamu pilih adalah Nasi goreng\n");
            hargaMakanan = 12000;
            strcpy(namaMakanan, "Nasi goreng");
            break;

        case '4':
            printf("Menu makanan yang kamu pilih adalah Nasi Uduk\n");
            hargaMakanan = 11000;
            strcpy(namaMakanan, "Nasi Uduk");
            break;
        
        case '5':
            printf("Menu makanan yang kamu pilih adalah Mie rebus\n");
            hargaMakanan = 10000;
            strcpy(namaMakanan, "Mie rebus");
            break;
        
        case '6':
            printf("Menu makanan yang kamu pilih adalah Pecel ayam\n");
            hargaMakanan = 13000;
            strcpy(namaMakanan, "Pecel ayam");
            break;

        case '7':
            printf("Kamu tidak memesan makanan apapun\n");
            hargaMakanan = 0;
            strcpy(namaMakanan, "Tidak ada");
            break;

        default:
            printf("Input yang kamu masukkan tidak valid\n");
            goto balikpilihan2;
    }
    }

    if (pilihanmakanan >= '1' && pilihanmakanan <= '7') {
        printf("\n------------------------------------------------------\n");
        printf("Pilihlah dari menu ini minuman yang anda inginkan!\n");
        printf("1. Air putih (Rp0)\n");
        printf("2. Teh es (Rp5000)\n");
        printf("3. Jus pokat (Rp10000)\n");
        printf("4. Jus mangga (Rp10000)\n");
        printf("5. Kopi hitam (Rp8000)\n");
        printf("6. Kopi susu (Rp10000)\n");
        printf("7. Tidak ada\n");
        printf("------------------------------------------------------\n");
        balikpilihan3:
        printf("Input minuman yang diinginkan : ");
        scanf(" %c", &pilihanminuman);

    switch (pilihanminuman) {
        case '1':
            printf("Minuman yang kamu pilih adalah Air putih\n");
            hargaMinuman = 0;
            strcpy(namaMinuman, "Air putih");
            break;

        case '2':
            printf("Minuman yang kamu pilih adalah Teh es\n");
            hargaMinuman = 5000;
            strcpy(namaMinuman, "Teh es");
            break;

        case '3':
            printf("Minuman yang kamu pilih adalah Jus pokat\n");
            hargaMinuman = 10000;
            strcpy(namaMinuman, "Jus pokat");
            break;

        case '4':
            printf("Minuman yang kamu pilih adalah Jus mangga\n");
            hargaMinuman = 10000;
            strcpy(namaMinuman, "Jus mangga");
            break;
        
        case '5':
            printf("Minuman yang kamu pilih adalah Kopi hitam\n");
            hargaMinuman = 8000;
            strcpy(namaMinuman, "Kopi hitam");
            break;
        
        case '6':
            printf("Minuman yang kamu pilih adalah Kopi susu\n");
            hargaMinuman = 10000;
            strcpy(namaMinuman, "Kopi susu");
            break;

        case '7':
            printf("Kamu tidak memesan minuman apapun\n");
            hargaMinuman = 0;
            strcpy(namaMinuman, "Tidak ada");
            break;

        default:
            printf("Input yang kamu masukkan tidak valid\n");
            goto balikpilihan3;
    }
    }

    int totalHarga = hargaPaket + hargaMakanan + hargaMinuman;
    printf("Total Harga: %d\n", totalHarga);

    printf("\n--------------------------------------------");
    printf("\nPaket yang Anda pilih adalah %s\n", namaPaket);
    printf("Makanan yang Anda pilih adalah %s\n", namaMakanan);
    printf("Minuman yang Anda pilih adalah %s\n", namaMinuman);
    printf("Total harga dari pilihan anda adalah %d\n", totalHarga);
    printf("--------------------------------------------\n");
    printf("Apakah Anda yakin dengan pilihan anda? (Y/N)\n");
    scanf(" %c", &ulangi);
    
    } while (ulangi == 'n' || ulangi == 'N');

    printf("\nSelamat Menikmati!!");
    return 0;
}
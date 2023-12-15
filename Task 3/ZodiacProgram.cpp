/* namaTugas : Tugas ke 3
   namaProgrammer : Fattan Naufan Islami / 23343037
   kasus program : Menentukan Kategori Umur
*/

#include <stdio.h>

int main() {
    char ulangi;
    int tanggal, bulan;

	do {	
	printf("\t\tProgram Menentukan Bintang Seseorang Berdasarkan Tanggal dan Bulan Kelahiran \n");
	printf("\t\t-----------------------------------------------------------------------------\n");
	printf("\nMasukkan Tahun Kelahiranmu ");
	printf("\n---------------------------");
	printf("\n\nTanggal lahir (1-31) : ");
	scanf("%i", &tanggal);
	printf("Bulan lahir (1-12) : ");
	scanf("%i", &bulan); 
	fflush (stdin);
	
	if ((bulan == 1 && tanggal >= 20) || (bulan == 2 && tanggal <= 18)) {
        printf("Zodiak kamu adalah Aquarius.\n");
    } else if ((bulan == 2 && tanggal >= 19) || (bulan == 3 && tanggal <= 20)) {
        printf("Zodiak kamu adalah Pisces.\n");
    } else if ((bulan == 3 && tanggal >= 21) || (bulan == 4 && tanggal <= 19)) {
        printf("Zodiak kamu adalah Aries.\n");
    } else if ((bulan == 4 && tanggal >= 20) || (bulan == 5 && tanggal <= 20)) {
        printf("Zodiak kamu adalah Taurus.\n");
    } else if ((bulan == 5 && tanggal >= 21) || (bulan == 6 && tanggal <= 20)) {
        printf("Zodiak kamu adalah Gemini.\n");
    } else if ((bulan == 6 && tanggal >= 21) || (bulan == 7 && tanggal <= 22)) {
        printf("Zodiak kamu adalah Cancer.\n");
    } else if ((bulan == 7 && tanggal >= 23) || (bulan == 8 && tanggal <= 22)) {
        printf("Zodiak kamu adalah Leo.\n");
    } else if ((bulan == 8 && tanggal >= 23) || (bulan == 9 && tanggal <= 22)) {
        printf("Zodiak kamu adalah Virgo.\n");
    } else if ((bulan == 9 && tanggal >= 23) || (bulan == 10 && tanggal <= 22)) {
        printf("Zodiak kamu adalah Libra.\n");
    } else if ((bulan == 10 && tanggal >= 23) || (bulan == 11 && tanggal <= 21)) {
        printf("Zodiak kamu adalah Scorpio.\n");
    } else if ((bulan == 11 && tanggal >= 22) || (bulan == 12 && tanggal <= 21)) {
        printf("Zodiak kamu adalah Sagittarius.\n");
    } else if ((bulan == 12 && tanggal >= 22) || (bulan == 1 && tanggal <= 19)) {
        printf("Zodiak kamu adalah Capricorn.\n");
    
    }
 	printf("\nApakah kamu ingin menentukan bintang lagi? (y/n): ");
 	printf("\n-------------------------------------------------\n");
    scanf(" %c", &ulangi);  

    } while (ulangi == 'y' || ulangi == 'Y');

    printf("\nSampai bertemu lagi!!");
	return 0;
}

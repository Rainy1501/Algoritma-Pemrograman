/* namaTugas : Tugas ke 2
   namaProgrammer : Fattan Naufan Islami / 23343037
   kasus program : Menkonversi waktu jam ke total detik
*/

#include <stdio.h>

int main() {
	char ulangi;
	int jam, menit, detik, total_detik;
	int hitung_jam = 3600, hitung_menit = 60;
	
	do {
	
	printf("\tProgram Konversi Waktu Jam ke Total Detik\n");
	printf("\t ---------------------------------------\n");
	printf("Tulis Jam yang ingin di konversi dengan format (Jam:Menit:Detik) : ");
	scanf("%i:%i:%i", &jam, &menit, &detik); fflush (stdin);
	
	total_detik = jam * hitung_jam + menit * hitung_menit + detik;
	
	printf("\nJadi hasil dari konversi %i:%i:%i adalah %i total detik\n", jam, menit, detik, total_detik);
	
 	printf("\nApakah kamu ingin konversi waktu lagi? (y/n): ");
 	printf("\n--------------------------------------\n");
    scanf(" %c", &ulangi);  

    } while (ulangi == 'y' || ulangi == 'Y');

    printf("\nSampai bertemu lagi!!");
	return 0;
}

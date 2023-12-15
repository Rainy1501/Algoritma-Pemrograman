/* namaTugas : Tugas ke 3
   namaProgrammer : Fattan Naufan Islami / 23343037
   kasus program : Menentukan Kategori Umur
*/

#include <stdio.h>

int main() {
    char ulangi;
    int umur;

	do {	
	printf("\tProgram Menentukan Kategori Umur \n");
	printf("\t--------------------------------\n");
	printf("Masukkan umur anda : ");
	scanf("%i", &umur); 
	fflush (stdin);
	
	if ((umur >= 0) && (umur <= 5)) {
        printf("Kategori Umur kamu adalah Masa Balita.\n");
    } else if ((umur >= 5) && (umur <= 11)) {
        printf("Kategori Umur kamu adalah Masa kanak-kanak.\n");
	} else if ((umur >= 12) && (umur <= 16)) {
		printf("Kategori Umur kamu adalah Masa Remaja Awal.\n");
	} else if ((umur >= 17) && (umur <= 25)) {
		printf("Kategori Umur kamu adalah Masa Remaja Akhir.\n");
	} else if ((umur >= 26) && (umur <= 35)) {
		printf("Kategori Umur kamu adalah Masa Dewasa Awal.\n");
	} else if ((umur >= 36) && (umur <= 45)) {
		printf("Kategori Umur kamu adalah Masa Dewasa Akhir.\n");
	} else if ((umur >= 46) && (umur <= 55)) {
		printf("Kategori Umur kamu adalah Masa Lansia Awal.\n");
	} else if ((umur >= 56) && (umur <= 65)) {
		printf("Kategori Umur kamu adalah Masa Lansia Akhir.\n");
	} else if ((umur >=66)) {
		printf("Kategori Umur kamu adalah Masa Manula.\n");
}
 	printf("\nApakah kamu ingin konversi waktu lagi? (y/n): ");
 	printf("\n--------------------------------------\n");
    scanf(" %c", &ulangi);  

    } while (ulangi == 'y' || ulangi == 'Y');

    printf("\nSampai bertemu lagi!!");
	return 0;
}

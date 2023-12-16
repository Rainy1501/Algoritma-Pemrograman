/* namaTugas : Tugas ke 4
   namaProgrammer : Fattan Naufan Islami / 23343037
   kasus program : Menghitung nilai Faktorial dari bilangan n
*/

#include <stdio.h>

int main() {
    char ulangi;
    int angka;
    
    do {
        int hasil = 1;
        printf("Menghitung nilai Faktorial\n");
        printf("---------------------------\n");
        
        lompat:
        printf("Masukkan bilangan bulat positif: ");
        scanf("%i", &angka);	

        if (angka == 0) {
            printf("Hasil dari nilai faktorial %i! ialah 1\n", angka);
        } else if (angka < 0) {
            printf("Tidak bisa dilakukan faktorial untuk bilangan negatif\n\n");
            goto lompat;
        } else {
            for (int i = 1; i <= angka; ++i) {
                hasil *= i;
            }
            printf("Hasil dari nilai faktorial %i! ialah %i\n", angka, hasil);
        }

        printf("Apakah Anda ingin mengulang? (Y/N)\n");
        scanf(" %c", &ulangi);

    } while (ulangi == 'Y' || ulangi == 'y');

    printf("-------------------------");
	printf("\n Sampai bertemu lagi!!");
	return 0;
}

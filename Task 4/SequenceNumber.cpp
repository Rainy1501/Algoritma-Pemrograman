/* namaTugas : Tugas ke 4
   namaProgrammer : Fattan Naufan Islami / 23343037
   kasus program : Membuat deret bilangan sebanyak suku yang diinginkan
*/

#include <stdio.h>

int main() {
    char ulangi;
    int angka, angkautama;

    printf("Membuat deret bilangan sebanyak suku yang diinginkan\n");
    printf("-----------------------------------------------------\n");

    do {
        printf("Masukkan suku bilangan : ");
        scanf("%i", &angka);

        printf("\n");

        if (angka == 0) {
            printf("Deret Bilangannya ialah : \n");
            printf("Hasil dari nilai faktorial 0! ialah 1\n");
        } else if (angka < 0) {
            printf("Tidak bisa dilakukan faktorial untuk bilangan negatif\n\n");
        } 
		else 
		{
            angkautama = 1;
            printf("Deret Bilangannya ialah : \n");
            for (int i = 1; i <= angka; i++) {
                printf("%d ", angkautama);
                angkautama *= 2;
            }
            printf("\n");
        }

        printf("Apakah Anda ingin mengulang? (Y/N)\n");
        scanf(" %c", &ulangi);

    } while (ulangi == 'Y' || ulangi == 'y');

	printf("----------------------------");
    printf("\n Sampai bertemu lagi!!");
    return 0;
}
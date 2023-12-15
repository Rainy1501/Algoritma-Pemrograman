/* namaTugas : Tugas ke 3
   namaProgrammer : Fattan Naufan Islami / 23343037
   kasus program : Menentukan Wujud Air Berdasarkan Suhunya
*/

#include <stdio.h>

int main() {
    char ulangi;
    int suhuair= 2;
    int suhuair= -2;

	do {	
	printf("\tProgram Menentukan wujud air berdasarkan suhunya \n");
	printf("\t------------------------------------------------\n");
	fflush (stdin);
	
	if (suhuair < 0) {
        printf("Wujud air adalah beku.\n");
    } else if (suhuair >= 0 && suhuair <= 100) {
        printf("Wujud air adalah cair.\n");
	} else if (suhuair >= 100) {
		printf("Wujud air adalah gas.\n");
}
 	printf("\nApakah kamu ingin menentukan wujud air lagi? (y/n): ");
 	printf("\n--------------------------------------\n");
    scanf(" %c", &ulangi);  

    } while (ulangi == 'y' || ulangi == 'Y');

    printf("\nSampai bertemu lagi!!");
	return 0;
}

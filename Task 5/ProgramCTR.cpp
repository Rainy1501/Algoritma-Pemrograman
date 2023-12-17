/*
namaTugas : Tugas ke 5
namaProgrammer : Fattan Naufan Islami / 23343037
kasus program : Membuat Program Menghitung Lomba Lari
*/

#include <stdio.h>
#include <string.h>
#define PartisipanMaks 50

const char WaktuStart[] = "07:00:00";

void JudulProgram() {
    printf("\t\t-----------------------------\n");
    printf("\t\tProgram Menghitung Lomba Lari\n");
    printf("\t\t-----------------------------\n\n");
}

int Waktu(const char WaktuFinish[]) {
    int start_hour, start_minute, start_second;
    sscanf(WaktuStart, "%d:%d:%d", &start_hour, &start_minute, &start_second);

    int finish_hour, finish_minute, finish_second;
    sscanf(WaktuFinish, "%d:%d:%d", &finish_hour, &finish_minute, &finish_second);

    int start_seconds = start_hour * 3600 + start_minute * 60 + start_second;
    int finish_seconds = finish_hour * 3600 + finish_minute * 60 + finish_second;

    return finish_seconds - start_seconds;
}

void InputDataPeserta(int *RunnerParticipant, char Name[][50], char RunnerNumber[][60], char WaktuFinish[][20], int *TimeDifference) {
    Pengulangan:
	printf("Berapa peserta yang akan mengikuti lomba lari?\n");
    printf("Jumlah peserta: ");
    scanf("%i", RunnerParticipant);

    if (*RunnerParticipant > PartisipanMaks) {
        printf("Nomor partisipan maksimal sudah tercapai, inisiasi pengulangan program...\n\n");
        goto Pengulangan;
    }

    for (int i = 0; i < *RunnerParticipant; i++) {
        printf("\nMasukkan nama dari Pelari %d: ", i + 1);
        scanf(" %[^\n]s", Name[i]);

        printf("Masukkan nomor baju pelari %d: ", i + 1);
        scanf("%s", RunnerNumber[i]);

        printf("Masukkan waktu finish pelari %d [JJ:MM:DD]: ", i + 1);
        scanf("%s", WaktuFinish[i]);
        
        printf("\n");

        TimeDifference[i] = Waktu(WaktuFinish[i]);
    }
}

void PapanPeringkat(int RunnerParticipant, char Name[][50], char RunnerNumber[][60], char WaktuFinish[][20], int TimeDifference[]) {
    for (int i = 0; i < RunnerParticipant - 1; i++) {
        for (int j = i + 1; j < RunnerParticipant; j++) {
            if (TimeDifference[i] > TimeDifference[j]) {
            	
                int tempDiff = TimeDifference[i];
                TimeDifference[i] = TimeDifference[j];
                TimeDifference[j] = tempDiff;

                char tempName[50];
                strcpy(tempName, Name[i]);
                strcpy(Name[i], Name[j]);
                strcpy(Name[j], tempName);

                char tempNumber[60];
                strcpy(tempNumber, RunnerNumber[i]);
                strcpy(RunnerNumber[i], RunnerNumber[j]);
                strcpy(RunnerNumber[j], tempNumber);

                char tempFinish[20];
                strcpy(tempFinish, WaktuFinish[i]);
                strcpy(WaktuFinish[i], WaktuFinish[j]);
                strcpy(WaktuFinish[j], tempFinish);
            }
        }
    }

    printf("\nPapan Peringkat:\n\n");
    printf("%-9s %-20s %-12s %-12s %-12s\n", "Peringkat", "Nama", "No Peserta", "Waktu Finish", "Waktu Selisih");

    for (int i = 0; i < RunnerParticipant; i++) {
        printf("%-9d %-20s %-12s %-12s %d\n", i + 1, Name[i], RunnerNumber[i], WaktuFinish[i], TimeDifference[i]);
    }
}

int main() {
    char nama[PartisipanMaks][50];
    char nomorpeserta[PartisipanMaks][60];
    char WaktuFinish[PartisipanMaks][20];
    int JumlahPartisipasi, WaktuSelisih[PartisipanMaks];

    JudulProgram();
    InputDataPeserta(&JumlahPartisipasi, nama, nomorpeserta, WaktuFinish, WaktuSelisih);
    PapanPeringkat(JumlahPartisipasi, nama, nomorpeserta, WaktuFinish, WaktuSelisih);

    return 0;
}

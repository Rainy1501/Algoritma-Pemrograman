/*
    namaTugas : Tugas ke 7
    namaProgrammer : Fattan Naufan Islami / 23343037
    kasus program : Membuat Pembangunan Struktur Menu Pohon
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Maksimalhuruf 50

struct NodeMenu {
    char* nama;
    struct NodeMenu** submenu;
    int jumlah_submenu;
    int IMenu;
};

struct NodeMenu* buatNodeMenu(const char* nama, int jumlah_submenu, int IMenu) {
    struct NodeMenu* nodeBaru = (struct NodeMenu*)malloc(sizeof(struct NodeMenu));
    nodeBaru->nama = strdup(nama);
    nodeBaru->jumlah_submenu = jumlah_submenu;
    nodeBaru->IMenu = IMenu;

    nodeBaru->submenu = (struct NodeMenu**)malloc(jumlah_submenu * sizeof(struct NodeMenu*));
    for (int i = 0; i < jumlah_submenu; ++i) {
        nodeBaru->submenu[i] = NULL;
    }

    return nodeBaru;
}

void Judul() {    

printf("      ___               __   __        __      \n"); 
printf("|\\/| |__  |\\ | |  |    |__) /  \\ |__| /  \\ |\\ |\n"); 
printf("|  | |___ | \\| \\__/    |    \\__/ |  | \\__/ | \\|\n"); 
printf("-----------------------------------------------\n");
printf("\n");
}

void buatMenu(struct NodeMenu* root, int kedalaman) {
    if (kedalaman <= 0) {
        return;
    }

    for (int i = 0; i < root->jumlah_submenu; ++i) {
        char nama[Maksimalhuruf];
        printf("Masukkan nama submenu %d: ", i + 1);
        fgets(nama, sizeof(nama), stdin);
        nama[strcspn(nama, "\n")] = '\0'; 

        int jumlah_submenu;
        printf("Masukkan jumlah submenu untuk %s: ", nama);
        scanf("%d", &jumlah_submenu);
        getchar(); 

        root->submenu[i] = buatNodeMenu(nama, jumlah_submenu, 0); 
        buatMenu(root->submenu[i], jumlah_submenu);
    }
}

void tampilMenu(struct NodeMenu* root, int kedalaman) {
    if (root == NULL || kedalaman < 0) {
        return;
    }

    for (int i = 0; i < kedalaman; ++i) {
        printf("\t"); 
    }
    printf("%s\n", root->nama); 

    for (int i = 0; i < root->jumlah_submenu; ++i) {
        tampilMenu(root->submenu[i], kedalaman + 1);
    }
}

void bersihkanMenu(struct NodeMenu* root) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < root->jumlah_submenu; ++i) {
        bersihkanMenu(root->submenu[i]);
    }

    free(root->submenu);
    free(root->nama);
    free(root);
}

int main() {
    int jumlahSubmenuRoot;
    char repeat;

    Judul();
    do {
        printf("Masukkan jumlah submenu root: ");
        scanf("%d", &jumlahSubmenuRoot);
        getchar(); 

        char namaRoot[Maksimalhuruf] = "Menu Utama";

        struct NodeMenu* root = buatNodeMenu(namaRoot, jumlahSubmenuRoot, 1); 
        buatMenu(root, jumlahSubmenuRoot);

        printf("\nPohon Menu:\n");
        tampilMenu(root, 0); 

        bersihkanMenu(root);

        printf("Apakah Anda ingin membuat submenu lagi? (Y/N): ");
        scanf(" %c", &repeat); 
        printf("\n");

        while (getchar() != '\n');
    } while (repeat == 'y' || repeat == 'Y');

    printf("Inisialisasi pengeluaran program...\n");
    return 0;
}

#include <stdio.h>
#include <string.h>

//302250008 - Anandiaz Indra Putra

struct Karyawan {
    char nama[50];
    char golongan;
    char status[20];
    int gajiPokok;
    int tunjangan;
    int potongan;
    int gajiBersih;
};

struct Karyawan data[100];
int jumlah = 0;

int hitungGajiPokok(char gol) {
    if (gol == 'A') return 200000;
    if (gol == 'B') return 350000;
    return 0;
}

int hitungTunjangan(char gol, char status[]) {
    if (gol == 'A') return (strcmp(status, "Nikah") == 0) ? 50000 : 25000;
    if (gol == 'B') return (strcmp(status, "Nikah") == 0) ? 75000 : 60000;
    return 0;
}

void inputData() {
    struct Karyawan *k = &data[jumlah];
    int total;

    printf("\nNama Karyawan        : "); scanf(" %[^\n]", k->nama);
    printf("Golongan (A/B)       : "); scanf(" %c", &k->golongan);
    printf("Status (Nikah/Belum) : "); scanf(" %[^\n]", k->status);

    k->gajiPokok = hitungGajiPokok(k->golongan);
    k->tunjangan = hitungTunjangan(k->golongan, k->status);
    total        = k->gajiPokok + k->tunjangan;
    k->potongan  = (k->gajiPokok <= 300000) ? total * 0.05 : total * 0.10;
    k->gajiBersih = total - k->potongan;

    jumlah++;
    printf("\nData berhasil disimpan!\n");
}

void tampilData() {
    if (jumlah == 0) { printf("\nBelum ada data!\n"); return; }

    printf("\n=== DATA GAJI KARYAWAN ===\n");
    for (int i = 0; i < jumlah; i++) {
        printf("\nData ke-%d\n", i + 1);
        printf("Nama Karyawan   : %s\n",    data[i].nama);
        printf("Golongan        : %c\n",    data[i].golongan);
        printf("Status          : %s\n",    data[i].status);
        printf("Gaji Pokok      : Rp.%d\n", data[i].gajiPokok);
        printf("Tunjangan       : Rp.%d\n", data[i].tunjangan);
        printf("Potongan Iuran  : Rp.%d\n", data[i].potongan);
        printf("Gaji Bersih     : Rp.%d\n", data[i].gajiBersih);
    }
}

void cariData() {
    char cari[50];
    int ketemu = 0;

    printf("\nMasukkan nama : "); scanf(" %[^\n]", cari);

    for (int i = 0; i < jumlah; i++) {
        if (strcmp(cari, data[i].nama) == 0) {
            printf("\nNama Karyawan   : %s\n",    data[i].nama);
            printf("Golongan        : %c\n",    data[i].golongan);
            printf("Status          : %s\n",    data[i].status);
            printf("Gaji Bersih     : Rp.%d\n", data[i].gajiBersih);
            ketemu = 1;
        }
    }
    if (!ketemu) printf("\nData tidak ditemukan!\n");
}

int main() {
    int pilih;

    do {
        printf("\n=== PROGRAM GAJI KARYAWAN ===\n");
        printf("1. Input Data\n");
        printf("2. Tampilkan Data\n");
        printf("3. Cari Data\n");
        printf("4. Keluar\n");
        printf("Pilih Menu : "); scanf("%d", &pilih);

        switch (pilih) {
            case 1: inputData();  break;
            case 2: tampilData(); break;
            case 3: cariData();   break;
            case 4: printf("\nProgram selesai.\n"); break;
            default: printf("\nMenu tidak valid!\n");
        }
    } while (pilih != 4);

    return 0;
}
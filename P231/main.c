#include <stdio.h>

struct Student {
    char name[105];
    char nim[20];
    int age;
    char postal[20];
    char birthPlace[105];
    char birthDate[105];
    char highSchool[105];
    int siblings;
    int height;
    char bank[20];
};

int main(){
    int n;
    scanf("%d", &n);

    struct Student s[n];
    for(int i = 0; i < n; i++){
        scanf(" %[^\n]", s[i].name);
        scanf("%s", s[i].nim);
        scanf("%d", &s[i].age);
        scanf("%s", s[i].postal);
        scanf(" %[^\n]", s[i].birthPlace);
        scanf(" %[^\n]", s[i].birthDate);
        scanf(" %[^\n]", s[i].highSchool);
        scanf("%d", &s[i].siblings);
        scanf("%d", &s[i].height);
        scanf("%s", s[i].bank);
    }

    for(int i = 0; i < n; i++){
        printf("Mahasiswa ke-%d:\n", i + 1);
        printf("Nama: %s\n", s[i].name);
        printf("NIM: %s\n", s[i].nim);
        printf("Umur: %d\n", s[i].age);
        printf("Kode Pos: %s\n", s[i].postal);
        printf("Tempat Lahir: %s\n", s[i].birthPlace);
        printf("Tanggal Lahir: %s\n", s[i].birthDate);
        printf("Almamater SMA: %s\n", s[i].highSchool);
        printf("Jumlah Saudara Kandung: %d\n", s[i].siblings);
        printf("Tinggi Badan: %d\n", s[i].height);
        printf("NOMOR REKENING: %s\n", s[i].bank);
    }

    return 0;
}
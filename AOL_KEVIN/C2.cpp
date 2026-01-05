#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5000
#define LINE 1024

typedef struct {
    char name[100];
    char city[100];
    int cost;
    char currency[50];
    int price_range;
    float rating;
    char rating_text[50];
    int votes;
} Restaurant;

Restaurant r[MAX];
int total = 0;


void loadFile() {
    FILE *fp = fopen("restaurant.csv", "r");
    char line[LINE];

    if(fp == NULL) {
        printf("ERROR: restaurant.csv tidak ditemukan!\n");
        return;
    }

    fgets(line, LINE, fp); 

    while(fgets(line, LINE, fp) != NULL) {
        char *token;

        if (total >= LINE) {
            break;
        }

        token = strtok(line, ",");
        if(!token) continue;
        strcpy(r[total].name, token);

        token = strtok(NULL, ",");
        strcpy(r[total].city, token);
        
        token = strtok(NULL, ",");
        r[total].cost = atoi(token);

        token = strtok(NULL, ",");
        strcpy(r[total].currency, token);

        token = strtok(NULL, ",");
        r[total].price_range = atoi(token);

        token = strtok(NULL, ",");
        r[total].rating = atof(token);


        token = strtok(NULL, ",");
        strcpy(r[total].rating_text, token);

        token = strtok(NULL, ",");
        r[total].votes = atoi(token);

        total++;
    }

    fclose(fp);
}


void displayData(int n) {
    if(n > total) n = total;

    for(int i = 0; i < n; i++) {
        printf("\nRestaurant Name : %s", r[i].name);
        printf("\nCity            : %s", r[i].city);
        printf("\nCost for two    : %d", r[i].cost);
        printf("\nCurrency        : %s", r[i].currency);
        printf("\nPrice range     : %d", r[i].price_range);
        printf("\nRating          : %.1f", r[i].rating);
        printf("\nRating text     : %s", r[i].rating_text);
        printf("\nVotes           : %d\n", r[i].votes);
    }
}


void searchData() {
    char key[100];
    int found = 0;

    printf("Input restaurant name: ");
    scanf(" %[^\n]", key);

    for(int i = 0; i < total; i++) {
        if(strcmp(r[i].name, key) == 0) {
            printf("\nRestaurant Name : %s", r[i].name);
            printf("\nCity            : %s", r[i].city);
            printf("\nCost for two    : %d", r[i].cost);
            printf("\nCurrency        : %s", r[i].currency);
            printf("\nPrice range     : %d", r[i].price_range);
            printf("\nRating          : %.1f", r[i].rating);
            printf("\nRating text     : %s", r[i].rating_text);
            printf("\nVotes           : %d\n", r[i].votes);
            found = 1;
        }
    }

    if(!found) {
        printf("Data not found!\n");
    }
}


void sortData() {
    char order[10];

    printf("Sort (asc/desc): ");
    scanf("%s", order);

    for(int i = 0; i < total - 1; i++) {
        for(int j = 0; j < total - i - 1; j++) {
            int cmp = strcmp(r[j].rating_text, r[j+1].rating_text);

            if((strcmp(order, "asc") == 0 && cmp > 0) ||
               (strcmp(order, "desc") == 0 && cmp < 0)) {
                Restaurant temp = r[j];
                r[j] = r[j+1];
                r[j+1] = temp;
            }
        }
    }

    displayData(10);
}


void exportData() {
    char filename[100];
    FILE *fp;

    printf("File name: ");
    scanf("%s", filename);

    strcat(filename, ".csv");
    fp = fopen(filename, "w");

    if(fp == NULL) {
        printf("Gagal membuat file!\n");
        return;
    }

    fprintf(fp, "Restaurant Name,City,Cost for two,Currency,Price range,Rating,Rating text,Votes\n");

    for(int i = 0; i < total; i++) {
        fprintf(fp, "%s,%s,%d,%s,%d,%.1f,%s,%d\n",
            r[i].name,
            r[i].city,
            r[i].cost,
            r[i].currency,
            r[i].price_range,
            r[i].rating,
            r[i].rating_text,
            r[i].votes
        );
    }

    fclose(fp);
    printf("Data berhasil disimpan!\n");
}

/* ================= MAIN ================= */
int main() {
    int menu;

    loadFile();

    do {
        printf("\n=== MENU ===\n");
        printf("1. Display Data\n");
        printf("2. Search Data\n");
        printf("3. Sort Data\n");
        printf("4. Export Data\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &menu);

        if(menu == 1) {
            int n;
            printf("Number of rows: ");
            scanf("%d", &n);
            displayData(n);
        }
        else if(menu == 2) {
            searchData();
        }
        else if(menu == 3) {
            sortData();
        }
        else if(menu == 4) {
            exportData();
        }

    } while(menu != 5);

    return 0;
}
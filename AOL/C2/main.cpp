#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\x1B[31m"
#define RESET "\x1B[0m"
#define MAX_DATA 7369

enum Menu
{
    DISPLAY_MENU = 1,
    SEARCH_MENU = 2,
    SORT_MENU = 3,
    EXPORT_MENU = 4,
    EXIT_MENU = 5,
};

struct Restaurant
{
    char name[50];
    char city[50];
    int cost;
    char currency[50];
    int priceRange;
    char rating[50];
    char ratingText[50];
    int votes;
};

FILE *fp;
int selectedMenu = 0;
Restaurant restaurants[MAX_DATA];
int totalRestaurants = 0;

// function general untuk clear console sesuai OS
void clear()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Saya membuat function untuk load datanya dulu
void loadData()
{
    fp = fopen("restaurant.csv", "r");
    if (fp == NULL)
    {
        printf("File not found\n Please ensure file restaurant.csv is exist.\n");
        exit(1);
    }

    // buang header
    char trash[1000];
    fgets(trash, 1000, fp);

    while (totalRestaurants < MAX_DATA)
    {
        int scanning = fscanf(fp, "%[^,],%[^,],%d,%[^,],%d,%[^,],%[^,],%d\n",
                              restaurants[totalRestaurants].name,
                              restaurants[totalRestaurants].city,
                              &restaurants[totalRestaurants].cost,
                              restaurants[totalRestaurants].currency,
                              &restaurants[totalRestaurants].priceRange,
                              restaurants[totalRestaurants].rating,
                              restaurants[totalRestaurants].ratingText,
                              &restaurants[totalRestaurants].votes);

        if (scanning == EOF)
        {
            break;
        }

        totalRestaurants++;
    }
}

// Function ini akan display data dengan 'n' baris. (a.	Display (15%))
void display()
{
    long long n;

    printf("Number of rows: ");
    printf(RED);
    scanf("%lld", &n);
    printf(RESET);

    printf("\n");
    printf(
        "%-18s %-18s %-15s %-20s %-15s %-10s %-15s %-10s\n",
        "Restaurant name", "City", "Cost for two", "Currency", "Price range", "Rating", "Rating text", "Votes");

    for (int i = 0; i < n; i++)
    {
        printf(
            "%-18.18s %-18s %-15d %-20s %-15d %-10s %-15s %-10d\n",
            restaurants[i].name,
            restaurants[i].city,
            restaurants[i].cost,
            restaurants[i].currency,
            restaurants[i].priceRange,
            restaurants[i].rating,
            restaurants[i].ratingText,
            restaurants[i].votes);
    }
    printf("\n");
}

// Function untuk mencari dari column dan query yang case sensitive (b. Search (20%))
void search()
{
    char column[50];
    char query[150];

    printf("Choose column: ");
    printf(RED);
    getchar();
    scanf("%[^\n]", column);
    getchar();
    printf(RESET);

    printf("What data do you want to find? ");
    printf(RED);
    scanf("%[^\n]", query);
    getchar();
    printf(RESET);

    int found = 0;
    Restaurant datas[totalRestaurants];
    for (int i = 0; i < totalRestaurants; i++)
    {
        int addData = 0;
        if (strcasecmp(column, "restaurant name") == 0)
        {
            if (strstr(restaurants[i].name, query) != NULL)
            {
                addData = 1;
            }
        }
        else if (strcasecmp(column, "city") == 0)
        {
            if (strstr(restaurants[i].city, query) != NULL)
            {
                addData = 1;
            }
        }
        else if (strcasecmp(column, "currency") == 0)
        {
            if (strstr(restaurants[i].currency, query) != NULL)
            {
                addData = 1;
            }
        }
        else if (strcasecmp(column, "rating text") == 0)
        {
            if (strstr(restaurants[i].ratingText, query) != NULL)
            {
                addData = 1;
            }
        }
        else if (strcasecmp(column, "cost for two") == 0)
        {
            int queryCost = atoi(query);

            if (restaurants[i].cost == queryCost)
            {
                addData = 1;
            }
        }
        else if (strcasecmp(column, "price range") == 0)
        {
            int queryCost = atoi(query);

            if (restaurants[i].priceRange == queryCost)
            {
                addData = 1;
            }
        }
        else if (strcasecmp(column, "votes") == 0)
        {
            int queryCost = atoi(query);

            if (restaurants[i].votes == queryCost)
            {
                addData = 1;
            }
        }
        else if (strcmp(column, "rating") == 0)
        {
            if (strstr(restaurants[i].rating, query) != NULL)
            {
                addData = 1;
            }
        }

        if (addData)
        {
            datas[found] = restaurants[i];
            found++;
        }
    }

    printf("\n");
    if (!found)
    {
        printf("Data not found!\n");
        return;
    }

    printf(
        "%-18s %-18s %-15s %-20s %-15s %-10s %-15s %-10s\n",
        "Restaurant name", "City", "Cost for two", "Currency", "Price range", "Rating", "Rating text", "Votes");

    for (int i = 0; i < found; i++)
    {
        printf(
            "%-18.18s %-18s %-15d %-20s %-15d %-10s %-15s %-10d\n",
            datas[i].name,
            datas[i].city,
            datas[i].cost,
            datas[i].currency,
            datas[i].priceRange,
            datas[i].rating,
            datas[i].ratingText,
            datas[i].votes);
    }
    printf("\n");
}

// Function ini untuk sorting (c. Sort (20%))
void sort()
{
    char column[50];
    char query[150];

    printf("Choose column: ");
    printf(RED);
    getchar();
    scanf("%[^\n]", column);
    getchar();
    printf(RESET);

    printf("Sort ascending (asc) or descending (desc)? ");
    printf(RED);
    scanf("%s", query);
    printf(RESET);

    int isAsc = strcasecmp(query, "asc") == 0 ? 1 : -1;
    for (int i = 0; i < totalRestaurants; i++)
    {
        for (int j = 0; j < totalRestaurants - i - 1; j++)
        {
            int shouldSwap = 0;

            if (strcasecmp(column, "restaurant name") == 0)
            {
                if (strcmp(restaurants[j].name, restaurants[j + 1].name) * isAsc > 0)
                {
                    shouldSwap = 1;
                }
            }
            else if (strcasecmp(column, "city") == 0)
            {
                if (strcmp(restaurants[j].city, restaurants[j + 1].city) * isAsc > 0)
                {
                    shouldSwap = 1;
                }
            }
            else if (strcasecmp(column, "currency") == 0)
            {
                if (strcmp(restaurants[j].currency, restaurants[j + 1].currency) * isAsc > 0)
                {
                    shouldSwap = 1;
                }
            }
            else if (strcasecmp(column, "rating text") == 0)
            {
                if (strcmp(restaurants[j].ratingText, restaurants[j + 1].ratingText) * isAsc > 0)
                {
                    shouldSwap = 1;
                }
            }
            else if (strcasecmp(column, "cost for two") == 0)
            {
                if ((restaurants[j].cost - restaurants[j + 1].cost) * isAsc > 0)
                {
                    shouldSwap = 1;
                }
            }
            else if (strcasecmp(column, "price range") == 0)
            {
                if ((restaurants[j].priceRange - restaurants[j + 1].priceRange) * isAsc > 0)
                {
                    shouldSwap = 1;
                }
            }
            else if (strcasecmp(column, "votes") == 0)
            {
                if ((restaurants[j].votes - restaurants[j + 1].votes) * isAsc > 0)
                {
                    shouldSwap = 1;
                }
            }
            else if (strcasecmp(column, "rating") == 0)
            {
                float a = atof(restaurants[j].rating);
                float b = atof(restaurants[j + 1].rating);
                if (isAsc == 1)
                {
                    if (a > b)
                    {
                        shouldSwap = 1;
                    }
                }
                else
                {
                    if (a < b)
                    {
                        shouldSwap = 1;
                    }
                }
            }

            if (shouldSwap)
            {
                struct Restaurant temp = restaurants[j];
                restaurants[j] = restaurants[j + 1];
                restaurants[j + 1] = temp;
            }
        }
    }

    printf("\n");

    printf(
        "%-18s %-18s %-15s %-20s %-15s %-10s %-15s %-10s\n",
        "Restaurant name", "City", "Cost for two", "Currency", "Price range", "Rating", "Rating text", "Votes");

    for (int i = 0; i < 10; i++)
    {
        printf(
            "%-18.18s %-18s %-15d %-20s %-15d %-10s %-15s %-10d\n",
            restaurants[i].name,
            restaurants[i].city,
            restaurants[i].cost,
            restaurants[i].currency,
            restaurants[i].priceRange,
            restaurants[i].rating,
            restaurants[i].ratingText,
            restaurants[i].votes);
    }
    printf("\n");
}

// function untuk export (d. Export (15%))
void exportData()
{
    char filename[150];

    printf("File name: ");
    printf(RED);
    scanf("%s", filename);
    printf(RESET);
    strcat(filename, ".csv");

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("File not found\n Please ensure file restaurant.csv is exist.\n");
        exit(1);
    }

    fprintf(fp, "Restaurant Name,City,Cost for two,Currency,Price range,Rating,Rating text,Votes\n");
    for (int i = 0; i < totalRestaurants; i++)
    {
        fprintf(fp, "%s,%s,%d,%s,%d,%s,%s,%d\n",
                restaurants[i].name,
                restaurants[i].city,
                restaurants[i].cost,
                restaurants[i].currency,
                restaurants[i].priceRange,
                restaurants[i].rating,
                restaurants[i].ratingText,
                restaurants[i].votes);
    }

    fclose(fp);
    printf("Data successfully written to file %s!\n", filename);
}

// Function ini untuk print menu seperti pada contoh soal.
void printMenu()
{
    printf("What do you want to do?\n");
    printf("1. Display data\n");
    printf("2. Search Data\n");
    printf("3. Sort Data\n");
    printf("4. Export Data\n");
    printf("5. Exit\n");
    printf("Your choice: ");

    printf(RED);
    scanf("%d", &selectedMenu);
    printf(RESET);

    switch (selectedMenu)
    {
    case DISPLAY_MENU:
        display();
        break;
    case SEARCH_MENU:
        search();
        break;
    case SORT_MENU:
        sort();
        break;
    case EXPORT_MENU:
        exportData();
        break;
    case EXIT_MENU:
        exit(1);
        break;
    default:
        break;
    }

    char buffer[100];
    printf("\nType 'yes' to continue...\n");
    scanf(" %s", buffer);
    if(strcasecmp(buffer, "yes") != 0){
        exit(1);
    }

    printMenu();
    printf("-----------------------\n");
}

int main()
{
    loadData();
    printMenu();

    return 0;
}

// Copyright aokaokaokaowk
// 2902659922 - Fazril Syaveral Hillaby
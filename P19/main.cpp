#include <stdio.h>
#include <string.h>

struct Product
{
    char name[55];
    int quantity;
};

struct Output
{
    int length;
    Product *products;
};

int isExists(Product *products, int productsCount, char name[55])
{
    for (int i = 0; i < productsCount; i++)
    {
        if (strcmp(products[i].name, name) == 0)
        {
            return i;
        }
    }

    return -1;
}

void assert(Product *product, char status[55], int quantity)
{
    if (strcmp(status, "buy") == 0)
    {
        product->quantity += quantity;
    }
    else if (strcmp(status, "sell") == 0)
    {
        product->quantity -= quantity;
    }
}

int printNotCorrect(Output output){
    int flag = 0;
    for (int i = 0; i < output.length; i++)
    {
        if (output.products[i].quantity < 0)
        {
            flag = 1;
            printf("stock is not enough for product %s\n", output.products[i].name);
        }
    }
    
    return flag;
}

int main()
{
    FILE *file = fopen("testdata.in", "r");
    if (file == NULL)
    {
        return printf("File not found.");
    }

    int t;
    fscanf(file, "%d\n", &t);

    Output outputs[t];
    for (int i = 0; i < t; i++)
    {
        int p;
        fscanf(file, "%d\n", &p);

        outputs[i].length = p;
        outputs[i].products = new Product[p];

        int productCount = 0;
        for (int j = 0; j < p; j++)
        {
            char status[55];
            char name[55];
            int quantity;

            fscanf(file, "%[^#]#%[^#]#%d\n", status, name, &quantity);

            int existsIndex = isExists(outputs[i].products, p, name);
            if (existsIndex == -1)
            {
                strcpy(outputs[i].products[productCount].name, name);
                outputs[i].products[productCount].quantity = 0;

                existsIndex = productCount;
                productCount++;
            }

            assert(&outputs[i].products[existsIndex], status, quantity);
            // printf("%s %d\n", outputs[i].products[existsIndex].name, outputs[i].products[existsIndex].quantity);
        }

        outputs[i].length = productCount;
    }

    for (int i = 0; i < t; i++)
    {
        printf("Case #%d:\n", i + 1);

        int response = printNotCorrect(outputs[i]);
        if (response) continue;
        
        for (int j = 0; j < outputs[i].length; j++)
        {
            printf("%s - %d\n", outputs[i].products[j].name, outputs[i].products[j].quantity);
        }
    }

    return 0;
}
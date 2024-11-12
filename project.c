
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 500

int top1 = -1;
int top2 = -1;

typedef struct
{
    char name[35];
    float price;
    int quantity;
} Item;

typedef struct
{
    char name[35];
    int quantity;
} solditem;

Item stack1[max];
solditem stack2[max];

void waitforuser()
{
    getchar();
    getchar();
    system("cls");
}


void additem()
{
    system("cls");

    if (top1 == max - 1)
    {
        printf("Your inventory is full. . .\n");
        waitforuser();
    }
    else
    {
        Item newitem;
        printf("\t\t\t\t=====================================================\n");
        printf("\t\t\t\t                                                   \n ");
        printf("\t\t\t\t=====          ADD ITEM TO INVENTORY           =====\n");
        printf("\t\t\t\t                                                   \n ");
        printf("\t\t\t\t=====================================================\n");
        printf("\n");
        printf("\t\t\t\tEnter product name: ");
        scanf("%s", newitem.name);
        printf("\n");
        printf("\t\t\t\tEnter Product Price: ");
        scanf("%f", &newitem.price);
        printf("\n");
        printf("\t\t\t\tEnter Product Quantity: ");
        scanf("%d", &newitem.quantity);

        top1++;
        stack1[top1] = newitem;
        printf("\n");
        printf("\t\t\t\t=====================================================\n");
        printf("\n");
        printf("\t\t\t\t%s added to Inventory successfully!\n", newitem.name);
        waitforuser();
    }
}

void deletefrominventory()
{
    system("cls");

    if (top1 == -1)
    {
        printf("Inventory is Empty. . .\n");
        waitforuser();
    }
    else
    {
        char deletename[35];
        printf("\t\t\t\t=====================================================\n");
        printf("\t\t\t\t                                                   \n ");
        printf("\t\t\t\t======              DELETE ITEM               =====\n");
        printf("\t\t\t\t                                                   \n ");
        printf("\t\t\t\t=====================================================\n");
        printf("\n");
        printf("\t\t\t\tEnter product name to delete: ");
        scanf("%s", deletename);
        int found = 0;

        for (int i = 0; i <= top1; i++)
        {
            if (strcmp(stack1[i].name, deletename) == 0)
            {
                found = 1;
                for (int j = i; j < top1; j++)
                {
                    stack1[j] = stack1[j + 1];
                }
                top1--;
                printf("\n");
                printf("\t\t\t\t%s removed from inventory successfully!\n", deletename);
                waitforuser();
                return;
            }
        }
        if (!found)
        {
            printf("\n");
            printf("\t\t\t\t%s Not found in the inventory. . .\n", deletename);
            waitforuser();
        }
    }
}




void sell()
{

    char choice;

    do
    {
        system("cls");
        if(top1 == -1)
        {
            printf("Inventory is empty. . . \n");
        }
        else
        {
            printf("\n");
            printf("\t\t\t\t=====================================================\n");
            printf("\t\t\t\t             METRO STORE LIMITED                         \n");
            printf("\t\t\t\t            3100, Boteshwar, Sylhet                       \n");
            printf("\t\t\t\t                                                   \n ");
            printf("\t\t\t\t                   SELL                           \n");
            printf("\t\t\t\t=====================================================\n");
            solditem product;
            printf("\t\t\t\tEnter Product name: ");
            scanf("%s", product.name);
            int found = 0;

            for(int i=0; i<=top1; i++)
            {
                if(strcmp(stack1[i].name, product.name) == 0)
                {
                    found = 1;
                    printf("\n");
                    printf("\t\t\t\tEnter product quantity: ");
                    scanf("%d", &product.quantity);

                    if(product.quantity <= stack1[i].quantity)
                    {


                        top2++;
                        stack2[top2] = product;
                        stack1[i].quantity -= product.quantity;
                        printf("\t\t\t\t=====================================================\n");
                        printf("\n");
                        printf("\t\t\t\t%s added to cart. . .\n", product.name);
                    }
                    else
                    {
                        printf("\t\t\t\t=====================================================\n");
                        printf("\n");
                        printf("\t\t\t\tNot enough quantity in stock. . .\n");
                    }
                    break;
                }
            }
            if(!found)
            {
                printf("\t\t\t\t=====================================================\n");
                printf("\n");
                printf("\t\t\t\t%s Not found in the inventory. . .\n", product.name);
            }
        }


        printf("\n");
        printf("\t\t\t\tMore Items (Y/N): ");
        getchar();
        scanf("%c", &choice);

    }
    while(choice == 'y' || choice == 'Y');

    waitforuser();
}

void inventory()
{
    system("cls");

    if(top1 == -1)
    {
        printf("Inventory is Empty. . . \n");
        waitforuser();
    }

    else
    {
        printf("\t\t\t\t=================================================================================\n");
        printf("\t\t\t\t                                METRO STORE LIMITED                         \n");
        printf("\t\t\t\t                              3100, Boteshwar, Sylhet                       \n");
        printf("\t\t\t\t                                                                            \n");
        printf("\t\t\t\t                                    INVENTORY                               \n");
        printf("\t\t\t\t                                                                            \n");
        printf("\t\t\t\t=================================================================================\n");
        printf("\t\t\t\t| %-3s | %-15s | %-15s | %-15s |\n", "No", "ITEM NAME", "PRICE", "QUANTITY");
        printf("\t\t\t\t=================================================================================\n");

        for(int i=0; i<=top1; i++)
        {
            printf("\t\t\t\t| %-3d | %-15s | %-15.2f | %-15d |\n", i+1, stack1[i].name, stack1[i].price, stack1[i].quantity);
        }
        printf("\t\t\t\t==================================================================================\n");
    }
    printf("\t\t\t\tPress ENTER to continue. . . ");
    waitforuser();
}


void billing()
{
    system("cls");
    printf("\t\t\t\t=================================================================================\n");
    printf("\t\t\t\t                                METRO STORE LIMITED                         \n");
    printf("\t\t\t\t                              3100, Boteshwar, Sylhet                       \n");
    printf("\t\t\t\t                                                                            \n");
    printf("\t\t\t\t                                    BILLING                                    \n");
    printf("\t\t\t\t                                                                            \n");
    printf("\t\t\t\t=================================================================================\n");
    printf("\t\t\t\t| %-3s | %-15s | %-15s | %-15s | %-15s |\n", "No", "ITEM NAME", "PRICE", "QUANTITY","SUBTOTAL");
    printf("\t\t\t\t=================================================================================\n");
    int found = 0;
    float cost = 0.0;
    float total = 0.0;

    for(int i=0; i<=top2; i++)
    {
        float price = 0.0;
        for(int j=0; j<=top1; j++)
        {
            if(strcmp(stack1[j].name,stack2[i].name) == 0)
            {
                found =1;
                price = stack1[j].price;
                break;
            }

        }
        cost = stack2[i].quantity * price;
        total +=cost;
        printf("\t\t\t\t| %-3d | %-15s | %-15.2f | %-15d | %-15.2f |\n", i+1, stack2[i].name, price, stack2[i].quantity, cost);

    }

    printf("\t\t\t\t=================================================================================\n");
    printf("\t\t\t\t%-15s | %-15.2f ","TOTAL AMOUNT:",total);
    waitforuser();

    char ch;
    printf("Delete all item from cart(Y/N): ");
    scanf("%c",&ch);

    if(ch == 'y' || ch == 'Y')
    {
       deleteallitemfromcart();
       waitforuser(); 
    }
    else
    {
        return;
        waitforuser();
    }

    

}

void cart()
{
    system("cls");
    printf("\t\t\t\t=================================================================================\n");
    printf("\t\t\t\t                                METRO STORE LIMITED                         \n");
    printf("\t\t\t\t                              3100, Boteshwar, Sylhet                       \n");
    printf("\t\t\t\t                                                                            \n");
    printf("\t\t\t\t                                    CART                                    \n");
    printf("\t\t\t\t                                                                            \n");
    printf("\t\t\t\t=================================================================================\n");
    printf("\t\t\t\t|%-3s | %-15s | %-15s | %-15s | %-15s |\n", "No", "ITEM NAME", "PRICE", "QUANTITY","SUBTOTAL");
    printf("\t\t\t\t=================================================================================\n");
    int found = 0;
    float cost = 0.0;

    for(int i=0; i<=top2; i++)
    {
        float price = 0.0;
        for(int j=0; j<=top1; j++)
        {
            if(strcmp(stack1[j].name,stack2[i].name) == 0)
            {
                found =1;
                price = stack1[j].price;
                break;
            }

        }
        cost = stack2[i].quantity * price;
        printf("\t\t\t\t| %-3d | %-15s | %-15.2f | %-15d | %-15.2f |\n", i+1, stack2[i].name, price, stack2[i].quantity, cost);

    }

    printf("\t\t\t\t=================================================================================\n");


    char ch;
    getchar();
    printf("\t\t\t\tGO TO BILLING(Y/N): ");
    scanf("%c",&ch);

    if(ch == 'y' || ch == 'Y')
    {
        billing();
    }
    waitforuser();

}


void deletefromcart()
{
    system("cls");
    if(top2 == -1)
    {
        printf("\t\t\t\t=================================================================================\n");
        printf("\t\t\t\t                                METRO STORE LIMITED                         \n");
        printf("\t\t\t\t                              3100, Boteshwar, Sylhet                       \n");
        printf("\t\t\t\t                                                                            \n");
        printf("\t\t\t\t                                    DELETE ITEM                                    \n");
        printf("\t\t\t\t=================================================================================\n");
        printf("\t\t\t\t                                                                            \n");
        printf("\t\t\t\tCart is Empty. Sell some Item first. . .                                    \n");
        waitforuser();
    }
    else
    {
        char deletefromcartname[35];
        printf("\n");
        printf("\t\t\t\t=================================================================================\n");
        printf("\t\t\t\t                                METRO STORE LIMITED                         \n");
        printf("\t\t\t\t                              3100, Boteshwar, Sylhet                       \n");
        printf("\t\t\t\t                                                                            \n");
        printf("\t\t\t\t                                    DELETE ITEM                                    \n");
        printf("\t\t\t\t=================================================================================\n");
        printf("\n");
        printf("Enter Product name to Delete: ");
        scanf("%s", deletefromcartname);

        int found = 0;
        for(int i=0; i<=top2; i++)
        {
            if(strcmp(deletefromcartname,stack2[i].name) == 0)
            {
                found = 1;

                for (int j = 0; j <= top1; j++)
                {
                    if (strcmp(stack1[j].name, deletefromcartname) == 0)
                    {
                        stack1[j].quantity += stack2[i].quantity;
                        break;
                    }
                }
                for(int j=i; j<=top2; j++)
                {
                    stack2[j] = stack2[j+1];
                }
                top2--;
                printf("\n");
                printf("\t\t\t\t%s deleted from cart successfully. . .\n",deletefromcartname);
                printf("\t\t\t\t=================================================================================\n");
                waitforuser();
                break;

            }
        }
        if(!found)
        {
            printf("\n");
            printf("\t\t\t\t%s not found in the inventory. . .\n",deletefromcartname);
            printf("\t\t\t\t=================================================================================\n");
            waitforuser();
        }
    }

}


void restock()
{
    system("cls");
    if(top1 == -1)
    {
        printf("\n");
        printf("\t\t\t\t=================================================================================\n");
        printf("\t\t\t\t                                METRO STORE LIMITED                         \n");
        printf("\t\t\t\t                              3100, Boteshwar, Sylhet                       \n");
        printf("\t\t\t\t                                                                            \n");
        printf("\t\t\t\t                                    RESTOCK ITEM                                    \n");
        printf("\t\t\t\t=================================================================================\n");
        printf("\t\t\t\tInventory is Empty. . . \n");
        waitforuser();
    }
    else
    {
        printf("\n");
        printf("\t\t\t\t=================================================================================\n");
        printf("\t\t\t\t                                METRO STORE LIMITED                         \n");
        printf("\t\t\t\t                              3100, Boteshwar, Sylhet                       \n");
        printf("\t\t\t\t                                                                            \n");
        printf("\t\t\t\t                                    RESTOCK ITEM                                    \n");
        printf("\t\t\t\t=================================================================================\n");
        char stockitemname[35];
        printf("\t\t\t\tEnter Product name to Restock: ");

        scanf("%s", stockitemname);
        int stockitemquantity;

        int found = 0;
        for(int i=0; i<=top1; i++)
        {
            if(strcmp(stockitemname, stack1[i].name) == 0)
            {
                found = 1;
                printf("\n");
                printf("\t\t\t\tEnter quantity: ");
                scanf("%d",&stockitemquantity);

                stack1[i].quantity += stockitemquantity;
                printf("\n");
                printf("\t\t\t\t=================================================================================\n");
                printf("\n");
                printf("\t\t\t\t%d Unit added to %s.\n\t\t\t\t New Quantity: %d",stockitemquantity,stack1[i].name, stack1[i].quantity);

                waitforuser();
                break;
            }
        }
        if(!found)
        {
            printf("\n");
            printf("\t\t\t\t=================================================================================\n");
            printf("\t\t\t\t%s Not found in the INVENTORY. . . \n",stockitemname);
            waitforuser();
        }
    }
}

void storename()
{
    printf("\n");
    printf("\t\t\t\t===========================================\n");
    printf("\t\t\t\t                                       \n ");
    printf("\t\t\t\t          METRO STORE LIMITED         \n");
    printf("\t\t\t\t        3100, Boteshwar, Sylhet        \n");
    printf("\t\t\t\t                                       \n ");
    printf("\t\t\t\t===========================================\n");
}




void shopOwnerMenu()
{
    system("cls");
    int choice;
    do
    {
        printf("\n");
        printf("\t\t\t\t==========================================================\n");
        printf("\t\t\t\t                                                          \n ");
        printf("\t\t\t\t                 Shop Owner Operations                    \n");
        printf("\t\t\t\t                                                          \n ");
        printf("\t\t\t\t                  METRO STORE LIMITED                     \n");
        printf("\t\t\t\t                3100, Boteshwar, Sylhet                   \n");
        printf("\t\t\t\t                                                          \n ");
        printf("\t\t\t\t==========================================================\n");
        printf("\t\t\t\t||        1. ADD ITEM                                  || \n");
        printf("\t\t\t\t||                                                     || \n ");
        printf("\t\t\t\t||        2. VIEW INVENTORY                            || \n");
        printf("\t\t\t\t||                                                     || \n ");
        printf("\t\t\t\t||        3. DELETE ITEM(from inventory)               || \n");
        printf("\t\t\t\t||                                                     || \n ");
        printf("\t\t\t\t||        4. RESTOCK ITEM                              || \n");
        printf("\t\t\t\t||                                                     || \n ");
        printf("\t\t\t\t||        0. Back to Main Menu                         || \n");
        printf("\t\t\t\t==========================================================\n");
        printf("\n");
        printf("\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            additem();
            break;
        case 2:
            inventory();
            break;
        case 3:
            deletefrominventory();
            break;
        case 4:
            restock();
            break;
        case 0:
            system("cls");
            return;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    while (choice != 0);
}

void deleteallitemfromcart()
{
    system("cls");
    if(top2 == -1)
    {
        printf("\n");
        printf("\t\t\t\t===========================================\n");
        printf("\t\t\t\t                                       \n ");
        printf("\t\t\t\t          METRO STORE LIMITED         \n");
        printf("\t\t\t\t        3100, Boteshwar, Sylhet        \n");
        printf("\t\t\t\t                                       \n ");
        printf("\t\t\t\t===========================================\n");
        printf("\n");
        printf("\t\t\t\tCart Is Empty. . .\n");
        waitforuser();
    }

    else
    {
        printf("\n");
        printf("\t\t\t\t===========================================\n");
        printf("\t\t\t\t                                       \n ");
        printf("\t\t\t\t          METRO STORE LIMITED         \n");
        printf("\t\t\t\t        3100, Boteshwar, Sylhet        \n");
        printf("\t\t\t\t                                       \n ");
        printf("\t\t\t\t===========================================\n");
        top2 = -1;
        printf("\n");
        printf("\t\t\t\tCart is clear. . . \n");
        printf("\n");
        printf("\t\t\t\t===========================================\n");
    }
}

void sellingMenu()
{
    system("cls");
    int choice;
    do
    {
        printf("\t\t\t\t==========================================================\n");
        printf("\t\t\t\t                                                          \n ");
        printf("\t\t\t\t                  METRO STORE LIMITED                     \n");
        printf("\t\t\t\t                3100, Boteshwar, Sylhet                   \n");
        printf("\t\t\t\t                                                          \n ");
        printf("\t\t\t\t                 SELLING OPERATIONS                       \n");
        printf("\t\t\t\t                                                          \n ");
        printf("\t\t\t\t==========================================================\n");
        printf("\t\t\t\t||                                                      ||\n ");
        printf("\t\t\t\t||        1. SELL ITEM                                  ||\n");
        printf("\t\t\t\t||                                                      ||\n ");
        printf("\t\t\t\t||        2. VIEW CART                                  ||\n");
        printf("\t\t\t\t||                                                      ||\n ");
        printf("\t\t\t\t||        3. DELETE ITEM(from Cart)                     ||\n");
        printf("\t\t\t\t||                                                      ||\n ");
        printf("\t\t\t\t||        4. BILLING                                    ||\n");
        printf("\t\t\t\t||                                                      ||\n ");
        //printf("\t\t\t\t||        4. REMOVE ALL ITEM(from cart)                 ||\n");
        //printf("\t\t\t\t||                                                      ||\n ");
        printf("\t\t\t\t||        0. BACK TO MAIN MENU                          ||\n");
        printf("\t\t\t\t||                                                      ||\n ");
        printf("\t\t\t\t==========================================================\n");
        printf("\n");
        printf("\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            sell();
            break;
        case 2:
            cart();
            break;
        case 3:
            deletefromcart();
            break;
        case 4:
            billing();
            break;
        case 0:
            system("cls");
            return;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    while (choice != 0);
}

int main()
{
    system("cls");
    int choice;
    do
    {
        storename();
        //printf("\t\t\t\t===========================================\n");
        printf("\t\t\t\t||                                       ||\n ");
        printf("\t\t\t\t||   1. Shop Owner Operations            ||\n");
        printf("\t\t\t\t||                                       ||\n");
        printf("\t\t\t\t||   2. Selling Operations               ||\n");
        printf("\t\t\t\t||                                       ||\n");
        printf("\t\t\t\t||   0. Exit                             ||\n");
        printf("\t\t\t\t||                                       ||\n ");
        printf("\t\t\t\t===========================================\n");
        printf("\n");
        printf("\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            shopOwnerMenu();
            break;
        case 2:
            sellingMenu();
            break;
        case 0:
            printf("\t\t\t\tExiting...\n");
            break;
        default:
            printf("\t\t\t\tInvalid choice. Try again.\n");
        }
    }
    while (choice != 0);
    return 0;
}

// function to insert node to the Bill-list
struct BillNode *insertBNode(char name2[20], float price2, float quantity1, struct BillNode *answer1)
{
    struct BillNode *newnode, *temp, *tail;
    newnode = (struct BillNode *)malloc(sizeof(struct BillNode));
    strcpy(newnode->name, name2);
    newnode->price = price2;
    newnode->quantity = quantity1;
    newnode->next = 0;

    if (temp == 0)
    {
        answer1 = tail = newnode;
    }
    else
    {
        newnode->next = answer1;
        answer1 = newnode;
    }
    return answer1;
}

// function to display item list & let user add items to the bill list
struct BillNode *displayNselect(struct ItemNode *temp, struct BillNode *answer1)
{
    int ind;
    float quant, price;
    char name[20];
    displayList(temp);
    printf("\nSelect the item index number that you want to purchase: ");
    scanf("%d", &ind);

    struct ItemNode *temp2, *head;
    int i, count = 0;
    head = temp2 = temp;
    while (temp2 != 0)
    {
        count = count + 1;
        temp2 = temp2->next;
    }
    temp2 = temp;
    if (ind <= 0 || ind > count)
    {
        printf("\nInvalid choice!\n");
        head = temp;
    }
    else if (ind == 1)
    {
        temp2 = temp;

        printf("\nEnter the quantity for [%s] in KGs: ", temp2->name);
        scanf("%f", &quant);
        strcpy(name, temp2->name);
        price = temp2->price;

        answer1 = insertBNode(name, price, quant, answer1);
    }
    else
    {
        for (i = 1; i < ind; i++)
        {
            temp2 = temp->next;
            temp = temp->next;
        }
        printf("\nEnter the quantity for [%s] in KGs: ", temp2->name);
        scanf("%f", &quant);
        strcpy(name, temp2->name);
        price = temp2->price;

        answer1 = insertBNode(name, price, quant, answer1);
    }

    return answer1;
}
// function to display Bill list
void displayBList(struct BillNode *temp)
{
    int i = 1;
    if (temp == 0)
    {
        printf("\nNo item!\n");
    }
    else
    {
        while (temp != 0)
        {

            int j, l = strlen(temp->name);
            printf("%d) %s", i, temp->name);
            for (j = l; j < 30; j++)
            {
                printf(" ");
            }
            printf("%.2f                    %.2f\n", temp->quantity, temp->price);

            temp = temp->next;
            i++;
        }
    }
}

// function to get grand total cost from vegetable and fruit bill list
float addition(struct BillNode *veg, struct BillNode *frut)
{
    float Vsum = 0, Fsum = 0, Gsum = 0;
    if (veg == 0)
    {
        Vsum = 0;
    }
    else
    {
        while (veg != 0)
        {
            Vsum = Vsum + (veg->price) * (veg->quantity);
            veg = veg->next;
        }
    }

    if (frut == 0)
    {
        Fsum = 0;
    }
    else
    {
        while (frut != 0)
        {
            Fsum = Fsum + (frut->price) * (frut->quantity);
            frut = frut->next;
        }
    }
    Gsum = Vsum + Fsum;
    return Gsum;
}

// function to make a bill for the user
void billMaker(struct BillNode *veg, struct BillNode *frut)
{
    float ans;
    char name[20], date[10];
    printf("\nKindly enter your name: ");
    scanf(" %[^\n]s", name);
    printf("\nKindly enter today's date(DD/MM/YY): ");
    scanf(" %[^\n]s", date);

    system("cls");
    printf("\nYour Bill:-");
    printf("\n____________________________________________________________________\n");
    printf("\t\tFERNANDES HORTICULTURE ASSOCIATION\n");
    printf("--------------------------------------------------------------------\n");
    printf("\t\t\t    BILL RECEIPT\n");
    printf("--------------------------------------------------------------------\n");
    printf("Customer name: %s\n", name);
    printf("Date: %s\n", date);
    printf("\n\t\t   ########## VEGETABLES ##########\n");
    printf("--------------------------------------------------------------------\n");
    printf("   ITEMS\t\t\tQUANTITY(in KGs)\tPRICE(Rs./KG)\n");
    printf("--------------------------------------------------------------------\n");
    displayBList(veg);
    printf("\n");
    printf("\n\t\t   ############ FRUITS ############\n");
    printf("--------------------------------------------------------------------\n");
    printf("   ITEMS\t\t\tQUANTITY(in KGs)\tPRICE(Rs./KG)\n");
    printf("--------------------------------------------------------------------\n");
    displayBList(frut);
    ans = addition(veg, frut);
    printf("--------------------------------------------------------------------\n");
    printf("Total:\t\t\t\t\t\t     Rs. %.2f/-\n", ans);
    printf("--------------------------------------------------------------------\n");
    printf("\n\t\t   Thank You & Visit Again :) \n");
    printf("____________________________________________________________________\n");
}
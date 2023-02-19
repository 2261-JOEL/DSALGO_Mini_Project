// head pointers for the Item-list and Bill-list respectively for vegetables and fruits
struct ItemNode *Vresult;
struct ItemNode *Fresult;
struct BillNode *VBresult;
struct BillNode *FBresult;

struct ItemNode // user defined structure for Item-list
{
    char name[20];
    float price;
    struct ItemNode *next;
};

struct BillNode // user defined structure for Bill-list
{
    char name[20];
    float price;
    float quantity;
    struct BillNode *next;
};
// function to add items to the Item-list
struct ItemNode *insertNode(char name1[20], float price1, struct ItemNode *answer)
{
    struct ItemNode *newnode, *head, *tail;                       // pointers of the struct ItemNode type
    newnode = (struct ItemNode *)malloc(sizeof(struct ItemNode)); // dynamic memory allocation to the node
    strcpy(newnode->name, name1);
    newnode->price = price1;
    newnode->next = 0;

    if (answer == 0)
    {
        answer = tail = newnode;
    }
    else
    {
        newnode->next = answer;
        answer = newnode;
    }
    return answer;
}

void displayList(struct ItemNode *temp) // function to to display item list (used for both vegetables & fruits)
{
    int i = 1;
    if (temp == 0)
    {
        printf("\nList is empty!\n");
    }
    else
    {
        while (temp != 0)
        {
            int j, l = strlen(temp->name);
            printf("%d) %s", i, temp->name);
            for (j = l; j < 50; j++)
            {
                printf("-");
            }
            printf("%.2f\n", temp->price);

            temp = temp->next;
            i++;
        }
    }
}

struct ItemNode *deleteNode(struct ItemNode *temp) // function to delete a node from the item-list
{
    struct ItemNode *temp2, *temp3, *head;
    int i, count = 0, choice;
    head = temp2 = temp;
    while (temp2 != 0)
    {
        count = count + 1;
        temp2 = temp2->next;
    }
    displayList(temp);
    printf("\nSelect the item index number that you want to remove: ");
    scanf("%d", &choice);
    if (choice <= 0 || choice > count)
    {
        printf("\nInvalid choice!\n");
        head = temp;
        return head;
    }
    else if (choice == 1)
    {
        temp2 = temp;
        head = temp->next;
        free(temp2);
        return head;
    }
    else
    {
        temp2 = temp;
        for (i = 1; i < choice - 1; i++)
        {
            temp2 = temp->next;
            temp = temp->next;
        }
        temp3 = temp2;
        temp3 = temp2->next;
        temp2->next = temp3->next;
        free(temp3);
        return head;
    }
}

void preVegData() // function to add pre-vegetable data to the vegetable list
{
    Vresult = insertNode("Cabbage", 27, Vresult);
    Vresult = insertNode("Carrot", 30, Vresult);
    Vresult = insertNode("Cauliflower", 27, Vresult);
    Vresult = insertNode("Cucumber", 22, Vresult);
    Vresult = insertNode("Onion", 30, Vresult);
    Vresult = insertNode("Potato", 28, Vresult);
    Vresult = insertNode("Tomato", 15, Vresult);
    Vresult = insertNode("Eggplant", 24, Vresult);
}
void preFruitData() // function to add pre-fruit data to the fruit list
{
    Fresult = insertNode("Mango", 110, Fresult);
    Fresult = insertNode("Avocado", 230, Fresult);
    Fresult = insertNode("Custard Apple", 62, Fresult);
    Fresult = insertNode("Banana", 43, Fresult);
    Fresult = insertNode("Guava", 47, Fresult);
    Fresult = insertNode("Grapes", 73, Fresult);
    Fresult = insertNode("Jackfruit", 100, Fresult);
    Fresult = insertNode("Orange", 43, Fresult);
}

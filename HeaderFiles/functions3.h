int printCustSect() //function to print the customer section menu and return the user's choice
{
    int choice;
    printf("\n _________________________________");
    printf("\n|                                 |\n");
    printf("|         CUSTOMER SECTION        |\n");
    printf("|_________________________________|\n");
    printf("| 1) Vegetable List               |\n");
    printf("| 2) Fruit List                   |\n");
    printf("| 3) Buy Items                    |\n");
    printf("| 4) Generate Bill                |\n");
    printf("| 5) Main Menu                    |\n");
    printf("|_________________________________|\n");
    printf("\nYour choice: ");
    scanf("%d", &choice);
    return choice;
}

int printOwnSect() //function to print the owner section menu and return the user's choice
{
    int choice;
    printf("\n _________________________________");
    printf("\n|                                 |\n");
    printf("|         OWNER SECTION\t          |\n");
    printf("|_________________________________|\n");
    printf("| 1) Vegetable List               |\n");
    printf("| 2) Fruit List                   |\n");
    printf("| 3) Add items                    |\n");
    printf("| 4) Delete items                 |\n");
    printf("| 5) Main Menu                    |\n");
    printf("|_________________________________|\n");
    printf("\nYour choice: ");
    scanf("%d", &choice);
    return choice;
}
int printMainMenu() //function to print the Main menu and return the user's choice
{
    int choice;
    printf("\n _________________________________");
    printf("\n|                                 |\n");
    printf("|    VEGETABLE SHOP MANAGEMENT    |\n");
    printf("|_________________________________|\n");
    printf("|                                 |\n");
    printf("| 1) OWNER SECTION                |\n");
    printf("| 2) CUSTOMER SECTION             |\n");
    printf("| 3) EXIT THE SHOP                |\n");
    printf("|_________________________________|\n");
    printf("\nYour choice: ");
    scanf("%d", &choice);
    return choice;
}

// included 4 pre-defined header files and 3 user-defined header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "functions1.h" //contains most of functions related to the Item-Node
#include "functions2.h" //contains most of functions related to the Bill-Node
#include "functions3.h" //contains lists printing functions (Menu, owner and customer section)

void main() // main function that gets executed during program execution
{
    // initialized all the head nodes to null
    Vresult = 0;
    Fresult = 0;
    VBresult = 0;
    FBresult = 0;
    preVegData();   // Creates vegetable items pre-list
    preFruitData(); // Creates fruit items pre-list

    char name[20], uname[20], pass[20];
    float price;
    int t0 = 1, ch0, ch1, ch2, t1, t2, t3, addChoice, remChoice, purChoice;
    // main two switch cases are used for Owner section and Customer section

    while (t0)
    {
        ch0 = printMainMenu(); // takes choice input from the menu list from the user
        switch (ch0)
        {
        case 1:
            t1 = 1;
            while (t1)
            { // below code segment is used for login purpose in the owner section
                printf("\nEnter Owner's Name: ");
                scanf(" %[^\n]s", uname);
                printf("Enter Pass: ");
                scanf(" %[^\n]s", pass);
                if (strcmp(uname, "Joel") == 0 && strcmp(pass, "12345") == 0) // checks for validity of the input
                {
                    printf("\nLogin Successful!\n");
                    t3 = 1;
                    while (t3)
                    {
                        ch1 = printOwnSect(); // takes choice input from the owner section list from the user(owner)
                        switch (ch1)
                        {
                        case 1: // displays vegetable list to the user
                            printf("\n------------------------------------------------------------\n");
                            printf("   VEGETABLE\t\t\t\t\tPRICE(Rs./KG)\n");
                            printf("------------------------------------------------------------\n");
                            displayList(Vresult);
                            break;
                        case 2: // displays fruit list to the user
                            printf("\n------------------------------------------------------------\n");
                            printf("   FRUIT\t\t\t\t\tPRICE(Rs./KG)\n");
                            printf("------------------------------------------------------------\n");
                            displayList(Fresult);
                            break;
                        case 3: // takes choice input from the owner whether to choose vegetable or fruit list
                            printf("\nSelect the list to which item is to be added:-\n");
                            printf("1) Vegetable list\n2) Fruit list\n");
                            printf("\nYour choice: ");
                            scanf("%d", &addChoice);
                            if (addChoice == 1)
                            { // takes name and the price of the vegetable from the owner
                                printf("\nEnter name: ");
                                scanf(" %[^\n]s", name);
                                printf("Enter price(in Rs.): ");
                                scanf("%f", &price);
                                Vresult = insertNode(name, price, Vresult);
                                printf("\n%s added to the list successfully!\n", name);
                            }
                            else if (addChoice == 2)
                            { // takes name and the price of the fruit from the owner
                                printf("\nEnter name: ");
                                scanf(" %[^\n]s", name);
                                printf("Enter price(in Rs.): ");
                                scanf("%f", &price);
                                Fresult = insertNode(name, price, Fresult);
                                printf("\n%s added to the list successfully!\n", name);
                            }
                            else
                            {
                                printf("\nInvalid Choice!!\n");
                            }

                            break;
                        case 4: // takes choice input from the owner whether to choose vegetable or fruit list
                            printf("\nSelect the list from which item is to be removed:-\n");
                            printf("1) Vegetable list\n2) Fruit list\n");
                            printf("\nYour choice: ");
                            scanf("%d", &remChoice);
                            if (remChoice == 1)
                            { // below code segment used to remove an item from the vegetable list
                                printf("\n------------------------------------------------------------\n");
                                printf("   VEGETABLE\t\t\t\t\tPRICE(Rs./KG)\n");
                                printf("------------------------------------------------------------\n");
                                Vresult = deleteNode(Vresult);
                            }
                            else if (remChoice == 2)
                            { // below code segment used to remove an item from the fruit list
                                printf("\n------------------------------------------------------------\n");
                                printf("   FRUIT\t\t\t\t\tPRICE(Rs./KG)\n");
                                printf("------------------------------------------------------------\n");
                                Fresult = deleteNode(Fresult);
                            }
                            else
                            {
                                printf("\nInvalid Choice!!\n");
                            }
                            break;
                        case 5:
                            // to move out from both the while loops
                            t1 = 0, t3 = 0;
                            break;
                        default:
                            printf("\nInvalid Choice!!\n");
                            break;
                        }
                    }
                }
                else
                { // else part of the login code
                    printf("\nLogin Unsuccessful!\n");
                    t1 = 0;
                }
            }
            break;
        case 2:
            t2 = 1;
            while (t2)
            {
                ch2 = printCustSect(); // takes choice input from the customer section list from the user
                switch (ch2)
                {
                case 1: // displays vegetable list to the user
                    printf("\n------------------------------------------------------------\n");
                    printf("   VEGETABLE\t\t\t\t\tPRICE(Rs./KG)\n");
                    printf("------------------------------------------------------------\n");
                    displayList(Vresult);
                    break;
                case 2: // displays fruit list to the user
                    printf("\n------------------------------------------------------------\n");
                    printf("   FRUIT\t\t\t\t\tPRICE(Rs./KG)\n");
                    printf("------------------------------------------------------------\n");
                    displayList(Fresult);
                    break;
                case 3: // takes choice input from the user whether to choose vegetable or fruit list
                    printf("\nSelect the list from which you want to purchase an item:- \n");
                    printf("1) Vegetable list\n2) Fruit list\n");
                    printf("\nYour choice: ");
                    scanf("%d", &purChoice);
                    if (purChoice == 1)
                    { // lets the user to purchase item from the vegetable list
                        printf("\nHere is the item List:-\n");
                        printf("------------------------------------------------------------\n");
                        printf("   VEGETABLE\t\t\t\t\tPRICE(Rs./KG)\n");
                        printf("------------------------------------------------------------\n");
                        VBresult = displayNselect(Vresult, VBresult);
                    }
                    else if (purChoice == 2)
                    { // lets the user to purchase item from the fruit list
                        printf("\nHere is the item List:-\n");
                        printf("------------------------------------------------------------\n");
                        printf("   FRUIT\t\t\t\t\tPRICE(Rs./KG)\n");
                        printf("------------------------------------------------------------\n");
                        FBresult = displayNselect(Fresult, FBresult);
                    }
                    else
                    {
                        printf("\nInvalid Choice!!\n");
                    }
                    break;
                case 4: // bill is printed for the user
                    billMaker(VBresult, FBresult);
                    break;
                case 5:
                    t2 = 0; // to move from the while loop
                    break;
                default:
                    printf("\nInvalid Choice!!\n");
                    break;
                }
            }
            break;
        case 3:
            printf("\nExited Shop Successfully. Thank You!\n");
            printf("\n");
            t0 = 0;
            break;
        default:
            printf("\nInvalid Choice!!\n");
            break;
        }
    }
    getch();
}
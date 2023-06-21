#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#include "contract_class.cpp"

int contract::numCT = 0; // num of contracts

// add function calc receiveYearly
// receiveDaily = receiveYearly / 365
// add function calc amountAll
// avgItrRate = amountYearly * 100 / amountAll

// add function question y/n for deleteCt

void getInfCTList(contract ct[])
{           // get list of information of contract
    int np; // number plus
    printf("\nHow Many Savings Contract Do You Want To Add: ");
    scanf("%d", &np);
    for (int i = 0; i < np; i++)
    {
        printf("\nThe Contract %d", contract::numCT + i + 1);
        ct[contract::numCT + i].getInf();
    }
    contract::numCT = contract::numCT + np;
}

float receiveDaily(contract ct[])
{                       // amount received daily
    float itrPYear = 0; // interest Per Year

    // calc interest per year
    for (int i = 0; i < contract::numCT; i++)
    {
        itrPYear += (ct[i].getMoney() * (ct[i].getItrRate() / 100));
    }
    return itrPYear / 365;
}

float avgItrRate(contract ct[])
{ // average of interest Rate per year
    int amount = 0;

    // calc total amount of contracts
    for (int i = 0; i < contract::numCT; i++)
    {
        amount += ct[i].getMoney();
    }
    return receiveDaily(ct) * 36500 / amount;
}

void displayInfoCtList(contract ct[])
{
    printf("\nSTT\t\tAmount\t\tinterest Rate\n");
    for (int i = 0; i < contract::numCT; i++)
    {
        printf("%d", i + 1);
        ct[i].display();
    }
}

void editCT(contract ct[])
{
    int ptr;
    printf("There Are All Your Contracts:");

    // display all of detail of contracts
    displayInfoCtList(ct);

    // select contract to change detail
    printf("Which Contract Do You Want To Edit: ");
    scanf("%d", &ptr);

    // change detail
    printf("You Are Editing Contract %d", ptr);
    ct[ptr - 1].getInf();
    printf("Your change is Complete.");
}

void deleteCT(contract ct[])
{
    int ptr;
    char decision[1];
    printf("There Are All Your Contracts:");

    // display all of detail of contracts
    displayInfoCtList(ct);

    // select contract to delete
    printf("Select Contract Do You Want To Delete: ");
    scanf("%d", &ptr);

    // display contract is about to be deleted
    printf("\nThis Contract Will Be Delete: ");
    printf("\nAmount\t\tinterest Rate\n");
    ct[ptr - 1].display();

    // ask again to confirm
    printf("Are You Sure About That: [y/n]");
    rewind(stdin);
    gets(decision);
    if (decision[0] == 'y')
    {
        // delete detail
        for (int i = ptr - 1; i < contract::numCT - 1; i++)
            ct[i] = ct[i + 1];
        contract::numCT--;
        printf("\nThis Contract Are Deleted.");
    }
    else
        printf("delete command has been canceled");
    getch();
}

void calcWhenSaving()
{
    int option;
    contract ct[100];
    do
    {
        system("cls");
        printf("\n\n1. Add More Contract: ");
        printf("\n2. Display Information Of Contracts: ");
        printf("\n3. Amount Received Daily: ");
        printf("\n4. Average Of Interest Rate: ");
        printf("\n5. Edit Information Of Contract");
        printf("\n6. Delete The Contract: ");
        printf("\nPlease Choose Your Request: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            getInfCTList(ct);
            break;
        case 2:
            displayInfoCtList(ct);
            getch();
            break;
        case 3:
            printf("Amount Received Daily: %.2f", receiveDaily(ct));
            getch();
            break;
        case 4:
            printf("Average Of Interest Rate: %.2f", avgItrRate(ct));
            getch();
            break;
        case 5:
            editCT(ct);
            break;
        case 6:
            deleteCT(ct);
            break;
        }
    } while (option = !0);
}

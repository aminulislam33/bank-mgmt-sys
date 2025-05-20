#include <stdio.h>
#include <string.h>

int currentAccountIndex = -1;

#define MAX_ACCOUNTS 100

struct Account
{
    int accountNumber;
    char name[50];
    char password[20];
    float balance;
};

struct Account accounts[MAX_ACCOUNTS];

int totalAccounts = 0;

void createAccount()
{
    char name[50];
    char password[20];

    printf("\n--- Create Account ---\n");
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter a password: ");
    scanf("%s", password);

    accounts[totalAccounts].accountNumber = 23720015 + totalAccounts;
    strcpy(accounts[totalAccounts].name, name);
    strcpy(accounts[totalAccounts].password, password);
    accounts[totalAccounts].balance = 0.0;

    printf("Account created successfully!\n");
    printf("Your Account Number is: %d\n", accounts[totalAccounts].accountNumber);

    totalAccounts++;
}

int login()
{
    int accNum;
    char pass[20];
    int found = 0;

    printf("\n--- Login ---\n");
    printf("Enter your Account Number: ");
    scanf("%d", &accNum);
    printf("Enter your Password: ");
    scanf("%s", pass);

    for (int i = 0; i < totalAccounts; i++)
    {
        if (accounts[i].accountNumber == accNum && strcmp(accounts[i].password, pass) == 0)
        {
            currentAccountIndex = i;
            printf("Login successful. Welcome, %s!\n", accounts[i].name);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Invalid account number or password.\n");
    }

    return found;
}

void checkBalance()
{
    if (currentAccountIndex == -1)
    {
        printf("You are not logged in.\n");
        return;
    }

    printf("\n--- Account Balance ---\n");
    printf("Account Holder: %s\n", accounts[currentAccountIndex].name);
    printf("Account Number: %d\n", accounts[currentAccountIndex].accountNumber);
    printf("Balance: ₹  %.2f\n", accounts[currentAccountIndex].balance);
}

void transferMoney()
{
    int targetAcc;
    float amount;
    int found = 0;

    if (currentAccountIndex == -1)
    {
        printf("You are not logged in.\n");
        return;
    }

    printf("\n--- Transfer Money ---\n");
    printf("Enter recipient's Account Number: ");
    scanf("%d", &targetAcc);

    for (int i = 0; i < totalAccounts; i++)
    {
        if (accounts[i].accountNumber == targetAcc)
        {
            found = 1;

            printf("Enter amount to transfer: ");
            scanf("%f", &amount);

            if (amount <= 0)
            {
                printf("Invalid amount.\n");
            }
            else if (accounts[currentAccountIndex].balance >= amount)
            {
                accounts[currentAccountIndex].balance -= amount;
                accounts[i].balance += amount;

                printf("₹%.2f transferred to %s (Acc No: %d)\n",
                       amount, accounts[i].name, accounts[i].accountNumber);
            }
            else
            {
                printf("Insufficient balance.\n");
            }

            break;
        }
    }

    if (!found)
    {
        printf("Recipient account not found.\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        if (currentAccountIndex == -1)
        {
            printf("\n--- Bank Management System ---\n");
            printf("1. Create Account\n");
            printf("2. Login\n");
            printf("3. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                createAccount();
                break;
            case 2:
                login();
                break;
            case 3:
                printf("Thank you for using the system.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
            }
        }
        else
        {
            printf("\n--- Welcome, %s ---\n", accounts[currentAccountIndex].name);
            printf("1. Check Balance\n");
            printf("2. Transfer Money\n");
            printf("3. Logout\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                checkBalance();
                break;
            case 2:
                transferMoney();
                break;
            case 3:
                currentAccountIndex = -1;
                printf("Logged out successfully.\n");
                break;
            default:
                printf("Invalid choice.\n");
            }
        }
    }
    return 0;
}
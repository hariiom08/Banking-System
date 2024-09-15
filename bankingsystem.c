#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

// Structure to represent a bank account
struct Account {
    int accountNumber;
    char name[100];
    double balance;
};

// Function prototypes
void createAccount(struct Account accounts[], int *accountCount);
void deposit(struct Account accounts[], int accountCount, int accountNumber, double amount);
void withdraw(struct Account accounts[], int accountCount, int accountNumber, double amount);
void checkBalance(struct Account accounts[], int accountCount, int accountNumber);
void printMenu();

int main() {
    struct Account accounts[MAX_ACCOUNTS];
    int accountCount = 0;
    int choice;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &accountCount);
                break;
            case 2: {
                int accountNumber;
                double amount;
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter deposit amount: ");
                scanf("%lf", &amount);
                deposit(accounts, accountCount, accountNumber, amount);
                break;
            }
            case 3: {
                int accountNumber;
                double amount;
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter withdrawal amount: ");
                scanf("%lf", &amount);
                withdraw(accounts, accountCount, accountNumber, amount);
                break;
            }
            case 4: {
                int accountNumber;
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                checkBalance(accounts, accountCount, accountNumber);
                break;
            }
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void createAccount(struct Account accounts[], int *accountCount) {
    if (*accountCount < MAX_ACCOUNTS) {
        struct Account newAccount;
        newAccount.accountNumber = *accountCount + 1;
        printf("Enter account holder's name: ");
        scanf("%s", newAccount.name);
        printf("Enter initial balance: ");
        scanf("%lf", &newAccount.balance);
        accounts[*accountCount] = newAccount;
        (*accountCount)++;
        printf("Account created successfully.\n");
    } else {
        printf("Maximum number of accounts reached.\n");
    }
}

void deposit(struct Account accounts[], int accountCount, int accountNumber, double amount)
 {
    for (int i=0; i<accountCount; i++) 
	{
        if (accounts[i].accountNumber == accountNumber) 
		{
            accounts[i].balance += amount;
            printf("Deposit successful. New balance: %.2lf\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw(struct Account accounts[], int accountCount, int accountNumber, double amount) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. New balance: %.2lf\n", accounts[i].balance);
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void checkBalance(struct Account accounts[], int accountCount, int accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Current Balance: %.2lf\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void printMenu() {
    printf("\nBanking Menu:\n");
    printf("1. Create Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
}

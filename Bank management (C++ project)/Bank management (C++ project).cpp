#include <iostream>
#include <string>
using namespace std;

// Struct to store account details
struct Account {
    int accountNumber;     // Unique account number
    string name;           // Account holder's name
    string father_name;    // Account holder's father's name
    string cnic;           // Account holder's CNIC
    double balance;        // Account balance
};

// Array to store accounts, supports up to 100 accounts
Account accounts[100];
int totalAccounts = 0;     // Total number of accounts created

// Function to set the console text color using ANSI escape codes
void setColor(string color) {
    cout << color;
}

// Function to reset the console text color to default
void resetColor() {
    cout << "\033[0m";
}

// Function to create a new account
void createAccount() {
    if (totalAccounts < 100) {
        // Prompt user for account details
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, accounts[totalAccounts].name);
        cout << "Enter your father's name: ";
        getline(cin, accounts[totalAccounts].father_name);
        cout << "Enter your CNIC: ";
        getline(cin, accounts[totalAccounts].cnic);

        // Assign account number and initialize balance
        accounts[totalAccounts].accountNumber = totalAccounts + 1;
        accounts[totalAccounts].balance = 0.0;
        totalAccounts++;

        // Display success message in green
        setColor("\033[32m"); // Green
        cout << "Account created successfully. Your account number is: " << totalAccounts << endl;
        resetColor();
    }
    else {
        // Display error message if account limit reached
        setColor("\033[31m"); // Red
        cout << "Sorry, the bank has reached its maximum capacity for accounts." << endl;
        resetColor();
    }
}

// Function to deposit amount into an account
void deposit(int accountNumber, double amount) {
    if (accountNumber <= totalAccounts && accountNumber > 0) {
        // Add deposit amount to account balance
        accounts[accountNumber - 1].balance += amount;
        // Display success message in green
        setColor("\033[32m"); // Green
        cout << "Deposit successful. Current balance: " << accounts[accountNumber - 1].balance << endl;
        resetColor();
    }
    else {
        // Display error message for invalid account number
        setColor("\033[31m"); // Red
        cout << "Invalid account number." << endl;
        resetColor();
    }
}

// Function to withdraw amount from an account
void withdraw(int accountNumber, double amount) {
    if (accountNumber <= totalAccounts && accountNumber > 0) {
        if (accounts[accountNumber - 1].balance >= amount) {
            // Subtract withdrawal amount from account balance
            accounts[accountNumber - 1].balance -= amount;
            // Display success message in green
            setColor("\033[32m"); // Green
            cout << "Withdrawal successful. Current balance: " << accounts[accountNumber - 1].balance << endl;
            resetColor();
        }
        else {
            // Display error message for insufficient funds
            setColor("\033[31m"); // Red
            cout << "Insufficient funds." << endl;
            resetColor();
        }
    }
    else {
        // Display error message for invalid account number
        setColor("\033[31m"); // Red
        cout << "Invalid account number." << endl;
        resetColor();
    }
}

// Function to display account details
void displayAccount(int accountNumber) {
    if (accountNumber <= totalAccounts && accountNumber > 0) {
        // Display account details in cyan
        setColor("\033[36m"); // Cyan
        cout << "Account Number: " << accounts[accountNumber - 1].accountNumber << endl;
        cout << "Name: " << accounts[accountNumber - 1].name << endl;
        cout << "Father's Name: " << accounts[accountNumber - 1].father_name << endl;
        cout << "CNIC: " << accounts[accountNumber - 1].cnic << endl;
        cout << "Balance: " << accounts[accountNumber - 1].balance << endl;
        resetColor();
    }
    else {
        // Display error message for invalid account number
        setColor("\033[31m"); // Red
        cout << "Invalid account number." << endl;
        resetColor();
    }
}

// Function to edit account details
void editAccount(int accountNumber) {
    if (accountNumber <= totalAccounts && accountNumber > 0) {
        // Prompt user for new account details
        cout << "Editing Account Number: " << accounts[accountNumber - 1].accountNumber << endl;
        cout << "Enter new name: ";
        cin.ignore();
        getline(cin, accounts[accountNumber - 1].name);
        cout << "Enter new father's name: ";
        getline(cin, accounts[accountNumber - 1].father_name);
        cout << "Enter new CNIC: ";
        getline(cin, accounts[accountNumber - 1].cnic);
        // Display success message in green
        setColor("\033[32m"); // Green
        cout << "Account details updated successfully." << endl;
        resetColor();
    }
    else {
        // Display error message for invalid account number
        setColor("\033[31m"); // Red
        cout << "Invalid account number." << endl;
        resetColor();
    }
}

// Main function to provide menu and handle user choices
int main() {
    char choice;
    do {
        // Display menu options in yellow
        setColor("\033[33m"); // Yellow
        cout << "\n....** MENU **....\n" << endl;
        cout << "Choose an option:" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Display Account" << endl;
        cout << "5. Edit Account Details" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        resetColor();
        cin >> choice;

        switch (choice) {
        case '1':
            createAccount();
            break;
        case '2': {
            int accountNum;
            double depositAmount;
            cout << "Enter account number: ";
            cin >> accountNum;
            cout << "Enter deposit amount: ";
            cin >> depositAmount;
            deposit(accountNum, depositAmount);
            break;
        }
        case '3': {
            int withdrawAccountNum;
            double withdrawAmount;
            cout << "Enter account number: ";
            cin >> withdrawAccountNum;
            cout << "Enter withdrawal amount: ";
            cin >> withdrawAmount;
            withdraw(withdrawAccountNum, withdrawAmount);
            break;
        }
        case '4': {
            int displayAccountNum;
            cout << "Enter account number: ";
            cin >> displayAccountNum;
            displayAccount(displayAccountNum);
            break;
        }
        case '5': {
            int editAccountNum;
            cout << "Enter account number to edit details: ";
            cin >> editAccountNum;
            editAccount(editAccountNum);
            break;
        }
        case '6':
            cout << "Exiting program." << endl;
            break;
        default:
            // Display error message for invalid menu choice
            setColor("\033[31m"); // Red
            cout << "Invalid choice. Please try again." << endl;
            resetColor();
        }
    } while (choice != '6');

    return 0;
}


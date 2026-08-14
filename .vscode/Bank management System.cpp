#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Bank
{
    int accNo;
    string name;
    float balance;

public:

    void createAccount()
    {
        cout << "\nEnter Account Number: ";
        cin >> accNo;

        cin.ignore();

        cout << "Enter Account Holder Name: ";
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;

        if (balance < 0)
        {
            balance = 0;
            cout << "Invalid balance. Balance set to 0.\n";
        }

        cout << "Account created successfully!\n";
    }

    void deposit()
    {
        float amount;

        cout << "\nEnter Deposit Amount: ";
        cin >> amount;

        if (amount > 0)
        {
            balance += amount;
            cout << "Amount deposited successfully!\n";
            cout << "Updated Balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount!\n";
        }
    }

    void withdraw()
    {
        float amount;

        cout << "\nEnter Withdrawal Amount: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid withdrawal amount!\n";
        }
        else if (amount <= balance)
        {
            balance -= amount;
            cout << "Amount withdrawn successfully!\n";
            cout << "Updated Balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient Balance!\n";
        }
    }

    void checkBalance()
    {
        cout << "\nCurrent Balance: " << balance << endl;
    }

    void display()
    {
        cout << "\n----- Account Details -----\n";
        cout << "Account Number : " << accNo << endl;
        cout << "Account Holder : " << name << endl;
        cout << fixed << setprecision(2);
        cout << "Balance        : " << balance << endl;
        cout << "---------------------------\n";
    }
};

int main()
{
    Bank b;
    int choice;

    do
    {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Display Account\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                b.createAccount();
                break;

            case 2:
                b.deposit();
                break;

            case 3:
                b.withdraw();
                break;

            case 4:
                b.checkBalance();
                break;

            case 5:
                b.display();
                break;

            case 6:
                cout << "\nThank You for using Bank Management System!\n";
                break;

            default:
                cout << "Invalid Choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
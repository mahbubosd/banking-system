/*Create a Banking System with 10 objects as users of this Bank.
   Now implement it to perform withdraw, deposit, account creation,
   FDR and DPS with a default interest rate.
 */

 #include <iostream>
#include <cmath>
using namespace std;

class BankUser {
public:
    string name;
    double balance;

    void input() {
        cout << "Enter user name: ";
        cin >> name;
        cout << "Enter initial balance: ";
        cin >> balance;
    }

    void display() {
        cout << "User: " << name << ", Balance: $" << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
        cout << name << " deposited " << amount << ". New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance)
            cout << name << " has insufficient balance!\n";
        else {
            balance -= amount;
            cout << name << " withdrew " << amount << ". New Balance: " << balance << endl;
        }
    }

    void fdr(double amount, int years, double rate = 0.07) {
        if (amount > balance) {
            cout << name << " has insufficient balance for FDR.\n";
            return;
        }
        balance -= amount;
        double result = amount * pow(1 + rate, years);
        cout << name << " created FDR of " << amount << " for " << years
             << " years. Return: " << result << endl;
    }

    void dps(double monthly, int months, double rate = 0.05) {
        double total = monthly * months;
        if (total > balance) {
            cout << name << " balance for DPS.\n";
            return;
        }
        balance -= total;
        double result = total * (1 + rate);
        cout << name << " created DPS " << monthly << "/month for "
             << months << " months. Return: " << result << endl;
    }
};

int main() {
    int n = 10;
    BankUser users[n];

    cout << "Enter details for 10 users:\n";
    for (int i = 0; i < n; i++) {
        cout << "User " << i + 1 << ":\n";
        users[i].input();
    }

    cout << "\n--- Performing Transactions---\n";
    users[1].deposit(200);
    users[2].withdraw(100);
    users[3].fdr(300, 2);
    users[4].dps(100, 6);
    users[5].withdraw(50);
    users[6].deposit(400);
    users[7].fdr(200, 1);
    users[8].dps(50, 12);
    users[9].deposit(150);

    cout << "\n--- Final Account Summary ---\n";
    for (int i = 0; i < n; i++) {
        users[i].display();
    }

    return 0;
}



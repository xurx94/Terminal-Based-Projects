#include<iostream>
#include <string>
#include <conio.h>
using namespace std;

struct bills{
    string billname;
    float credit;
};
class NewBankLtd{
    string ID;
    float amount;
    string name;
    string mobile;
    string passcode;
    int transactions;
    struct bills history[1000];
    public:
        void setAccount(string acc,float money,string nam,string mob,string pass){
            ID = acc;
            amount = money;
            mobile = mob;
            passcode = pass;
            name = nam;
        }
        string getID(){
            return ID;
        }
        string getPass(){
            return passcode;
        }
        void addTransaction(int index,string bill,float credit){
            history[index].billname = bill;
            history[index].credit = credit;
        }
        float getBalance(){
            return amount;
        }
        void AddBalance(float ammo){
            amount += ammo;
            transactions++;
        }
        void SubBalance(float ammo){
            if(amount >= ammo){
                amount -= ammo; 
                transactions++;
            }
        }
        int Transaction(){
            return transactions;
        }
        int TransactionHistory(){
            cout << "\n";
            for(int i=0;i<transactions;i++){
                
            cout << "Transaction: " << history[i].billname << " Amount: " << history[i].credit<< endl;
            }
        }
};
NewBankLtd b[1000];
int total = 0;
int index;

int searchAccount(string target) {
    for (int i = 0; i < sizeof(b)/sizeof(b[0]); i++) {
        if (b[i].getID() == target) {
            return i;
        }
    }
    return -1; 
}
int searchPass(string target) {
    for (int i = 0; i < sizeof(b)/sizeof(b[0]); i++) {
        if (b[i].getPass() == target) {
            return 1;
        }
    }
    return -1; 
}
int login(){
    string acc,pass;
    cout << "****** Login ******"<<endl;
    cout << "Enter your account No.: ";
    cin >> acc;
    cout << "Enter Passcode: ";
    cin >> pass;
    index = searchAccount(acc);
    int val = searchPass(pass);
    if(index>=0 && val==1){
        return 1;
    }
    else{
        return -1;
    }
}
void Create(){
    string name,mob,pass;
     cout << "****** Create Account ******"<<endl;
    float x;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your Mobile No.: ";
    cin >> mob;
    while(1){
    cout << "Enter a 5 digit passcode: ";
    cin >> pass;
    if((pass.length())==5){
        break;
    }}   
    cout << "Creating your account.....\n";
    string L = mob.substr(mob.length() - 4);
    string ano = name+L;
    cout << "Your Account Number is: " << ano << endl;
    cout << "Deposit your initial balance: ";
    cin >> x;
    b[total].setAccount(ano,x,name,mob,pass);
    total++;
    cout << "New account successfully created!!!" << endl;
    cout << "Press any key to continue.... ";
    getch();
    system("cls");
}
void showTransaction(){
    string pass;
    cout << "Enter your passcode to confirm: ";
    cin >> pass;
    if(searchPass(pass)==1 && index>=0){
        cout << "You have made a total of " << b[index].Transaction() <<" transactions \n";
        int x;
        cout << "Enter 1 to see transaction history: ";
        cin >> x;
        if(x==1){
            b[index].TransactionHistory();
        }
    if(b[index].Transaction()<1){
        cout << "As your transactions are zero we will freeze your account!\n";
        cout << "Unless you make 1 transaction within 24 hours\n";
    }
}
    cout << "\nPress any key to continue.... ";
    getch();
    system("cls");
}
void Deposit(){
    string acc,pass;
    float money;
    cout << "Enter deposit amount: ";
    cin >> money;
    cout << "Enter your passcode to confirm: ";
    cin >> pass;
    if(searchPass(pass)==1 && index>=0){
        b[index].AddBalance(money);
        cout << "\nDeposit successful" << endl;
        cout << "Your new balance is " << b[index].getBalance()<<endl;
        int x = b[index].Transaction();
        b[index].addTransaction(x-1,"Deposit",money);
    }
    else{
        cout << "Invalid account or Password" << endl;
    }
    cout << "Press any key to continue.... ";
    getch();
    system("cls");
}
void showBalance(){
    string pass;
    cout << "Enter your Passcode: ";
    cin >> pass;
    if(searchPass(pass)==1 && index>=0){
        cout << "Your balance is " << b[index].getBalance()<<endl;
    }
    else{
        cout << "Invalid account or Password" << endl;
    }
    cout << "Press any key to continue.... ";
    getch();
    system("cls");
}
void Withdraw(){
    string pass;
    float money;
    cout << "Enter Withrawl amount: ";
    cin >> money;
    cout << "Enter your passcode to confirm: ";
    cin >> pass;
    if(searchPass(pass)==1 && index>=0){
        int z = b[index].getBalance();
        if(z<money){
            cout << "Sorry, Insufficient Balance" << endl;
        }
        else{
            b[index].SubBalance(money);
            cout << "Withdrawl successful" << endl;
            cout << "Your new balance is " << b[index].getBalance()<<endl;
            int x = b[index].Transaction();
            b[index].addTransaction(x-1,"Withdraw",money);
        }
    }
    else{
        cout << "Invalid account or Password" << endl;
    }
    cout << "Press any key to continue.... ";
    getch();
    system("cls");
}
void Transfer(){
    string rec,pass;
    float money;
    cout << "Enter receiver account number: ";
    cin >> rec;
    int index2 = searchAccount(rec);
    cout << "Enter your passcode to confirm: ";
    cin >> pass;
    if(index>=0 && index2>=0){
        int z = b[index].getBalance();
        cout << "Enter transfer amount: ";
        cin >> money;        
        if(z<money){
            cout << "Sorry, Insufficient Balance" << endl;
        }
        else{
            b[index].SubBalance(money);
            b[index2].AddBalance(money);
            cout << "\nFund Transfer successful" << endl;
            cout << "Your new balance is " << b[index].getBalance()<<endl;
            int x = b[index].Transaction();
            b[index].addTransaction(x-1,"Send Money",money);
            int y = b[index2].Transaction();
            b[index2].addTransaction(y-1,"Received Money",money);
        }
    }
    else{
        cout << "Invalid account or Password" << endl;
    }
    cout << "Press any key to continue.... ";
    getch();
    system("cls");

}
void PayBill(){
    int cid;
    string pass;
    float money;
    cout << "Enter Passcode to confirm: ";
    cin >> pass;
    if(searchPass(pass)==1 && index>=0){
    cout << "Which bill you want to pay? \n1. Electricity \n2. Gas\n3. Water\n4. Wifi\n5. Credit Card" <<endl;
    int opt;
    cout << "Select one: ";
    cin >> opt;
    switch(opt){
        case 1: {
            cout << "Enter customer ID: ";
            cin >> cid;
            cout << "Enter Amount: ";
            cin >> money;
            b[index].SubBalance(money);
            cout << "Bill Paid Sucessfully"<<endl;
            int f = b[index].Transaction();
            b[index].addTransaction(f-1,"Electricity Bill",money);
            break;}
        case 2:{
            cout << "Enter customer ID: ";
            cin >> cid;
            cout << "Enter Amount: ";
            cin >> money;
            b[index].SubBalance(money);
            cout << "Bill Paid Sucessfully"<<endl;
            int a = b[index].Transaction();
            b[index].addTransaction(a-1,"Gas Bill",money);
            break;}
        case 3:{
            cout << "Enter customer ID: ";
            cin >> cid;
            cout << "Enter Amount: ";
            cin >> money;
            b[index].SubBalance(money);
            cout << "Bill Paid Sucessfully"<<endl;
            int c = b[index].Transaction();
            b[index].addTransaction(c-1,"Water Bill",money);
            break;}
        case 4:{
            cout << "Enter customer ID: ";
            cin >> cid;
            cout << "Enter Amount: ";
            cin >> money;
            b[index].SubBalance(money);
            cout << "Bill Paid Sucessfully"<<endl;
            int d = b[index].Transaction();
            b[index].addTransaction(d-1,"Wifi Bill",money);
            break;}
        case 5:{
            cout << "Enter customer ID: ";
            cin >> cid;
            cout << "Enter Amount: ";
            cin >> money;
            b[index].SubBalance(money);
            cout << "Bill Paid Sucessfully"<<endl;
            int e = b[index].Transaction();
            b[index].addTransaction(e-1,"Credit Card Bill",money);
            break;}
        default:
            cout << "Choose a valid option" << endl;
    }
}
else{
    cout << "Invalid account or passcode" << endl;
}
    cout << "Press any key to continue.... ";
    getch();
    system("cls");
}
int main() {
    int choice;
    do {
        cout << "\n----- Objective Bank LTD -----\n";
        cout << "1. Create an Account \n2. Login \n3. Exit\n";
        cout <<"Choose an option: ";
        cin >> choice;
        if(choice == 1){
            Create();
        }
        else if (choice == 2){
            int x = login();
            if(x>0){
                int choose;
                do{
                cout << "\n--- Main Menu ---\n";
                cout << "1. Add Money\n2. Cash Out\n3. Balance Inquiry\n";
                cout << "4. Send Money\n5. Transaction History\n6. Pay Bill\n0. Exit\n" << endl;
                cout << "Choose an option: ";
                cin >> choose;
                switch (choose) {
                    case 1: Deposit(); break;
                    case 2: Withdraw(); break;
                    case 3: showBalance(); break;
                    case 4: Transfer(); break;
                    case 5: showTransaction(); break;
                    case 6: PayBill(); break;
                    case 0: cout << "Thank you for banking with us\n"; break;
                    default: cout << "Invalid choice.\n";
                }
                }while(choose!=0);  
            }
            else{
                cout << "Invalid ID or Password\n";
                    cout << "Press any key to continue.... ";
                    getch();
                    system("cls");
            }
        }
        else if(choice ==3){
            cout << "Thank your banking with us!!" << endl;
            break;
        }
        else {
            cout << "Invalid choice\n";
            cout << "Press any key to continue.... ";
            getch();
            system("cls");
        }
    } while (choice != 0);

    return 0;
}

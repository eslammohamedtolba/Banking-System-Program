#include "bits/stdc++.h"
using namespace std;
class BasicBankAccount
{
protected:
    int account_ID,balance;
public:
    BasicBankAccount()
    {
        balance=0;
    }
    BasicBankAccount(int balance)
    {
        this-> balance=balance;
    }
    virtual void withdraw()
    {

    }
    virtual void deposit()
    {

    }
    //getters and setters
};
//----------------------------------------------------------------------------------------------------------------------
class SavingsBankAccount:public BasicBankAccount
{
private:
    int minimumBalance,valuedeposit,valuewithdraw;
public:
    SavingsBankAccount(int Initial_balance)
    {
        minimumBalance=1000;
        while(Initial_balance<minimumBalance){
            cout<<"Please enter initial balance that is greater than or equal to 1000"<<endl;
            cin>>Initial_balance;
        }
        balance=Initial_balance;

    }
    void withdraw()
    {
        cin>>valuewithdraw;
        while(valuewithdraw<minimumBalance){
            cout<<"Please enter withdraw value that is greater than or equal to 1000 and not greater than "<<balance<<endl;
            cin>>valuedeposit;
        }
        balance-=valuewithdraw;
    }
    void deposit()
    {
        cin>>valuedeposit;
        while(valuedeposit<100){
            cout<<"Please enter deposit value that is greater than or equal to 100"<<endl;
            cin>>valuedeposit;
        }
        balance+=valuedeposit;
    }
    //getters and setters
};
//----------------------------------------------------------------------------------------------------------------------
class Client
{
private:
    string name;
    long long address,phone_number;
};
//----------------------------------------------------------------------------------------------------------------------
void Create_a_New_Account()
{
    cout<<"Please Enter Client Name =========>";
    cout<<"Please Enter Client Address =========>";
    cout<<"Please Enter Client Phone =========>";
    cout<<"What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 =========>";
    cout<<"Please Enter the Starting Balance =========>";
    cout<<"An account was created with ID FCAI-001 and Starting Balance"<<""<<" L.E. "<<endl;
}
void List_Clients_and_Accounts()
{

}
void Withdraw_Money()
{
    cout<<"Please Enter Account ID (e.g., FCAI-015) =========>"; //FCAI-001
    cout<<"Account ID:\n"
          "Acocunt Type: Basic\n"
          "Balance: 1500\n";

    cout<<"Please Enter The Amount to Withdraw =========>"; //1550
    cout<<"Sorry. This is more than what you can withdraw.\n";

    cout<<"Please Enter The Amount to Withdraw =========>"; //40
    cout<<"Thank you. \n"
          "Account ID: FCAI-001 \n"
          "New Balance: 1460 \n";
}
void Deposit_Money()
{

}
//----------------------------------------------------------------------------------------------------------------------
int main()
{
    int choice;
    while(true){
        cout<<"Welcome to FCAI Banking Application \n"
              "1. Create a New Account \n"
              "2. List Clients and Accounts \n"
              "3. Withdraw Money \n"
              "4. Deposit Money \n"
              "Please Enter Choice =========> ";
        cin>>choice;
        if(choice==1){
            Create_a_New_Account();
            break;
        }
        else if(choice==2){
            List_Clients_and_Accounts();
            break;
        }
        else if(choice==3){
            Withdraw_Money();
            break;
        }
        else if(choice==4){
            Deposit_Money();
            break;
        }
        else{
            cout<<"Please, enter valid choice from that ";
        }
    }

}
#include "SavingsBankAccount.h"
SavingsBankAccount::SavingsBankAccount(long long &Initial_balance)
{
    minimumBalance=1000;
    while(Initial_balance<minimumBalance){
        cout<<"Please enter initial balance that is greater than or equal to 1000"<<endl;
        cin>>Initial_balance;
    }   balance=Initial_balance;
}

void SavingsBankAccount::withdraw(long long valuewithdraw)
{
    if(balance>=minimumBalance){
        while(valuewithdraw<minimumBalance || valuewithdraw>balance){
            cout<<"Please enter withdraw value that is greater than or equal to 1000 and not greater than "<<balance<<endl;
            cin>>valuewithdraw;
        }
        
        balance-=valuewithdraw;
        cout<<"Thank you."<<endl;
        cout<<"Account ID: "<<account_ID<<endl;
        cout<<"New Balance: "<<balance<<endl;
    }
    else{
        cout<<"you can't withdraw any money from your balance because it's enough to withdraw"<<endl;
    }
}
void SavingsBankAccount::deposit(long long valuedeposit) {
    while(valuedeposit<100){
        cout<<"Please enter deposit value that is greater than or equal to 100"<<endl;
        cin>>valuedeposit;
    }
    
    balance+=valuedeposit;
    cout<<"Thank you."<<endl;
    cout<<"Account ID: "<<account_ID<<endl;
    cout<<"New Balance: "<<balance<<endl;
}

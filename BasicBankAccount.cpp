#include "BasicBankAccount.h"
BasicBankAccount::BasicBankAccount()
{
    balance=0;
}
BasicBankAccount::BasicBankAccount(long long bal)
{
    while(bal<0){
        cout<<"please enter your balance that is greater than zero"<<endl;
    }
    balance=bal;
}
void BasicBankAccount::setbalance(long long bal)
{
    balance=bal;
}
void BasicBankAccount::setId(string ID)
{
    account_ID=ID;
}
long long BasicBankAccount::getbalance()
{
    return balance;
}
string BasicBankAccount::getId()
{
    return account_ID;
}
void BasicBankAccount::withdraw(long long valuewithdraw)
{
    while(valuewithdraw<0 || valuewithdraw>balance){
        cout<<"please enter your withdraw that is greater than or equal to zero and smaller then or equal your balance"<<endl;
        cin>>valuewithdraw;
    }
    balance-=valuewithdraw;
    cout<<"Thank you."<<endl;
    cout<<"Account ID: "<<account_ID<<endl;
    cout<<"New Balance: "<<balance<<endl;
}
void BasicBankAccount::deposit(long long valuedeposit)
{
    if(valuedeposit<0){
        cout<<"please enter your withdraw that is greater than or equal to zero"<<endl;
        cin>>valuedeposit;
    }
    balance+=valuedeposit;
    cout<<"Thank you."<<endl;
    cout<<"Account ID: "<<account_ID<<endl;
    cout<<"New Balance: "<<balance<<endl;
}
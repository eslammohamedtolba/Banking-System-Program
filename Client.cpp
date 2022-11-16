#include "Client.h"
void Client::setname(string name)
{
    this->name=name;
}
void Client::setaddress(string address)
{
    this->address=address;
}
void Client::setphone(string phone)
{
    this->phone_number=phone;
}
void Client::settype(string type)
{
    type_account=type;
}
void Client::setID(string ID)
{
    client_account->setId(ID);
}
void Client::setbalance(int balance)
{
    client_account->setbalance(balance);
}
void Client::createacount(int type,long long startingbalance)
{
    type_account=(type==1? "1":"2");
    if(type==1){
        client_account=new BasicBankAccount(startingbalance);
    }
    else{
        client_account=new SavingsBankAccount(startingbalance);
    }
}
string Client::getname()
{
    return name;
}
string Client::getaddress()
{
    return address;
}
string Client::getphone()
{
    return phone_number;
}
string Client::gettype()
{
    return type_account;
}
string Client::getclientID()
{
    string myid= client_account->getId();
    return myid;
}
void Client::print(){
    cout<<"Name->"<<getname()<<endl;
    cout<<"ID->"<<getclientID()<<endl;
    cout<<"Address->"<<getaddress()<<endl;
    cout<<"Type->"<<gettype()<<endl;
    cout<<"Clientbalance->"<<getclientbalance()<<endl;
    cout<<"Phone->"<<getphone()<<endl;
}
long long Client::getclientbalance()
{
    long long mybalance=client_account->getbalance();
    return mybalance;
}
void Client::clientwithdraw(long long valuewithdraw)
{
    client_account->withdraw(valuewithdraw);
}
void Client::clientdeposit(long long valuedeposit)
{
    client_account->deposit(valuedeposit);
}
//-------------------------------------------------------------

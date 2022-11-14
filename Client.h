#ifndef BANKING_SYSTEM_PROGRAM_CLIENT_H
#define BANKING_SYSTEM_PROGRAM_CLIENT_H
#include "BasicBankAccount.h"
#include "SavingsBankAccount.h"
class Client
{
private:
    string name,address,phone_number,type_account;
    BasicBankAccount *client_account=NULL;
public:
    void setname(string name);
    void setaddress(string address);
    void setphone(string phone);
    void settype(string type);
    void setID(string ID);
    void setbalance(int balance);
    void createacount(int type,long long startingbalance);
    string getname();
    string getaddress();
    string getphone();
    string gettype();
    string getclientID();
    void print();
    long long getclientbalance();
    void clientwithdraw(long long valuewithdraw);
    void clientdeposit(long long valuedeposit);
};

#endif //BANKING_SYSTEM_PROGRAM_CLIENT_H

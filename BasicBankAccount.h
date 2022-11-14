#ifndef BANKING_SYSTEM_PROGRAM_BASICBANKACCOUNT_H
#define BANKING_SYSTEM_PROGRAM_BASICBANKACCOUNT_H
#include "bits/stdc++.h"
using namespace std;
class BasicBankAccount
{
protected:
    string account_ID;
    long long balance;
public:
    BasicBankAccount();
    BasicBankAccount(long long bal);
    virtual void setbalance(long long bal);
    virtual void setId(string ID);
    virtual long long getbalance();
    virtual string getId();
    virtual void withdraw(long long valuewithdraw);
    virtual void deposit(long long valuedeposit);
};

#endif //BANKING_SYSTEM_PROGRAM_BASICBANKACCOUNT_H

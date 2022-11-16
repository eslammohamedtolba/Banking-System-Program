#ifndef BANKING_SYSTEM_PROGRAM_SAVINGSBANKACCOUNT_H
#define BANKING_SYSTEM_PROGRAM_SAVINGSBANKACCOUNT_H
#include "BasicBankAccount.h"
class SavingsBankAccount:public BasicBankAccount
{

private:
    int minimumBalance;
public:
    // parameterize constructor
    SavingsBankAccount(long long &Initial_balance);
    // function withdraw
    void withdraw(long long valuewithdraw);
    // function deposit
    void deposit(long long valuedeposit);
    
};


#endif //BANKING_SYSTEM_PROGRAM_SAVINGSBANKACCOUNT_H

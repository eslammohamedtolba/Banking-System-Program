cmake_minimum_required(VERSION 3.21)
project(Banking_System_Program)

set(CMAKE_CXX_STANDARD 14)

add_executable(Banking_System_Program main.cpp Client.cpp Client.h SavingsBankAccount.cpp SavingsBankAccount.h BasicBankAccount.cpp BasicBankAccount.h BankingApplication.cpp BankingApplication.h)

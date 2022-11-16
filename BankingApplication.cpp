#include "BankingApplication.h"
fstream fileacount;string nextclient;
//----------------------------------------------------------------------------------------------------------------------
void increaseID(string ID)
{
    ID=ID.substr(4,ID.size()-4);
    for(int i=ID.size()-1;i>=0;i--){
        if(ID[i]!='9'){
            ID[i]++;
            break;
        }
        else if(i==0 && ID[0]=='9'){
            ID='1'+ID;
        }
        
    }
    
    nextclient="FCI-"+ID;
}
void findnextclient()
{
    fileacount.open("Accountsinformation.txt",ios::in);
    string name,address,phone_number,ID="FCI-000",type,strbalance;
    if(fileacount.is_open()){
        while(getline(fileacount,name)){
            getline(fileacount,ID);
            getline(fileacount,strbalance);
            getline(fileacount,type);
            getline(fileacount,address);
            getline(fileacount,phone_number);
        }
    }
    fileacount.close();
    increaseID(ID);
}
//----------------------------------------------------------------------------------------------------------------------
void fillfile(Client &C)
{
    fileacount.open("Accountsinformation.txt",ios::app);
    long long balance;string ID,name,address,phone,strbalance,type;
    balance=C.getclientbalance();
    ID=C.getclientID();
    strbalance=to_string(balance);
    name=C.getname();
    address=C.getaddress();
    phone=C.getphone();
    type=C.gettype();
    if(fileacount.is_open()){
        fileacount<<name<<endl;
        fileacount<<ID<<endl;
        fileacount<<strbalance<<endl;
        fileacount<<type<<endl;
        fileacount<<address<<endl;
        fileacount<<phone<<endl;
    }
    fileacount.close();
}
bool checkinfandfillinfs(Client &C,string infID)
{
    fileacount.open("Accountsinformation.txt",ios::in);
    string name,address,phone_number,ID,strbalance,type;
    long long startingbalance;int intype;
    while(getline(fileacount,name)){
        getline(fileacount,ID);
        getline(fileacount,strbalance);
        getline(fileacount,type);
        getline(fileacount,address);
        getline(fileacount,phone_number);
        if(ID==infID){
            C.setname(name);
            C.setphone(phone_number);
            C.setaddress(address);
            intype=(type=="1"? 1:2);
            startingbalance=stoi(strbalance);
            C.createacount(intype,startingbalance);
            C.setID(ID);
            fileacount.close();
            return 1;
        }
    }
    fileacount.close();
    return 0;
}
void modifyingdatafile(string modifyID,long long modifyingbal)
{
    fileacount.open("Accountsinformation.txt",ios::in);
    fstream modifyingfile;modifyingfile.open("modifyingfile.txt",ios::out);
    string name,address,phone_number,ID,type,
            strbalance,strmodifyingbal=to_string(modifyingbal);
    if(fileacount.is_open()){
        while(getline(fileacount,name)){
            getline(fileacount,ID);
            getline(fileacount,strbalance);
            getline(fileacount,type);
            getline(fileacount,address);
            getline(fileacount,phone_number);
            modifyingfile<<name<<endl;
            modifyingfile<<ID<<endl;
            if(ID==modifyID){
                modifyingfile<<strmodifyingbal<<endl;
            }
            else{
                modifyingfile<<strbalance<<endl;
            }
            modifyingfile<<type<<endl;
            modifyingfile<<address<<endl;
            modifyingfile<<phone_number<<endl;
        }
    }
    modifyingfile.close();
    fileacount.close();
    modifyingfile.open("modifyingfile.txt",ios::in);
    fileacount.open("Accountsinformation.txt",ios::out);

    if(fileacount.is_open()){
        while(getline(modifyingfile,name)){
            getline(modifyingfile,ID);
            getline(modifyingfile,strbalance);
            getline(modifyingfile,type);
            getline(modifyingfile,address);
            getline(modifyingfile,phone_number);

            fileacount<<name<<endl;
            fileacount<<ID<<endl;
            fileacount<<strbalance<<endl;
            fileacount<<type<<endl;
            fileacount<<address<<endl;
            fileacount<<phone_number<<endl;
        }
    }
    modifyingfile.close();
    fileacount.close();
    remove("modifyingfile.txt");
}
void Create_a_New_Account()
{
    Client client;int type;long long starting_balance;cin.ignore();
    string name,address,phone_number;
    cout<<"Please Enter Client Name =========>\n";
    getline(cin,name);
    client.setname(name);

    cout<<"Please Enter Client Address =========>\n";
    getline(cin,address);
    client.setaddress(address);

    cout<<"Please Enter Client Phone =========>\n";
    getline(cin,phone_number);
    client.setphone(phone_number);
    while(true){
        cout<<"What Type of Account Do You Like? (1) Basic (2) Saving =========>\n";
        cin>>type;
        if(type==1 || type==2){
            break;
        }
    }
    cout<<"Please Enter the Starting Balance =========>\n";
    cin>>starting_balance;
    client.createacount(type,starting_balance);
    client.setID(nextclient);
    fillfile(client);
    cout<<"An account was created with ID "<<nextclient<<" and Starting Balance "<<client.getclientbalance()<<" L.E. "<<endl;
    increaseID(nextclient);
}
//------------------------------------------------------------------------------------------------------------------------------
void List_Clients_and_Accounts()
{
    int chk;string ID;Client temp;
    while(true){
        cout<<"if you have any ID in our system, please enter 1 otherwise enter 0"<<endl;
        cin>>chk;
        if (chk==0){
            break;
        }
        else{
            cout<<"please enter the ID :";
            cin>>ID;
            while (!checkinfandfillinfs( temp,ID)){
                cout<<"the ID invaliad ,pleae enter the ID again or exit to exit:";
                cin>>ID;
            }
            temp.print();
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
void Withdraw_Money()
{
    Client client;string IDclient="";int continuing=0;long long withdraw=0;
    while(true){
        cout<<"if you have any ID in our system, please enter 1 otherwise enter 0"<<endl;cin>>continuing;
        if(continuing==0){
            break;
        }
        else{
            cout<<"Please Enter Account ID (e.g., FCAI-015) =========>"<<endl;cin>>IDclient;
            if(checkinfandfillinfs(client,IDclient)){
                cout<<"Account ID: "<<client.getclientID()<<endl;
                cout<<"Acocunt Type: "<<(client.gettype()=="1"? "Base":"Saving")<<endl;
                cout<<"Balance: "<<client.getclientbalance()<<endl;
                cout<<"Please Enter The Amount to Withdraw =========>"<<endl;cin>>withdraw;
                client.clientwithdraw(withdraw);
                modifyingdatafile(client.getclientID(),client.getclientbalance());
            }
            else{
                cout<<"your account ID not exit in our system, ";
            }
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
void Deposit_Money()
{
    Client client;string IDclient="";int continuing=0;long long deposit=0;
    while(true){
        cout<<"if you have any ID in our system, please enter 1 otherwise enter 0"<<endl;cin>>continuing;
        if(continuing==0){
            break;
        }
        else{
            cout<<"Please Enter Account ID (e.g., FCAI-015) =========>"<<endl;cin>>IDclient;
            if(checkinfandfillinfs(client,IDclient)){
                cout<<"Account ID: "<<client.getclientID()<<endl;
                cout<<"Acocunt Type: "<<(client.gettype()=="1"? "Base":"Saving")<<endl;
                cout<<"Balance: "<<client.getclientbalance()<<endl;
                cout<<"Please Enter The Amount to deposit =========>"<<endl;cin>>deposit;
                client.clientdeposit(deposit);
                modifyingdatafile(client.getclientID(),client.getclientbalance());
            }
            else{
                cout<<"your account ID not exit in our system, ";
            }
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
BankingApp::BankingApp()
{
    findnextclient();
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
//-----------------------------------------------------------------

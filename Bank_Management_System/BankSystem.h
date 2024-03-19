#ifndef BANKSYSTEM_H_INCLUDED
#define BANKSYSTEM_H_INCLUDED

#define Number_Of_Bank_Accounts 1000
typedef struct
{
    char name[60];
    char address[60];
    char National_ID [14];
    int age ;
    int Bank_Account_ID;
    char Guardian[60];
    char Guardian_National_ID [14];
    char Account_Status[10];
    float Balance ;
    int Password;
} Bank_Account ;

typedef struct
{
    char Name[60] ;
    int Password ;
}Admin ;

void Admin_Window();
void Client_Window();
void Admin_LogIn(Admin a, int Password);
void Client_LogIn(Bank_Account *ptb);
void Create_New_Account (Bank_Account *ptb,int Number_Of_Customers);
void Make_Transaction(Bank_Account *ptb) ;
void Change_Account_Status (Bank_Account *ptb) ;
void Get_Cash (Bank_Account *ptb);
void Deposit (Bank_Account *ptb) ;
void Change_Password(Bank_Account *ptb);


#endif // BANKSYSTEM_H_INCLUDED

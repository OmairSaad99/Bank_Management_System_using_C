#include <stdio.h>
#include <stdlib.h>
#include "BankSystem.h"
#include "BankSystem.c"

extern char Flag_Admin_Password ;
int main()
{
    char choice[1];
    Bank_Account b[Number_Of_Bank_Accounts];
    Admin a ;
    int Number_Of_Accounts ;
    char Option_Mode = 0, Operation_Option, Return_Main_Menu_Flag = 0;
    printf("1 - Admin Mode \n");
    printf("2 - User Mode \n");

    while (1)
    {
        if (Return_Main_Menu_Flag == 0)
        {
            printf("Enter Option Of Mode : ");
            scanf("%d",&Option_Mode);
        }
        if (Option_Mode == 1) // Admin Mode
        {
            if (Return_Main_Menu_Flag == 0)
            {
                Admin_LogIn(a,1234);
            }
            if (Flag_Admin_Password == 1)
            {
                if (Return_Main_Menu_Flag == 0)
                {
                    Flag_Admin_Password = 0 ;
                    Admin_Window() ;
                }
                while(1)
                {
                    if (Return_Main_Menu_Flag == 1)
                        Return_Main_Menu_Flag = 0 ;
                    printf("Enter Option Of Operation : ");
                    scanf("%d",&Operation_Option);

                    if (Operation_Option == 1)
                    {
                        printf("Enter Number Of Accounts : ");
                        scanf("%d",&Number_Of_Accounts);

                        Create_New_Account(b,Number_Of_Accounts);
                    }
                    else if (Operation_Option == 2)
                    {
                        Admin_Window();
                    }
                    else if (Operation_Option == 3)
                    {
                        Change_Account_Status(b);
                    }
                    else if (Operation_Option == 4)
                    {
                        break ;
                    }
                }
            }
            else
            {
                break ;
            }
        }
        else if (Option_Mode == 2)
        {
            Client_LogIn(b);
            Client_Window();

            printf("Enter Option Of Operation : ");
            scanf("%d",&Operation_Option);

            if (Operation_Option == 1)
            {
                Make_Transaction(b);
            }
            else if (Operation_Option == 2)
            {
                Change_Password(b);
            }
            else if (Operation_Option == 3)
            {
                Get_Cash(b);
            }
            else if (Operation_Option == 4)
            {
                Deposit(b);
            }
            printf("Do you Want To return To Main Menu ? \n");
            printf("If You Want Press (y) , Else (n) : ");
            scanf(" %[^\n]%*c",choice);
            if (strcmp(choice, "y") == 0)
            {
                Admin_Window();
                Return_Main_Menu_Flag = 1 ;
                Option_Mode = 1 ;
                Flag_Admin_Password = 1 ;
            }
            else if (strcmp(choice, "n") == 0)
            {
                /*Do no Thing*/
            }
        }
        else
        {
            printf("Wrong Option , Enter Correct Option \n");
        }
    }

    return 0;
}

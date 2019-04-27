/**
 * Author: Hair Albeiro Parra Barrera
 * The following program constructs a data structure for a simulated 
 * "Bank account", by making use of both structs, unions ,  
 * */
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

// struct for checking account
typedef struct Checking {
    double balance; 
} Checking;

// struct for savings account
typedef struct Savings { 
    double balance; 
    double interest; 
    double withdraw_fee; 
} Savings; 

// struct for the overall account
typedef struct Account{  

    // basic data
    char *name; 
    int age ; 
    char *password; 

    // only one of these should be valid (for the sake of the exercise)
    union PSW_REMAINDER { 
        char* pets_name; 
        char* mothers_name; 
        char* native_city; 
    } PSW_REMAINDER; 

    // struct types
    Checking *checking_account; 
    Savings *savings_account; 

} Account; 

// Initializes a new bank account 
Account set_up_account(char* name, int age, char* password, char* inremainder,  double balance1, double balance2) { 
    
    Account new_account ; // initialize main account 
    Checking *new_checking = (struct Checking*)malloc(sizeof(Checking)); // initialize checking account 
    Savings *new_savings = (struct Savings*)malloc(sizeof(Savings)); // initialize savings

    // assign basic fields
    new_account.name = name; 
    new_account.age = age; 
    new_account.password = password; 

    // inquire about reminder type 
    printf("What kind of reminder would you like to choose?\n"); 
    printf("Please input a number:\n"); 
    printf("1. Pet's name; \n"); 
    printf("2. Mother's name \n"); 
    printf("3. Native city\n");

    char answer[50]; // to store the answer
    int cont = 1; // to stop the loop 

    // while wrong input
    while(cont) { 
        scanf("%s", &answer); // get the answer
        if(strcmp(answer, "1") == 0 || strcmp(answer, "pet") == 0) { 
            printf("You chose your pet's name as a reminder\n"); 
            new_account.PSW_REMAINDER.pets_name = remainder; 
            cont = 0; 
        }
        else if(strcmp(answer, "2") == 0 || strcmp(answer, "mother") == 0) { 
            printf("You chose your mother's name as a remainder\n"); 
            new_account.PSW_REMAINDER.mothers_name = remainder; 
            cont = 0; 
        }
        else if(strcmp(answer, "3") == 0 || strcmp(answer, "native city") == 0 ) { 
            printf("You chose your native citiy's name as a reminder\n"); 
            new_account.PSW_REMAINDER.native_city = remainder; 
            cont = 0;
        }

    }

    printf("Thanks\n"); 

    // distribute balances
    if( balance1 >= 0)  { 
        new_checking->balance = balance1; 
    }
    else { 
        new_checking->balance = 0; 
    }
    if( balance2 >= 0) { 
        new_savings->balance = balance2; 
    } 
    else { 
        new_savings->balance = 0; 
    }

    // set up interest and withdrawing fee
    new_savings->interest = 0.02; // 2%
    new_savings->withdraw_fee = 0.05; // 5%  

    // set up checking accounts 
    new_account.checking_account = new_checking; 
    new_account.savings_account = new_savings; 

    printf("Account has been set.\n"); 
    
    return new_account; 
}

// Displays account information 
void check_status(Account input_account){ 
    printf("Name: %s\n", input_account.name); 
    printf("Age: %d\n", input_account.age); 
    printf("Checking balance: %.2f\n", input_account.checking_account->balance); 
    printf("Savings balance:  %.2f\n", input_account.savings_account->balance); 
    printf("Savings interest: %.2f\n", input_account.savings_account->interest); 
    printf("Withdrwaing fee: %.2f\n", input_account.savings_account->withdraw_fee); 
    double interest = input_account.savings_account->interest; 
    input_account.savings_account->balance *= (1+interest); // update based on interest
}

// Simulates a deposit into the account 
void deposit(Account input_account, char* type, int amount) {
    if(strcmp(type, "Savings") == 0 || strcmp(type, "savings") == 0) { 
        input_account.savings_account->balance += abs(amount); 
    }else { 
        input_account.checking_account->balance += abs(amount); 
    }
}

// Simulates a withdraw from the account 
void withdraw(Account input_account, char* type, int withdraw_amount) { 

    // initialize the balances and withdrawin fees
    int saving_funds = input_account.savings_account->balance; 
    int checking_funds = input_account.checking_account->balance; 
    int wfee = input_account.savings_account->withdraw_fee; 
    int total_withdraw = withdraw_amount*(1 + wfee); 


    // Check for the ype of account and the availability of funds
    if(strcmp(type, "Savings") == 0 || strcmp(type, "savings") == 0) { 
        if( total_withdraw > saving_funds) { 
            printf("Not enough funds\n"); 
        }
        else { 
            input_account.savings_account->balance -= total_withdraw; 
        }
    }
    else { 
        if( withdraw_amount > checking_funds) { 
            printf("Not enough funds\n");
        }
        else { 
            input_account.checking_account->balance -= withdraw_amount; 
        }
    }

}

int main(void){ 

    Account test; 
    test.age = 40; 
    printf("age = %d\n", test.age); 

    Account test_account = set_up_account("Jair", 22, "Passw", "Abuelita", 1000, 233); 
    check_status(test_account); 
    // printf("Password: %s", test_account->password); 

    deposit( test_account, "checking", 9999); 
    check_status(test_account); 
    check_status(test_account); 

    return 0; 
}

/*
 * PrePaidPhone.cpp
 *
 *  Created on: Sep 15b, 2016
 *      Author: Zhongheng Li
 *      NetID: zl1761
 *
 *
 */
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <time.h>
#include "assert.h"

using namespace std;

class PrepaidAccount {
    
private:
   
    string phoneNumber;
    float availableBalance;
  
    
public:
    
    PrepaidAccount();
    PrepaidAccount(string iniPhoneNumber);
    string getPhoneNumber();
    void  setPhoneNumber(string number);
    float getAvailableBalance();
    void addBalance(double amount);
    float payForCall(int callDuration, double tariff);
    void resetAccount(PrepaidAccount acccount);
    void resetAccount();
    bool isEmpty();
 
    
};



PrepaidAccount::PrepaidAccount(){

    phoneNumber  = "";
    availableBalance = 0;
    
};


PrepaidAccount::PrepaidAccount(string iniPhoneNumber){
    
    //Make sure the iniPhoneNumber has 10 characters, otherwise throw exception
    assert(iniPhoneNumber.length() == 10);
    
    phoneNumber = iniPhoneNumber;
    availableBalance = 0;
    
};


string  PrepaidAccount::getPhoneNumber(){
    
    return  phoneNumber;
}


void PrepaidAccount::resetAccount(PrepaidAccount acccount){
    
    phoneNumber  = "";
    availableBalance = 0;
    
    
}

void PrepaidAccount::resetAccount(){
    
    phoneNumber  = "";
    availableBalance = 0;
    
    
}



void PrepaidAccount::setPhoneNumber(string number){
    
    phoneNumber = number;
    
}


float PrepaidAccount::getAvailableBalance(){
    
    
    return availableBalance;
    
};


void PrepaidAccount::addBalance(double amount){
    
    availableBalance += amount;
    
}

bool PrepaidAccount::isEmpty(){
    
    if(getPhoneNumber()==""){
        
        return true;
    }
    else
        return false;
}



float PrepaidAccount::payForCall(int callDuration, double tariff){
    
    float amountTobeDeducted =  tariff * (callDuration/60);
    
    
    cout << "This is the account balance before this call: $" << availableBalance <<endl;
    
 
    
    if (amountTobeDeducted > availableBalance){
        
        return -1 ;
    }
    else if( amountTobeDeducted <= availableBalance){
        
        availableBalance = availableBalance - amountTobeDeducted;
        

    }
    
    cout << "This is the account balance after this call $" << availableBalance <<endl;
    
    return amountTobeDeducted;
}



int compareAccounts( PrepaidAccount a1,  PrepaidAccount a2){
    
    
    stringstream ssAcount1(a1.getPhoneNumber());
    stringstream ssAcount2(a2.getPhoneNumber());
    
    
    long account1Number=0;
    long account2Number=0;
    
    ssAcount1 >> account1Number;
    ssAcount2 >> account2Number;
  
    
    if (account1Number < account2Number){
        
        return -1;
    }
    if (account1Number == account2Number){
        
        return 0;
    }
    else
        
        return 1;
    
    
};





class AccountStore {
    
    
public:
    
    AccountStore();
    static const int maxSizeOfAccounts = 100;
    int getSize();
    PrepaidAccount getAccount(int i);
    int removeAccount(string phoneNumber);
    void insertAccount(PrepaidAccount a);
    
    
private:
    int size;
    PrepaidAccount myAccounts[maxSizeOfAccounts];
    
};



AccountStore::AccountStore(){
    

    size = 0;
    
};


int AccountStore::getSize(){
        
        return size;
};


    
PrepaidAccount AccountStore::getAccount(int i){
    
    return myAccounts[i];
};



int AccountStore::removeAccount(string phoneNumber){
    
    //Make sure there are accounts can be remove
    assert(getSize() != 0);
    
    
    bool isAccountExisit = false;
    
    for (int targetIndex = 0; targetIndex < getSize(); targetIndex++ ){
        
        if ( myAccounts[targetIndex].getPhoneNumber() == phoneNumber ){
            

            
            for ( int index = targetIndex; index < getSize(); index ++){
                
                myAccounts[index] = myAccounts[index+1];
                
                
            }

                myAccounts[getSize()-1].resetAccount();
                size -- ;
                isAccountExisit = true;
        }

        
    }
    
    if (isAccountExisit == true ){
        
        
        cout << "The account with this number:" << phoneNumber << " is removed." << endl;
        
        return 0;
        
      
        
    }
    else {
        
        cout << "The account with this number:" << phoneNumber << " is NOT exist." << endl;
        
        return -1;

    }



    
};
    




void AccountStore::insertAccount(PrepaidAccount a){
    
    //Make sure there are enough space for a new account
    assert (getSize() < maxSizeOfAccounts);
    
    
    /* compareAccounts References:
     • -1 : if a1’s phone number is smaller than a2’s phone number
     • 0 : if a1’s phone number is equal to a2’s phone number
     • 1 : if a1’s phone number is larger than a2’s phone number
     */
    
    int pivotIndex = 0;
    
    while ( pivotIndex <= getSize()){
 
        if(compareAccounts (a,myAccounts[pivotIndex]) == -1 || myAccounts[pivotIndex].isEmpty()==true){
            

                                for ( int decreasingIndex = size; decreasingIndex > pivotIndex; decreasingIndex--){
            
                                    myAccounts[decreasingIndex] = myAccounts[decreasingIndex - 1];
            
                                }
            
                                myAccounts[pivotIndex] = a;
            
                                size ++;
                                break;

        }

        
        pivotIndex++ ;
    
            cout << "The next Pivot is: "<< pivotIndex  << endl;
  
        
    }
      
    };
    

/* Finally, write a main function to test your code. In the function generate 5
 PrepaidAccount objects and 1 AccountStore object. PrepaidAccount should be
 initialized with random 10-digit phone numbers. For each account object:
 • add random amount of dollars (between $50 and $100). Use rand() function
 • Make a phone call with random duration (between 10 seconds 200 seconds)
 and random tariff (between .1 dollars/minute and .5 dollars/minute).
 • Insert account into the AccountStore
 (Hint: you can use srand(time(NULL)); and rand(); to generate random
 numbers)
 Then call getAccount(int i) of the AccountStore for i=1,2,3,4,5. Print out the
 phoneNumber and availableBalance of the returned accounts. Note that if your
 AccountStore implementation is correct then the printed phone numbers should be
 in ascending order.
 
 */

int main() {
    
    srand(time(NULL));
    
    cout << "Hey this is the Pre Paid Phone System" << endl;
    
    AccountStore accountStore;
   
    cout << "The initial account store size is: " <<   accountStore.getSize() << endl;
    
    cout << "The current max size of accounts is: " <<  AccountStore::maxSizeOfAccounts << endl;
    
    cout << "____________________________________________________________________________"<< endl;
    
    cout << " "<< endl;
    
    for (int i = 1; i < 6; i++){
        
        
        stringstream phoneNumberStringStream;
        
        
        
        for (int j =1; j < 11; j++){
            
            
            int digit  = rand() % 10;
            
            
            phoneNumberStringStream << digit;
            
        }

        string phoneNumber = phoneNumberStringStream.str();
        
        PrepaidAccount acount = PrepaidAccount(phoneNumber);
        
        
        double balance = rand() % (100 - 50 + 1) + 50;
        
        acount.addBalance(balance);
        
        
        cout << "Before insert, the phone number is: " << phoneNumber  << endl;
        
        cout << "Before insert, the account balance is: $" << setprecision (2) << fixed <<  balance   << endl;
        
        accountStore.insertAccount(acount);

        cout << "The current account store size is: " <<   accountStore.getSize() << endl;
        
    }

    
    cout << "____________________________________________________________________________"<< endl;
    
    cout << " "<< endl;
    
    cout << "These are the accounts in this account store:" << endl;
    
   for (int i = 0; i < 8; i++){
       
       
       
       cout << "This is account" << i <<  ": " <<endl;
       
       
       cout << "The phone number is: " <<   accountStore.getAccount(i).getPhoneNumber() << endl;
     
        cout << "The account balance is: $" <<  setprecision (2) << fixed << accountStore.getAccount(i).getAvailableBalance()<< endl;
       
 
       
   }
    
    
    cout << "Check if account 10 is empty" << endl;
    
    if (accountStore.getAccount(10).isEmpty()){
        
           cout << "This account is empty" << endl;
    }
    else {
        
          cout << "This account is NOT empty" << endl;
    }
    
    
    cout << "____________________________________________________________________________"<< endl;
    
    cout << " "<< endl;

    
    /*
     • Make a phone call with random duration (between 10 seconds 200 seconds)
     and random tariff (between .1 dollars/minute and .5 dollars/minute).
        (Hint: you can use srand(time(NULL)); and rand(); to generate random
     numbers)
     Then call getAccount(int i) of the AccountStore for i=1,2,3,4,5. Print out the
     phoneNumber and availableBalance of the returned accounts. Note that if your
     AccountStore implementation is correct then the printed phone numbers should be
     in ascending order.
     
     */
    
     cout << "Make a phone call on the first account..." << endl;
    
    
    int thisCallDuration = rand() % (200 - 10 + 1) + 10;
    
    double thisTariff = ((double)rand()) / ((double)RAND_MAX) * 0.5 + 0.1;
    
    cout << "The duration for this call is: " <<  thisCallDuration << " seconds." <<endl;
    
    
    cout << "The tariff for this call is: $" <<  setprecision (2) << fixed << thisTariff << " per minute."<< endl;
    
    
   float amountDeductedFromAccount =  accountStore.getAccount(0).payForCall(thisCallDuration, thisTariff);
    
    
    cout << "The amount Deducted From the Account is: " <<  setprecision (2) << fixed << amountDeductedFromAccount << endl;
    
    
    
    
    
    cout << "Print the details of the First Account Again:" << endl;
    

        
        cout << "The phone number is: " <<   accountStore.getAccount(0).getPhoneNumber() << endl;
        
        cout << "The account balance is: $" <<   setprecision (2) << fixed << accountStore.getAccount(0).getAvailableBalance()<< endl;
        
    
    
    
    cout << "____________________________________________________________________________"<< endl;
    
    
    cout << "Removing the this account with account number:" <<  accountStore.getAccount(2).getPhoneNumber()
 <<  endl;
    
    
    accountStore.removeAccount(accountStore.getAccount(2).getPhoneNumber() );
    
    cout << "These are the accounts in this account store after removal of the first account:" << endl;
    
    
    for (int i = 0; i < 8; i++){
        
        
        
        cout << "This is account" << i <<  ": " <<endl;
        
        
        cout << "The phone number is: " <<   accountStore.getAccount(i).getPhoneNumber() << endl;
        
        cout << "The account balance is: $" <<   setprecision (2) << fixed << accountStore.getAccount(i).getAvailableBalance()<< endl;
        
        
        
    }
    
    
    
    
    cout << "Trying to remove the a account with incorrect or not exisit account number: 9173368899...."     <<  endl;
    
    
    accountStore.removeAccount("9173368899");

 

//    Funtion Unit Testing the compareAccounts function:
//    cout << "Hey this is the Pre Paid Phone System" << endl;
//    
//    
//    PrepaidAccount acount1 = PrepaidAccount("2966243326");
//    
//    
//    string acount1Number1 = acount1.getPhoneNumber();
//    
//    cout << acount1Number1 << endl;
//    
//    
//    
//    PrepaidAccount acount2 = PrepaidAccount("3079575097");
//
//    
//    string acount1Number2 = acount2.getPhoneNumber();
//
//    cout << acount1Number2 << endl;
//    
//    
//    
//    
//    cout << "Is account 1 greater than account 2? :" << compareAccounts( acount1,  acount2) << endl;
//    cout << "-1 : if acount1’s phone number is smaller than acount2’s phone number" << endl;
//    cout << "0 : if acount1’s phone number is equal to acount2’s phone number" << endl;
//    cout << "1 : if acount1’s phone number is larger than acount2’s phone number" << endl;
//    
//    
//    
    
    
    cout << "____________________________________________________________________________"<< endl;
    
    
    return 0;
    
    
}


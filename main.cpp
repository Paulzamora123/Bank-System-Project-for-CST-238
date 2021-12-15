/*
Title: Project2.cpp
Abstract: This program creates an online bank that includes many ways of managing your account
Author: Paul Zamora
ID: 9001
Date: 12/11/21
*/
#include <iostream>
#include <fstream>
#include <istream>
#include <iomanip>
#include <algorithm>
using namespace std;


class Bank
{
	public:
		Bank();
		void setAccountDetails(int newSSN, string newFirstName, string newLastName, int newAccountNumber, double newBalance, int newAccountType, bool checkHasBothAccounts);
		void displayCustomerList() const;
		void displayBankInfo();
		int getSSN();
		string getFirstName();
		string getLastName();
		int getAccountNumber();
		int getSecondAccountNumber();
		double getBalance();
		double getSecondAccountBalance();
		int getAccountType();
		int isChecking();
		bool checkForSavingsAndCheckingAccount();
		int getTotalAccounts();
		void deductBalance(int sourceAccountNum, int destinationAccountNum, double transferAmount);
		void transferBalance(int sourceAccountNum, int destinationAccountNum, double transferAmount);
		void deleteAccount(int accountNum, int newSSN);
		void deleteSecondAccount(int accountNum, int newSSN);
		void displayCustomerInfo();
		void displaySecondCustomerInfo();
		void displayCustomers();

	private:
		int SSN;
		string firstName;
		string lastName;
		int accountNumber;

		//accountType checks if the new account is a either savings account or checking account
		int accountType;

		//When a new person makes an account, their balance will be stored in here
		double balance;

		//A check to see if a new account has been created under the same name
		bool hasBothAccounts;

		//When a second account is created under the same name, the newly inputted balance will be stored in here
		double secondAccountBalance;

		//When a second account is created under the same name, the new account number will be stored in here
		int secondAccountNumber;

		//The amount of accounts in the bank system (includes savings and checking accounts)
		int totalAccounts;

		//The new account type (either savings or checking)
		int newAccountType;

		//The overall balance of the bank
		int overallBalance;
};

Bank::Bank()     
: SSN(0), firstName("UNKNOWN"), lastName("UNKNOWN"), accountNumber(0), balance(0), accountType(0), secondAccountBalance(0), secondAccountNumber(0), totalAccounts(0), newAccountType(0), overallBalance(0)
{}

void Bank::setAccountDetails(int newSSN, string newFirstName, string newLastName, int newAccountNumber, double newBalance, int newAccountType, bool checkHasBothAccounts) {
	SSN = newSSN;
	firstName = newFirstName;
	lastName = newLastName;
	
	if (checkHasBothAccounts == true) {
		hasBothAccounts = true;
		secondAccountBalance = newBalance;
		secondAccountNumber = newAccountNumber;
		if (accountType == 1) {
			newAccountType = 2;
		} else {
			newAccountType = 1;
		}
	} else {
		balance = newBalance;
		accountNumber = newAccountNumber;
		accountType = newAccountType;
	}
	
}

void Bank::displayCustomerList() const {
	cout << "SSN: " << SSN << "\n";
	cout << "Name: " << firstName << " " << lastName << "\n";
}

void Bank::displayCustomerInfo() {
	
	cout << "\tName: " << firstName << " " << lastName << "\n";
	cout << "\tAccount Number: " << accountNumber << "\n";
	if (accountType == 1) {
		cout << "\tAccount Type: Checking\n";
	} else if (accountType == 2) {
		cout << "\tAccount Type: Saving\n";
	}
	cout << "\tBalance: $" << balance << "\n\n"; 
	
		
}



void Bank::displayCustomers() {
	if (hasBothAccounts == true) {
		cout << "\t" << firstName << " " << lastName << ": " << SSN << " - " << accountNumber << "($" << balance << "), " << secondAccountNumber << "($" << secondAccountBalance << ")\n";
	} else {
		cout << "\t" << firstName << " " << lastName << ": " << SSN << " - " << accountNumber << "($" << balance << ")\n";
	}
}

void Bank::displaySecondCustomerInfo() {
	if (secondAccountNumber == 0) {

	} else {
		cout << "\tName: " << firstName << " " << lastName << "\n";
		cout << "\tAccount Number: " << secondAccountNumber << "\n";
		if (accountType == 1) {
			cout << "\tAccount Type: Saving\n";
		} else if (accountType == 2) {
			cout << "\tAccount Type: Checking\n";
		}
		cout << "\tBalance: $" << secondAccountBalance << "\n\n"; 
	}
	
}

void Bank::displayBankInfo()  {
	//cout << sizeof(accountNumber) ;
	if (hasBothAccounts == true) {
		if (accountType == 1) {
			cout << "\t" << accountNumber << ": $" << balance << " (checking)\n";
			cout << "\t" <<  secondAccountNumber << ": $" << secondAccountBalance << " (saving)\n";
		} else {
			cout << "\t" <<  accountNumber << ": $" << balance << " (saving)\n";
			cout << "\t" <<  secondAccountNumber << ": $" << secondAccountBalance << " (checking)\n";
		}
		
	} else {
		if (accountType == 1) {
			cout << "\t" <<  accountNumber << ": $" << balance << " (checking)\n";
		} else {
			cout << "\t" <<  accountNumber << ": $" << balance << " (saving)\n";
		}
	}
}

void Bank::deleteAccount(int accountNum, int newSSN) {
	hasBothAccounts = false;
	balance = secondAccountBalance;
	accountNumber = secondAccountNumber;
	if (accountType == 1) {
		accountType = 2;
	} else {
		accountType = 1;
	}
}

void Bank::deleteSecondAccount(int accountNum, int newSSN) {
	hasBothAccounts = false;
}

int Bank::getSSN() {
	return SSN;
}

string Bank::getFirstName() {
	return firstName;
}

string Bank::getLastName() {
	return lastName;
}

int Bank::getAccountNumber() {
	return accountNumber;
}

int Bank::getSecondAccountNumber() {
	return secondAccountNumber;
}

double Bank::getBalance() {
	return balance;
}

double Bank::getSecondAccountBalance() {
	return secondAccountBalance;
}

int Bank::getAccountType() {
	return accountType;
}

bool Bank::checkForSavingsAndCheckingAccount() {
	return hasBothAccounts;
}

int Bank::isChecking() {
	if (accountType == 1) {
		return 1;
	} else {
		return 2;
	}
}



int Bank::getTotalAccounts() {
	
	return totalAccounts;
}

void Bank::deductBalance(int sourceAccountNum, int destinationAccountNum, double transferAmount) {
	if (sourceAccountNum == secondAccountNumber) {
		secondAccountBalance -= transferAmount;
		cout << "Transfer Succeed.\nNew Balance\n\t" << secondAccountNumber << ": $" << secondAccountBalance << "\n";
	} else {
		balance -= transferAmount;
		cout << "Transfer Succeed.\nNew Balance\n\t" << accountNumber << ": $" << balance << "\n";
	}
}

void Bank::transferBalance(int sourceAccountNum, int destinationAccountNum, double transferAmount) {
	if (destinationAccountNum == secondAccountNumber) {
		secondAccountBalance += transferAmount;
		cout << "\t" << secondAccountNumber << ": $" << secondAccountBalance << "\n\n";
	} else {
		balance += transferAmount;
		cout << "\t" << accountNumber << ": $" << balance << "\n\n";
	}
	
}

const int CAPACITY = 20; 

class BankList
{
	public:
		BankList();
		int displayPrompt();
		void readFile();
		void customerList();
		void displayAccountInfo();
		void transferMoney();
		void closeAccount();
		void erase(int SSN);
		void displayCustomerInfo();
	private:
		int mySize;
		string filename;
		Bank myArray[CAPACITY];
		
};

BankList::BankList()     
: mySize(0)
{}

//#0
int BankList::displayPrompt() {
	int selection = 0;
	cout << "Select your choice:" << "\n";
	cout << "\t" << "1. Read customer data file" << "\n";
	cout << "\t" << "2. Close an account" << "\n";
	cout << "\t" << "3. Customer Info" << "\n";
	cout << "\t" << "4. Bank Info" << "\n";
	cout << "\t" << "5. Transfer Money" << "\n";
	cout << "\t" << "6. Customer List" << "\n";
	cout << "\t" << "7. Exit" << "\n";
	while (selection == 0) {
		cin >> selection;
		if (selection > 7) {
			selection = 0;
			cout << "Please enter a valid number \n";
		} else if (selection < 1) {
			selection = 0;
			cout << "Please enter a valid number \n";
		} else {
			return selection;
		}
	}
	return 1;
}

//#1 
void BankList::readFile() {
	
  cout << "Enter a file name: ";
  cin >> filename;
  ifstream f_input(filename);
  if (f_input.fail()){
    cout << "File not found." << endl << "No operation";     
  }
	cout << "Reading data...\n";
	//Gets the size of the inputted data file
	int fileSize;
	f_input >> fileSize;
	int SSN, accountNumber, accountType;
	string firstName;
	string lastName;
	double balance;
	int totalAccounts;
	bool hasBothAccounts = false;

	//Write the check between the files here for duplicate entries
	//Rewrite the account type so its a boolean instead of an int
	


	//if passedCheck is 1 or higher then it failed the check process
	int passedCheck = 0;
	for (int i = 0; i < fileSize; i++) {
		f_input >> SSN;
		f_input >> firstName;
		f_input >> lastName;
		f_input >> accountNumber;
		f_input >> accountType;
		f_input >> balance;

		if(mySize > 0) { 
			
			for(int i = 0; i < mySize; i++) {

				//If the new file has any duplicate SSN's, it will not be added to the customer list 
				if (SSN == myArray[i].getSSN()) {
					passedCheck++;
					
					if (firstName == myArray[i].getFirstName() && lastName == myArray[i].getLastName()) {

						//Checks if there are duplicate accounts
						if (myArray[i].isChecking() == accountType) {
							if (accountType == 1) {
								cout << "Account Creation Failed - " << firstName << " " << lastName << " cannot have two checking accounts\n";
							} else if (accountType == 2) {
								cout << "Account Creation Failed - " << firstName << " " << lastName << " cannot have two saving accounts\n";
							}
							
						} else if (myArray[i].isChecking() != accountType) {
							

							//Code checks if there is repetitive account ids and if so will skip the append process of adding a savings or checkings to a currently existing account
							int checkForRep = 0;
							for (int j = 0; j < mySize; j++) {
								if (myArray[j].getAccountNumber() == accountNumber) {
									checkForRep++;
								}
							}
							if (checkForRep == 0) {
								hasBothAccounts = true;
								if (myArray[i].checkForSavingsAndCheckingAccount() == 1) {
									if (accountType == 1) {
										cout << "Account Creation Failed - " << firstName << " " << lastName << " cannot have two checking accounts\n";
								} else if (accountType == 2) {
										cout << "Account Creation Failed - " << firstName << " " << lastName << " cannot have two saving accounts\n";
									}
								} else {
									
									myArray[i].setAccountDetails(SSN, firstName, lastName, accountNumber, balance, accountType, hasBothAccounts);	
								}
								
								
							} else {
								checkForRep = 0;
							}
							


						}	
					} else {
						//If the names linked to the SSN don't correlate this will sound to the console
						cout << "Account Creation Failed - A customer with the SSN " << SSN << " already exists.\n";
					}
				} else if (myArray[i].getAccountNumber() == accountNumber){ 
					cout << "Account Creation Failed - Account number " << accountNumber << " already exists.\n";
					passedCheck++;
				} 

			}
			if (passedCheck == 0) {
				if (mySize != 20) {
					myArray[mySize].setAccountDetails(SSN, firstName, lastName, accountNumber, balance, accountType, hasBothAccounts);
					mySize++;
				}
				
				
				
			} else {
				passedCheck = 0;
			}
			
		} else {
			
			myArray[mySize].setAccountDetails(SSN, firstName, lastName, accountNumber, balance, accountType, hasBothAccounts);
			
			mySize++;
		}

		
		
	}
	
	
	cout << "Done.\n";
}

//#2
void BankList::closeAccount() {
	int accountNumber, customerSSN, check, check2, passed;
	cout << "Enter Account Number: ";
	cin >> accountNumber;
	for (int i = 0; i < mySize; i++) {
		if (myArray[i].getAccountNumber() == accountNumber) {
			check++;
		} else if (myArray[i].getSecondAccountNumber() == accountNumber) {
			check += 2;
		}
	}
	if (check == 0) {
		cout << "Incorrect account number.\n";
	} else {
		cout << "Enter Customer SSN: ";
		cin >> customerSSN;
			for (int i = 0; i < mySize; i++) {
			if (myArray[i].getSSN() == customerSSN) {
				check2++;
			}
		}
		if (check2 == 0) {
			cout << "Incorrect SSN\n";
		} else {
			passed++;
		}
	}
	if (passed == 1) {
		cout << "Account Closed\n";
		for (int i = 0 ; i < mySize; i++) {
			if (myArray[i].getAccountNumber() == accountNumber) {
				if (myArray[i].getSSN() == customerSSN) {
					if (myArray[i].checkForSavingsAndCheckingAccount() == true) {
						myArray[i].deleteAccount(accountNumber, customerSSN);
					} else {
						erase(customerSSN);
					}
				}
			} else if (myArray[i].getSecondAccountNumber() == accountNumber) {
				if (myArray[i].getSSN() == customerSSN) {
					if (myArray[i].checkForSavingsAndCheckingAccount() == true) {
						myArray[i].deleteAccount(accountNumber, customerSSN);
					} else {
						myArray[i].deleteSecondAccount(accountNumber, customerSSN);
					}	
				}
			}
		}
		// delete(myArray)




	}
}

void BankList::erase(int SSN){
	int index = -1;
	for (int i = 0; i < mySize; i++) {
		if (myArray[i].getSSN() == SSN) {
			index = i;
		}
	}
	if (index == -1){
			
		return;
	}

	for(int i = index; i < mySize; i++) {
		myArray[i] = myArray[i + 1];
	}
	mySize--;

}

//#3
void BankList::displayCustomerInfo() {
	int choice;
	int SSN;
	string lastName;
	int accountNumber;
	int check;
	cout << "SSN (1)/Last Name (2)/Account Number (3): ";
	cin >> choice;
	if (choice == 1) {
		cout << "Enter SSN: "; 
		cin >> SSN;
		for (int i = 0; i < mySize; i++) {
			if (myArray[i].getSSN() == SSN) {
				myArray[i].displayCustomerInfo();
				check++;
			}
		}
		if (check == 0) {
			cout << "No customer with the SSN.\n";
		}
	} else if (choice == 2) { 
		cout << "Enter a last name: ";
		cin >> lastName;
		for (int i = 0; i < mySize; i++) {
			if(myArray[i].getLastName() == lastName) {
				myArray[i].displayCustomerInfo();
				check++;
			}
		}
		if (check == 0) {
			cout << "No customer with the last name.\n";
		}
	} else if (choice == 3) {
		cout << "Enter an account number: ";
		cin >> accountNumber;
		for (int i = 0; i < mySize; i++) {
			if (myArray[i].getAccountNumber() == accountNumber) {
				myArray[i].displayCustomerInfo();
				check++;
			} else if (myArray[i].getSecondAccountNumber() == accountNumber) {
				myArray[i].displayCustomerInfo();
				check++;
			}
		}
		if (check == 0) {
			cout << "No customer with the account number.\n";
		}
	}
}


//#4
void BankList::displayAccountInfo() {
	int accountTotal = 0;
	for (int i = 0; i < mySize; i++) {
		if (myArray[i].checkForSavingsAndCheckingAccount()) {
			accountTotal += 2;
		} else {
			accountTotal++;
		}
	}
	double bankTotal;
	cout << "Number of Accounts: " << accountTotal << "\n";
	for (int i = 0; i < mySize; i++) {
		myArray[i].displayBankInfo();
	}
	cout << "\nNumber of customers: " << mySize << "\n";
	for (int i = 0; i < mySize; i++) {
		myArray[i].displayCustomers();
		if (myArray[i].checkForSavingsAndCheckingAccount()) {
			myArray[i].displaySecondCustomerInfo();
		}
	}
	for (int i = 0; i < mySize; i++) {
		if (myArray[i].checkForSavingsAndCheckingAccount()) {
			bankTotal += myArray[i].getBalance();
			bankTotal += myArray[i].getSecondAccountBalance();
		} else {
			bankTotal += myArray[i].getBalance();
		}
	}
	cout << "\nTotal Balance: $" << bankTotal << "\n\n";

	
}

//#5
void BankList::transferMoney() {
	int sourceAccountNumber, destinationAccountNumber; 
	double transferAmount;
	cout << "Source Account: ";
	cin >> sourceAccountNumber;
	cout << "Destination Account: ";
	cin >> destinationAccountNumber;
	cout << "Money Amount: ";
	cin >> transferAmount;
	int check = 0;
	for (int i = 0; i < mySize; i++) {


		if (myArray[i].getAccountNumber() == sourceAccountNumber) {
			for (int j = 0; j < mySize; j++) {
				if (myArray[j].getAccountNumber() == destinationAccountNumber) {
					if (transferAmount < myArray[i].getBalance()) {
						myArray[i].deductBalance(sourceAccountNumber, destinationAccountNumber, transferAmount);
 						myArray[j].transferBalance(sourceAccountNumber, destinationAccountNumber, transferAmount);
						check++;
					} else {
						cout << "Transfer Fail - Insufficient amount\n";
						check++;
					}
				} else if (myArray[j].getSecondAccountNumber() == destinationAccountNumber) {
					if (transferAmount < myArray[i].getBalance()) {
						myArray[i].deductBalance(sourceAccountNumber, destinationAccountNumber, transferAmount);
 						myArray[j].transferBalance(sourceAccountNumber, destinationAccountNumber, transferAmount);
						check++;
					} else {
						cout << "Transfer Fail - Insufficient amount\n";
						check++;
					}
				}
			}
		}


		else if (myArray[i].getSecondAccountNumber() == sourceAccountNumber) {
			for (int k = 0; k < mySize; k++) {
				if (myArray[k].getAccountNumber() == destinationAccountNumber) {
					if (transferAmount < myArray[i].getSecondAccountBalance()) {
						myArray[i].deductBalance(sourceAccountNumber, destinationAccountNumber, transferAmount);
 						myArray[k].transferBalance(sourceAccountNumber, destinationAccountNumber, transferAmount);
						check++;
					} else {
						cout << "Transfer Fail - Insufficient amount\n";
						check++;
					}
				} else if (myArray[k].getSecondAccountNumber() == destinationAccountNumber) {
					if (transferAmount < myArray[i].getSecondAccountBalance()) {
						myArray[i].deductBalance(sourceAccountNumber, destinationAccountNumber, transferAmount);
 						myArray[k].transferBalance(sourceAccountNumber, destinationAccountNumber, transferAmount);
						check++;
					} else {
						cout << "Transfer Fail - Insufficient amount\n";
						check++;
					}
				}
			}
		}
	}
	if (check == 0) {
		cout << "Transfer Fail - Incorrect account number\n";
	}
	
}


//#6
void BankList::customerList() {
	//fix 6 for if theres nothing in the bank database
	
	cout << "========== Customer List ==========";
	for (int i = 0; i < mySize; i++) {
		cout << "\n";
		myArray[i].displayCustomerList();
	}
	cout << "===================================\n \n";
	
}


int main() {
	BankList account;
  cout << "Welcome to CSUMB Bank" << "\n \n";
	int selection = 0;
	
	while (selection != 7) {
		selection = account.displayPrompt();
		if (selection == 1) {
			account.readFile();
		}
		if (selection == 2) {
			account.closeAccount();
		}
		if (selection == 3) {
			account.displayCustomerInfo();
		}
		if (selection == 4) {
			account.displayAccountInfo();
		}
		if (selection == 5) {
			account.transferMoney();
		}
		if (selection == 6) {
			account.customerList();
		}
	}
	cout << "Bye.";
	return 0;
} 




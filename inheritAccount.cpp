/*
2. Define class Account to represent bank account of customer,
derive classes Savings, FixedDeposit and Current from class Account.
Next derive classes ShortTerm and LongTerm from class FixedDeposit.
Write a program to implement this hierarchical relationship
using parameterized constructor in each class.
*/
#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;
class Account
{
protected:
	char name[20];
	int accNum;
	float blc;
public:
	Account(){}
	Account(char *n,int acc,float balance){
		strcpy(name,n);
		accNum=acc;
		blc=balance;
	}
	void display(){
		cout<<"\nName: "<<name;
		cout<<"\nAccount no.: "<<accNum;
		cout<<"\nBalance while creating: "<<blc;
	}
};
class Savings: public Account
{
protected:
	float savingInterest;
public:
	Savings(){}
	Savings(char *n,int acc,float balance,float sav): Account(n,acc,balance)
	{
		savingInterest=sav;
	}
	void display(){
		Account::display();
		blc+=savingInterest;
		cout<<"\nBalance after Savings deposit: "<<blc;
	}
};
class FixedDeposit: public Account
{
protected:
	float interest;
public:
	FixedDeposit(){}
	FixedDeposit(char *n,int acc,float balance): Account(n,acc,balance)
	{
	}
};
class Current: public Account
{
protected:
	float noInterest;
public:
	Current(){}
	Current(char *n,int acc,float balance,float noIn): Account(n,acc,balance)
	{
		noInterest=noIn;
	}
	void display(){
		Account::display();
		blc+=noInterest;
		cout<<"\nBalance after Current deposit: "<<blc;
	}
};
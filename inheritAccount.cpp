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
class ShortTerm: public FixedDeposit
{
public:
	ShortTerm(){}
	ShortTerm(char *n,int acc,float balance,float in1): FixedDeposit(n,acc,balance)
	{
		interest=in1;
	}
	void display(){
		Account::display();
		blc+=interest;
		cout<<"\nBalance after ShortTerm FixedDeposit: "<<blc;
	}
};
class LongTerm: public FixedDeposit
{
public:
	LongTerm(){}
	LongTerm(char *n,int acc,float balance,float in2): FixedDeposit(n,acc,balance)
	{
		interest=in2;
	}
	void display(){
		Account::display();
		blc+=interest;
		cout<<"\nBalance after LongTerm FixedDeposit: "<<blc;
	}
};
int main()
{
	int choice,ch;
	Savings s("Bikram",1234,2000,20.10);
	ShortTerm st("Bikram",1234,2000,100);
	LongTerm lt("Bikram",1234,2000,200);
	Current c("Bikram",1234,2000,0);
	cout<<"\nEnter choice for creating account \n1. Savings deposit \n2. FixedDeposit \n3. Current deposit\n\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			s.display();
			break;
		case 2:
			cout<<"\nEnter choice for FixedDeposit \n1. ShortTerm \n2. LongTerm\n\n";
			cin>>ch;
			switch(ch)
			{
				case 1:
					st.display();
					break;
				case 2:
					lt.display();
					break;
				default:
					cout<<"\nPlease enter correct choice.";
			}
			break;
		case 3:
			c.display();
			break;
		default:
			cout<<"\nPlease enter correct choice.";
	}
	getch();
	return 0;
}
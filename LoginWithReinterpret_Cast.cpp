#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <regex>
using namespace std;
const char *datafile="userData.dat";
class User
{
private:
	char name[50],username[50],email[50],pw[50];
public:
	void registration();
	int checkdata(char *value);//for checking existence of email and username.
	void login();
	void displayInfo();
	void menu();
};
void User:: registration()
{
	system("cls");
	int flag=0;
  //creating temporary data variable to reduce the overwritten data member
  //from checking reinterpret_cast operator
	char name1[50],username1[50],email1[50];

	cout<<"\n\n For the registration: \n";
	cout<<" Enter full name: ";
	cin>>ws;
	cin.getline(name1,50);
	while(!regex_match(name1,regex("[A-Za-z]+(\\s[A-Za-z]+){1,3}"))){
		cout<<"\n Not valid or full name. \n Please re-enter: ";
		cin.getline(name1,50);
	}

	cout<<" Enter email: ";
	cin.getline(email1,50);
	//checking validation
	while(!regex_match(email1,regex("\\w+(\\.)?(\\w*)\\@\\w+(\\.\\w+)+"))){
		cout<<"\n Not valid email. \n Please re-enter: ";
		cin.getline(email1,50);
	}
	//checking existence
	flag=checkdata(email1);
	while(flag==1){
		cout<<"\n Email already exist. Please enter other valid email: ";
		cin.getline(email1,50);
		flag=checkdata(email1);
	}

	cout<<" Enter username: ";
	cin.getline(username1,50);
	while(!regex_match(username1,regex("(\\w+){3,}"))){
		cout<<"\n Not valid for non-word and less than 3 character. \n Please re-enter: ";
		cin.getline(username1,50);
	}
	flag=0;
	flag=checkdata(username1);
	while(flag==1){
		cout<<"\n Username already exist. Please enter other valid username: ";
		cin.getline(username1,50);
		flag=checkdata(username1);
	}

	strcpy(name,name1);
	strcpy(email,email1);
	strcpy(username,username1);
	cout<<" Enter password: ";
	cin.getline(pw,50);
	while(!regex_match(pw,regex("(\\w+){4,}"))){
		cout<<"\n Not valid for less than 4 character. \n Please re-enter: ";
		cin.getline(pw,50);
	}
	//writing record in file;
	ofstream outfile(datafile,ios::app);
	outfile.write(reinterpret_cast<char*>(this),sizeof(*this));
	outfile.close();
	cout<<"\n\n Successfully registered.";
	displayInfo();
	cout<<endl;
	system("pause");
	system("cls");
}
int User:: checkdata(char *value)
{
	int flag=0;

	ifstream infile(datafile);
	if(!infile)
	{
		return 0;
	}
  //checking if email and username exist.
	while(!infile.eof())
	{
		if(infile.read(reinterpret_cast<char*>(this),sizeof(*this))){
			if((strcmp(email,value)==0)or(strcmp(username,value)==0)){
				flag=1;
				break;
			}
		}
	}
	infile.close();
	if(flag==1)
		return 1;
	else
		return 0;
}
void User:: login()
{
	//reading record from file;
	system("cls");
	int flag=0;
	char user[50],pass[50];

	cout<<"\n\n For the login: \n";
	cout<<" Enter username: ";
	cin>>ws;
	cin.getline(user,50);
	cout<<" Enter password: ";
	cin.getline(pass,50);

	ifstream infile(datafile);
	if(!infile)
	{
		cout<<"\n Please, register first"<<endl;
		return;
	}
  //Comparing username and password from file
	while(!infile.eof())
	{
		if(infile.read(reinterpret_cast<char*>(this),sizeof(*this))){
			if((strcmp(username,user)==0)and(strcmp(pw,pass)==0)){
				flag=1;
				break;
			}
		}
	}
	infile.close();
	if(flag==1)
		displayInfo();
	if(flag==0)
		cout<<"\n Username or password incorrect or doesn't registered.";
	cout<<endl;
	system("pause");
	system("cls");
}
void User::displayInfo()
{
	system("cls");
	cout<<"\n\n The details of user: ";
	cout<<"\n Name: "<<name;
	cout<<"\n Email: "<<email;
	cout<<"\n Username: "<<username;
	cout<<"\n Password: "<<pw;
}
void User:: menu()
{
	int choice;
while(1)
	{
		cout<<"\n\n OPTION \n 1.Registration \n 2.Login \n 3.Exit \n";
		cout<<"\n Enter your choice ";
		cin>>choice;
		switch(choice)
		{
			case 1: registration(); break;
			case 2: login(); break;
			case 3: exit(0);
			default: cout<<"\n\n Please re-enter correct option";
		}
}
}
int main()
{
	User u;
	u.menu();
	system("pause");
	return 0;
}

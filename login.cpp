#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
const char *datafile="userData.dat";
class User
{
private:
	static int id;
	char name[20],username[20],email[20],pw[20];
	char user[20],pass[20];
public:
	void registration();
	void login();
	void displayInfo();
	void write_record();
	void read_record();
	void file_handler(string);
	void menu();
};
int User::id=0;
void User:: registration()
{
	cout<<"\n For the registration: \n";
	cout<<" Enter name: ";
	cin>>ws;
	cin.getline(name,20);
	cout<<" Enter email: ";
	cin.getline(email,20);
	cout<<" Enter username: ";
	cin.getline(username,20);
	cout<<" Enter password: ";
	cin.getline(pw,20);
	file_handler("registration");
}
void User:: login()
{
	cout<<"\n For the login: \n";
	cout<<" Enter username: ";
	cin>>ws;
	cin.getline(user,20);
	cout<<" Enter password: ";
	cin.getline(pass,20);
	file_handler("login");
}
void User::displayInfo()
{
	cout<<"\n The details of user: ";
	cout<<"\n Name: "<<name;
	cout<<"\n Email: "<<email;
	cout<<"\n Username: "<<username;
	cout<<"\n Password: "<<pw;
}
void User::write_record()
{
	ofstream outfile(datafile,ios::app|ios::binary);
	if(outfile)
		id++;
	outfile<<id<<" "<<name<<" "<<email<<" "<<username<<" "<<pw<<endl;
	cout<<"\n Successfully registered.";
}
void User::read_record()
{
	int i,n,flag=0,id1;
	char name1[20],email1[20],username1[20],pw1[20];
	ifstream infile(datafile,ios::binary);

	if(!infile)
	{
		cout<<"\n Please, register first"<<endl;
		return;
	}
	infile.seekg(0,ios::end);
	n=infile.tellg()/sizeof(*this);
	for(i=0;i<n;i++)
	{
		infile.seekg(i*sizeof(*this));
		infile>>id1>>name1>>email1>>username1>>pw1;
		bool logic1,logic2;
		if(strcpy(username1,user)==0)
			logic1=true;
		if((strcpy(pw1,pass)==0))
			logic2=true;
		if(logic1&&logic2){
				displayInfo();
				flag=1;
				break;
			}
	
	}
	if(flag==0)
		cout<<"\n Username or password incorrect or doesn't registered.";
}
void User::file_handler(string s)
{
	//for registration
	if(s=="registration"){
		write_record();
	}
	//for login
	if(s=="login"){
		read_record();
	}
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

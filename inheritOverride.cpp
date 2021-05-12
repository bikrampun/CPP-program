/*3. Define a class Rectangle withdata members to represent
length and breadth and member function to input and
calculate the area. Derive class Box with appropriate
data member to represent height and member function to
calculate surface area. Use same function name input() and
calculate() in both the classes and implement function overriding.*/
#include <iostream>
#include <conio.h>
using namespace std;
class Rectangle
{
protected:
	float length,breadth,area;
public:
	void input(){
		cout<<"\nEnter length:";
		cin>>length;
		cout<<"Enter breadth:";
		cin>>breadth;
	}
	void calculate(){
		area=length*breadth;
		cout<<"\nArea="<<area<<endl;
	}
	void display(){
		cout<<"\nThe length: "<<length<<" and breadth: "<<breadth<<endl;
	}
};
class Box: public Rectangle
{
protected:
	float height,sa;
public:
	void input(){
		Rectangle:: input();
		cout<<"\nEnter height:";
		cin>>height;
	}
	void calculate(){
		Rectangle:: calculate();
		sa=2*(length*breadth+length*height+breadth*height);
		cout<<"Total surface area= "<<sa<<endl;
	}
	void display(){
		Rectangle:: display();
		cout<<"\nThe height: "<<height<<endl;
	}
};
int main()
{
	Box b;
	b.input();
	b.display();
	b.calculate();
	getch();
	return 0;
}
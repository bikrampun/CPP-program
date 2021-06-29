/*
Write a program to read value of sine and find its inverse.
Raise different exceptions if the value of sine is greater than 1 and less than -1.
*/
#include <iostream>
#include <cmath>
using namespace std;
class Sine
{
private:
	float x;
public:
	class LT{};
	class GT{};
	void read(){
		cout<<"Enter value of x to find sine and its inverse: ";
		cin>>x;
		if(x>1)
			throw GT();
		else if(x<-1)
			throw LT();
	}
	void display(){
		cout<<"\nsin"<<x<<"="<<sin(x)<<"\nArcsin"<<x<<"="<<asin(x);
	}
};

int main()
{
	Sine s;
	try{
		s.read();
		s.display();
	}
	catch(Sine::LT){
		cout<<"Exception: given value is less than -1";
	}
	catch(Sine::GT){
		cout<<"Exception: given value is greater than 1";
	}
	cout<<endl;
	system("pause");
	return 0;
}

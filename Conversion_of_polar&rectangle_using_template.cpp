/*
Define two classes “Polar” and “Rectangle” to represent points in polar and rectangle system.
Use conversion routines to convert from one system to another system using template.
*/
#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;
template <typename T1>   //can be use template <class T1>
class Polar
{
private:
	T1 radius,angle; //angle in radian;
public:
	Polar(){}
	Polar(T1 x,T1 y):radius(x),angle(y){}
	void display(){
		cout<<"("<<radius<<","<<angle<<")";
	}
	T1 getRadius(){ return radius;}
	T1 getAngle(){ return angle;}
};

template <typename T2>
class Rectangular
{
private:
	T2 xco,yco;
public:
	Rectangular(){}
	Rectangular(T2 x,T2 y):xco(x),yco(y){}
	void display(){
		cout<<"("<<xco<<","<<yco<<")";
	}
	Rectangular(Polar<T2> p){
		xco=p.getRadius()*cos(p.getAngle());
		yco=p.getRadius()*sin(p.getAngle());
	}
	operator Polar<T2>(){
		float r=sqrt(pow(xco,2)+pow(yco,2));
		float theta= atan(yco/ xco); 
		return Polar<T2>(r,theta); //return temporary polar obj(constructor) 
	}
};
int main()
{
	Polar<double> p1(2,1);
	Rectangular<double>r1;
	cout<<"\nDisplay of polar co-ordinates:\n";
	p1.display();
	r1=p1; //r1=Rectangular(p1);
	cout<<"\nDisplay of rectangular co-ordinates:\n";
	r1.display();

	Polar<float>p2;
	Rectangular<float>r2(3.51,1.92);
	cout<<"\nDisplay of rectangular co-ordinates:\n";
	r2.display();
	p2=r2; //p2=r2.operator Polar();
	cout<<"\nDisplay of polar co-ordinates:\n";
	p2.display();
	getch();
	return 0;
}

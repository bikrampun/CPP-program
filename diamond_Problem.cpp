/* Define a class Student, derive classes AcademicMarks and PracticalMarks from class Student.
Next derive class Result from AcademicMarks and PracticalMarks. Calculate the result of student.
Use parameterized constructor in each class to set the initial values of data.*/
#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;
class Student
{
protected:
	char name[20];
	int roll;
public:
	Student(){}
	Student(char *n,int r){
		strcpy(name,n);
		roll=r;
	}
	void display(){
		cout<<"Name: "<<name<<"\nRoll: "<<roll;
	}
};
class AcademicMarks: virtual public Student
{
protected:
	float aMark;
public:
	AcademicMarks(){}
	AcademicMarks(char *n,int r,float m1): Student(n,r),aMark(m1){}
	void show(){
		cout<<"\nAcademicMarks: "<<aMark;
	}
};
class PracticalMarks: virtual public Student
{
protected:
	float pMark;
public:
	PracticalMarks(){}
	PracticalMarks(char *n,int r,float m2): Student(n,r),pMark(m2){}
	void show(){
		cout<<"\nPracticalMarks: "<<pMark;
	}
};
class Result: public AcademicMarks,public PracticalMarks
{
protected:
	float total;
public:
	Result(){}
	Result(char *n,int r,float m1,float m2): Student(n,r),AcademicMarks(n,r,m1),PracticalMarks(n,r,m2){}
	//Since the order of inheritance,constructor called as,
	//Student 1st,AcademicMarks 2nd and finally PracticalMarks 3rd(last).
	void show(){
		AcademicMarks::show();
		PracticalMarks::show();
	}
	void calculate(){
		total=aMark+pMark;
		cout<<"\nTotal marks: "<<total;
	}
};
int main()
{
	Result r("Ram",17,70,80);
	r.display();
	r.show();
	r.calculate();
	getch();
	return 0;
}
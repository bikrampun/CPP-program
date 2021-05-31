/*
PYRAMID PATTERN
    A
   ABC
  ABCDE
 ABCDEFG
ABCDEFGHI
*/
#include <iostream>
using namespace std;
int main()
{
	char str[]="ABCDEFGHI";
	int i,j,k=4,l=1,m;
	for (i=0;i<5;i++)
	{
		for(j=0;j<9;j++)
		{
			if(j<k||j>=k+l){
				cout<<" ";
				m=0;
			}	
			else{
				cout<<str[m++];
			}
		}
		cout<<endl;
		k--;
		l+=2;
	}
	system("pause");
	return 0;
}

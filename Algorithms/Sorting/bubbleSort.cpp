//bubble sort
#include <iostream>
using namespace std;
void bubbleSort(int a[],int n)
{
	//n is size of array
	for (int i=0;i<n-1;i++)
	{
		//first, we find max value in unsorted array
		//then sorting from right index
		for(int j=0;j<(n-1)-i;j++){
					//arraySize-sortedNumber
			if(a[j]>a[j+1])
			{
				//swapping
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
int main()
{
	int a[]={9,4,8,7,3,5,1,2};
	int n;
	n=sizeof(a)/sizeof(int);
	cout<<"Before sorting array:\n";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	bubbleSort(a,n);
	cout<<endl<<"After sorting array:\n";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	system("pause");
	return 0;
}
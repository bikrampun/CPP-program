//selection sort
#include <iostream>
using namespace std;
void selectionSort(int *a,int n)
{
	//n is size of array
	for (int i=0;i<n-1;i++)
	{
		//first, we find min value in unsorted array
		//then sorting from left index
		int min=i;
		//finding min value checking via index
		for(int j=i+1;j<n;j++)
		{
			//if find min in array the index is checked
			if(a[min]>a[j])
				min=j;
		}
		//swapping through index(i.e by selection)
		int temp=a[i];
		a[i]=a[min];
		a[min]=temp;
		//now i++ and again select to sort
	}
}
int main()
{
	int a[]={9,4,8,7,3,5,1,2};
	int n;
	n=sizeof(a)/sizeof(int);
	cout<<"Before sorting array:\n";
	for(int i=0;i<n;i++)
		cout<<a[i]<<endl;
	selectionSort(a,n);
	cout<<"After sorting array:\n";
	for(int i=0;i<n;i++)
		cout<<a[i]<<endl;
	cout<<endl;
	system("pause");
	return 0;
}
#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int *histogram;
	int *right_max;
	int *left_max;
	int temp=-1;
	histogram=(int*) malloc(sizeof(int)*n);
	left_max=(int*) malloc(sizeof(int)*n);
	right_max=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
		cin>>histogram[i];
	}
	for(int i=0;i<n;i++)
	{	
		if(temp<histogram[i])
		{
			temp=histogram[i];
		}
		left_max[i]=temp;

	}
	temp=-1;
	for(int i=n-1;i>=0;i--)
	{	
		if(histogram[i]==left_max[i])
			temp=left_max[i];
		else if(temp<histogram[i])
		{
			temp=histogram[i];
		}
		right_max[i]=temp;
	}
	int volume=0;
	for(int i=0;i<n;i++)
	{
		int min=right_max[i]>left_max[i]?left_max[i]:right_max[i];
		volume+= min-histogram[i];
	}
	cout<<"volume is ::"<<volume<<endl;
}

/*
Here, Greedy approach is used from the observation that to minimize the difference between number of choclates, we need to 
take packets with consecutive number of chococlates.

Minimize ya maximize aaya to greedy use karo

TC => O(nlogn) for sorting
*/

#include<iostream>
#include<climits>   //to use INT_MAX variable
#include<algorithm> //to use sort()

using namespace std;

int min(int a,int b)
{
	if(a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main()
{
	int *a,n,m;
	
	cout<<"\nHow many elements do you want in the array? => ";
	cin>>n;
	
	cout<<"\nEnter the number of students plz => ";
	cin>>m;
	
	//corner cases:
	if(n<0)
	{
		cout<<"\nSize can't be negative!";
	}
	else if(n==0)
	{
		return 0;
	}
	else if(m<0)
	{
		cout<<"\nNumber of students can't be negative!";
	}
	else if(m>n)
	{
		cout<<"\nNumber of students can't be more than packets available!";
	}
	else
	{
		//allocating array dynamically
		a=(int*)malloc(n*sizeof(int));
	
		//feeding the array 
		for(int i=0;i<n;i++)
		{
			cout<<"\n\nElement no "<<i+1<<" ";
			cin>>a[i];
		}
		
		//Its a clear observation that we should distribute packets such that consecutive array elements are distributed
		//in order to get minimum difference.
		
		//sort the array first
		sort(a,a+n);
		
		int i=0,diff,minDiff=INT_MAX;
		//use sliding window technique
		int window_left;        //left end of window
		int window_right;   //right end of window
		
		//slide this window through 0.....n
		for(i=0;(i+m-1)<n;i++)
		{
			window_left=i;        
		    window_right=i+m-1;   
			diff=a[window_right]-a[window_left];
			minDiff=min(minDiff,diff);
		}
		cout<<"\nThe minimum possible difference is => "<<minDiff;
	}
	
return 0;	
}




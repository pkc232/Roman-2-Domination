#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n , sum = 0 ;
	cout << "Enter number of vertices n : " ;
	cin >> n ;
	if(n%2==0)
	{
		for(int i=3;i<=n-3;i=i+2)
		{
			sum += i ;
		}
		sum = sum*2 ;
		sum = sum + (4*n-4)/2 ; 
	}
	else
	{
		for(int i=3;i<=n-4;i=i+2)
		{+
			sum += i ;
		}
		sum *= 2 ;
		sum = sum + (n-2) + (4*n-4)/2 ;
	}
	cout << "sum : " << sum << endl ;
	return 0 ;
}
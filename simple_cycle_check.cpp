#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define pii pair<int,int>
#define large_int 2139062143
#define large_long_long_int 9187201950435737471
using namespace std;

#define NOV 100005


int main(){
	ios_base::sync_with_stdio(false);
	int x,y,z;
	for(int i=1;i<=10000000;i++){
		x = (i+1)/2;
		y = (i+2)/3;
		z = (i/2);
		// if(x==y)
			// cout<<i<<endl;
		if(y==z)
			cout<<i<<endl;
	}
}
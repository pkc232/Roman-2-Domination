#include <bits/stdc++.h>
#include <chrono> 
#define pb push_back

using namespace std;
using namespace std::chrono;
#define NOV 10000

vector<int> tree[30];
int val[30];
int n;
int cntNeighbour[30];
int isGiven[30];
int deg[30];
int cntPriv[30];

void assignPrivate(){
	for(int i = 1;i<=n;i++){
		if(deg[i] == 1)
		{
			for(int v:tree[i]){
				cntPriv[v]++;
			}
		}
	}
}

void assign2(){

	for(int i=1;i<=n;i++){
		if(cntPriv[i] >= 3){
			val[i] = 2;
			for(int v:tree[i]){
				if(deg[v] == 1){
					val[v] = 0;
				}
			}
		}
		else
		{
			for(int v:tree[i]){
				if(deg[v]==1){
					val[v] = 1;
				}
			}
		}
	}
}

void assign1(){
	for(int i=1;i<=n;i++){
		if(val[i] == -1){
			if(cntPriv[i]>=2){
				val[i] = 0;
			}
			else if(cntPriv[i]>=1&&cntPriv[i]==deg[i]-1)
			{	
				cout<<"Doing for i"<<endl;
				val[i] = 0;
				for(int v:tree[i]){
					if(deg[v]>1)
						val[v] = 1;
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		tree[u].pb(v);
		deg[u]++;
		tree[v].pb(u);
		deg[v]++;
	}
	memset(val,-1,sizeof(val));

	auto start = high_resolution_clock::now(); 
	assignPrivate();
	assign2();
	assign1();
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start); 
	cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
	
	for(int i=1;i<=n;i++){
		cout<<i<<" "<<cntPriv[i]<<endl;
	}
	for(int i=1;i<=n;i++)
		cout<<val[i]<<" ";
	cout<<endl;
	return 0;
}
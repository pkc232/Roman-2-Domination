#include <bits/stdc++.h>
#define pb push_back
#include <chrono> 
using namespace std;
using namespace std::chrono;


vector<int> graph[30];
vector<int> val(30);
int n, e;
vector<vector<int> >DS;
int dmval;

int dominationVal(){
	int s=0;
	for(int i=1;i<=n;i++)
		s += val[i];
	return s;
}

int isDominated(int u){
	if(val[u])
		return 1;
	int cnt = 0;
	for(int v:graph[u])
		cnt += val[v];
	return (cnt>=2);
}

int isGraphDominated(){
	int ans = 1;
	for(int i=1;i<=n;i++){
		ans &= isDominated(i);
		if(!ans)
			return 0;
	}
	return 1;
}


void assign(int u){
	if(u==n+1)
	{
		if(isGraphDominated()){
			int x = dominationVal(); 
			if(x<dmval)
			{
				dmval = x;
				DS.clear();
				DS.pb(val);
			}
			else if(x==dmval)
				DS.pb(val);
		}
		return;
	}

	val[u] = 0;
	assign(u+1);
	val[u] = 1;
	assign(u+1);
	val[u] = 2;
	assign(u+1);
}





int main(int argc, char const *argv[]) {
	cin>>n>>e;
	for(int i=0; i<e; i++) {
		int u,v;
		cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	dmval = INT_MAX;
	auto start = high_resolution_clock::now(); 
	assign(1);
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start); 
	cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
	cout<<"Minimum Roman 2 Dominating Sets\n";

	for(auto v:DS) {
		cout<<":::"<<endl;
		for(int i=1; i<=n; i++){
			cout<<v[i]<<" ";
		}
		cout<<endl<<endl;
	}
	cout<<dmval<<endl;
	return 0;
}


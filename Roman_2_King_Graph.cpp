#include <bits/stdc++.h>
#include <chrono> 
#define pb push_back
using namespace std;
using namespace std::chrono;


int val[20][20];
int n;
int dx[] = {-1,0,1};
int dy[] = {-1,0,1};
int mincnt = 400;
int vis[20][20];
int currentConfig;


int isPossib(int r,int c){
	if(r>=1&&r<=n&&c>=1&&c<=n)
		return 1;
	return 0;
}

int isDominated(int r, int c){
	int cnt = 0,nr,nc;
	if(val[r][c])
		return 1;

	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			nr = r+dx[i];
			nc = c+dy[j];
			if(isPossib(nr, nc)){
				cnt += val[nr][nc];
			}
			if(cnt>=2)
				return 1;
		}
	return 0;
}

int moveAhead(int num){
	int r = (num-1)/n;
	if(r==0)
		return 1;
	int i = r;
	// for(int i=1;i<r;i++)
	{
		for(int j=1;j<=n;j++){
			if(!isDominated(i,j))
				return 0;
		}
	}
	return 1;
}

int isValidConfig(){
	int fl = 1;
	int c = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			fl &= isDominated(i,j);
			c += val[i][j];
			if(!fl)
				return 0;
		}
	}

	if(fl)
		mincnt = min(mincnt,c);

	return fl;
}

void generateAll(int num){
	if(num>n*n){
		if(isValidConfig()){
		}
		return;
	}
	// cout<<currentConfig++<<endl;

	if((num%n==0)&&!moveAhead(num))
		return;
	int r = (num-1)/n+1;
	int c = (num-1)%n+1;
	val[r][c] = 0;
	generateAll(num+1);
	val[r][c] = 1;
	generateAll(num+1);
	val[r][c] = 2;
	generateAll(num+1);
}

int main(int argc, char const *argv[])
{
	cin>>n;
	currentConfig=0;
	auto start = high_resolution_clock::now(); 
	generateAll(1);
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start); 
	cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
	cout<<mincnt<<endl;
	return 0;
}
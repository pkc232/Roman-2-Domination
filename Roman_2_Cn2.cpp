#include <bits/stdc++.h>
#include <chrono> 
#define pb push_back
using namespace std;
using namespace std::chrono;


int val[20];
int graph[20][20];
int n;
bool vis[20];
int dx[] = {1,2,-1,-2};
int mincnt = INT_MAX;
int currentcnt;
int valans[20];

bool isDominated(int k) {
	if (val[k])
		return true;

	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		cnt += val[(k + dx[i] + n)%n];
		if (cnt >= 2)
			return true;
	}
	return false;
}

bool isValidConfig() {
	for (int i = 0; i < n; i++) {
		if (!isDominated(i))
			return false;
	}
	return true;
}

int getSum() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += val[i];
	}
	return sum;
}

bool visited() {
	for (int i = 0; i < n; i++)
		if (!vis[i])
			return false;
	return true;
}

void generateAll(int num) {
	if (num > n) {
		if (isValidConfig()) {
			currentcnt = getSum();
			if (currentcnt < mincnt) {
				mincnt = currentcnt;
				for (int i = 0; i < n; i++)
					valans[i] = val[i];
			}
		}
		return;
	}
	val[num] = 0;
	generateAll(num + 1);
	val[num] = 1;
	generateAll(num + 1);
	val[num] = 2;
	generateAll(num + 1);
}



int main(int argc, char const *argv[]) {
	// cin>>n;
	for (n = 3; n < 30; n++){
		cout<<"=================== For n = "<<n<<" ==========================\n";
		memset(vis, false, sizeof vis);
		memset(val, 0, sizeof val);
		memset(valans, 0, sizeof valans);
		currentcnt = 0;
		mincnt = INT_MAX;
		auto start = high_resolution_clock::now(); 
		generateAll(0);
		auto stop = high_resolution_clock::now(); 
		auto duration = duration_cast<microseconds>(stop - start); 
		cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
		int formula_ans = ceil((n + 2)/3);
		printf("Calculated ans = %d, Formula ans = %d\n", mincnt, formula_ans);
		cout<<"Configuration: ";
		for(int j = 0; j < n; j++)
			cout<<valans[j]<<" ";
		cout<<endl;
	}
	return 0;
}
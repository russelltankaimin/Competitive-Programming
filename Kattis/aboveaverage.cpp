#include<iostream>
#include<algorithm>
#include<iterator>
#include<numeric>
#include<map>
#include<set>
#include<bitset>
#include<iomanip>
#include<string>
#include<vector>
#include<array>
#include<utility>
#include<cmath>
#include<cctype>
using namespace std;
typedef long long ll;
typedef bitset<22> BITS;
#define ALL(x) x.begin(),x.end()
#define UNIQUE(x) (x).resize(unique(ALL(x)) - x.begin())

template<typename T>
void display(T a){
	cout << "[ ";
	for(int i = 0; i < a.size();i++){
		cout << a[i] << " ";
	}
	cout <<" ]"<< endl;
}


void solve(){
	int n ; cin >> n;
	int sum = 0;
	vector<int> a(n);
	for(int i = 0; i < n;i++){
		cin >> a[i];
		sum+=a[i];
	}
	cout << fixed;
	cout << setprecision(3);
	double mean = sum / n;
	int p = 0;
	for(int i = 0; i < n; i++){
		p += (a[i] > mean);
	}
	cout << (double)(100*p)/n << "%" << endl;
	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

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
	int t; cin >> t;
	vector<vector<int>>ss(t);
	for(int i = 0; i < t; i++){
		for(int j = 0; j < 3;j++){
				int v; cin >> v;
				ss[i].push_back(v);
			}
	}
	for(int i = 1; i < t+1; i++){
		ll lo = pow(10,9); ll hi = 0;
		ll lic = pow(10,9); ll hic = 0;
		ll ans = 0;
		for(int j = 0; j < i; j++){
			// find max and min
			lo = min(lo,ss[j][0]);
			hi = max(hi,ss[j][1]);
		}
		for(int j = 0; j < i; j++){
			if(s[j][0] == lo){lic = min(lic,s[j][2]);}
			if(s[j][1] == hi){hic = min(hic,s[j][2]);}
		}
		// check if they are the same 
		for(int j = 0; j < i; j++){
			if(s[j][0] == lo && s[j][1] == hi){
				ans += 
				}
		}
	}

}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

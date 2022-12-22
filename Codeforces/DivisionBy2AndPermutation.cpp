#include "/Users/russelltankaimin/bits/stdc++.h"
//#include "bits/stdc++.h"
/*
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
#include<deque>
#include<array>
#include<utility>
#include<cmath>
#include<cctype>
*/
using namespace std;
typedef long long ll;
typedef bitset<22> BITS;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define ALL(x) x.begin(),x.end()
#define UNIQUE(x) (x).resize(unique(ALL(x)) - x.begin())
template<typename T,typename U>
void debug(pair<T,U> a, bool submit){
	if(!submit){
		cout <<"[ ";
	}
	for(int i = 0; i < a.size();i++){
		cout << "(" << a[i].first << "," << a[i].second <<")" << " ";
	}
		cout <<(!submit ? " ]" : "")<< endl;
}
template<typename T>
void debug(T a, bool submit){
	if(!submit){
		cout <<"[ ";
	}
	for(int i = 0; i < a.size();i++){
		cout << a[i] << " ";
	}
		cout <<(!submit ? " ]" : "")<< endl;
}

bool possible(ll a, ll b){
	cout << "testing on " << a << " " << b << endl;
	while( a > b){
		a/=2;
	}
	cout << "outcome " << (a==b ? "True" : "FALSE") << endl;
	return a == b;
}

void solve(){
	int n; cin >> n;
	vector<ll> a(n);
	for(auto &b : a){
		cin >> b;
	}
	sort(ALL(a));
	debug(a,false);
	for(ll i = 0; i < n; i++){
		if(a[i] == i + 1){
			continue;
		}else{
			ll p = a[i];

		}
	}
	cout << "YES" << endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

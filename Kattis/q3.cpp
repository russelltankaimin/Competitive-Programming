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
template<typename T, typename U, typename V>
T min(U a, V b){
  return a < b ? a : b;
}
template<typename T, typename U, typename V>
T max(U a, V b){
  return a > b ? a : b;
}
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

void solve(){
  int n, m, d; cin >> n >> m >> d;
  vector<pair<pair<int,int>, int> > tt;
  int lo = 150000;
  int hi = 0;
  vector<bool> time(m+1,false);
  for(int i = 0; i < n; i++) {
    pair<int,int> p;
    pair<pair<int, int> , int> pp;
    cin >> p.first >> p.second >> pp.second;
    pp.first = p;
    tt.push_back(p);
    lo = min(lo, p.first);
    hi = max(hi, p.second);
    time[pp.second] = true;
  }
  sort(ALL(tt),[](pair<pair<int,int>, int> a, pair<pair<int,int>, int> b) {
      return a.second < b.second;
      });
  int cost = 0;
  for (int i = 0; i < m + 1; i++ ) {
    if (time[i]) {
      
    } else {
      continue;
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

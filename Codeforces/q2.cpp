//#include "/Users/russelltankaimin/bits/stdc++.h"
//#include "bits/stdc++.h"

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
#include<unordered_map>
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
  int n; cin >> n;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int b; cin >> b;
    a.push_back(b);
  }
  unordered_map<int,int> out;
  unordered_map<int,int> cache;
  out[0] = 0;
  for (auto &p : a) {
    cache = out;
    for (auto &it : cache) {
      int k = it.first;
      out[k + p] = max(out[k + p], cache[k] + p);
      out[k - p] = max(out[k - p], cache[k]);
    }
  }
  cout << out[0];
}

int main(){
	int t = 1;
	while(t--){
		solve();
	}
	return 0;
}

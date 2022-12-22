#include "bits/stdc++.h"

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
  ifstream MyReadFile("in1");
  string text;
  vector<pair<int,int>> a;
  for (int i = 0; i < 12; i++) {
    a.push_back(make_pair(0,0));
  }
  while (getline(MyReadFile, text)) {
    for (int i = 0; i < 12; i++) {
      if (text[i] == '0') {
        a[i].first++;
      } else {
        a[i].second++;
      }
    }
  }
  int gamma = 0;
  int epsilon = 0;
  int exponent = 1;
  for (int i = 11; i >= 0; i--) {
    cout << a[i].first << endl;
    cout << a[i].second << endl;
    if (a[i].first > a[i].second) {
      // zero is the most common bit
      // one is the least common bit
      epsilon += exponent;
    } else {
      gamma += exponent;
    }
    exponent <<= 1;
  }
  cout << gamma * epsilon << endl;
}

int main(){
  solve();
	return 0;
}

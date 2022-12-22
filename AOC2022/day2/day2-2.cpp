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
  vector<string> commands(1000);
  vector<int> d(1000);
  long horizontal = 0, vertical = 0;
  int aim = 0;
  for (int i = 0; i < 1000; i++) {
    cin >> commands[i] >> d[i];
    if (commands[i] == "up") {
      //vertical -= d[i];
      aim -= d[i];
    } else if (commands[i] == "down") {
      //vertical += d[i];
      aim += d[i];
    } else {
      horizontal += d[i];
      vertical += d[i] * aim;
    }
  }
  cout << horizontal * vertical << endl;
}

int main(){
  solve();
	return 0;
}

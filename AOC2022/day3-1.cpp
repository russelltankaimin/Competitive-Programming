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

int priority(char A) {
  if (A >= 97) {
    return A % 96;
  } else {
    return (A % 64) + 26;
  }
}

void solve(){
  int count = 0;
  vector<string> rs = vector<string>(300);
  for (int i = 0; i < 300; i++) {
    cin >> rs[i];
    unordered_map<char, int> map1;
    unordered_map<char, int> map2;
    for (int j = 0; j < rs[i].length(); j++) {
      if (j < rs[i].length() / 2) {
        if (map1.count(rs[i][j]) == 0) {
          map1[rs[i][j]] = 1;
        } else {
          map1[rs[i][j]]++;
        }
      } else {
        if (map2.count(rs[i][j]) == 0) {
          map2[rs[i][j]] = 1;
        } else {
          map2[rs[i][j]]++;
        }
      }
    }
    for (int j = 0; j < rs[i].length() / 2; j++) {
      if (map2.count(rs[i][j]) > 0) {
        count += priority(rs[i][j]);
        break;
      }
    }
  }
  cout << count << endl;
}

int main(){
  solve();
	return 0;
}

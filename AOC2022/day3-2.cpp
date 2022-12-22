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
  string a, b, c;
  for (int i = 0; i < 100; i++) {
    cin >> a >> b >> c;
    unordered_map<char, int> map1;
    unordered_map<char, int> map2;
    unordered_map<char, int> map3;
    for (int j = 0; j < a.length(); j++) {
      if (map1.count(a[j]) == 0) map1[a[j]] = 1;
      else map1[a[j]]++;
    }
    for (int j = 0; j < b.length(); j++) {
      if (map2.count(b[j]) == 0) map2[b[j]] = 1;
      else map2[b[j]]++;
    }
    for (int j = 0; j < c.length(); j++) {
      if (map3.count(c[j]) == 0) map3[c[j]] = 1;
      else map3[c[j]]++;
    }
    for (int k = 0; k < a.length(); k++) {
      if (map2.count(a[k]) > 0 && map3.count(a[k]) > 0) {
        count += priority(a[k]);
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

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

pair<int, int> countBits(vector<string> s, int pos) {
  pair<int, int> p = {0, 0};
  for (int i = 0; i < s.size(); i++) {
    if (s[i][pos] == '0') p.first++;
    else p.second++;
  }
  return p;
}

vector<string> filter(vector<string> text, int pos, bool isLCB) {
  vector<string> ans;
  pair<int, int> p = countBits(text, pos);
  for (int i = 0; i < text.size(); i++) {
    if (isLCB) {
      if (p.first > p.second) {
        if (text[i][pos] == '1') ans.push_back(text[i]);
      } else {
        if (text[i][pos] == '0') ans.push_back(text[i]);
      }
    } else {
      if (p.first > p.second) {
        if (text[i][pos] == '0') ans.push_back(text[i]);
      } else {
        if (text[i][pos] == '1') ans.push_back(text[i]);
      }
    }
  }
  return ans;
}

void solve(){
  ifstream MyReadFile("in1");
  string text;
  vector<pair<int,int>> a;
  vector<string> ss;
  vector<string> tt;
  while (getline(MyReadFile, text)) {
    ss.push_back(text);
    tt.push_back(text);
  }
  int p1 = 0;
  int p2 = 0;
  while(ss.size() != 1) {
    ss = filter(ss, p1, false);
    p1++;
  }
  while(tt.size() != 1) {
    tt = filter(tt, p2, true);
    p2++;
  }
  int a1 = stoi(ss[0], 0, 2);
  int a2 = stoi(tt[0], 0, 2);
  cout << a1 * a2 << endl;
}

int main(){
  solve();
	return 0;
}

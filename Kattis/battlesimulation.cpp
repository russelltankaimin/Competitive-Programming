#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef bitset<22> BITS;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vector<vector<int>>> vv3d;
#define ALL(x) x.begin(),x.end()
#define UNIQUE(x) (x).resize(unique(ALL(x)) - x.begin())

void printVector(vector<int> a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

template<typename T>
void printMatrix(vector<vector<T>> matrix){
  for (int i = 0; i<matrix.size();i++){
    for (int j = 0;j<matrix[i].size();j++){
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }

}
void printTensor(vv3d tensor){
  for (int i = 0; i<tensor.size();i++){
    for (int j = 0;j<tensor[i].size();j++){
      for (int k =0; k<tensor[i][j].size();k++){
        cout<<tensor[i][j][k]<<" ";
      }
      cout<<"  "<<endl;
    }
    cout<<"    "<<endl;
  }
}

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

bool isCombo(string s, int start, int end) {
  bool ans = false;
  string ss = s.substr(start, 3);
  string a = "BLR";
  do {
    if (ss.compare(a) == 0) {
//      cout << ss << " matched " << a << endl;
      return true;
    }
//    cout << a << endl;
  } while (next_permutation(ALL(a)));
  if (ss.compare(a) == 0) {
//    cout << ss << " matched " << a << endl;
    return true;
  }
  return false;
}

void solve() {
  string s; cin >> s;
  string r = "";
  // check for combo first
  vector<int> idx;
  if (s.length() < 3) {
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'R') r.push_back('S');
      if (s[i] == 'B') r.push_back('K');
      if (s[i] == 'L') r.push_back('H');
    }
    cout << r << endl;
    return;
  }
  for (int i = 0; i < s.length() - 3 + 1; i++) {
//    cout << "CHECKED " << i << endl;
    if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2]) {
      idx.push_back(i);
//      cout << "i range " << i << " " << i + 1 << " " << i + 2 << endl;
      i = i + 2;
//      cout << " skipped to " << i + 1 << endl;
    }
  }
  int p = 0;
  int ptr = 0;
  while (p < s.length()) {
    if (idx.size() > 0 && p == idx[ptr]) {
      r.push_back('C');
      ptr++;
      p+=3;
    } else {
      if (s[p] == 'R') r.push_back('S');
      if (s[p] == 'B') r.push_back('K');
      if (s[p] == 'L') r.push_back('H');
      p++;
    }
  }
  cout << r << endl;
}

int main(){
  solve();
  return 0;
}

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

bool in_range(pair<char, int> des, pair<char, int> src) {
  return abs(src.first - des.first) == abs(src.second - des.second);
}

bool operator!=(pair<char, int> a, pair<char, int> b) {
  return a.first != b.first || a.second != b.second;
}

void solve() {
  int T; cin >> T;
  while(T--) {
    pair<char, int> src; cin >> src.first >> src.second;
    pair<char, int> des; cin >> des.first >> des.second;
    if (((src.first + des.first) % 2) != ((src.second + des.second) % 2)) {
//      cout << (src.first - des.first) % 2 << " " << (src.second - des.second) % 2 << endl;
      cout << "Impossible" << endl;
      continue;
    }
    int steps = 0;
    vector<pair<char,int>> s;
    if (!(src != des)) {
      printf("%d %c %d\n",0, src.first, src.second); 
      continue;
    }
    if (abs(src.first - des.first) == abs(src.second - des.second)) {
      printf("%d %c %d %c %d\n", 1, src.first, src.second, des.first, des.second);
      continue;
    } else {
      char i1; int i2;
      // iterate thru each pt
      // im lazy so i doing all 64 LOL
      for (char c : "ABCDEFGH") {
        for (int i = 1; i<= 8; i++) {
          pair<char, int> ab = {c, i};
          if (in_range(src, {c, i}) && in_range({c, i}, des) && ab != src && ab != des) {
            i1 = c; i2 = i;
            break;
          }
        }
      }
      printf("%d %c %d %c %d %c %d\n", 2, src.first, src.second, i1, i2, des.first, des.second);
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

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

bool adjacent(pair<int, int> a, pair<int, int> b) {
  return abs(a.first - b.first) <= 1 && abs(a.second - b.second) <= 1;
}

pair<int, int> generate(pair<int, int> t, pair<int, int> h) {
  int ddx = h.first - t.first;
  int ddy = h.second - t.second;
  int xSign = ddx == 0 ? 0 : ddx / abs(ddx);
  int ySign = ddy == 0 ? 0 : ddy / abs(ddy);
  return {t.first + xSign, t.second + ySign};
}

void solve(){
  pair<int, int> head = {0, 0};
  pair<int, int> tail = {0, 0};
  set<pair<int, int>> points;
  char a; int b;
  points.insert({0, 0});
  int dx = 0; int dy = 0;
  for (int i = 0; i < 2000; i++) {
    cin >> a >> b;
    if (a == 'R') dx = 1;
    if (a == 'L') dx = -1;
    if (a == 'U') dy = 1;
    if (a == 'D') dy = -1;
    for (int j = 0; j < b; j++) {
      pair<int, int> newHead = {head.first + dx , head.second + dy };
      if (!adjacent(tail, newHead)) {
        tail = generate(tail, newHead);
        points.insert(tail);
      }
      head = newHead;
    }
  }
  cout << points.size() << endl;
}

int main(){
  solve();
  return 0;
}

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

void solve() {
  int n, m;
  while(true) {
    cin >> n >> m;
    if (m == 0 && n == 0) {
      return;
    }
    vector<pair<int, int>> possible;
    for (int i = 0; i < n; i++) {
      int a,b; cin >> a >> b;
      if (a <= m) {
        pair<int, int> p = {a, b};
        possible.push_back(p);
      }
    }
    if (possible.size() == 0) {
      printf("No suitable tickets offered\n"); 
      continue;
    }
    sort(ALL(possible), [&](pair<int, int> a, pair<int, int> b) {
        if (a.second * b.first == a.first * b.second) {
          return a.first > b.first;
        }
      return a.second * b.first < a.first * b.second;
        });
    printf("Buy %d tickets for $%d\n", possible[0].first, possible[0].second);
  }
}

int main(){
  solve();
  return 0;
}

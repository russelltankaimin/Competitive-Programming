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
  long shares = 0; long double mean = 0.0;
  string action;
  while (cin >> action && action.compare("die") != 0) {
    if (action.compare("buy") == 0) {
      long double x, y; cin >> x >> y;
      mean = (mean * shares + x * y) / (shares + x);
      shares += x;
    } else if (action.compare("sell") == 0) {
      long double x,y; cin >> x >> y;
      shares -= x;
    } else if (action.compare("split") == 0) {
      long x; cin >> x;
      shares *= x;
      mean /= x;
    } else if (action.compare("merge") == 0) {
      long x; cin >> x;
      shares /= x;
      mean *= x;
    } else {
      continue;
    }
    mean = shares == 0 ? 0 : mean;
    //cout << "shares mean : " << shares << " " << mean << endl;
  }
  long x; cin >> x;
  printf("%Lf", shares*mean - max((long double) 0.0, 0.3*(shares*mean-x)));
}

int main(){
  solve();
  return 0;
}

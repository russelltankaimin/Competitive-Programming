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

string process(int a) {
  string b = "";
  while (a != 0 && b.length() != 4) {
    if (a & 1) b.push_back('*');
    else b.push_back('.');
    a >>= 1;
  }
  while (b.length() != 4) {
    b.push_back('.');
  }
  reverse(ALL(b));
  return b;
}

void solve() {
  stack<int> digits;
  vector<string> dots;
  string T; cin >> T;
  for (int i = 3; i >= 0; i--) {
    digits.push(T[i] - '0');
  }
  while (!(digits.empty())) {
    int p = digits.top();
    digits.pop();
    dots.push_back(process(p));
  }
  for (int j = 0; j < 4; j++) {
    for (int i = 0; i < 5; i++) {
      if (i == 2) {
        cout << "  ";
      } else if (i < 2) {
        cout << dots[i][j] << " ";
      } else if (i == 3){
        cout << dots[i - 1][j] << " ";
      } else if (i == 4) {
        cout << dots[i - 1][j];
      }
    }
    cout << endl;
  }
}

int main(){
  solve();
  return 0;
}

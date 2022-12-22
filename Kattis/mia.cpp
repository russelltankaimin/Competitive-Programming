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

int category(int p) {
  if (p == 21) return 1;
  if (p % 10 == p / 10) return 2;
  else return 3;
}

void solve() {
  int s0, s1, r0, r1;
  while (cin >> s0 >> s1 >> r0 >> r1 && s0 != 0 && s1 != 0 && r0 != 0 && r1 != 0) {
    int p1 = 10 * max(s0, s1) + min(s0, s1);
    int p2 = 10 * max(r0, r1) + min(r0, r1);
    int c1 = category(p1); int c2 = category(p2);
    if (c1 == c2) {
      if (c1 == 1) {
        cout << "Tie." << endl;
      } else {
        if (p1 > p2) {
          cout << "Player 1 wins." << endl;
        } else if (p1 < p2) {
          cout << "Player 2 wins." << endl;
        } else {
          cout << "Tie." << endl;
        }
      }
    } else {
      if (c1 < c2) {
        cout << "Player 1 wins."  << endl;
      } else {
        cout << "Player 2 wins." << endl;
      }
    }
  }
}

int main(){
  solve();
  return 0;
}

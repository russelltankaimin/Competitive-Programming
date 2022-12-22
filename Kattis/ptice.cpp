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

char adrian(int i) {
  return i % 3 == 0 ? 'A' 
    : (i % 3 == 1 ? 'B' : 'C');
}

char bruno(int i) {
  return (i % 4 == 0 || i % 4 == 2) ? 'B' : (i % 4 == 1 ? 'A' : 'C');
}

char goran(int i) {
  return (i % 6 == 0 || i % 6 == 1) ? 'C' : ((i % 6 == 2 || i % 6 == 3) ? 'A' : 'B');
}

void solve() {
  int T; cin >> T;
  int a = 0, b = 0, g = 0;
  string s; cin >> s;
  for (int i = 0; i < T; i++) {
    a += adrian(i) == s[i];
    b += bruno(i) == s[i];
    g += goran(i) == s[i];
  }
  cout << max(a, max(b,g)) << endl;
  if (a == max(a, max(b, g))) {
    cout << "Adrian" << endl;
  } 
  if (b == max(a, max(b,g))) {
    cout << "Bruno" << endl;
  } 
  if (g == max(a, max(b, g))) {
    cout << "Goran" << endl;
  }
}

int main(){
  solve();
  return 0;
}

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
  int T; cin >> T;
  vector<string> a;
  vector<string> b;
  while (T--) {
    string p; cin >> p;
    a.push_back(p);
    b.push_back(p);
  }
  auto increasing = [&](string a, string b) {
    return lexicographical_compare(ALL(a), ALL(b));
  };
  
  sort(ALL(b), increasing);
  bool incr = true;
  bool decr = true;
  for (int i = 0, j = a.size() - 1; i < a.size(); i++, j--) {
    if (a[i].compare(b[i]) != 0) {
      incr = false;
    }
    if (a[i].compare(b[j]) != 0) {
      decr = false;
    }
  }
  if (incr) {
    cout << "INCREASING" << endl;
    return;
  }
  if (decr) {
    cout << "DECREASING" << endl;
    return;
  } else {
    cout << "NEITHER" << endl;
  }
}

int main(){
  solve();
  return 0;
}

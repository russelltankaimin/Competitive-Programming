#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef bitset<22> BITS;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vector<vector<int>>> vv3d;
#define ALL(x) x.begin(),x.end()
#define UNIQUE(x) (x).resize(unique(ALL(x)) - x.begin())
#define pb push_back
#define pf push_front

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

void in_shuffle(vector<int> &v) {
    int n = v.size();
    vector<int> v1, v2;
    for (int i = 0; i < n / 2; i++) {
        v1.pb(v[i]);
    }
    for (int i = n / 2; i < n; i++) {
        v2.pb(v[i]);
    }
    for (int i = 0; i < n / 2; i++) {
        v[i * 2] = v2[i];
        v[i * 2 + 1] = v1[i];
    }
    if (n % 2) {
        v[n - 1] = v2[n / 2];
    }
}

void out_shuffle(vector<int> &v) {
    int n = v.size();
    vector<int> v1, v2;
    if (n % 2) {
        for (int i = 0; i < (n / 2) + 1; i++) {
            v1.pb(v[i]);
        }
        for (int i = (n / 2) + 1; i < n; i++) {
            v2.pb(v[i]);
        }
        v[n - 1] = v1[n / 2];
    } else {
        for (int i = 0; i < n / 2; i++) {
            v1.pb(v[i]);
        }
        for (int i = n / 2; i < n; i++) {
            v2.pb(v[i]);
        }
    }
    for (int i = 0; i < n / 2; i++) {
        v[i * 2] = v1[i];
        v[i * 2 + 1] = v2[i];
    }
}

void solve() {
  int c; string t; cin >> c >> t;
  vector<int> orig;
  vector<int> shuf;
  for (int i = 0; i < c; i++) {
    orig.pb(i); shuf.pb(i);
  }
  int steps = 0;
  do {
    if (t.compare("in") == 0) {
      in_shuffle(shuf);
    } else {
      out_shuffle(shuf);
    }
    steps++;
  } while (orig != shuf);
  cout << steps << endl;
}

int main(){
  solve();
  return 0;
}

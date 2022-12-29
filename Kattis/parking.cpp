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
#define FOR(init, exc,itr) for(int i = init; i < exc; i+=itr)

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
  int A, B, C; cin >> A >> B >> C;
  vector<pair<int, bool>> intervals; // bool true is in, false is out
  for (int i = 0; i < 3; i++) {
    pair<int, bool> in = {0, true};
    pair<int, bool> out = {0, false};
    cin >> in.first >> out.first;
    intervals.pb(in); intervals.pb(out);
  }
  sort(ALL(intervals), [&](pair<int, bool> a , pair<int, bool> b) {
      return a.first < b.first;
      });
  int fare = 0;
  int d = 0;
  vector<int> f = {A, B, C};
  for (int i = 0; i < intervals.size() - 1; i++) {
    pair<int, bool> pib = intervals[i];
    if (pib.second) {
      d++;
      fare += d * (intervals[i + 1].first - pib.first) * f[d - 1]; 
    } else {
      d--;
      fare += d * (intervals[i + 1].first - pib.first) * f[d - 1];
    }
  }
  cout << fare << endl;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

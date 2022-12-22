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
  int N, K; cin >> N >> K;
  vector<int> ints(N);
  unordered_map<int, int> map;
  for (int i = 0; i < N; i++) {
    cin >> ints[i];
    if (map.count(ints[i]) == 0) {
      map[ints[i]] = 1;
    } else {
      map[ints[i]]++;
    }
  }
  if (K == 1) {
    for (auto p : map) {
      if (map.count(7777 - p.first) > 0) {
//        cout << p.first << " " << 7777 - p.first << endl;
        cout << "Yes" << endl;
        return;
      }
    }
    cout << "No" << endl;
  } else if (K == 2) {
    UNIQUE(ints);
    printVector(ints);
    if (ints.size() == N) {
      cout << "Unique" << endl;
    } else {
      cout << "Contains duplicate" << endl;
    }
  } else if (K == 3) {
    for (auto p : map) {
      if (p.second > (N / 2)) {
        cout << p.first << endl;
        return;
      }
    }
    cout << -1 << endl;
    return;
  } else if (K == 4) {
    sort(ALL(ints));
    if (N % 2 == 0) {
      cout << ints[(N/2) - 1] << " " << ints[N/2] << endl;
    } else {
      cout << ints[N/2] << endl;
    }
  } else {
    sort(ALL(ints));
    vector<int> f;
    for (int i = 0; i < ints.size(); i++) {
      if (ints[i] <= 999 && ints[i] >= 100) {
        f.push_back(ints[i]);
      }
    }
    for (int i = 0; i < f.size() - 1; i++) {
      cout << f[i] << " ";
    }
    cout << f.back() << endl;
  }
}

int main(){
  solve();
  return 0;
}

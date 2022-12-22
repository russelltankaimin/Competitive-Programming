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

void solve(int k, int m) {
  vector<string> cses;
  unordered_map<int, vector<string>> catToCses;
  unordered_map<int, int> counts;
  for (int i = 0; i < k; i++) {
    string c; cin >> c;
    cses.push_back(c);
  }
  for (int i = 0; i < m; i++) {
    int cat; int cts; cin >> cat >> cts;
    vector<string> collect;
    for (int j = 0; j < cat; j++) {
      string pp; cin >> pp;
      collect.push_back(pp);
    }
    catToCses[cat] = collect;
    counts[cat] = cts;
  }
  for (auto p : catToCses) {
    for (string ss : cses) {
      if (find(ALL(p.second), ss) != p.second.end()) {
        counts[p.first]--;
      }
    }
  }
  int success = true;
  for (auto p : counts) {
    success &= (p.second < 1);
  }
  if (success) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
}

int main(){
  int k, m;
  while (true) {
    cin >> k;
    if (k == 0) {
      break;
    } else {
      cin >> m;
      solve(k, m);
    }
  }
  return 0;
}

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

template<typename T>
void printVector(vector<T> a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

template<typename T, typename S>
void printVector(vector<pair<T,S>> a){
  for (int i = 0; i < a.size(); i++) {
    cout << "( " << a[i].first << ", " << a[i].second << " ) ";
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

template<typename T, typename S>
void printMatrix(vector<vector<pair<T,S>>> matrix){
  for (int i = 0; i<matrix.size();i++){
    printVector<T,S>(matrix[i]);
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
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        if (hash1 != hash2) {
            return hash1 ^ hash2;
        }
          return hash1;
    }
};

void printMapPair(unordered_map<pair<int, int> , long long, hash_pair> a) {
  for (auto p : a) {
    printf("(%d, %d) => %lld\n", p.first.first, p.first.second, p.second);
  }
}

void solve() {
  while(true) {
    int N; cin >> N;
    if (N == 0) {
      break;
    } else {
      int curr = -1;
      long long hi = LONG_MIN;
      unordered_map<pair<int, int>, long long, hash_pair> umap;
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
          if (j == 0) {
            cin >> curr;
            continue;
          } else {
            int p;
            cin >> p;
            pair<int, int> pp = {curr, p};
            if (umap.count(pp) == 0) {
              umap[pp] = 1;
            } else {
              umap[pp]++;
            }
            hi = max(hi, umap[pp]);
            curr = p;
          }
        }
      }
      long long max = LONG_MIN;
      long long ans = 0;
      cout << "highest count " << hi << endl;
      printMapPair(umap);
      for (auto p : umap) {
        if (p.second == hi) {
          ans++;
        }
      }
      cout << ans <<  endl;
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

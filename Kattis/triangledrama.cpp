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

struct Triangle {
  int a;
  int b;
  int c;
  int d;
};

void solve() {
  int N; cin >> N;
  vvi adj; adj.assign(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> adj[i][j];
    }
  }
  vector<Triangle> drama;
  for (int i = 0; i < N - 2; i++) {
    for (int j = i + 1; j < N - 1; j++) {
      for (int k = j + 1; k < N; k++) {
        if (adj[i][j] != 0 &&  adj[j][k] != 0 && adj[i][k] != 0) {
          drama.pb({i, j, k, adj[i][j] * adj[j][k] * adj[i][k]});
        }
      }
    }
  }
  sort(ALL(drama), [&](Triangle x, Triangle y) {
      if (x.d == y.d) {
      return x.a < y.a ? true : x.b < y.b ? true : x.c < y.c;
      } else {
      return x.d > y.d;
      }
      });
  Triangle ans = drama[0];
  printf("%d %d %d\n", ans.a + 1, ans.b + 1, ans.c + 1);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

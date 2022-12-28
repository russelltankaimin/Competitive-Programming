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

struct Edge {
  int x;
  int y;
  char c;
};

struct DSU {
  vector<int> parent;
  vector<int> rank;
  DSU(int n) {
    parent = vector<int>(n, -1);
    rank = vector<int>(n, 1);
  }

  int find(int i) {
    if (parent[i] == -1)
      return i;
    return parent[i] = find(parent[i]);
  }

  void unite(int x, int y) {
    int s1 = find(x);
    int s2 = find(y);
    if (s1 != s2) {
      if (rank[s1] < rank[s2]) {
        parent[s1] = s2;
      }
      else if (rank[s1] > rank[s2]) {
        parent[s2] = s1;
      }
      else {
        parent[s2] = s1;
        rank[s1] += 1;
      }
    }
  }
};

void solve() {
  int N; int M; int k; cin >> N >> M >> k;
  DSU red = DSU(N);
  DSU blue = DSU(N);
  for (int i = 0; i < M; i++) {
    int a, b; char c;
    cin >> c >> a >> b;
    a--; b--;
    if (c == 'R') {
      red.unite(a, b);
    } else {
      blue.unite(a, b);
    }
  }
  int ba = 0; int bn = 0;
  for (int i = 0; i < N; i++) {
    if (red.parent[i] == -1) {
      bn++;
    }
    if (blue.parent[i] != -1) {
      ba++;
    }
  }
  if (ba < k || ba < bn || bn > k) {
    cout << 0 << endl;
  } else {
    cout << 1 << endl;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

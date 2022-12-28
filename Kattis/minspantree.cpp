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

vector<bool> visited;

struct Edge {
  int x;
  int y;
  int weight;
};

void dfs(vvi adj, int start) {
//  cout << "visited " << start << endl;
  if (visited[start]) return;
  visited[start] = true;
  for (int a : adj[start]) {
    dfs(adj, a);
  }
}
bool connected(vvi adj) {
  visited = vector<bool>(adj.size(), false);
  dfs(adj, 0);
//  cout << "DFS completed" << endl;
  for (int i = 0; i < visited.size(); i++) {
    if (!visited[i]) return false;
  }
  return true;
}

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
  while (true) {
here:
    int n, m; cin >> n >> m;
    if (n == 0 && m == 0) return;
    else {
      vector<Edge> edges;
      vector<vector<int>> adj = vector<vector<int>>(n, vector<int>());
      for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; int w; cin >> w;
//        cout << a << " " << b << " " << w << endl;
        adj[a].pb(b); adj[b].pb(a);
        edges.pb({a < b ? a : b, a < b ? b : a, w});
      }
//      cout << "CONNECTED" << endl;
      DSU dsu = DSU(n);
      vector<Edge> mst;
      sort(ALL(edges), [&](Edge a, Edge b) {
        return a.weight < b.weight;
          });
      int tw = 0;
      vector<bool> visited = vector<bool>(n, false);
      for (auto e : edges) {
        if (dsu.find(e.x) != dsu.find(e.y)) {
          tw += e.weight;
          mst.pb(e);
          dsu.unite(e.x, e.y);
          visited[e.x] = true; visited[e.y] = true;
        }
      }
      for (auto b : visited) {
        if (!b) {
          cout << "Impossible" << endl;
          goto here;
        }
      }
      sort(ALL(mst), [&](Edge a, Edge b) {
        if (a.x == b.x) {
          return a.y < b.y;
        } else {
          return a.x < b.x;
        }
          });

      cout << tw << endl;
      for (auto e : mst) {
        cout << e.x << " " << e.y << endl;
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

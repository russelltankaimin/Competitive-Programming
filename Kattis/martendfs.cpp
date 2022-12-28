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

unordered_map<int, int> umap;

bool cmp(int a, int b) {
  return umap[a] < umap[b];
}

bool flag = false;
int ctr = 0;

void dfs1(int v, vector<int> p,vector<vector<int>> adj ,int N) {
  ctr++;
  if (ctr == N) {
    flag = true;
    return;
  } else {
    for (auto vv : adj[v]) {
      if (vv == p[ctr]) {
        dfs1(vv, p, adj, N);
      }
    }
  }
  return;
}
template <typename Out>
void split(const std::string& s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}
void solve() {
  int N, E; cin >> N >> E;
  vector<bool> edges = vector<bool>(N, false);
  vector<vector<int>> adj = vector<vector<int>>(N, vector<int>());
  for (int i = 0; i < E; i++) {
    int x,y; cin >> x >> y;
    adj[x].pb(y); adj[y].pb(x);
  }
  vector<int> dfs;
  string ss;
  getline(cin, ss);
  if (ss == "") {
    getline(cin, ss);
  }
  string s = "";
  for (int i = 0; i <= ss.length(); i++) {
    if (i == ss.length() || ss[i] == ' ') {
      dfs.pb(stoi(s));
      umap[dfs.back()] = dfs.size() - 1;
      s = "";
    } else {
      s.pb(ss[i]);
    }
  }
  printVector(dfs);
  if (dfs.size() != N) {
    cout << "NO" << endl;
    return;
  }
  for (auto v : adj) {
    sort(ALL(v), cmp);
  }
  dfs1(dfs[0], dfs, adj, N);
  if (flag) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

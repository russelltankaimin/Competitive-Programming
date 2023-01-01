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

vector<string> process(string sounds) {
  vector<string> ans;
  string s = "";
  for (int i = 0; i < sounds.length() + 1; i++) {
    if (i == sounds.length() || sounds[i] == ' ') {
      ans.pb(s);
      s = "";
    } else {
      s.pb(sounds[i]);
    }
  }
  return ans;
}

void solve() {
  int T; cin >> T;
  while(T--) {
    string sounds; getline(cin, sounds);
    if (sounds == "") getline(cin, sounds);
    vector<string> s = process(sounds);
    unordered_map<string, vector<int>> umap;
    vector<int> blocked; blocked.assign(s.size(), false);
    string ss;
    for (int i = 0; i < s.size(); i++) {
      if (umap.count(s[i]) == 0) umap[s[i]] = {i};
      else umap[s[i]].pb(i);
    }
    while(true) {
      getline(cin,ss);
      if (ss.compare("what does the fox say?") == 0) {
        break;
      }
      vector<string> cmd = process(ss);
      for (int i = 0; i < umap[cmd[2]].size(); i++) {
        blocked[umap[cmd[2]][i]] = true;
      }
    }
    vector<string> printt;
    for (int i = 0; i < s.size(); i++) {
      if (!blocked[i]) printt.pb(s[i]);
    }
    printVector<string>(printt);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

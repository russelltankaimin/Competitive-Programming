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

vector<vector<char>> process(string s) {
  vector<vector<char>> key;
  key.assign(5, vector<char>(5, 0));
  unordered_set<char> hashset;
  int r = 0, c = 0;
  for (int i = 0; i < s.length(); i++) {
    if (hashset.count(s[i]) == 0 && s[i] != ' ') {
      key[r][c] = s[i];
      hashset.insert(s[i]);
//      printf("r : %d c : %d, inserting %c into hashset\n",r, c, s[i]);
      if (c == 4) {
        r++;
        c = 0;
      } else {
        c++;
      }
    }
  }
  for (char p : "abcdefghijklmnoprstuvwxyz") {
    if (r == 5) break;
    if (hashset.count(p) == 0) {
//      printf("r : %d c : %d, inserting %c into hashset\n",r, c, p);
      key[r][c] = p;
      hashset.insert(p);
      if (c == 4) {
        r++;
        c = 0;
      } else {
        c++;
      }
    }
  }
  assert(hashset.size() == 25);
  return key;
}

string encrypt(string s, vector<vector<char>> &key, unordered_map<char, pair<int, int>> &umap) {
  assert(s.length() == 2);
//  cout << "GOING TO ENCRYPT " << s << endl;
  pair<int, int> loc1 = umap[s[0]];
  pair<int, int> loc2 = umap[s[1]];
  if (loc1.first == loc2.first) {
    s[0] = key[loc1.first][(loc1.second + 1) % 5];
    s[1] = key[loc2.first][(loc2.second + 1) % 5];
  } else if (loc1.second == loc2.second) {
    s[0] = key[(loc1.first + 1) % 5][loc1.second];
    s[1] = key[(loc2.first + 1) % 5][loc2.second];
  } else {
    s[0] = key[loc1.first][loc2.second];
    s[1] = key[loc2.first][loc1.second];
  }
//  cout << "RESULT " << s << endl;
  return s;
}

void solve() {
  string s; getline(cin, s);
  if (s == "") getline(cin, s);
  vector<vector<char>> key = process(s);
//  printMatrix<char>(key);
  string pt; getline(cin, pt);
  if (pt == "") getline(cin, pt);
  string pt1 = "";
  for (int i = 0; i < pt.length(); i++) {
    if (pt[i] != ' ') pt1.pb(pt[i]);
  }
  unordered_map<char, pair<int, int>> umap;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      umap[key[i][j]] = {i, j};
    }
  }
  vector<string> digraphs;
  for (int i = 0; i < pt1.length(); i+=2) {
    string k = pt1.substr(i, 2);
    string c = "";
    if (i == pt1.length() - 1) {
      c.pb(pt1[i]);
      c.pb('x');
      digraphs.pb(encrypt(c, key, umap));
    } else if (k[0] == k[1]) {
      c.pb(k[0]); c.pb('x');
      digraphs.pb(encrypt(c, key, umap));
      i--;
    } else {
      digraphs.pb(encrypt(k, key, umap));
    }
  }
  for (string s : digraphs) {
    cout << (char)toupper(s[0]) << (char)toupper(s[1]);
  }
  cout << endl;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

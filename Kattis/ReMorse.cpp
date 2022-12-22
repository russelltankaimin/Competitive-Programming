#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef bitset<22> BITS;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vector<vector<int>>> vv3d;
#define ALL(x) x.begin(),x.end()
#define UNIQUE(x) (x).resize(unique(ALL(x)) - x.begin())

void printVector(vector<string> a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i].length() << " ";
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

bool isAlpha(char a) {
  return (a >= 97 && a <= 122) || (a >= 65 && a <= 90);
}

char convert(char a) {
  return (a >= 97 && a <= 122) ? a - 32 : a;
}

void solve() {
  vector<pair<char, int>> c;
  unordered_map<char, int> counts;
  string T; getline(cin, T);
  for (int i = 0; i < T.length(); i++) {
    if (isAlpha(T[i])) {
      counts[tolower(T[i])] = counts.count(tolower(T[i])) == 0 ? 1 : counts[tolower(T[i])] + 1;
    } else {
    }
  }
  int total = 0;
  for (auto p : counts) {
    c.push_back({p.first, p.second});
    total += p.second;
  }
  int ans = 3 * (total - 1);
  sort(ALL(c), [&](pair<char, int> a, pair<char, int> b) {
        return a.second > b.second;
      });
  // generate strings
  vector<string> b = {".", "---"};
  unordered_set<string> cc = {".", "---"};
  while (cc.size() <= 256) {
    unordered_set<string> c1 = cc;
    for (string ccc : cc) {
      for (string cccc : b) {
        c1.insert(ccc+' '+cccc);
        c1.insert(cccc+' '+ccc);
      }
    }
    swap(cc, c1);
  }
  vector<string> bb;
  for (string cf : cc) {
    bb.push_back(cf);
  }
  sort(ALL(bb), [&](string a, string b) {
        return a.length() < b.length();
      });
  for (int i = 0; i < c.size(); i++) {
    ans += bb[i].length() * c[i].second;
  }
  cout << ans << endl;
}

int main(){
  solve();
  return 0;
}

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

struct Person {
  string name;
  vector<string> h;
};

vector<string> process(string h) {
  vector<string> a;
  string name = "";
  for (int i = 0; i < h.length(); i++) {
    if (i == 0 || h[i] != '-') {
      name.pb(h[i]);
    } else {
      a.pb(name);
      name = "";
    }
  }
  a.pb(name);
  reverse(ALL(a));
  printVector(a);
  return a;
}

void solve() {
  int T; cin >> T;
  unordered_map<string, int> hhh;
  hhh["upper"] = 3;
  hhh["middle"] = 2;
  hhh["lower"] = 1;
  while (T--) {
    int n; cin >> n;
    vector<Person> person;
    for (int i = 0; i < n; i++) {
      string name; cin >> name;
      string hierarcy; cin >> hierarcy;
      string c; cin >> c;
      vector<string> hh = process(hierarcy);
      person.pb({name.substr(0, name.length() - 1), hh});
    }
    sort(ALL(person), [&](Person a, Person b) {
      vector<string> h1 = a.h;
      vector<string> h2 = b.h;
      bool same = true;
      for (int i = 0; i < min(h1.size(), h2.size()); i++) {
        if (hhh[h1[i]] > hhh[h2[i]]) {
          return true;
        } else if (hhh[h1[i]] < hhh[h2[i]]) {
          return false;
        } else {
          continue;
        }
      }
      return lexicographical_compare(ALL(a.name), ALL(b.name));
      });
    for (Person p : person) {
      cout << p.name << endl;
    }
    cout << "==============================" << endl;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

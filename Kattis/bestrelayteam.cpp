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

struct Runner {
  string name;
  double first;
  double second;
};

void solve() {
  int n; cin >> n;
  vector<Runner> r;
  for (int i = 0; i < n; i++) {
    string n; double s, e; cin >> n >> s >> e;
    r.pb({n, s, e});
  }
  sort(ALL(r), [&](Runner a, Runner b) {
    return a.second < b.second;
      });
  double ans = DBL_MAX;
  vector<Runner> vans1 = vector<Runner>(4, {"Russell", 0, 0});
  for (int i = 0; i < n; i++) {
    vector<Runner> vans;
    double trial = 0.0;
    Runner first = r[i];
    vans.pb(first);
    trial += first.first;
    for (int j = 0; j < n && vans.size() != 4; j++) {
      if (r[j].name.compare(first.name) != 0) {
        vans.pb(r[j]);
        trial += r[j].second;
      }
    }
    if (trial < ans) {
      vans1 = vans;
      ans = trial;
    }
  }
  printf("%.9f\n", ans);
  for (Runner p : vans1) {
    cout << p.name << endl;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

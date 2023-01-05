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

int process(string s) {
  bool hasdash = false;
  int dashindex = -1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '-') {
      hasdash = true;
      dashindex = i;
      break;
    }
  }
  if (!hasdash) {
    return 1;
  } else {
    string num1 = s.substr(0, dashindex);
    string num2 = s.substr(dashindex + 1, s.length() - dashindex - 1);
    return stoi(num2) - stoi(num1) + 1;
  }
}

void solve() {
  string s; getline(cin, s);
  if (s == "") getline(cin, s);
  int qns = 0;
  vector<int> colonindex;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ';') colonindex.pb(i);
  }
  if (colonindex.empty()) {
    cout << process(s) << endl;
  } else {
    s.pb(';');
    colonindex.pb(s.length() - 1);
    for (int i = 0; i < colonindex.size(); i++) {
      if (i == 0) {
        qns += process(s.substr(0, colonindex[i]));
      } else {
        qns += process(s.substr(colonindex[i - 1] + 1, colonindex[i] - colonindex[i - 1] - 1));
      }
    }
    cout << qns << endl;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

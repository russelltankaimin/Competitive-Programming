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

deque<int> process(string a) {
  deque<int> ans;
  if (a.compare("[]") == 0) return ans;
  string num = "";
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == '[') {
      continue;
    } else if (a[i] == ',' || a[i] == ']') {
      ans.pb(stoi(num));
      num = "";
    } else {
      num.pb(a[i]);
    }
  }
  return ans;
}

void printDequeBack(deque<int> d) {
  cout << "[";
  int ds = d.size();
  if (ds == 0) {
    cout <<"]"<< endl;
    return;
  }
  while (ds != 1) {
    cout << d.back() << ",";
    d.pop_back();
    ds--;
  }
  cout << d.back() <<"]" << endl;
  assert(d.front() == d.back());
}

void printDequeFront(deque<int> d) {
  cout << "[";
  int ds = d.size();
  if (ds == 0) {
    cout <<"]"<< endl;
    return;
  }
  while (ds != 1) {
    cout << d.front() << ",";
    d.pop_front();
    ds--;
  }
  cout << d.front() <<"]" << endl;
  assert(d.front() == d.back());
}

void solve() {
  int T; cin >> T;
  while(T--) {
    string cmd; cin >> cmd;
    int numvars; cin >> numvars;
    string arr; cin >> arr;
    deque<int> arr1 = process(arr);
//    printDeque(arr1);
    bool front = true;
    for (int i = 0; i < cmd.length(); i++) {
      if (cmd[i] == 'D') {
        if (arr1.empty()) {
          cout << "error" << endl;
          goto here;
        } else {
          if (front) {
            arr1.pop_front();
          } else {
            arr1.pop_back();
          }
        }
      } else {
        front = !front;
      }
    }
    if (front) {
      printDequeFront(arr1);
    } else {
      printDequeBack(arr1);
    }
here:
    continue;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

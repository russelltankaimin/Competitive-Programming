#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef bitset<22> BITS;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vector<vector<int>>> vv3d;
#define ALL(x) x.begin(),x.end()
#define UNIQUE(x) (x).resize(unique(ALL(x)) - x.begin())

void printVector(vector<long> a) {
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

void solve() {
  int t; cin >> t;
  vector<long> tea = vector<long>(t);
  for (int i = 0; i < t; i++) {cin >> tea[i];}
  int to; cin >> to;
  vector<long> allcosts;
  unordered_map<long, long> toppingcost;
  for (int i = 0; i < to; i++) {
    long p; cin >> p;
    toppingcost[i + 1] = p;
  }
  for (int i = 0; i < t; i++) {
    int T; cin >> T;
    for (int j = 0; j < T; j++) {
      long k; cin >> k;
      allcosts.push_back(tea[i] + toppingcost[k]);
    }
  } 
  sort(ALL(allcosts));
//  printVector(allcosts);
  long long money; cin >> money;
  long long cups = money / allcosts[0];
  int ptr = 0;
  if (cups == 0) {
    cout << 0 << endl;
    return;
  }
  cout << cups - 1 << endl;
}

int main(){
  solve();
  return 0;
}

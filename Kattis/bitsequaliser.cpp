#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef bitset<22> BITS;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vector<vector<int>>> vv3d;
#define ALL(x) x.begin(),x.end()
#define UNIQUE(x) (x).resize(unique(ALL(x)) - x.begin())

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

void solve() {
  int T; cin >> T;
  for (int i = 1; i <= T; i++) {
    int one1 = 0; int zero0 = 0; int qns = 0;
    int oner = 0; int zeror = 0;
    string a, b; cin >> a >> b;
    for (char c : a) {
      if (c == '0') zero0 ++;
      if (c == '1') one1++;
      if (c == '?') qns++;
    }
    for (char c : b) {
      if (c == '0') zeror++;
      if (c == '1') oner++;
    }
    if (one1 > oner) {
      printf("Case %d: %d\n", i, -1); 
    } else {
      int steps = 0;
      for (int j = 0; j < b.length(); j++) {
        if (a[j] == '?') {
          if (one1 == oner) {
            a[j] = '0';
            zero0++;
            steps++;
          } else {
            a[j] = b[j];
            zero0 += b[j] == '0';
            one1 += b[j] == '1';
            steps++;
          }
        }
      }
      for (int j = 0; zero0 > zeror; j++) {
        if (a[j] == '0' && b[j] == '1') {
          a[j] = '1';
          one1++;
          zero0--;
          steps++;
        }
      }
      int mm = 0;
      for (int j = 0; j < a.length(); j++) {
        if (a[j] != b[j]) {
          mm++;
        }
      }
//      cout << "mm " << mm << endl;
      assert(mm % 2 == 0);
      printf("Case %d: %d\n", i, steps + (mm / 2));
    }
  } 
}

int main(){
  solve();
  return 0;
}

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
  int x, y;
  while (cin >> x >> y && x != 0 && y != 0) {
    int T; cin >> T;
    int x1 = 0; int y1 = 0; // robot actual location
    int rx = 0; int ry = 0; // robot thinks
    for (int i = 0; i < T; i++) {
      char d; int dd; cin >> d >> dd;
      if (d == 'd') {
        ry -= dd;
        y1 = max(0, y1 - dd);
      } else if (d == 'u') {
        ry += dd;
        y1 = min(y - 1, y1 +dd);
      } else if (d == 'l') {
        rx -= dd;
        x1 = max(0, x1 - dd);
      } else {
        rx += dd;
        x1 = min(x - 1, x1 + dd);
      }
    }
    printf("Robot thinks %d %d\n", rx, ry);
    printf("Actually at %d %d\n", x1, y1);
    printf("\n");
  }
}

int main(){
  solve();
  return 0;
}

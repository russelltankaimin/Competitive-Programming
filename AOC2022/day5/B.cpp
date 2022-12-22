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

bool isHV(pair<int, int> a, pair<int, int> b) {
  return (a.first == b.first) || (a.second == b.second);
}

void solve(){
  vector<pair<int, int>> a = vector<pair<int,int>>(500, {0, 0});
  vector<pair<int, int>> b = vector<pair<int, int>>(500, {0, 0});
  vector<vector<int>> grid = vector<vector<int>>(1000, vector<int>(1000, 0));
  for (int i = 0; i < 500; i++) {
    cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
    if (isHV(a[i], b[i])) {
      if (a[i].first == b[i].first) {
        for (int j = min(a[i].second, b[i].second); j <= max(a[i].second, b[i].second); j++) {
          grid[a[i].first][j]++;
        }
      } else {
        for (int j = min(a[i].first, b[i].first); j <= max(a[i].first, b[i].first); j++) {
          grid[j][a[i].second]++;
        }
      }
    } else if (a[i].first < b[i].first) {
        int j = a[i].first; int k = a[i].second;
        while(j != b[i].first || k != b[i].second) {
          grid[j][k]++;
           if (a[i].second < b[i].second) {
            j++; k++;
           } else {
            j++; k--;
           }
        }
        grid[j][k]++;
    } else {
      int j = a[i].first; int k = a[i].second;
      while (j != b[i].first || k != b[i].second) {
        grid[j][k]++;
        if (a[i].second < b[i].second) {
          j--; k++;
        } else {
          j--; k--;
        }
      }
      grid[j][k]++;
    }
  }
  int count = 0;
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      if (grid[i][j] > 1) count++;
    }
  }
  //printMatrix(grid);
  cout << count << endl;
}

int main(){
  solve();
  return 0;
}

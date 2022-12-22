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

bool checkBoard(vector<vector<bool>> board) {
  // check row
  for (int i = 0; i < 5; i++) {
    bool r = true;
    for (int j = 0; j < 5; j++) {
      r &= board[i][j];
    }
    if (r) return r;
  }
  for (int i = 0; i < 5; i++) {
    bool c = true;
    for (int j = 0; j < 5; j++) {
      c &= board[j][i];
    }
    if (c) return c;
  }
  return false;
}

void solve(){
  vector<int> nums = vector<int>(100);
  for (int i = 0; i < 100; i++) {
    cin >> nums[i];
  }
  //for (int i = 0; i < 100; i++) {
  //  cout << nums[i] << endl;
  //}
  string holder;
  int p = -1;
  vector<vector<vector<int>>> grids = vector<vector<vector<int>>>(100, vector<vector<int>>(5, vector<int>(5, 0)));
  for (int i = 2; i <= 601; i++) {
    if ((i + 4) % 6 == 0) {
      //      cin >> holder;
      //      cout << "HOLDER " << holder << endl;
      p++;
    }else {
      for (int j = 0; j < 5; j++) {
        cin >> grids[p][(i + 3) % 6][j]; 
      }
    }
  }
  //  printTensor(grids);
  bool bingo = false;
  int pp;
  int called;
  vector<vector<vector<bool>>> visited = vector<vector<vector<bool>>>(100, vector<vector<bool>>(5, vector<bool>(5, false)));
  for (int r = 0; r < 100; r++) {
    for (int i = 0; i < 100; i++) {
      for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 5; k++) {
          visited[i][j][k] = visited[i][j][k] | (nums[r] == grids[i][j][k]); 
        }
      }
      bingo |= checkBoard(visited[i]);
      if (bingo) {
        pp = i;
        called = nums[r];
        cout << "BINGO BOARD : " << pp << endl;
        goto jump;
      }
    }
  }
jump:
  int score = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      score += (!visited[pp][i][j] ? grids[pp][i][j] : 0);
    }
  }
  printMatrix(grids[pp]);
  cout << endl;
  printMatrix(visited[pp]);
  score *= called;
  cout << "SCORE : " << score << endl;
}

int main(){
  solve();
  return 0;
}

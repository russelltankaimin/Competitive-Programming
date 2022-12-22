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

int score( int row, int col, vector<vector<int>> grid ){
  long upC = 0, leftC = 0, downC = 0, rightC = 0;
  int current = grid[row][col];
  int i = row;
  int j = col;
  int up = i;
  while (--up >= 0) {
    upC++;
    if (grid[up][j] >= current)
      break;
  }
  int down = i;
  while (++down < grid.size()) {
    downC++;
    if (grid[down][j] >= current)
      break;
  }
  int left = j;
  while (--left >= 0) {
    leftC++;
    if (grid[i][left] >= current)
      break;
  }
  int right = j;
  while (++right < grid[i].size()) {
    rightC++;
    if (grid[i][right] >= current)
      break;
  }

  if (upC == 0) upC = 1;
  if (leftC == 0) leftC = 1;
  if (downC == 0) downC = 1;
  if (rightC == 0) rightC = 1;

  return upC * leftC * downC * rightC;
}

void solve(){
  int ROW = 99;
  int highestScore = 0;
  vector<vector<int>> height = vector<vector<int>>(ROW,vector<int>(0));
  vector<vector<int>> scores = vector<vector<int>>(ROW, vector<int>(0));
  string text;
  for (int i = 0; i < ROW; i++) {
    cin >> text;
    for (int j = 0; j < text.size(); j++) {
      height[i].push_back(text[j] - '0');
    }
  }
  for (int i = 0; i < height.size(); i++) {
    for (int j = 0; j < height[i].size(); j++) {
      int o = score(i, j, height);
      scores[i].push_back(o);
      highestScore = max(highestScore, o);
    }
  }
  //printMatrix(scores);
  cout << highestScore << endl;;
}

int main(){
  solve();
	return 0;
}

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
vvi moveLeft(vvi board) {
  for (int i = 0; i < 4; i++) {
    int location = -1, counter = 0;
    for (int j = 0; j < 4; j++) {
      if (board[i][j] == 0) {
        counter++;
        if (counter == 1) location = j;
      }
      else if (board[i][j] != 0 && location != -1) {
        board[i][location] = board[i][j];
        board[i][j] = 0;
        location = j;
        counter = 0;
      }
    }
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != 0 && board[i][j] == board[i][j + 1]) {
        board[i][j] = board[i][j] * 2;
        for (int k = j + 1; k < 3; k++) {
          board[i][k] = board[i][k + 1];
        }
        board[i][3] = 0;
      }
    }

  }
  return board;
}

vvi moveUp(vvi board) {
  for (int j = 0; j < 4; j++) {
    int location = -1, counter = 0;
    // Pull everything to the top across the empty cells
    for (int i = 0; i < 4; i++) {
      if (board[i][j] == 0) {
        counter++;
        if (counter == 1) location = i;
      }
      else if (board[i][j] != 0 && location != -1) {
        board[location][j] = board[i][j];
        board[i][j] = 0;
        location = i;
        counter = 0;
      }
    }

    // Identify the identical neighbors in one row
    // Double the left one, set the right one to 0
    for (int i = 0; i < 3; i++) {
      if (board[i][j] != 0 && board[i][j] == board[i + 1][j]) {
        board[i][j] = board[i][j] * 2;
        for (int k = i + 1; k < 3; k++) {
          board[k][j] = board[k + 1][j];
        }
        board[3][j] = 0;
      }
    }

  }
  return board;
}

vvi moveRight(vvi board) {
  for (int i = 0; i < 4; i++) {
    int location = -1, counter = 0;
    for (int j = 3; j > -1; j--) {
      if (board[i][j] == 0) {
        counter++;
        if (counter == 1) location = j;
      }
      else if (board[i][j] != 0 && location != -1) {
        board[i][location] = board[i][j];
        board[i][j] = 0;
        location = j;
        counter = 0;
      }
    }
    for (int j = 3; j > 0; j--) {
      if (board[i][j] != 0 && board[i][j] == board[i][j - 1]) {
        board[i][j] = board[i][j] * 2;
        for (int k = j - 1; k > 0; k--) {
          board[i][k] = board[i][k - 1];
        }
        board[i][0] = 0;
      }
    }

  }
  return board;	
}

vvi moveDown(vvi board) {
  for (int j = 0; j < 4; j++) {
    int location = -1, counter = 0;
    for (int i = 3; i > -1; i--) {
      if (board[i][j] == 0) {
        counter++;
        if (counter == 1) location = i;
      }
      else if (board[i][j] != 0 && location != -1) {
        board[location][j] = board[i][j];
        board[i][j] = 0;
        location = i;
        counter = 0;
      }
    }
    for (int i = 3; i > 0; i--) {
      if (board[i][j] != 0 && board[i][j] == board[i - 1][j]) {
        board[i][j] = board[i][j] * 2;
        for (int k = i - 1; k > 0; k--) {
          board[k][j] = board[k - 1][j];
        }
        board[0][j] = 0;
      }
    }

  }
  return board;
}
void solve() {
  vector<vector<int>> grid = vector<vector<int>>(4, vector<int>(4, 0));
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> grid[i][j];
    }
  }
  int move; cin >> move;
  if (move == 0) {
    grid = moveLeft(grid);
  } else if (move == 1) {
    grid = moveUp(grid);
  } else if (move == 2) {
    grid = moveRight(grid);
  } else {
    grid = moveDown(grid);
  }
  printMatrix(grid);
}

int main(){
  solve();
  return 0;
}

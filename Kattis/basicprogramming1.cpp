#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef bitset<22> BITS;
typedef vector<long> vi;
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

void one() {
  cout << 7 << endl;
}

void two(vi nums) {
  if (nums[0] > nums[1]) {
    cout << "Bigger" << endl;
  } else if (nums[0] == nums[1]) {
    cout << "Equal" << endl;
  } else {
    cout << "Smaller" << endl;
  }
}

void three(vi nums) {
  long hi = max(nums[0], max(nums[1], nums[2]));
  long lo = min(nums[0], min(nums[1], nums[2]));
  for (int i = 0; i < 3; i++) {
    if (hi != nums[i] && lo != nums[i]) {
      cout << nums[i] << endl;
      return;
    }
  }
}

void four(vi nums) {
  long sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
  }
  cout << sum << endl;
}

void five(vi nums) {
  long sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i] * (nums[i] % 2 == 0);
  }
  cout << sum << endl;
}

void six(vi nums) {
  string s = "";
  for (int i = 0; i < nums.size(); i++) {
    s.push_back((nums[i] % 26) + 97);
  }
  cout << s << endl;
}

void seven(vi nums) {
  vector<bool> visited = vector<bool>(nums.size(), false);
  long i = 0;
  while (!visited[i]) {
    visited[i] = true;
    if (i < 0 || i >= nums.size()) {
      cout << "Out" << endl;
      return;
    }
    if (i == nums.size() - 1) {
      cout << "Done" << endl;
      return;
    }
    i = nums[i];
  } 
  cout << "Cyclic" << endl;
  return;
}

void solve() {
  long n, cmd; cin >> n >> cmd;
  vector<long> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  if (cmd == 1) {
    one();
  } else if (cmd == 2) {
    two(nums);
  } else if (cmd == 3) {
    three(nums);
  } else if (cmd == 4) {
    four(nums);
  } else if (cmd == 5) {
    five(nums);
  } else if (cmd == 6) {
    six(nums);
  } else {
    seven(nums);
  }
}

int main(){
  solve();
  return 0;
}

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef bitset<22> BITS;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vector<vector<int>>> vv3d;
#define ALL(x) x.begin(),x.end()
#define UNIQUE(x) (x).resize(unique(ALL(x)) - x.begin())

template<typename T>
void printVector(vector<T> a) {
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
  int p,a,b,c,d,n; cin >>p>>a>>b>>c>>d>>n;
  vector<float> price;
  setprecision(17);
  for (int i = 1; i <= n; i++) {
    price.push_back(p * (sin(a * i + b) + cos(c * i + d) + 2));
  }
//  printVector(price);
  vector<float> highest = vector<float>(n, 0);
  vector<float> lowest = vector<float>(n, 0);
  float decline = DBL_MIN;
  for (int i = 0, j = n - 1; i < n; i++, j--) {
    if (i == 0) {
      highest[0] = price[0];
    } else {
      highest[i] = max(price[i], highest[i - 1]);
    }
    if (j == n - 1) {
      lowest[j] = price[j];
    } else {
      lowest[j] = min(price[j], lowest[j + 1]);
    }
  }
//  printVector(highest);
//  printVector(lowest);
  for (int i = 0; i < n; i++) {
    decline = max(decline, highest[i] - lowest[i]);
  }
  if (DBL_MIN == decline) decline = 0.0;
  cout << setprecision(17) <<  decline << endl;
}

int main(){
  solve();
  return 0;
}

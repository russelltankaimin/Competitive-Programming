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

template<typename T>
struct teque {
  deque<T> front;
  deque<T> back;
  long long sz = 0;

  void balance() {
    long long diff = front.size() - back.size();
    if (diff == 0) {
      return;
    }
    // we allow front to be same size as back or at most 1 more
    if (diff > 1) {
      if (sz % 2 == 0) {
        while (front.size() != back.size()) {
          T p = front.back();
          front.pop_back();
          back.push_front(p);
        }
      } else {
        while (front.size() - 1 != back.size()) {
          T p = front.back();
          front.pop_back();
          back.push_front(p);
        }
      }
    } else if (diff <= -1) {
      if (sz % 2 == 0) {
        while (front.size() != back.size()) {
          T p = back.front();
          back.pop_front();
          front.push_back(p);
        }
      } else {
        while (front.size() - 1 != back.size()) {
          T p = back.front();
          back.pop_front();
          front.push_back(p);
        }
      }
    } else {
      return;
    }
  }

  void pushback(T u) {
    back.pb(u);
    sz++;
    balance();
  }

  void pushfront(T u) {
    front.pf(u);
    sz++;
    balance();
  }
    
  void pushmiddle(T u) {
    if (front.size() + 1 == (sz + 1) / 2) {
      front.pb(u);
    } else {
      back.pf(u);
    }
    sz++;
    balance();
  }

  T get(long long idx) {
    if (front.size() <= idx) {
      return back[idx - front.size()];
    } else {
      return front[idx];
    }
  }

  void print() {
    for (long long i = 0; i < front.size() ; i++) {
      cout << front[i] << " ";
    }
    for (long long j = 0; j < back.size(); j++) {
      cout << back[j] << " ";
    }
    cout << endl;
  }
};

void solve() {
  teque<long long> t = teque<long long>();
  long long N; cin >> N; 
  while(N--) {
    string cmd; long long i;
    cin >> cmd >> i;
    if (cmd.compare("push_back") == 0) {
      t.pushback(i);
    } else if (cmd.compare("push_front") == 0) {
      t.pushfront(i);
    } else if (cmd.compare("push_middle") == 0) {
      t.pushmiddle(i);
    } else {
      cout << t.get(i) << endl;
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

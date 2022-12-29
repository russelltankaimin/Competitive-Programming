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


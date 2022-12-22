#include<iostream>
#include<algorithm>
#include<iterator>
#include<numeric>
#include<map>
#include<set>
#include<bitset>
#include<iomanip>
#include<string>
#include<vector>
#include<array>
#include<utility>
#include<cmath>
#include<cctype>
using namespace std;
typedef long long ll;
typedef bitset<22> BITS;
#define ALL(x) x.begin(),x.end()
#define UNIQUE(x) (x).resize(unique(ALL(x)) - x.begin())

template<typename T>
void display(T a){
	cout << "[ ";
	for(int i = 0; i < a.size();i++){
		cout << a[i] << " ";
	}
	cout <<" ]"<< endl;
}


void solve(){
	
}

int main(){
	vector<int> a;
	for(int i = 0; i < 4; i++){
		int b; cin >> b;
		a.push_back(b);
	}
	sort(ALL(a));
	cout << a[0] * a[2] << endl;
	return 0;
}

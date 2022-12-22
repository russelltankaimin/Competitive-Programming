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

void solve(){
	int n, q; cin >> n >> q;
	string s; cin >> s;
	int abc = 0;
	for(int i = 0; i < n - 3; i++){
		if(s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c'){
			abc++;
		}
	}
	for(int i = 0; i < q; i++){
		int idx; string c; cin >> idx >> c;
		if(c == 'a'){
			
		}
	}
		
}

int main(){
	solve();
	return 0;
}

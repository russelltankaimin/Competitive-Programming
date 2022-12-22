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
	
}

int main(){
	ll t;
	cin>>t;
	ll hundred = t/100;
	ll twenty, ten, five;
	ll ans = hundred;
	t -= hundred*100;
	twenty = t/20;
	ans += twenty;
	t-= twenty * 20;
	ans += t/10;
	t-= (t/10) * 10;
	ans += t/5;
	t -= (t/5)*5;
	ans += t;
	cout << ans << endl;
	
	return 0;
}

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

template<typename T>
void display(T a){
	cout << "[ ";
	for(int i = 0; i < a.size();i++){
		cout << a[i] << " ";
	}
	cout << "]" << endl;
}


void solve(){
	int s; cin >> s;
	vector<int> sum(5);
	int days = 0;
	int unavail = 0;
	for(int i = 0; i < s; i++){
		for(int day = 0; day < 5; day++){
			int b ; cin >> b;
			sum[day] += b;
			}
		}
//	display(sum);
	for(int i = 0; i < 5; i++){
		if(sum[i] >= s/2){
				days++;
			}
		}
//	cout << "Days avail : " << days << endl;
	cout << (days < 2 ? "NO" : "YES") << endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

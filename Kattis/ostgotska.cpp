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
	string s;
	vector<char> ss;
	getline(cin,s);
	for(int i = 0; i < s.length(); i++){
		if(isalpha(s[i])){
			ss.push_back(s[i]);
		}
	}
	int ae = 0;
	for(int i = 1; i < ss.size(); i++){
		if(ss[i] == 'e' && ss[i-1] == 'a'){
			ae++;
		}
	}
//	display(ss);
	double ans = ss.size() - 2*ae;
	ans = ae*100/(double)ans;
//	cout << ans << endl;
	if(ans >= 40){
		cout <<"dae ae ju traeligt va" << endl;
	}else{
		cout <<"haer talar vi rikssvenska" << endl;
	}
}	

int main(){
	solve();
	return 0;
}

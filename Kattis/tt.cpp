#include<bits/stdc++.h>
using namespace std;
int main() {
    int T; cin >> T;
    bool hasEven = false;
    bool hasOdd = false;
    int start = T*(2 * 1 + (T - 1));
    int start1 = T*(2 * 2 + (T - 1));
    start >>= 1; start1 >>= 1;
    cout << start << endl;
    cout << start1 << endl;
    hasOdd = (start & 1) | (start1 & 1);
    hasEven = (start % 2 == 0) | (start1 % 2 == 0);
    if (hasOdd && hasEven) {
        cout << "Either" << endl;
    } else if (hasOdd) {
        cout << "Odd" << endl;
    } else {
        cout << "Even" << endl;
    }
}

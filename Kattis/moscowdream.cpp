#include<bits/stdc++.h>
using namespace std;
int main() {
    int count = 0;
    vector<int> a = vector<int>(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
        count += a[i];
    }
    int n; cin >> n;
    if (count < n || n < 3) {
        cout << "NO" << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    for (int p : a) {
        if (p == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}

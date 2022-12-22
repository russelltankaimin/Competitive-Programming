#include<bits/stdc++.h>
using namespace std;
int main() {
    string a, b; cin >> a >> b;
    if ((a.compare("OCT") == 0  && b.compare("31") == 0) || (a.compare("DEC") == 0 && b.compare("25") == 0)){
        cout << "yup" << endl;
    } else {
        cout << "nope" << endl;
    }
}

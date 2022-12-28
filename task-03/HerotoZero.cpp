#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int t, n, mana, zerocount = 0;
    bool flag = false;
    cin >> t;
    while (t--) {
        cin >> n;
        int ai[n];
        for (int i = 0; i < n; i++) {
            cin >> ai[i];
            if (ai[i] == 0) zerocount++;
        }
        sort(ai, ai + n);
        for (int i = 0; i < n-1; i++) {
            if ((ai[i+1] == ai[i]) && (ai[i] != 0)) {
                flag = true;
                break;
            }
        }
        mana = n - zerocount;
        if (!zerocount) 
            if (!flag) mana++;
        cout << mana << "\n";
    }
}


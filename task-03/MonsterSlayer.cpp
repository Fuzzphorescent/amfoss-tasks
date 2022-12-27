#include <iostream>
using namespace std;
int main() {
    int t, n;
    cin>>t;
    while (t>0) {
        cin>>n;
        int flag = 0;
        long long int ai[n];
        cin>>ai[0];
        for(int i = 1; i<n; i++) {
            cin>>ai[i];
            if(ai[i]%ai[0] != 0) flag = 1;
        }
        if (flag == 0) cout<<"YES\n";
        else cout<<"NO\n";
        t--;
    }
    return 0;
}


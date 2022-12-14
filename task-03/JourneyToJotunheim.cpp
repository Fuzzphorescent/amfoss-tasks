#include <cstdio>
#include <iostream>
using namespace std;


int main() {
    int t, x, portal[3];
    cin>>t;
    while(t>0) {
        cin>>x;
        cin>>portal[0]>>portal[1]>>portal[2];
        if(portal[x-1]!=0 & portal[portal[x-1]-1]!=0)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<"\n";
    t--;
    }
    return 0;
}

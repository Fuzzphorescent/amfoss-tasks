#include <cstdio>
#include <iostream>
using namespace std;


int main() {
    long long int n, sum, count = 0;
    cin>>n;
    while(n>=10) {
        long long int r;
        sum =0;
        while(n>0) {
            r = n%10;
            n = n/10;
            sum += r;
        }
        count++;
        n = sum;
    }
    cout<<count;
    return 0;
}

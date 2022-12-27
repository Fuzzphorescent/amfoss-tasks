#include <iostream>
using namespace std;

int main() {
    long long int n, m, count = 0;
    cin >> m >> n;
    if (n%m) count = -1;
    else {
        long long int q = n/m;
        while (!(q%3)) {
            q /= 3;
            count++;
        }
        while (!(q%2)) {
            q /= 2;
            count++;
        }
        if (q != 1) count = -1;
    }
    cout << count << "\n";
    return 0;
}


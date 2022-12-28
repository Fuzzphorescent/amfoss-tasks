#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    float n; int m;
    cin >> n >> m;
    int minNotes = ceil(n/2);
    if (n < m) cout << -1;
    else if (minNotes % m == 0) cout << minNotes;
    else cout << minNotes + m - minNotes % m;
    return 0;
}


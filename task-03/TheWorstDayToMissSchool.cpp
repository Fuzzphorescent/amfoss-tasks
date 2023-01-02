#include <iostream>
using namespace std;

int main() {
    int n, groupsof[5] = {0}, cars = 0;
    cin >> n;
    while (n--) {
        int i;
        cin >> i;
        groupsof[i]++;
    }
    
    cars = min(groupsof[1], groupsof[3]);
    groupsof[3] -= cars;
    groupsof[1] -= cars;
    cars += groupsof[3];
    
    cars += groupsof[4];
    
    cars += groupsof[2]/2;
    groupsof[2] &= 1;
    if (groupsof[2]) {
        if (groupsof[1] > 1) {
            groupsof[1] -= 2;
        }
        else if (groupsof[1] == 1) {
            groupsof[1] -= 1;
        }
        cars++;
    }

    cars += groupsof[1]/4;
    if (groupsof[1] % 4) cars++;
    
    cout << cars << "\n";
    return 0;
}


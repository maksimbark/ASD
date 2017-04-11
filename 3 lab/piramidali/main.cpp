#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
int main() {
vector<int> a;
    ifstream cin("isheap.in");
    ofstream cout("isheap.out");

    a.push_back(0);
    int n;
    cin >> n;
    int curr;
    for (int i = 1; i <= n; i++) {
        cin >> curr;
        a.push_back(curr);
    }
int flag = 0;

    for (int i = 1; i<=n; i++) {

if (2*i <= n) {
    if (a[i] > a[2 * i]) flag = 1;
}

    if ((2*i)+1 <= n) {
            if (a[i]>a[(2*i)+1]) flag = 1;
        }
}

    if (flag == 1) {
        cout << "NO";
    } else {
        cout << "YES";
    }

        return 0;
}

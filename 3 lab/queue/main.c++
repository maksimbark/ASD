#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    long long n,i,cu;
    vector<int> a;
    cin >> n;
    string curr;
    for (i = 0; i < n; i++) {
        cin >> curr;
        if (curr == "-") {
            cout << a[0] << endl;
            a.erase(a.begin());

        } else {
            cin >> cu;
            a.push_back(cu);
        }
    }

    //for (auto q: a) {
    //   cout << q << endl;
    // }

    return 0;
}
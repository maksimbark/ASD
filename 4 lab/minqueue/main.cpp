#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    int miniter = 0;
    ifstream cin("queuemin.in");
    ofstream cout("queuemin.out");
    long long n, i, cu;
    vector<long long> pushy;
    cin >> n;
    string curr;
    for (i = 0; i < n; i++) {
        cin >> curr;
        if (curr == "-") {
            //pushy.erase(pushy.begin());
            miniter++;
        } else if (curr == "+") {
            cin >> cu;
            pushy.push_back(cu);
            if (pushy.size() - miniter > 1) {
                for (int i = miniter; i < pushy.size(); i++) {
                    if (pushy[i] > cu) {
                        pushy[i] = cu;
                    }
                }
            }
        } else {
cout << pushy[miniter] << endl;
        }
    }


    return 0;
}
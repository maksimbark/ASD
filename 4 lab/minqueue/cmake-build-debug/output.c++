#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main() {
    ifstream cin("queuemin.in");
    ofstream cout("queuemin.out");
    long long n, i, cu, min, answer;
    vector< vector<int> > a, b;
    min = 1000000001;
    vector<int> pushy;
    cin >> n;
    string curr;
    for (i = 0; i < n; i++) {
        cin >> curr;
        if (curr == "-") {
            if (b.size() == 0) {
                reverse(a.begin(), a.end());
                b = a;
                a.clear();
            }
            b.pop_back();
 
        } else if (curr == "+") {
            cin >> cu;
            if (min > cu) {
                min = cu;
            }
            pushy.push_back(cu);
            pushy.push_back(min);
            a.push_back(pushy);
            pushy.clear();
        } else {
            answer = 1000000001;
            for (int i = 0; i < b.size(); i++) {
                if (b[i][0] < answer) {
                    answer = b[i][0];
                }
            }
            for (int i = 0; i < a.size(); i++) {
                if (a[i][1] < answer) {
                    answer = a[i][1];
                }
            }
            cout << answer << endl;
        }
    }
 
 
    return 0;
}
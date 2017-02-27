#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int n;

vector<string> rasort(vector<string> arr, int k) {

    vector<string> cat;
    vector< vector <int> > positions ('z'+1,vector<int>(0));
    //vector<int> count('z');
    for (int i = 0; i < n; i++) {
        //count[arr[i][k]]++;
        positions[arr[i][k]].push_back(i);
    }

    for (char i = 'a'; i <= 'z'; i++) {
        for (int j = 0; j < positions[i].size(); j++) {
            cat.push_back(arr[positions[i][j]]);
        }
    }
    return cat;
}

int main() {
    ifstream cin("radixsort.in");
    ofstream cout("radixsort.out");
    int m, k;
    string curr;
    cin >> n >> m >> k;
    vector<string> arr;
    for (int i = 0; i < n; i++) {
        cin >> curr;
        arr.push_back(curr);
    }
    for (int i = m-1; i>=m-k; i--) {
        arr = rasort(arr, i);
        //cout << i << " ";

    }
    for (int i = 0; i < arr.size(); i++) {
        //if (arr[i] != "") {
        cout << arr[i] << endl;
        //}
    }

    return 0;
}
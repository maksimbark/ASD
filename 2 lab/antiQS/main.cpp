#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
int main() {
ifstream cin("input.txt");
     ofstream cout("output.txt");
    int a;
    cin >> a;


    vector<int> arr(a);
    for (int i = 0; i < a; i++) {
        arr[i] = i + 1;
    }

    for (int i = 2; i < a; i++) {
        swap(arr[i], arr[i / 2]);
        //for (int i = 0; i < a; i++) {
           // cout << arr[i] << " ";
       // }
        //cout << endl;
    }

        for (int i = 0; i < a; i++) {
            cout << arr[i] << " ";
        }

        cout <<endl;




    return 0;
}
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>


using namespace std;

void restore(vector<int> &arr, int k) {

    int maxind = k;
    int left = (k + 1) * 2 - 1;
    int right = (k + 1) * 2;

    if (left < arr.size() && arr[left] > arr[maxind]) {
        maxind = left;
    }

    if (right < arr.size() && arr[right] > arr[maxind]) {
        maxind = right;
    }

    if (maxind != k) {
        swap(arr[k], arr[maxind]);
        restore(arr, maxind);
    }

};

int main() {
    vector<int> arr;
    vector<int> answer;

    ifstream fin("sort.in");
    ofstream fout("sort.out");

    int n, curr;

    fin >> n;

    for (int i = 0; i < n; i++) {
        fin >> curr;
        arr.push_back(curr);
    }

    for (int j = (arr.size() / 2) - 1; j >= 0; j--) {
        restore(arr, j);
    }


    for (int i = 0; i < n; i++) {
        answer.push_back(arr[0]);
        arr.erase(arr.begin());
        restore(arr, 0);
    }

    for (int i = answer.size() - 1; i >= 0; i--) {
        fout << answer[i] << " ";
    }

restore(arr, 0);

    for (int i = arr.size() - 1; i >= 0; i--) {
        swap(arr[1], arr[i]);
        fout << arr[i] << " ";
        arr.erase(arr.end() - 1);
        restore(arr, 0);
    }
for (auto q: arr) {
 //    fout << q << " ";
}
    return 0;
}
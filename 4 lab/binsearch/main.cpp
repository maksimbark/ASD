#include <bits/stdc++.h>

using namespace std;

int binser(vector<int> &arr, int a) {
    int left = 1;
    int right = arr.size() - 1;
    int curr = right / 2;
    while (true) {
        if ((arr[curr] == a && curr == 1) || (curr > 1 && arr[curr] == a && arr[curr - 1] != a)) {
            return curr;
        } else if (curr == 0 || curr == arr.size() - 1 || (right - left) < 2) {
            if ((curr + 1) < arr.size() && arr[curr + 1] == a) { return curr + 1; } else { return -1; }
        } else if (arr[curr] >= a) {
            right = curr;
            curr = (left + right) / 2;
        } else if (arr[curr] <= a) {
            left = curr;
            curr = (left + right) / 2;
        }

    }
}

int rightser(vector<int> &arr, int a, int left) {
    int right = arr.size() - 1;
    int curr = (left + right) / 2;
    while (true) {
        if ((arr[curr] == a && curr == arr.size() - 1) || (arr[curr] == a && arr[curr + 1] != a)) {
            return curr;
        } else if (arr[curr + 1] == a && curr + 1 == arr.size() - 1 || arr[curr + 1] == a && arr[curr + 2] != a) {
            return curr + 1;
        } else if (curr == 0 || curr == arr.size() - 1 || (right - left) < 2) {
            return -1;
        } else if (arr[curr] > a) {
            right = curr;
            curr = (left + right) / 2;
        } else if (arr[curr] <= a) {
            left = curr;
            curr = (left + right) / 2;
        }

    }
}

int main() {
    ifstream fin("binsearch.in");
    ofstream fout("binsearch.out");
    int n, curr, firsty;
    vector<int> arr;
    fin >> n;
    arr.push_back(0);
    for (int i = 0; i < n; i++) {
        fin >> curr;
        arr.push_back(curr);
    }
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> curr;
        firsty = binser(arr, curr);
        fout << firsty << " ";
        if (firsty > -1) {
            fout << rightser(arr, curr, firsty) << " " << endl;
        } else {
            fout << -1 << endl;
        }


    }
    return 0;
}

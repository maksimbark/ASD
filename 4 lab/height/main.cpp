//#pragma comment(linker, ”/STACK:36777216“)
//#include <bits/stdc++.h>
#include <fstream>


using namespace std;
int a[200001][3];
int maxh = -1;

void search(int k, int curr) {
    if (a[k][1] != 0) {
        search(a[k][1], curr + 1);
    } else {
        if (curr > maxh) {
            maxh = curr;
        }
    }
    if (a[k][2] != 0) {
        search(a[k][2], curr + 1);
    } else {
        if (curr > maxh) {
            maxh = curr;
        }
    }
}

int main() {
    ifstream fin("height.in");
    ofstream fout("height.out");
    int n, curr;
    fin >> n;
    if (n == 0) {
        fout << 0;
    } else {

        for (int i = 1; i <= n; i++) {
            fin >> curr;
            a[i][0] = curr;
            fin >> curr;
            a[i][1] = curr;
            fin >> curr;
            a[i][2] = curr;
        }
        search(1, 1);
         fout << maxh;
    }
    return 0;
}
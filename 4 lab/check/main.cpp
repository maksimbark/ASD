#include <bits/stdc++.h>


using namespace std;
int a[200001][4];
vector<int> sorty;

void lefty(int k) {
  if (a[k][3] == 111) {
      lefty(a[k][1]);
      sorty.push_back(a[k][0]);
      lefty(a[k][2]);
  }
}

bool issorted() {
    for (int i = 0; i <= sorty.size() - 2; i++) {
        if (sorty[i] >= sorty[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    ifstream fin("check.in");
    ofstream fout("check.out");
    int n, curr;
    fin >> n;
    if (n == 0 || n == 1) {
        fout << "YES";
    } else {

        for (int i = 1; i <= n; i++) {
            fin >> curr;
            a[i][0] = curr;
            fin >> curr;
            a[i][1] = curr;
            fin >> curr;
            a[i][2] = curr;
            a[i][3] = 111;
        }

        lefty(1);
        if (issorted()) {
            fout << "YES";
        } else {
            fout << "NO";
        }
    }

    return 0;
}
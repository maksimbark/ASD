#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int size, count;
    int n, m;
    fin >> size >> count;
    vector<vector<int>> matrix(size + 1, vector<int>(size + 1));
    for (int i = 0; i < count; i++) {
        fin >> n >> m;
        matrix[n][m]++;
        matrix[m][n]++;
        if (matrix[n][m] > 1) {
            fout << "YES" << endl;
            exit(0);
        }
    }
    fout << "NO" << endl;

    return 0;
}

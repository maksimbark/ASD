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
        matrix[n][m] = 1;
    }
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            fout << matrix[i][j] << " ";
        }
        fout << endl;
    }
    return 0;
}
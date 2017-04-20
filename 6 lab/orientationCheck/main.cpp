#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int size;
    fin >> size;
    vector<vector<int>> matrix(size, vector<int>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fin >> matrix[i][j];
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((matrix[i][j] != matrix[j][i]) || ((i == j) && (matrix[i][j] == 1))) {
                fout << "NO" << endl;
                exit(0);
            }
        }
    }
    fout << "YES" << endl;
    return 0;
}
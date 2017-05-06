#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("pathsg.in");
    ofstream fout("pathsg.out");
    long long size, edge;
    fin >> size >> edge;
    vector<vector<long long>> matrix(size + 1, vector<long long>(size + 1, LLONG_MAX));
    long long from, where, how;
    for (long long i = 1; i <= edge; ++i) {
        fin >> from >> where >> how;
        matrix[from][where] = matrix[from][where] > how ? how : matrix[from][where];
    }
    for (long long k = 1; k <= size; ++k)
        for (long long i = 1; i <= size; ++i)
            for (long long j = 1; j <= size; ++j)
                if (matrix[i][k] < LLONG_MAX && matrix[k][j] < LLONG_MAX)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);


    for (long long i = 1; i <= size; ++i) {
        for (long long j = 1; j <= size; ++j)
            fout << (i == j ? 0 : matrix[i][j]) << " ";
        fout << endl;
    }

    return 0;
}
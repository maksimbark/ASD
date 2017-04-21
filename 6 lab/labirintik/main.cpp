#include <bits/stdc++.h>

using namespace std;
struct point {
    int x, y;
} S, T;

int n, m;
vector<vector<char>> symbols(100, vector<char>(100));
int minStep = 1000000000;
bool found = false;
/*
 * from
 * 0 слева
 * 1 справа
 * 2 сверху
 * 3 снизу
 */
void search(int x, int y, int currStep, int from) {
    if (symbols[x][y] == 'T' && minStep > currStep) {
        minStep = currStep;
    } else {
        if (x - 1 >= 0 && symbols[x - 1][y] != '#' && from != 1) {
            search(x - 1, y, currStep + 1, 0);
        }
        if (y - 1 >= 0 && symbols[x][y-1] != '#' && from != 2) {
            search(x, y-1, currStep + 1, 3);
        }
        if (y + 1 < m && symbols[x][y+1] != '#' && from != 3) {
            search(x, y+1, currStep + 1, 2);
        }
        if (x + 1 < n && symbols[x+1][y] != '#' && from != 0) {
            search(x+1, y, currStep + 1, 1);
        }

    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    char curr;
    fin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fin >> curr;
            symbols[i][j] = curr;
            if (curr == 'S') {
                S.x = i;
                S.y = j;
            }
        }
    }

    search(S.x, S.y, 0, -1);
    if (minStep == 1000000000) {
        fout << -1;
    } else {
        fout << minStep;
    }
    return 0;
}
#include <bits/stdc++.h>
//be careful, it's WA version!
using namespace std;
struct graph {
    int kuda;
    graph *next;
};
vector<graph *> myGraph(100001);
vector<char> colors(100001);
vector<int> answer;
bool ruse = false;
int crutch = -1;

void search(int gde) {
    if (colors[gde] == 'w') {
        colors[gde] = 'g';
        graph *temp = myGraph[gde];
        while (temp) {
            if (colors[temp->kuda] == 'w') search(temp->kuda); else if (colors[temp->kuda] == 'g') {
                ruse = true;
                crutch = temp->kuda;
                break;
            }
            temp = temp->next;
        }
        if (ruse) answer.push_back(gde);
        if (gde == crutch) ruse = false;
        colors[gde] = 'b';
    }
}

int main() {
    ifstream fin("cycle.in");
    ofstream fout("cycle.out");
    int n, m, a, b;
    fin >> n >> m;

    for (int i = 0; i < m; i++) {
        fin >> a >> b;
        if (!myGraph[a]) {
            graph *temp = new(graph);
            temp->kuda = b;
            colors[a] = 'w';
            colors[b] = 'w';
            temp->next = NULL;
            myGraph[a] = temp;
        } else {
            graph *temp = myGraph[a];
            while (temp->next) {
                temp = temp->next;
            }
            graph *add = new(graph);
            add->kuda = b;
            colors[b] = 'w';
            add->next = NULL;
            temp->next = add;
        }
    }
    for (int i = 1; i <= n; i++) {
       if (colors[i] == 'w') search(i);
    }

    if (crutch == -1) {
        fout << "NO";
    } else {
        fout << "YES" << endl;
        for (auto q: answer) {
            fout << q << ' ';
        }
    }

    return 0;
}

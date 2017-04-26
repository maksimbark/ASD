#include <bits/stdc++.h>

using namespace std;
struct graph {
    int kuda;
    graph *next;
    bool exists;
};
vector<graph *> myGraph(100001);
vector<char> colors(100001);
vector<int> answer;

bool ruse = false;

void search(int gde) {
    if (colors[gde] == 'w') {
        colors[gde] = 'g';
        graph *temp = myGraph[gde];
        while (temp && temp->exists) {
            if (colors[temp->kuda] == 'w') search(temp->kuda);
            else if (colors[temp->kuda] == 'g') {
                ruse = true;
                return;
            }
            temp = temp->next;
        }
        answer.push_back(gde);
        colors[gde] = 'b';
    }
}

int main() {

    ifstream fin("topsort.in");
    ofstream fout("topsort.out");
    int n, m, a, b;
    fin >> n >> m;

    for (int i = 1; i <= n; i++) {
        colors[i] = 'w';
        myGraph[i] = new(graph);
        myGraph[i]->exists = false;
    }
    for (int i = 0; i < m; i++) {
        fin >> a >> b;
        if (!myGraph[a]->exists) {
            myGraph[a]->exists = true;
            myGraph[a]->kuda = b;
            colors[b] = 'w';
            myGraph[a]->next = NULL;
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
        if (myGraph[i] && colors[i] == 'w') {
            search(i);

        }
    }

    if (ruse) {
        fout << -1 << endl;
    } else {
        reverse(answer.begin(), answer.end());
        for (auto q: answer) {
            fout << q << ' ';
        }
    }

    return 0;
}
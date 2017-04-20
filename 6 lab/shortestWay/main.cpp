#include <bits/stdc++.h>

using namespace std;

struct listik {
    int kuda;
    listik *next;
};

struct node {
    listik *cat;
    string color;
};

int qcount = 1;
vector<int> answer(30001);
vector<node *> graph(30001);
queue<int> bfs;

void search(int curr) {
    graph[curr]->color = "grey";
    listik *temp = graph[curr]->cat;
    while (temp) {
        if (graph[temp->kuda]->color == "white") {
            if (!answer[temp->kuda]) {
                answer[temp->kuda] = qcount;
            }
            bfs.push(temp->kuda);
            temp = temp->next;
        } else break;
    }
    graph[curr]->color = "black";
    qcount++;
    bfs.pop();
    if (bfs.size() > 0) {
        search(bfs.front());
    }
}

int main() {
    ifstream fin("pathbge1.in");
    ofstream fout("pathbge1.out");
    int size, count;
    int from, where;
    fin >> size >> count;
    for (int i = 1; i <= size; i++) {
        node *temp = new(node);
        temp->color = "white";
        temp->cat = NULL;
        graph[i] = temp;
    }

    for (int i = 0; i < count; i++) {
        fin >> from >> where;

        if (!graph[from]->cat) {
            listik *add = new(listik);
            add->kuda = where;
            add->next = NULL;
            graph[from]->cat = add;
        } else {
            listik *temp = graph[from]->cat;
            while (temp->next) {
                temp = temp->next;
            }
            listik *add = new(listik);
            add->kuda = where;
            add->next = NULL;
            temp->next = add;
        }

        if (!graph[where]->cat) {
            listik *add = new(listik);
            add->kuda = from;
            add->next = NULL;
            graph[where]->cat = add;
        } else {
            listik *temp = graph[where]->cat;
            while (temp->next) {
                temp = temp->next;
            }
            listik *add = new(listik);
            add->kuda = from;
            add->next = NULL;
            temp->next = add;
        }

    }

    fout << 0 << " ";
    bfs.push(1);
    search(1);
    for (int i = 2; i <= size; i++) {
        fout << answer[i] << " ";
    }
    return 0;
}
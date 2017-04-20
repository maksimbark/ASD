#include <bits/stdc++.h>

using namespace std;

struct listik {
    int kuda;
    listik *next;
};

struct node {
    listik* cat;
    string color;
};

int qcount = 0;
vector<int> answer(100001);
vector<node *> graph(100001);
queue<int> bfs;

void search(int curr) {
    graph[curr]->color = "grey";
    listik* temp = graph[curr]->cat;
    while (temp) {
        if (graph[temp->kuda]->color == "white") {
            //graph[temp->kuda]->color = "grey";
            bfs.push(temp->kuda);
            temp = temp->next;
        } else break;
    }
    graph[curr]->color = "black";
    answer[curr] = qcount;
    bfs.pop();
    if (bfs.size() > 0) {
        search(bfs.front());
    }
}

int main() {
    ifstream fin("components.in");
    ofstream fout("components.out");
    int size, count;
    int from, where;
    fin >> size >> count;
    for (int i = 1; i <= size; i++) {
        node* temp = new(node);
        temp->color = "white";
        temp->cat = NULL;
        graph[i] = temp;
    }

    for (int i = 0; i < count; i++) {
        fin >> from >> where;
        if(!graph[from]->cat) {
            listik *add = new(listik);
            add->kuda = where;
            add->next = NULL;
            graph[from]->cat = add;
        } else {
            listik *temp = graph[from]->cat;
            while(temp->next) {
                temp = temp->next;
            }
            listik *add = new(listik);
            add->kuda = where;
            add->next = NULL;
            temp->next = add;
        }
    }

    for (int i = 1; i <= size; i++) {
        if (graph[i]->color == "white") {
            qcount++;
            bfs.push(i);
            search(i);
        }
    }
    fout << qcount << endl;
    for (auto q: answer) {
        if (q) fout << q << " ";
    }
    return 0;
}
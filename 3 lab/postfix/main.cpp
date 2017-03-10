#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main() {

    ifstream fin("postfix.in");
    ofstream fout("postfix.out");
    int temcur;
    vector<int> a;
    char curr;
    int temp;
    do {
        fin >> curr;
        if (curr == '+' && (a.size())>1) {
            temp = (a[a.size()-2]) + (a[a.size()-1]);
            a.erase(a.end()-1);
            a.erase(a.end()-1);
            a.push_back(temp);
        } else if (curr == '-' && (a.size())>1) {
            temp = (a[a.size()-2]) - (a[a.size()-1]);
            a.erase(a.end()-1);
            a.erase(a.end()-1);
            a.push_back(temp);
        } else if (curr == '*' && (a.size())>1) {
            //cout << curr << " " << a.size() << endl;
            temp = (a[a.size()-2]) * (a[a.size()-1]);
            a.erase(a.end()-1);
            a.erase(a.end()-1);
            a.push_back(temp);
        } else {
            temcur = int(curr)-48;
            a.push_back(temcur);
        }
    } while (!fin.eof());
    fout << a[0];
    return 0;
}
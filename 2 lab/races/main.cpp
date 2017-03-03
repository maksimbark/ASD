#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> msort(vector<string> mas) {
    vector<string> answ;
    if (mas.size() > 1) {
        vector<string> left;
        vector<string> right;

        for (int i = 0; i < mas.size()/2; i++) {
            left.push_back(mas[i]);
        }
        for (long int i = mas.size()/2; i < mas.size(); i++) {
            right.push_back(mas[i]);
        }
        left = msort(left);
        right = msort(right);
        int coLeft = 0;
        int coRight = 0;

        while (coLeft<left.size() && coRight < right.size()) {
            if (left[coLeft] > right[coRight]) {
                answ.push_back(right[coRight]);
                coRight++;
            } else {
                answ.push_back(left[coLeft]);
                coLeft++;
            }
        }
        while ((coLeft) < left.size() || (coRight) < right.size()) {
            if ((coLeft) < left.size()) {
                answ.push_back(left[coLeft]);
                coLeft++;
            }
            if ((coRight) < right.size()) {
                answ.push_back(right[coRight]);
                coRight++;
            }
        }


//cout << endl << coLeft << ' ' << coRight;
        return answ;
    }


    return mas;
}

int main() {
    ifstream fin("race.in");
    ofstream fout("race.out");
    map <string, int> count;
    vector<string> countries;
    map <string, vector<string>> mas;
    int a;
    fin >> a;
    string str1, str2;
    countries.clear();
    for (int i = 0; i < a; i++) {
        fin >> str1 >> str2;
        mas[str1].push_back(str2);
        count[str1]++;
        if (count[str1] == 1) {
            countries.push_back(str1);
        }
    }

    //cerr << countries.size();
    countries  = msort(countries);

    for (int i = 0; i < countries.size(); i++) {
        fout << "=== " << countries[i] << " ===" << endl;
        for (int j = 0; j < count[countries[i]]; j++) {
            fout << mas[countries[i]][j] << endl;
        }
    }
    return 0;
}
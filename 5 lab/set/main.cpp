#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
vector<bool> arr(2000000001);

int main() {
    ifstream fin("set.in");
    ofstream fout("set.out");

    string curr;
    int now;

    while(fin >> curr) {
        fin >> now;
        if (now < 0) {
            now = (abs(now))+1000000000;
        }
        if (curr == "insert") {
            arr[now] = true;
        } else if (curr == "exists") {
            if (arr[now]) {
                fout << "true" << endl;
            } else {
                fout << "false" << endl;
            }

        } else {
            arr[now] = false;
        }
    }


    return 0;
}

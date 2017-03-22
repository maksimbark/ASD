#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("brackets.in");
    ofstream fout("brackets.out");
    
    
    vector<char> a;
    char curr;
    string curs;
    while(!fin.eof()) {
        
        fin >> curs;
        
        for (int i = 0; i < curs.size(); i++) {
            curr = curs[i];
            
            a.push_back(curr);
            if (a.size() == 1) {
                
            } else {
                if ((curr == ']' && a[a.size() - 2] == '[') || (curr == ')' && a[a.size() - 2] == '(')) {
                    a.erase(a.end() - 1);
                    a.erase(a.end() - 1);
                }
            }
            
        }
        
        
        if (a.size() == 0) {
            fout << "YES" << endl;
        } else {
            fout << "NO" << endl;
        }
        a.clear();
        
        
        
    }
    
    return 0;
}

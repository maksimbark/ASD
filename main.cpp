#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int h, w;
    fin >> h >> w;
    
    vector< vector <int> > turtleArray(h+2,vector<int>(w+1));
    
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
         
            fin >> turtleArray[i][j];
            
        }
    }
    
    for (int i=h; i>=1; i--) {
        for (int j=1; j<=w; j++) {
         
            turtleArray[i][j]+=max(turtleArray[i+1][j], turtleArray[i][j-1]);
            
        }
    }
    /*
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
         
            cout<< turtleArray[i][j] << " ";
            
        }
        cout << endl;
    }*/
    fout << turtleArray[1][w];
    return 0;
}

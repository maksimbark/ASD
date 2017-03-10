#include <iostream>
#include <vector>


using namespace std;


void sorty(vector<int>& array, int a, int b) {
if ((b-a) > 0) {
    int min = a;
    int mid = (a+b)/2;
    int max = b;

    if (array[max] < array[min]) {
        swap(array[max], array[min]);
    }
    if (array[max] < array[mid]) {
        swap(array[max], array[mid]);
    }
    if (array[mid] < array[min]) {
        swap(array[mid], array[min]);
    }
    swap(array[mid],array[max]);
    mid = max;

    int curmid = array[mid];
    int i = a;
    int j = b;

    while (i < j) {
        while (array[i] < curmid) {
            i++;
        }
        while (array[j] > curmid) {
            j--;
        }
        if (i < j) {
            swap(array[i], array[j]);
            if (array[i] != curmid) {i++;}
            if (array[j] != curmid) {j--;}

        }
    }

    sorty(array, a, i-1);
    sorty(array, i+1,b);

}

}

int main() {
int curr;
    vector<int> array;
    for (int i = 0; i<150; i++) {
        array.push_back(i);
       // cin >> curr;
        //array.push_back(curr);
    }
    for (int i = 0; i<15000; i++) {
        swap(array[rand() % 150],array[rand() % 150]);
   }
    for (int i = 0; i<15; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    vector<int>& link = array;
    sorty(link, 0, array.size()-1);
    for (int i = 0; i<150; i++) {
        cout << array[i] << " ";
    }


    return 0;

}
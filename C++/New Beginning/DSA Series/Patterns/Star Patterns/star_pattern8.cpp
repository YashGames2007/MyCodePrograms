#include <iostream>
using namespace std;
/*
INCOMPLETE
4
   *
* * * *
 * * *
* * * *
   *
7

      *
     * *
* * * * * * * 
 * * * * * * 
  * * * * * 
 * * * * * * 
* * * * * * * 
     * *
      *
*/


void printStar(int n) {
    int mid = n/2;
    for(int i = 0; i < n; i++) {
        if (i == 0 || i == n-1) {
            // heavily indented single star
            for(int j = 0; j < mid; j++) cout << "  ";
            cout << "*\n";
        }
        else if (i == mid) {
            // central full row
            for(int j = 0; j < n; j++) cout << "* ";
            cout << "\n";
        }
        else if (i % 2 == 0) {
            // indented, alternate rows
            int spaces = n - i - 1;
            for(int j = 0; j < spaces; j++) cout << " ";
            for(int j = 0; j < n-1; j++) cout << "* ";
            cout << "\n";
        }
        else {
            // full star rows
            for(int j = 0; j < n; j++) cout << "* ";
            cout << "\n";
        }
    }
}

int main() {
    int n;
    cin >> n;
    printStar(n);
    return 0;
}

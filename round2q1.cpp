// abcdeeddx
// co*d+eed*


#include <iostream>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    
    int n = a.length();
    int x = 0;
    int i = 0;
    while (i < n) {
        int itr = i, xp = x;
        string temp = "";
        int poss = 1;
        while (poss && i < n && x < b.length()) {
            if (x + 1 < n) {
                if (b[x] >= 'a' && b[x] <= 'z' && b[x+1] == '+') {
                    int f = 1;
                    while (1) {
                        if (b[x] != a[i]) {
                            if (f) {
                                poss = 0;
                            }
                            break;
                        }
                        temp += a[i];
                        i++;
                        f = 0;
                    }
                    x += 2;
                    
                    
                } else if (b[x] >= 'a' && b[x] <= 'z' && b[x+1] == '*') {
                    while (1) {
                        if (b[x] != a[i]) {
                            break;
                        }
                        temp += a[i];
                        i++;
                    }
                    x += 2;
                    
                } else if (b[x] == a[i]) {
                    temp += b[x];
                    x++; i++;
                     
                } else {
                    poss = 0;
                }
            } else {
                if (b[x] == a[i]) {
                    temp += a[i];
                    cout << temp;
                    return 0;
                }
            }
        }
        if (poss == 1 && x >= b.length()) {
            cout << temp;
            return 0;
        }
        i = itr+1;
        x = 0;
    }
    
    
    
    
    cout << endl;
    return 0;
}

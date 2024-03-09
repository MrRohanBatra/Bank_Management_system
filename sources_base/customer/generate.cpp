#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream file;
    string name;
    cout<<"enter file name: ";
    getline(cin,name);
    file.open(name);
    file.close();
    return 0;
}
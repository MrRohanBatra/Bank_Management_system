#include <iostream>
#include <conio.h>

using namespace std;

string getdob() 
{
    int count = 1;
    string dob;
    char c;
    while (count <= 8)
    {
        c = getch();
        if (c != 13)
        {
            if (count == 3 || count == 5)
            {
                dob = dob + ".";
                cout << ".";
            }
            dob = dob + c;
            cout << c;
            count++;
        }
    }
    cout<<endl;
    return dob;
}
 int main()
 {
    string dob=getdob();
    cout<<dob<<endl;
 }
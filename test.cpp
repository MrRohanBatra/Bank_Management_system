#include <iostream>
#include <conio.h>
using namespace std;

string getdob() {
    int count = 1;
    string dob;
    char c;
    while (count <= 8) {
        c = getch();
        if (c != 13) { // 13 is the ASCII value for Enter key
            if (c == 8) { // Backspace
                if (!dob.empty()) {
                    cout << "\b \b"; // Move cursor back, overwrite character with space, move cursor back again
                    dob.pop_back(); // Remove the last character from dob
                    if (count == 4 || count == 7) {
                        cout << "\b \b"; // For the dot, move cursor back, overwrite with space, move cursor back again
                    }
                    count--;
                }
            } else if ((c >= '0' && c <= '9') && // Only accept digits
                       (count != 3 && count != 6)) { // Don't accept input for dots
                dob += c;
                cout << c;
                count++;
                if (count == 3 || count == 6) { // Add dot after day and month
                    dob += ".";
                    cout << ".";
                }
            }
        } else {
            break; // Exit loop if Enter key is pressed
        }
    }
    cout << endl;
    return dob;
}

int main() {
    cout << "Enter date of birth (DDMMYYYY): ";
    string dob = getdob();
    cout << "Date of Birth: " << dob << endl;
    return 0;
}

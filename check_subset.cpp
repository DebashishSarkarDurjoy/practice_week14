#include <iostream>

using namespace std;

bool checkSubsequence(string s1, string s2) {

    int i = 0;
    int j = 0;
    while (i < s1.length() && j < s2.length()) {
        if (s1[i] == s2[j]) {
            i++;
            j++;
        }
        else {
            i++;
        }
    }

    if (j == s2.length()) return true;


    return false;
}

int main(void) {
    string s1 = "coding minutes";
    string s2 = "cine";

    cout << (checkSubsequence(s1, s2) ? "Yes" : "No") << endl;

    return 0;
}
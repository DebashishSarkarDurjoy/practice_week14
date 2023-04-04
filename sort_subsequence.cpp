#include <iostream>
#include <vector>

using namespace std;

void find_subsequence(string s, string o, vector<string> &v) {
    // base case
    if (s.length() == 0) {
        v.push_back(o);
        return ;
    }

    // recursive case
    string reduced_string = s.substr(1);
    char c = s[0];
    find_subsequence(reduced_string, o + c, v);
    find_subsequence(reduced_string, o , v);

}

bool organise_function(string s1, string s2) {
    if (s1.length() == s2.length()) return s1 < s2;

    return s1.length() < s2.length();
}

int main(void) {
    string input = "abcd";
    vector<string> subsequences;

    find_subsequence(input, "", subsequences);

    sort(subsequences.begin(), subsequences.end(), organise_function);

    for (auto sub: subsequences) {
        cout << sub << " ";
    }
    cout << endl;

    return 0;
}
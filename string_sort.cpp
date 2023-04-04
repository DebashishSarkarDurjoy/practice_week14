#include <iostream>
#include <vector>


using namespace std;

string extractStringAtKey(string str, int key) {
    char *s = strtok( (char *) str.c_str(), " " );
    while (key > 1) {
        s = strtok(NULL, " ");
        key--;
    }
    return (string) s;
}

bool numericCompare(pair<string, string> a, pair<string, string> b) {
    string key1 = a.second;
    string key2 = b.second;

    int key1_int = 0;
    int pow = 1;
    for (int i = key1.size()-1; i >= 0; i--, pow *= 10) {
        key1_int = key1_int + ((key1[i] - '0') * pow);
    }
    int key2_int = 0;
    pow = 1;
    for (int i = key2.size()-1; i >= 0; i--, pow *= 10) {
        key2_int = key2_int + ((key2[i] - '0') * pow);
    }

    return key1_int < key2_int;
}

bool lexicoCompare(pair<string, string> a, pair<string, string> b) {
    string key1 = a.second;
    string key2 = b.second;

    return key1 < key2;
}

int main(void) {
    int n;
    cin >> n;
    cin.get(); // consumes the extra newline character

    vector<string> v;
    string temp;
    for (int i = 0; i < n; i++) {
        getline(cin, temp);
        v.push_back(temp);
    }
    int key;
    string reversal;
    string ordering;
    cin >> key >> reversal >> ordering;

    vector<pair<string, string>> vp;
    for (auto str: v) {
        vp.push_back({str, extractStringAtKey(str, key)});
    }
    // for (auto p: vp) cout << p.first << " " << p.second << endl;

    if (ordering == "numeric") {
        sort(vp.begin(), vp.end(), numericCompare);
    }
    else {
        sort(vp.begin(), vp.end(), lexicoCompare);
    }
   
    if (reversal == "true") {
        reverse(vp.begin(), vp.end());
    }

    for (auto p: vp) cout << p.first << " " << p.second << endl;

    return 0;
}
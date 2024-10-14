#include <iostream>
#include <string>
using namespace std;

string toLowerStr(string str) {
    for (char &c : str) {
        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');
        }
    }
    return str;
}

string toUpperStr(string str) {
    for (char &c : str) {
        if (c >= 'a' && c <= 'z') {
            c = c - ('a' - 'A');
        }
    }
    return str;
}

int calcHammingDist(string s1, string s2) {
    int count = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (toLowerStr(string(1, s1[i])) != toLowerStr(string(1, s2[i]))) {
            count += 1;
        }
    }
    return count;
}

int main() {
    string s1, s2;

    do {
        cout << "DNA1: ";
        cin >> s1;
        cout << "DNA2: ";
        cin >> s2;

        if (s1.length() != s2.length()) {
            cout << "오류: 길이가 다름. 다시 입력하세요." << endl; 
        }
    } while (s1.length() != s2.length());

    int hammingDistance = calcHammingDist(s1, s2);
    cout << "해밍 거리는 " << hammingDistance << endl; 

    return 0;
}
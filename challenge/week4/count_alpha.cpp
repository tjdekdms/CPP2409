#include <iostream>
using namespace std;

int main() {
    int vowel = 0;
    int consonant = 0;
    cout << "영문자를 입력하고 crl+z를 치세요" << endl;

    char ch;

    while(cin>>ch) {
        switch(ch) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                vowel++;
                break;
            default:
                consonant++; 
        }
    }

    cout << "모음:" << vowel << endl;
    cout << "자음:" << consonant << endl;
    return 0;
}
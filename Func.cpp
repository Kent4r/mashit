#include "Header.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void func1() {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        cout << rand() << endl;
    }
}
int auth1(string Login, string Password) {
    if (Login == "a" && Password == "q") {
        return 1;
    }
    else {
        return 0;
    }
}
string convert_to_lower(string sentence) {
    transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
    return sentence;
}
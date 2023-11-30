#include <iostream>
#include <string>
#include <string_view>
#include <windows.h>
#include <map>
#include <sstream>
#include <algorithm>
#include "Header.h"
using namespace std;

static void mg(string_view C, const map<string, int>& m) {
	cout << C;
	for (const auto& [key, value] : m)
		cout << key << " " << value << endl;
	cout << '\n';
}
int main() {
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	map<string, int> m;
	string sentence, Word, Pun = ",.:;-<>()0123456789ЧЂї", k = "-х";
	cout << "¬ведите ѕредложение: ";
	getline(cin, sentence);
	sentence = convert_to_lower(sentence);
	for (int i = sentence.size(); i >= 0; i--) {
		for (int k = Pun.size(); k >= 0; k--) {
			if (sentence[i] == '-' && sentence[i + 1] == 'х') { sentence.erase(i, 2); }
			if (sentence[i] == Pun[k]) sentence.erase(i, 1);
		}
		if ((sentence[i] == ' ' && sentence[i + 1] == ' ') || (sentence[i] == ' ' && sentence[i - 1] == ' ')) sentence.erase(i, 1);
	}
	istringstream stream(sentence);
	while (getline(stream, Word, ' ')) {
		m[Word]++;
		m["Total:"]++;
	}
	mg("Words: \n", m);
	return 0;
}
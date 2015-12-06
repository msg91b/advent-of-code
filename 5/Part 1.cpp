#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int vowels(string s) {
	string vowels = "aeiou";
	int numVowels(0);
	
	for (unsigned int i = 0; i < s.size(); i++) 
		if (vowels.find(s.substr(i, 1)) != (unsigned int)-1)
			numVowels++;
		
	return numVowels;
}

void others(string s, bool& doubles, bool& abcdpqxy) {
	for (unsigned int i = 0; i < s.size() - 1; i++) {
		if (s[i] == s[i + 1]) 
			doubles = true;
		
		if ((s[i] == 'a' && s[i + 1] == 'b') || (s[i] == 'c' && s[i + 1] == 'd')
			|| (s[i] == 'p' && s[i + 1] == 'q') || (s[i] == 'x' && s[i + 1] == 'y')) 
			abcdpqxy = false;
	}
}

int main() {
	ifstream input("input.txt");
	string s;
	int numNice(0);

	while (getline(input, s)) {
		int numVowels(0);
		bool doubles(false), abcdpqxy(true);

		//vowels
		numVowels = vowels(s);

		//doubles && ~abcdpqxy
		others(s, doubles, abcdpqxy);

		if (numVowels >= 3 && doubles && abcdpqxy) 
			numNice++;	
	}
	cout << "Number of nice strings: " << numNice << endl;

	input.close();

	return 0;
}


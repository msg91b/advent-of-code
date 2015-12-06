#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void nice(bool& one, bool& two, int& finalCount) {
	if (one && two)
		finalCount++;

	one = false;
	two = false;
}

void loop(string& s, bool& one, bool& two, int& finalCount) {
	string iTwoSub, jTwoSub, iOneSub, jOneSub;
	for (int i = 0; i < s.size() - 2; i++) {
		iOneSub = s.substr(i, 1);
		iTwoSub = s.substr(i, 2);

		for (int j = i + 2; j < s.size() - 1; j++) {
			jTwoSub = s.substr(j, 2);
			if (iTwoSub == jTwoSub)
				two = true;
		}

		if (i + 2 < s.size()) {
			jOneSub = s.substr(i + 2, 1);
			if (iOneSub == jOneSub)
				one = true;
		}
	}
	nice(one, two, finalCount);
}

int main() {
	ifstream input("input.txt");
	string s;
	bool one = false, two = false;
	int finalCount(0);

	while (getline(input, s)) {
		loop(s, one, two, finalCount);
	}

	cout << "finalCount is: " << finalCount << endl;
	input.close();

	system("pause");
	return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main() {
	string s = "3113322113", e; 
	int size;

	for (int x = 0; x < 50; x++) {
		size = s.size();
		e = "";
		for (int i = 0; i < size; i++) {

			char sub = s[i];
			string ss = s.substr(i, 1);
			int t = stoi(ss);

			if (s[i + 1] == sub) {
				int l = 1;

				while (s[i + l] == sub && (i + l) < size)
					l++;

				i += l - 1;
				e += to_string(l) + ss;
			}
			else
				e += "1" + ss;
		}
		s = e;
		if (x == 39)
			cout << "ending after 40 iterations: " << e.size() << endl;
	}

	cout << "ending after 50 iterations: " << e.size() << endl;

	system("pause");
	return 0;
}
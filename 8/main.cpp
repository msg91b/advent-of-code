using namespace std;

int main() {
	string lineRead;
	int changes(0);
	ifstream input("input.txt");

	while (getline(input, lineRead)) {
		changes += 2;                         // 2 changes for beginning & ending quotes

		for (int i = 0; i < lineRead.size(); i++) {
			if (lineRead[i] == '\\') {
				if (lineRead[i + 1] == 'x') { //if first character is \ and second character is x
					i += 3;                   // then we make 3 changes
					changes += 3;
				}
				else {                        //other two cases \\ and \" only result in one change
					i += 1;
					changes += 1;
				}
			}
		}
	}
	cout << "number of changes: " << changes << endl;

	system("pause");

	return 0;
}
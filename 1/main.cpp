#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int floor(0), position(0), counter(0);
	char c;
	bool flag = true;

	ifstream directions;
	directions.open("floor.txt");

	while (directions.get(c)) {
		counter++;
		if (c == '(') {
			floor++;
		}
		else if (c == ')') {
			floor--;
		}
		if (floor == -1 && flag) {
			position = counter;
			flag = false;
		}
	}

	cout << "The floor Santa needs to deliver presents to is floor: " << floor << endl;
	cout << "Position that takes santa to the basement (floor -1): " << position << endl;

	directions.close();

	return 0;
}
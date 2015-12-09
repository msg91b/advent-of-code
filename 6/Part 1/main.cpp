#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void parseCoordinate(istringstream& ss, int& xStart, int& yStart, int& xEnd, int& yEnd) {
	string temp;

	getline(ss, temp, ',');
	istringstream s1(temp);
	xStart = stoi(temp);

	getline(ss, temp, ' ');
	yStart = stoi(temp);

	getline(ss, temp, ' '); // get rid of "through"

	getline(ss, temp, ',');
	xEnd = stoi(temp);

	getline(ss, temp);
	yEnd = stoi(temp);
}

void initialparse(string& parse, istringstream& ss, int& xStart, int& yStart, int &xEnd, int& yEnd) {
	string p1;

	if (parse == "toggle")
		parseCoordinate(ss, xStart, yStart, xEnd, yEnd);

	else {
		getline(ss, p1, ' ');
		parse = parse + " " + p1;
		parseCoordinate(ss, xStart, yStart, xEnd, yEnd);
	}
}
void printNumLit(int grid[][1000]) {
	int num(0);

	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			if (grid[i][j] == 1)
				num++;

	cout << "Number of lights lit: " << num << endl;
}

void lightStatus(string& parse, int grid[][1000], int& xStart, int& yStart, int& xEnd, int& yEnd) {
	for (int i = xStart; i <= xEnd; i++)
		for (int j = yStart; j <= yEnd; j++)
			if (parse == "toggle")
				if (grid[i][j] == 1)
					grid[i][j] = 0;
				else
					grid[i][j] = 1;

			else if (parse == "turn off")
				grid[i][j] = 0;

			else if (parse == "turn on")
				grid[i][j] = 1;
}

int main() {
	int grid[1000][1000] = { 0 };
	string s, parse;
	int xStart(0), yStart(0), xEnd(0), yEnd(0);

	ifstream input("input.txt");


	while (getline(input, s)) {
		istringstream ss(s);
		getline(ss, parse, ' ');

		initialparse(parse, ss, xStart, yStart, xEnd, yEnd);
		lightStatus(parse, grid, xStart, yStart, xEnd, yEnd);
	}

	printNumLit(grid);

	input.close();

	system("pause");

	return 0;
}
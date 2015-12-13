#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <regex>
#include <sstream>

int main()
{
	int d, i, j;
	std::string line;

	std::regex rule{ "(.+) to (.+) = (\\d+)" };
	std::smatch substr;

	std::vector<std::tuple<std::string, std::string, int>> cities;
	std::vector<std::string> routes;

	std::ifstream file("input.txt");

	while (std::getline(file, line))
	{
		// Step 1. Parse each according to our (lazy) regex rule
		std::regex_search(line, substr, rule);

		// Step 2. Create a complete list of distances between cities (vector of tuples):
		//         (substr[1])    | (substr[2])    | (int)(substr[3])
		//         (substr[2])    | (substr[1])    | (int)(substr[3])
		// Example:
		//         Tristram       | AlphaCentauri  | 34
		//         AlphaCentauri  | Tristram       | 34
		// And prepare the possible routes by pushing all the cities into a vector
		std::istringstream ss(substr[3]);
		int a;
		ss >> a;




		cities.push_back(make_tuple(substr[1], substr[2], a));
		cities.push_back(make_tuple(substr[2], substr[1], a));
		routes.push_back(substr[1]); routes.push_back(substr[2]);
	} file.close();

	// Step 3. Erase all the duplicates of the routes vector
	std::sort(std::begin(routes), std::end(routes));
	routes.erase(std::unique(std::begin(routes), std::end(routes)), std::end(routes));

	std::vector<int> distance;

	// Step 4. Generate all the possible routes. At the same time, compute the total
	//         distance for each route and push it into a vector.
	// [city 1][city 2][city 3][city 4][city 5][city 6][city 7][city 8]
	//     (dist.1)(dist.2)(dist.3)(dist.4)(dist.5)(dist.6)(dist.7)
	do
	{
		d = 0;
		for (i = 0; i < routes.size() - 1; ++i)
			for (j = 0; j < cities.size(); ++j)
				if (routes[i] == std::get<0>(cities[j]) && routes[i + 1] == std::get<1>(cities[j]))
					d += std::get<2>(cities[j]);
		distance.push_back(d);
	} while (std::next_permutation(std::begin(routes), std::end(routes)));

	// Step 5. Sort the distance vector to obtain the two solutions
	std::sort(std::begin(distance), std::end(distance));

	std::cout << "Part One: " << distance[0] << std::endl;
	std::cout << "Part Two: " << distance[distance.size() - 1] << std::endl;
	return 0;
}
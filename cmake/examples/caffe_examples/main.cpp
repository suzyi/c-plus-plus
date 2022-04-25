#include <fstream>
#include <string>
#include <vector>
#include <iostream> // cout
#include <cstdlib> // system("pause")

int main(int argc, char** argv) {
	std::ifstream infile(argv[1]);
	std::vector<std::pair<std::string, int> > lines;
	std::string line;
	size_t pos;
	int label;
	while (std::getline(infile, line)) {
	pos = line.find_last_of(' ');
	label = atoi(line.substr(pos + 1).c_str());
	lines.push_back(std::make_pair(line.substr(0, pos), label));
	}

	for (int line_id = 0; line_id < lines.size(); ++line_id) {
		std::string fn = lines[line_id].first;
		size_t p = fn.rfind('.');
		std::string enc = fn.substr(p);
		std::cout << fn << ", " << enc << ", " << lines[line_id].second << std::endl;
	}
	system("pause");
	return 0;
}
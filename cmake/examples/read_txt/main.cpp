#include <iostream> // cout, endl;
#include <string> //stof
#include <fstream>


int main(int argc, char** argv) {
    std::ifstream path_to_file("matrix.txt");
	std::string line;
	while (std::getline(path_to_file, line)) {
        size_t pos_cur = 0;
        size_t pos_next = line.find(",", pos_cur);
        while (pos_next!=std::string::npos) {
            std::cout << std::stof(line.substr(pos_cur, pos_next-pos_cur)) << "\t";
            pos_cur = pos_next+1;
            pos_next = line.find(",", pos_cur);
        }
        std::cout << std::endl;
	}

    return 0;
}
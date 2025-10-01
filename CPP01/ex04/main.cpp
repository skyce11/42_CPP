#include <iostream>
#include <fstream>
#include <string>

std::string	replaceAll(const std::string& line, const std::string& s1, const std::string& s2) {
	std::string result;
	size_t pos = 0;
	size_t prev = 0;
	while ((pos = line.find(s1, prev)) != std::string::npos) {
		result += line.substr(prev, pos - prev);
		result += s2;
		prev = pos + s1.length();
	}
	result += line.substr(prev);
	return result;
}

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " filename s1 s2" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty()) {
		std::cerr << "Error: s1 cannot be empty." << std::endl;
		return 1;
	}

	std::ifstream infile(filename.c_str());
	if (!infile) {
		std::cerr << "Error: Cannot open input file." << std::endl;
		return 1;
	}
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile) {
		std::cerr << "Error: Cannot open output file." << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(infile, line)) {
		outfile << replaceAll(line, s1, s2);
		if (!infile.eof())
			outfile << std::endl;
	}
	infile.close();
	outfile.close();
	return 0;
}
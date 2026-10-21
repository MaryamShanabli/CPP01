#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	if (argv[2][0] == '\0')
	{
		std::cerr << "Error: s1 must not be empty" << std::endl;
		return (1);
	}
	std::ifstream	input(argv[1]);

	if (!input)
	{
		std::cerr << "Error: could not open input file" << std::endl;
		return (1);
	}
	std::ostringstream	buffer;

	buffer << input.rdbuf();
	if (input.bad())
	{
		std::cerr << "Error: could not read input file" << std::endl;
		return (1);
	}
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	std::string	content = buffer.str();
	std::string	replaced;
	std::string::size_type	position = 0;
	std::string::size_type	found = content.find(s1, position);
	while (found != std::string::npos)
	{
		replaced += content.substr(position, found - position);
		replaced += s2;
		position = found + s1.length();
		found = content.find(s1, position);
	}
	replaced += content.substr(position);
	std::ofstream	output((filename + ".replace").c_str());
	if (!output)
	{
		std::cerr << "Error: could not create output file" << std::endl;
		return (1);
	}
	output << replaced;
	if (!output)
	{
		std::cerr << "Error: could not write output file" << std::endl;
		return (1);
	}
	return 0;
}

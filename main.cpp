#include "Searcher.h"
int main()
{
	std::cout << "Enter the file name: ";
	std::string filename;
	std::cin >> filename;

	Searcher* sr = new Searcher;
	sr->searchFile(std::string("/"), filename);
}

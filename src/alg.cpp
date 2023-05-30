// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> TREE;
  std::ifstream file(filename);
	if (!file.is_open())
		throw std::string("The file don't open!!!");
	std::string line, w;
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    while (ss >> w) {
      for (char& c : w) {
        c = std::tolower(c); // понижение в регистре
        if (!std::isalpha(c)) { // проверка на алфавит
          w = w.substr(0, w.size() - 1);
				}
			}
			TREE.addNode(w);
		}
	}
	file.close();
	return TREE;
}

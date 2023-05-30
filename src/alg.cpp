// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> TREE;
    std::ifstream file(filename);
    std::string w;
    while (!file.eof()) {
        int ch = file.get();
        if (ch >= 65 && ch <= 90) {
            ch += 32;
            w += ch;
        }
        else if (ch >= 97 && ch <= 122) {
            w += ch;
        }
        else {
            TREE.addNode(w);
            w = "";
        }
    }
    file.close();
    return TREE;
}

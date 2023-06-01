// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>

template <typename Type>
class BST {
 public:
    struct Node {
        std::string word;
        int count;
        Node* left;
        Node* right;
    };
    BST() {
        root = nullptr;
    }
    ~BST() {
        destroyTree(root);
    }
    void addNode(std::string word) {
        addNode(root, word);
    }
    int search(std::string word) {
        return search(root, word);
    }
    int depth() {
        return depppth(root) - 1;
    }
    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    } private:
    Node* root;
    int search(Node* node, std::string word) {
        if (node == nullptr) {
            return 0;
        } else if (word == node->word) {
            return node->count;
        } else if (word < node->word) {
            return search(node->left, word);
        } else {
            return search(node->right, word);
        }
    }
    void addNode(Node*& node, std::string word) {
        if (node == nullptr) {
            node = new Node;
            node->word = word;
            node->count = 1;
            node->left = nullptr;
            node->right = nullptr;
        } else {
            if (word == node->word) {
                node->count++;
            } else if (word < node->word) {
                addNode(node->left, word);
            } else {
                addNode(node->right, word);
            }
        }
    }
    int depppth(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(depppth(root->left), depppth(root->right));
    }
};



#endif  // INCLUDE_BST_H_

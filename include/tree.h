// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

int fact(int n);

class PMTree {
 public:
    struct Node {
        char data;
        std::vector<Node*> children;
    };

 private:
    Node* root;
    void addNodes(Node* root, std::vector<char>& vec) {
        if (vec.empty())
            return;
        for (int i = 0; i < vec.size(); ++i) {
            Node* new_data = new Node;
            new_data->data = vec[i];
            root->children.push_back(new_data);
            std::vector<char> vecRemains = vec;
            vecRemains.erase(vecRemains.begin() + i);
            addNodes(new_data, vecRemains);
        }
    }
    void deleteTree(Node* root) {
        if (root == nullptr)
            return;
        for (auto i : root->children)
            deleteTree(i);
        delete root;
    }

 public:
    PMTree(std::vector<char> vec) {
        root = new Node;
        root->data = '*';
        addNodes(root, vec);
    }
    ~PMTree() {
        deleteTree(root);
    }
    Node* getRootNode() {
        return root;
    }
    void createBufferPerms(Node* root, std::vector<char>& buffer, std::vector<std::vector<char>>& result) {
        if (root == nullptr)
            return;
        if (root->children.empty()) {
            result.push_back(buffer);
            return;
        }
        for (auto i : root->children) {
            buffer.push_back(i->data);
            createBufferPerms(i, buffer, result);
            buffer.pop_back();
        }
    }
};

std::vector<std::vector<char>> getAllPerms(PMTree& tree);
std::vector<char> getPerm1(PMTree& tree, int num);
std::vector<char> getPerm2(PMTree& tree, int num);

#endif  // INCLUDE_TREE_H_


// Copyright 2022 NNTU-CS
#include  <iostream>
#include <vector>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

int fact(int n) {
    int res = 1;
    for (int i = 1; i <= n; ++i)
        res *= i;
    return res;
}

std::vector<std::vector<char>> getAllPerms(PMTree& tree) {
    std::vector<char> buffer;
    std::vector<std::vector<char>> result;
    tree.createBufferPerms(tree.getRootNode(), buffer, result);
    return result;
}

std::vector<char> getPerm1(PMTree& tree, int num) {
    std::vector<std::vector<char>> perms = getAllPerms(tree);
    if (num <= 0 || num > perms.size())
        return {};
    return perms[num-1];
}

std::vector<char> getPerm2(PMTree& tree, int num) {
    PMTree::Node* root = tree.getRootNode();
    int size = root->children.size();
    if (num <= 0 || num > fact(size))
        return {};
    std::vector<char> perms;
    num -= 1;
    PMTree::Node* cur = root;
    for (int i = 1; i <= size; ++i) {
        int count = fact(size - i);
        cur = cur->children[num / count];
        num %= count;
        perms.push_back(cur->data);
    }
    return perms;
}

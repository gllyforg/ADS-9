// Copyright 2022 NNTU-CS
#include "tree.h"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>

void permsTime(int n) {
    std::vector<char> vector;
    unsigned int seed = static_cast<unsigned int>(time(NULL));
    for (int i = 1; i <= n; ++i) {
        std::cout << i << " elements: \n";

        vector.push_back(static_cast<char>('0' + (i % 10)));
        int rand_num = (rand_r(&seed) % fact(i)) + 1;
        PMTree tree(vector);

        auto start1 = std::chrono::high_resolution_clock::now();
        getPerm1(tree, rand_num);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration<double>(end1 - start1);
        std::cout << "Time (getPerm1): " 
            << duration1.count() * 1000 << " ms" 
            << std::endl;

        auto start2 = std::chrono::high_resolution_clock::now();
        getPerm2(tree, rand_num);
        auto end2 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration<double>(end2 - start2);
        std::cout << "Time (getPerm2): " 
            << duration2.count() * 1000 << " ms" 
            << std::endl;

        auto start3 = std::chrono::high_resolution_clock::now();
        getAllPerms(tree);
        auto end3 = std::chrono::high_resolution_clock::now();
        auto duration3 = std::chrono::duration<double>(end3 - start3);
        std::cout << "Time (getAllPerms): " 
            << duration3.count() * 1000 << " ms" 
            << std::endl;
    }
}

void printExample(int num, std::vector<char> vec) {
    if (vec.empty()) {
        std::cout << "Empty" << std::endl;
        return;
    }
    for (auto i : vec)
        std::cout << i;
    std::cout << std::endl;
}

int main() {
  return 0;
    PMTree tree(std::vector<char>({'1', '2', '3', '4'}));//Examples
    std::vector<char> vec;
    std::cout << "Permutations examples:" << std::endl;
    vec = getPerm1(tree, 3);
    std::cout << "Number 3: " << std::endl;
    printExample(3, vec);

    vec = getPerm2(tree, 20);
    std::cout << "Number 20: " << std::endl;
    printExample(20, vec);

    vec = getPerm2(tree, 26);
    std::cout << "Number 26 (wrong number): " << std::endl;
    printExample(26, vec);

    std::vector<std::vector<char>> perms = getAllPerms(tree);
    std::cout << "All permutations: " << std::endl;
    for (auto i : perms) {
        for (auto j : i)
            std::cout << j;
        std::cout << " ";
    }
    std::cout << std::endl << std::endl << "Experiment:" << std::endl;
    //Experiment
    permsTime(10);

    return 0;
}

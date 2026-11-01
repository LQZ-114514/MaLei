#include<iostream>
#include"BinaryTree.h"

int main()
{
    MaLei::BinaryTree tree;
    
    std::cout << tree.size() <<" "<< tree.height() << std::endl;

    int values[] = {10, 5, 15, 2, 7, 12, 20, 1, 6};
    for (int v : values) 
    {
        tree.insert(v);
        std::cout << "size:" << tree.size() << " height:" << tree.height() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "inorder:";
    tree.inorder();

    std::cout << "preorder:";
    tree.preorder();

    std::cout << "postorder:";
    tree.postorder();

    std::cout << "levelorder:" << std::endl;
    tree.levelorder();

    std::cout << "leafCount:" << tree.leafCount() << std::endl;

    std::cout << "contains:4: " << tree.contains(4) << std::endl;
    std::cout << "contains:2: " << tree.contains(2) << std::endl;

    std::cout << "count:2: " << tree.count(2) << std::endl;
    tree.insert(2);
    tree.insert(2);
    std::cout << "count:2: " << tree.count(2) << std::endl;
    std::cout << "Max: " << tree.maxValue() << std::endl;
    std::cout << "level of 10: " << tree.levelof(10) << std::endl;
    std::cout << "level of 7: " << tree.levelof(7) << std::endl;
    std::cout << "degreeOneCount:" << tree.degreeOneCount() << std::endl; 
    std::cout << "degreeTwoCount:" << tree.degreeTwoCount() << std::endl;
    std::cout << "Is Full Tree? " << (tree.isFull() ? "Yes" : "No") << std::endl;
    std::cout << "Is Complete Tree? " << (tree.isComplete() ? "Yes" : "No") << std::endl;
    tree.printPaths();

    std::cout << "Max Path Sum: " << tree.maxPathSum() << std::endl;
    return 0;
}
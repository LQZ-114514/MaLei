#pragma once
#include<vector>
namespace MaLei
{

    class BinaryTree
    {
        public:
        BinaryTree();
        ~BinaryTree();

        bool empty() const;
        void clear();
        int size() const;
        int height() const;

        void preorder() const;
        void inorder() const;
        void postorder() const;
        void levelorder() const;

        void insert(int value);

        int leafCount() const;
        bool contains(int value) const;
        int count(int value) const;
        int maxValue() const;
        int levelof(int value) const;
        int degreeOneCount() const;
        int degreeTwoCount() const;

        bool isFull() const;
        bool isComplete() const;
        bool isBalanced() const;
        bool sameTree(const BinaryTree& other) const;
        bool isSymmetric() const;

        void mirror();
        int diameter() const;
        void printPaths() const;
        int lowestCommonAncestor(int a, int b) const;
        int maxPathSum() const;

        private:
        struct TreeNode
        {
            int data;
            TreeNode* left;
            TreeNode* right;
            TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
        };

        TreeNode* root_;      
        int size_; 

        void destroy(TreeNode* node);
        int getHeightHelper(TreeNode* node) const;

        void preorderHelper(TreeNode* node) const;
        void inorderHelper(TreeNode* node) const;
        void postorderHelper(TreeNode* node) const;

        TreeNode* insertHelper(TreeNode* ,int);

        int leafCountHelper(TreeNode* node) const;
        bool containsHelper(TreeNode* node, int value) const;
        int countHelper(TreeNode* node, int value) const;
        int maxValueHelper(TreeNode* node) const;
        int degreeOneCountHelper(TreeNode* node) const;
        int degreeTwoCountHelper(TreeNode* node) const;

        bool isFullHelper(TreeNode* node) const;
        int checkBalanceHelper(TreeNode* node) const; 
        bool isSameHelper(TreeNode* a, TreeNode* b) const; 
        bool isSymmetricHelper(TreeNode* a, TreeNode* b) const;

        void mirrorHelper(TreeNode* node);
        int diameterHelper(TreeNode* node, int& maxDiameter) const;
        void printPathsHelper(TreeNode* node, std::vector<int>& path) const;
        int lcaHelper(TreeNode* node, int a, int b) const;
        int maxPathSumHelper(TreeNode* node, int& maxSum) const;
    };
}
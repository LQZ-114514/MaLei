#include "BinaryTree.h"
#include<iostream>
#include<queue>


namespace MaLei
{


    BinaryTree::BinaryTree() 
    {
        root_ = nullptr;
        size_ = 0;
    }

    void BinaryTree::destroy(TreeNode* node)
    {
        if(node == nullptr) 
        return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    void BinaryTree::clear()
    {
        destroy(root_);
        root_ = nullptr;
        size_ = 0;
    }

    BinaryTree::~BinaryTree() 
    {
        clear();
    }

    bool BinaryTree::empty() const
    {
        if(root_ == nullptr)
        return 1;
        else return 0;
    }

    int BinaryTree::size() const
    {
        return size_;
    }

    int BinaryTree::height() const
    {
        return getHeightHelper(root_);
    }

    int BinaryTree::getHeightHelper(TreeNode* node) const
    {
        if(node == nullptr)
            return 0;
        int leftH = getHeightHelper(node->left);
        int rightH = getHeightHelper(node->right);
        return ((leftH > rightH ? leftH : rightH) + 1);
    }

    void BinaryTree::preorder() const
    {
        preorderHelper(root_);
        std::cout<<std::endl;
    }
    void BinaryTree::preorderHelper(TreeNode* node) const
    {
        if (node == nullptr) 
        return;
        std::cout<<node->data<<" ";
        preorderHelper(node->left);
        preorderHelper(node->right);

    }

    void BinaryTree::inorder() const
    {
        inorderHelper(root_);
        std::cout<<std::endl;
    }
    void BinaryTree::inorderHelper(TreeNode* node) const
    {
        if (node == nullptr) 
        return;
        inorderHelper(node->left);
        std::cout<<node->data<<" ";
        inorderHelper(node->right);

    }
    
    void BinaryTree::postorder() const
    {
        postorderHelper(root_);
        std::cout<<std::endl;
    }
    void BinaryTree::postorderHelper(TreeNode* node) const
    {
        if (node == nullptr) 
        return;
        postorderHelper(node->left);     
        postorderHelper(node->right);
        std::cout<<node->data<<" ";
    }

    void BinaryTree::levelorder() const
    {
        if(root_ == nullptr)
        return;
        
        std::queue<TreeNode*> q;
        q.push(root_);
        
        while(!q.empty())
        {
            size_t levelSize = q.size();
            for(int i = 0;i<levelSize;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                std::cout << temp->data;
                if(i!=levelSize-1)
                std::cout << " ";
                if(temp->left != nullptr)
                q.push(temp->left);
                if(temp->right != nullptr)
                q.push(temp->right);
            }
            std::cout << std::endl;
        }
    }

    void BinaryTree::insert(int value)
    {
        root_ = insertHelper(root_,value);
    }
    BinaryTree::TreeNode* BinaryTree::insertHelper(TreeNode* node,int value)
    {
        if(node == nullptr)
        {
            size_++;
            return new TreeNode(value);
        }
        if(value < node->data)
        {
            node->left = insertHelper(node ->left,value);
        }
        else if(value > node->data)
        {
            node->right = insertHelper(node->right, value);
        }
        return node;
    }

    int BinaryTree::leafCount() const
    {
        return leafCountHelper(root_);
    }
    int BinaryTree::leafCountHelper(TreeNode* node) const
    {
        if(node == nullptr)
            return 0;
        if(node->left == nullptr && node->right == nullptr)
            return 1;
        else 
            return leafCountHelper(node->left)+leafCountHelper(node->right);
    }

    bool BinaryTree::contains(int value) const
    {
        return containsHelper(root_,value);
    }
    bool BinaryTree::containsHelper(TreeNode* node, int value) const
    {
        if(node == nullptr)
            return false;
        if(node->data == value)
            return true;
        return(containsHelper(node->left,value)||containsHelper(node->right,value));
    }

    int BinaryTree::count(int value) const
    {
        return countHelper(root_, value);
    }
    int BinaryTree::countHelper(TreeNode* node, int value) const
    {
        if(node == nullptr)
            return 0;
        int currentCount = 0;
        if(node->data == value)
            currentCount = 1;
        return currentCount + countHelper(node->left, value)+countHelper(node->right, value);
    }
    
    int BinaryTree::maxValue() const
    {
        return maxValueHelper(root_);
    }
    int BinaryTree::maxValueHelper(TreeNode* node) const
    {
        if(node == nullptr)
        return 0;
        else
        {
            int a = (maxValueHelper(node->left) > maxValueHelper(node->right) ? maxValueHelper(node->left) : maxValueHelper(node->right));
            return (a > node->data ? a : node->data);
        }
    }

    int BinaryTree::levelof(int value) const
    {
        if(root_ == nullptr)
        return -1;
        
        std::queue<TreeNode*> q;
        q.push(root_);
        int level = 0;
        while(!q.empty())
        {
            size_t levelSize = q.size();
            for(int i = 0;i<levelSize;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->data == value)
                return level;
                if(temp->left != nullptr)
                q.push(temp->left);
                if(temp->right != nullptr)
                q.push(temp->right);
                
            }level++;
        }
        return -1;
    }

    int BinaryTree::degreeOneCount() const
    {
        return degreeOneCountHelper(root_);
    }
    int BinaryTree::degreeOneCountHelper(TreeNode* node) const
    {
        if(node == nullptr)
            return 0;
        int isDegreeOne = ((node->left == nullptr && node->right != nullptr) || (node->left != nullptr && node->right == nullptr)) ? 1 : 0;
        return isDegreeOne + degreeOneCountHelper(node->left) + degreeOneCountHelper(node->right);
    }

    int BinaryTree::degreeTwoCount() const
    {
        return degreeTwoCountHelper(root_);
    }
    int BinaryTree::degreeTwoCountHelper(TreeNode* node) const
    {
        if(node == nullptr)
            return 0;
        int isDegreeTwo = (node->left != nullptr && node->right != nullptr) ? 1 : 0;
        return isDegreeTwo + degreeTwoCountHelper(node->left) + degreeTwoCountHelper(node->right);
    }

    bool BinaryTree::isFull() const
    {
        return isFullHelper(root_);
    }
    bool BinaryTree::isFullHelper(TreeNode* node) const
    {
        if(node == nullptr)
            return true;
        if(node->left == nullptr && node->right == nullptr)
            return true;
        if(node->left != nullptr && node->right != nullptr)
            return (isFullHelper(node->left) && isFullHelper(node->right));
        return false;
    }

    bool BinaryTree::isComplete() const
    {
        if(root_ == nullptr)
            return true;
        std::queue<TreeNode*> q;
        q.push(root_);
        bool see = 0;
        while(!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            if(cur == nullptr)
            see = 1;
            else
            {
                if(see)
                    return false;
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return true;
    }

    bool BinaryTree::isBalanced() const
    {
        return (checkBalanceHelper(root_) != -1);
    }
    int BinaryTree::checkBalanceHelper(TreeNode* node) const
    {
        if (node == nullptr) 
            return 0;
        int leftHeight = checkBalanceHelper(node->left);
        if (leftHeight == -1) 
            return -1; 
        int rightHeight = checkBalanceHelper(node->right);
        if (rightHeight == -1) 

            

        if (leftHeight - rightHeight > 1 || rightHeight - leftHeight > 1) 
        {
            return -1; 
        }
        
        return ((leftHeight > rightHeight ? leftHeight : rightHeight) + 1);
    }

    bool BinaryTree::sameTree(const BinaryTree& other) const
    {
        return isSameHelper(root_,other.root_);
    }
    bool BinaryTree::isSameHelper(TreeNode* a,TreeNode* b) const
    {
        if(a == nullptr && b == nullptr)
            return true;
        if(a == nullptr || b == nullptr)
            return false;
        if(a->data != b->data)
            return false;
        return (isSameHelper(a->left,b->left)&&isSameHelper(a->right,b->right));
    }

    bool BinaryTree::isSymmetric() const
    {
        if(root_ == nullptr)
            return true;
        else return isSymmetricHelper(root_->left, root_->right);
    }
    bool BinaryTree::isSymmetricHelper(TreeNode* a, TreeNode* b) const
    {
        if(a == nullptr && b == nullptr)
            return true;
        if(a == nullptr || b == nullptr)
            return false;
        if(a->data != b->data)
            return false; 
        return (isSymmetricHelper(a->left,b->right)&&isSymmetricHelper(a->right,b->left));
    }

    void BinaryTree::mirror()
    {
        mirrorHelper(root_);
    }
    void BinaryTree::mirrorHelper(TreeNode* node)
    {
        if(node == nullptr)
            return;
        TreeNode* cur = node->left;
        node->left = node->right;
        node->right = cur;
        mirrorHelper(node->left);
        mirrorHelper(node->right);
    }

    int BinaryTree::diameter() const
    {
        int result = 0;
        diameterHelper(root_, result);
        return result;
    }
    int BinaryTree::diameterHelper(TreeNode* node, int& maxDiameter) const
    {
        if(node == nullptr)
            return 0;
        int leftHeight = diameterHelper(node->left, maxDiameter);
        int rightHeight = diameterHelper(node->right, maxDiameter);
        int currentDiameter = leftHeight + rightHeight; 
        if (currentDiameter > maxDiameter) 
        {
            maxDiameter = currentDiameter; 
        }
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }

    void BinaryTree::printPaths() const
    {
        std::vector<int> path;
        printPathsHelper(root_, path);
    }
    void BinaryTree::printPathsHelper(TreeNode* node, std::vector<int>& path) const
    {
        if(node == nullptr)
        return;
        path.push_back(node->data);
        if (node->left == nullptr && node->right == nullptr) 
        {
            for (size_t i = 0; i < path.size(); i++) 
            {
                std::cout << path[i];
                if (i != path.size() - 1) 
                {
                    std::cout << "->";
                }
            }
            std::cout << std::endl;
        }
        else
        {
            printPathsHelper(node->left, path);
            printPathsHelper(node->right, path);
        }
        path.pop_back(); 
    }

    int BinaryTree::lowestCommonAncestor(int a, int b) const
    {
        return lcaHelper(root_, a, b);
    }
    int BinaryTree::lcaHelper(TreeNode* node, int a, int b) const
    {
        if(node == nullptr)
        return -1;
        if(node->data == a || node->data == b)
        return node -> data;
        int leftFound = lcaHelper(node->left, a, b);
        int rightFound = lcaHelper(node->right, a, b);

        if (leftFound != -1 && rightFound != -1) 
            return node->data;
        if (leftFound != -1) 
            return leftFound;
        else 
            return rightFound;   
    }

    int BinaryTree::maxPathSum() const
    {
        if (root_ == nullptr) 
            return 0;
        int maxSum = root_->data; 
        
        maxPathSumHelper(root_, maxSum);
        return maxSum;
    }

    int BinaryTree::maxPathSumHelper(TreeNode* node, int& maxSum) const
    {
        if(node == nullptr)
        return 0;
        int leftGain = maxPathSumHelper(node->left, maxSum);
        int rightGain = maxPathSumHelper(node->right, maxSum);
        
        if (leftGain < 0) 
            leftGain = 0;
        if (rightGain < 0) 
            rightGain = 0;

        int cur = leftGain + rightGain + node->data;
        if(cur > maxSum)
        {
            maxSum = cur;
        }
        int maxChildGain = (leftGain > rightGain ? leftGain : rightGain);
        return (node->data + maxChildGain);
    }
}

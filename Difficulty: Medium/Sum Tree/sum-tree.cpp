/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    void Sum(Node* root, int& sum){
        if(root == NULL) return;
        
        sum += root->data;
        Sum(root->left, sum);
        Sum(root->right, sum);
    }
    bool isSumTree(Node* root) {
        // Your code here
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        
        int sumleft = 0;
        Sum(root->left, sumleft);
        int sumright = 0;
        Sum(root->right, sumright);
        
        return (sumleft + sumright == root->data) && isSumTree(root->left) && isSumTree(root->right);
    }
};
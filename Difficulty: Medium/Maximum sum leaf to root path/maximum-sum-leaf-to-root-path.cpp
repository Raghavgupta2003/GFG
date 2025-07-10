// User function Template for C++

class Solution {
  public:
    int maxPath(Node* root){
        if(root == NULL) return INT_MIN;
        //basecase
        if(root->left ==  NULL && root->right == NULL) return root->data;
        
        int left = maxPath(root->left);
        int right = maxPath(root->right);
        
        return root->data + max(left, right);
    }
    int maxPathSum(Node* root) {
        // code here
        return maxPath(root);
    }
};
/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    bool check(Node* root){
        if(root == NULL) return true; //nulls' left+right = null
        //leave node
        if(root->left == NULL && root->right == NULL) return true;
        
        //sum property
        int l = 0;
        if(root->left) l = root->left->data;
        int r = 0;
        if(root->right) r = root->right->data;
        
        return (l+r == root->data) && check(root->left) && check(root->right);
    }
    int isSumProperty(Node *root) {
        // Add your code here
        return check(root);
    }
};
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    //function 1
    //first store all the left nodes by iterating only in left, except leaf node
    
    //function2
    //store all the leave nodes, except leaf nodes
    
    // function3
    //store all right node but in reverse session.
    
    void left(Node* root, vector<int>& ans){
        root = root->left;
        while(root){
            //not leave node
            if(!(root->left == NULL && root->right==NULL)){
                ans.push_back(root->data);
            }
            if (root->left) root = root->left;
            else root = root->right;
        }
    }
    
    void leaf(Node* root, vector<int>& ans){
        if(root == NULL) return;
        
        if(root->left == NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        
        leaf(root->left, ans);
        leaf(root->right, ans);
    }
    
    
     void right(Node* root, vector<int>& arr){
         root = root->right;
        while(root){
            //not leave node
            if(!(root->left == NULL && root->right==NULL)){
                arr.push_back(root->data);
            }
            if (root->right) root = root->right;
            else root = root->left;
        }
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        if(root == NULL) return {};
        
        vector<int> ans;
        if (!(root->left == NULL && root->right == NULL)) ans.push_back(root->data);
        
        left(root, ans);
        leaf(root, ans);
        vector<int> arr;
        right(root, arr);
        //reverse arr and push into ans
        reverse(arr.begin(), arr.end());
        
        for(int i=0; i<arr.size(); i++){
            ans.push_back(arr[i]);
        }
        
        
        
        return ans;
    }
};
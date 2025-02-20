//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after splitting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
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
    bool leaf(Node*root){
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        return false;
    }
    void addleft(Node* root, vector<int> &ans){
        Node* cur = root->left;
        while(cur){
            if(!leaf(cur)) ans.push_back(cur->data);
            
            if(cur->left) cur = cur->left; // if left exits
            else cur = cur->right; //if left not exits
        }
        
    }
    void leafnodes(Node* root, vector<int>& ans){
        if(root == NULL) return;
        if(leaf(root)) ans.push_back(root->data);
        leafnodes(root->left,ans);
        leafnodes(root->right,ans);
    }
    void addright(Node* root, vector<int> &ans){
        Node* cur = root->right;
        vector<int> v;
        while(cur){
            if(!leaf(cur)) v.push_back(cur->data);
            
            if(cur->right) cur = cur->right; // if right exits
            else cur = cur->left; //if right not exits
        }
        
        for(int i=v.size()-1; i>=0; i--){
            ans.push_back(v[i]);
        }
        
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if (root == NULL) return ans;
        ans.push_back(root->data);
        addleft(root, ans);
        if(!leaf(root)) leafnodes(root, ans);
        addright(root,ans);
        
        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundaryTraversal(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
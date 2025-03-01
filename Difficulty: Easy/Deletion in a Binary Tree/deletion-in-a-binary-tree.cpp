//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Define the structure for a tree node
struct Node {
    int data;    // Value of the node
    Node* left;  // Pointer to the left child
    Node* right; // Pointer to the right child
};

// Function to create a new node with the given value
Node* createNewNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build the binary tree from a string input
Node* buildTree(const string& str) {
    // Corner Case: if the input string is empty or starts with 'N', return NULL
    if (str.empty() || str[0] == 'N')
        return NULL;

    // Create a vector of strings from the input by splitting it on spaces
    vector<string> nodeValues;
    istringstream iss(str);
    for (string value; iss >> value;) {
        nodeValues.push_back(value);
    }

    // Create the root node of the tree
    Node* root = createNewNode(stoi(nodeValues[0]));

    // Use a queue to build the tree level by level
    queue<Node*> q;
    q.push(root);

    int i = 1; // Index for traversing the node values
    while (!q.empty() && i < nodeValues.size()) {
        Node* currentNode = q.front();
        q.pop();

        // Handle the left child
        string currentValue = nodeValues[i];
        if (currentValue != "N") {
            currentNode->left = createNewNode(stoi(currentValue));
            q.push(currentNode->left);
        }

        // Handle the right child
        i++;
        if (i >= nodeValues.size())
            break;
        currentValue = nodeValues[i];
        if (currentValue != "N") {
            currentNode->right = createNewNode(stoi(currentValue));
            q.push(currentNode->right);
        }
        i++;
    }

    return root;
}

// In-order traversal function to print the tree nodes
void inorderTraversal(Node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}


// } Driver Code Ends

/*
Structre of the node of the tree is as
struct Node
{
    int data;
    Node* left, *right;
};
*/
class Solution {
  public:
    void  DeletelastNode(Node*root){
        queue<Node*> q;
        q.push(root);
        
        while(q.size()>0){
            int size = q.size();
            for(int i=0; i<size; i++){
                Node* cur = q.front();
                q.pop();
                
                if(cur->left){
                    q.push(cur->left);
                    if(cur->left->data == -1){
                        cur->left = NULL;
                        return;
                    }
                }
                if(cur->right){
                    q.push(cur->right);
                    if(cur->right->data == -1){
                        cur->right = NULL;
                        return;
                    }
                }
                
            }
        }
    }
    Node* deleteNode(Node* root, int key) {
        // code here
        Node* keynode = NULL;
        Node* lastnode = NULL;
        
        queue<Node*> q;
        q.push(root);
        if(root->data == key) keynode = root;
        
        while(q.size()>0){
            int size = q.size();
            for(int i=0; i<size; i++){
                Node* cur = q.front();
                q.pop();
                
                if(cur->left){
                    q.push(cur->left);
                    if(cur->left->data == key) keynode = cur->left;
                }
                if(cur->right){
                    q.push(cur->right);
                    if(cur->right->data == key) keynode = cur->right;
                }
                
                lastnode = cur;
            }
        }
        
        if(keynode == NULL) return root;
        
        keynode->data = lastnode->data;
        lastnode->data = -1;
        
        DeletelastNode(root);
        
        return root;
    }
};


//{ Driver Code Starts.

// Main function
int main() {
    int t;
    scanf("%d", &t); // Input the number of test cases

    while (t--) {
        int key;

        string input;
        getline(cin >> ws, input); // Read the input tree as a string
        scanf("%d", &key);         // Input the key to be deleted

        // Build the tree from the input string
        Node* root = buildTree(input);

        // Call the solution to delete the node with the given key
        Solution sol;
        root = sol.deleteNode(root, key);

        // Perform in-order traversal to display the tree
        inorderTraversal(root);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends
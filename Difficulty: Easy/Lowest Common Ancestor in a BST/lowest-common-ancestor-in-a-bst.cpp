//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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
    bool path(vector<Node*> &v, Node* root, Node* n,bool &left, bool &right){
        if(root == NULL) return false;
        
        if(root->data == n->data){
            v.push_back(root);
            return true;
        }
        else if(n->data < root->data){
            left =  path(v, root->left, n, left,right);
        }
        else{
            right =  path(v, root->right, n, left,right);
        }
        
        if(left || right){
            v.push_back(root);
            return true;
        }
        else return false;
    }
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        vector<Node*> v1;
        bool left = false;
        bool right = false;
        path(v1, root, n1, left,right);
        vector<Node*> v2;
        path(v2, root, n2, left, right);
        
        int i = v1.size()-1;
        int j = v2.size()-1;
        
        while(i>=0 && j>=0){
            if(v1[i] == v2[j]){
                i--;
                j--;
            }
            else{
                return v1[i+1];
            }
        }
        if(i<v1.size()) return v1[i+1];
        if(j<v2.size()) return v2[j+1];
    }
};


//{ Driver Code Starts.

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

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
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node* searchOnTree(Node* root, int num) {
    if (root == nullptr || root->data == num)
        return root;
    if (num < root->data)
        return searchOnTree(root->left, num);
    else
        return searchOnTree(root->right, num);
}

int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        int l, h;
        getline(cin, s);
        scanf("%d ", &l);
        scanf("%d ", &h);
        Node* root = buildTree(s);
        Node* n1 = searchOnTree(root, l);
        Node* n2 = searchOnTree(root, h);
        Solution sol;
        int ans = sol.LCA(root, n1, n2)->data;
        cout << ans << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
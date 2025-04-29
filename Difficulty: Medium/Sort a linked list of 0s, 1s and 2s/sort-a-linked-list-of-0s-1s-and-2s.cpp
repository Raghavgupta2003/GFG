//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        if(head == NULL || head->next==NULL) return head;
        Node* zero = new Node(10);
        Node* tempZero = zero;
        Node* one = new Node(10);
        Node* tempone = one;
        Node* two = new Node(10);
        Node* temptwo = two;
        
        while(head!=NULL){
            if(head->data == 0){
                tempZero->next = head;
                head = head->next;
                tempZero = tempZero->next; 
            } 
            else if(head->data == 1){
                tempone->next = head;
                head = head->next;
                tempone = tempone->next; 
            } 
            else if(head->data == 2){
                temptwo->next = head;
                head = head->next;
                temptwo = temptwo->next; 
            } 
        }
        temptwo->next = NULL;
        
        tempZero->next = one->next ? one->next : two->next;
        tempone->next = two->next;
        
        return zero->next;
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
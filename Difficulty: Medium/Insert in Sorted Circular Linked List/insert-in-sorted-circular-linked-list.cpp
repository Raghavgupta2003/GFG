/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        if(head == NULL) return new Node(data);
        if(data < head->data){
            Node* newnode = new Node(data);
            newnode->next = head;
            while(head->next != newnode->next){
                head = head->next;
            }
            head->next = newnode;
            return newnode;
        }
        Node* tail = NULL;
        Node* temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        tail = temp;
        
        if(data > tail->data){
            tail->next = new Node(data);
            tail->next->next = head;
            return head;
        }
        
        
        Node* tempHead = head;
        while(tempHead->next != head){
            if(data >= tempHead->data && data<=tempHead->next->data){
                Node* temp = tempHead->next;
                Node* newnode = new Node(data);
                tempHead->next = newnode;
                newnode->next = temp;
                break;
            }
            tempHead = tempHead->next;
        }
        return head;
    }
    
};
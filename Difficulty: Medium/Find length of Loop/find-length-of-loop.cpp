/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        if( head -> next == nullptr )
        {
            return 0;
        }
        
        Node* slow = head, *fast = head;
        
        while( fast and fast -> next )
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if( slow == fast )
            {
                int nodeCount = 1;
                Node* temp = slow;
                
                while( temp -> next != slow )
                {
                    nodeCount++;
                    temp = temp -> next;
                }
                
                return nodeCount;
            }
        }
        
        return 0;
    }
};
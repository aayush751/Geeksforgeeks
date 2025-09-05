
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        int zero = 0, one = 0, two = 0;
        
        Node* j = head;
        while( j )
        {
            if( j -> data == 0 )
            {
                zero++;
            }
            else if( j -> data == 1 )
            {
                one++;
            }
            else
            {
                two++;
            }
            j = j -> next;
        }
        
        Node* dummyNode = new Node( 0 );
        Node* i = dummyNode;
        
        while( zero > 0 )
        {
            Node* newNode = new Node( 0 );
            i -> next = newNode;
            zero--;
            i = i -> next;
        }
        
        while( one > 0 )
        {
            Node* oneNode = new Node( 1 );
            i -> next = oneNode;
            one--;
            i = i -> next;
        }
        
        while( two > 0 )
        {
            Node* twoNode = new Node( 2 );
            i -> next = twoNode;
            two--;
            i = i -> next;
        }
        
        return dummyNode -> next;
        
    }
};




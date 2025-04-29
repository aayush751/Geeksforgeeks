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
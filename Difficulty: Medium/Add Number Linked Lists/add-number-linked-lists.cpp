//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
  void reverseList( Node*& head )
  {
      Node* prev = nullptr;
      Node* curr = head;
      Node* next;
      
      while( curr )
      {
          next = curr -> next;
          curr -> next = prev;
          prev = curr;
          curr = next;
      }
      
      head = prev;
  }
  
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        // sbse phle dono list ko reverse krna hai taki add krne me easy ho
        reverseList( num1 );
        reverseList( num2 );
        
        Node* itr1 = num1;
        Node* itr2 = num2;
        Node* tail = nullptr;
        
        int carry = 0;
        
        while( itr1 and itr2 )
        {
            int nodeValue = itr1 -> data + itr2 -> data + carry;
            itr1 -> data = nodeValue % 10;
            carry = nodeValue / 10;
            tail = itr1;
            itr1 = itr1 -> next;
            itr2 = itr2 -> next;
        }
        
        if( itr1 == nullptr )
        {
            tail -> next = itr2;
        }
        
        while( itr1 )
        {
            int nodeValue = itr1 -> data + carry;
            itr1 -> data = nodeValue % 10;
            carry = nodeValue / 10;
            tail = itr1;
            itr1 = itr1 -> next;
        }
        
        while( itr2 )
        {
            int nodeValue = itr2 -> data + carry;
            itr2 -> data = nodeValue % 10;
            carry = nodeValue / 10;
            tail = itr2;
            itr2 = itr2 -> next;
        }
        
        if( carry )
        {
            Node* carryNode = new Node( carry );
            tail -> next = carryNode;
            tail = tail -> next;
        }
        
        reverseList( num1 );
        
        Node* zeroNode = num1;
        
        while( zeroNode -> data == 0 )
        {
            zeroNode = zeroNode -> next;
        }
        
        return zeroNode;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
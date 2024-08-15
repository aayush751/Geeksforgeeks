//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
    void reverseList( Node* &head )
    {
        if( head == nullptr)
        {
            return;
        }
        
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
    
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        if( !head ) return nullptr;
        
        reverseList( head );
        Node* i = head;
        int carry = 1;
        
        while( i )
        {
            int sum = i -> data + carry;
            carry = sum / 10;
            i -> data = sum % 10;
            
            if( i -> next == nullptr and carry!= 0 )
            {
                Node* newNode = new Node( carry );
                i -> next = newNode;
                carry = 0;
            }
            i = i -> next;
        }
        reverseList( head );
        
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


// } Driver Code Ends
/*
structure of the node of the list is as
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
    // Should return head of the modified linked list
    Node* sortedInsert(struct Node* head, int x) {
        // Code here
        Node* prev = nullptr;
        Node* curr = head;
        Node* newNode = new Node( x );
        
        
        if( x <= curr -> data )
        {
            newNode -> next = curr;
            head = newNode;
            
            return head;
        }
        
        while( curr )
        {
            if( x <= curr -> data )
            {
                newNode -> next = curr;
                prev -> next = newNode;
                return head;
            }
            else
            {
                prev = curr;
                curr = curr -> next;
            }
        }
        
        if( !curr )
        {
            Node* nullNode = nullptr;
            newNode -> next = nullNode;
            prev -> next = newNode;
        }
        
        return head;
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main() {

    int T, i, n, l;
    cin >> T;
    cin.ignore();

    while (T--) {
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
        Node *head = new Node(data);
        Node *tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after the integer input

        Solution ob;
        Node *result = ob.sortedInsert(head, k);
        print(result);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
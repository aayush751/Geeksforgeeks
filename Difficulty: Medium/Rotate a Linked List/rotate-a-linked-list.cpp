//{ Driver Code Starts
// Initial Template for C++
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
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // Your code here
        
        int listSize = 0;
        
        
        
        
        Node* itr = head;
        Node* originalHead = head;
        Node* newHead;
        Node* lastNode = nullptr;
        
        while( itr )
        {
            listSize++;
            itr = itr -> next;
        }
        
        k = k % listSize;
        if( k == 0 or !head -> next ) return head;
        
        if( listSize == k ) return head;
        
        
        
            int beforeCnt = 1;
            Node* i = head;
            
            while( i )
            {
                if( beforeCnt == k )
                {
                    break;
                }
                else
                {
                    beforeCnt++;
                    i = i -> next;
                }
            }
            
            newHead = i -> next;
            i -> next = lastNode;
            
            Node* j = newHead;
            while( j -> next )
            {
                j = j -> next;
            }
            
            j -> next = originalHead;
            
            return newHead;
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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
        cout << "~\n";
    }
    return 1;
}

// } Driver Code Ends
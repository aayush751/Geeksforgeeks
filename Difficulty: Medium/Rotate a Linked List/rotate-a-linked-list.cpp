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
    // Function to rotate a linked list.
    Node* rotate(Node* head, int k) {
        // Your code here
        if( head -> next == nullptr )
        {
            return head;
        }
        int beforeCnt = 1;
        int afterCnt = 0;
        Node* i = head;
        Node* j = head;
        Node* lastNode = nullptr;
        Node* kNode;
        Node* newNode = head;
        Node* temp = head;
        int cnt = 0;
        
        while( temp )
        {
            cnt++;
            temp = temp -> next;
        }
        
        if( cnt == k ) return head;
        
        while( i )
        {
            if( beforeCnt == k )
            {
                break;
            }
            else
            {
                i = i -> next;
                beforeCnt++;
            }
        }
        
        
        
        
        while( j )
        {
            if( afterCnt == k )
            {
                break;
            }
            else
            {
                j = j -> next;
                afterCnt++;
            }
        }
        
        kNode = j;
        
        // cout<< j -> data << endl;
        
        i -> next = lastNode;
        
        while( j -> next )
        {
            j = j -> next;
        }
        
        j -> next = newNode;
        
        return kNode;
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
    }
    return 1;
}

// } Driver Code Ends
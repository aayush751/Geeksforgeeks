//{ Driver Code Starts
#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        int k;
        if (temp->random == NULL)
            k = -1;
        else
            k = temp->random->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}

void append(Node **head_ref, Node **tail_ref, int new_data) {
    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        (*tail_ref)->next = new_node;
    }
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res) {
    Node *temp1 = head;
    Node *temp2 = res;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data != temp2->data)
            return false;
        if ((temp1->random == NULL && temp2->random != NULL) ||
            (temp1->random != NULL && temp2->random == NULL) ||
            (temp1->random != NULL && temp2->random != NULL &&
             temp1->random->data != temp2->random->data))
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}


// } Driver Code Ends
/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution {
  public:
    Node *copyList(Node *head) {
        // Write your code here
        
        if( !head or head -> next )
        {
            return nullptr;
        }
        
        Node* curr = head;
        
        while( curr )
        {
            Node* copy = new Node( curr -> data );
            copy -> next = curr -> next;
            curr -> next = copy;
            curr = curr -> next -> next;
        }
        
        curr = head;
        
        while( curr )
        {
            if( curr -> random != nullptr )
            {
                curr -> next -> random = curr -> random -> next;
            }
            curr = curr -> next -> next;
        }
        
        curr = head;
        Node* copyHead = nullptr;
        Node* copyTail = nullptr;
        
        while( curr )
        {
            if( copyHead == nullptr )
            {
                copyHead = curr -> next;
                copyTail = curr -> next;
            }
            else
            {
                copyTail -> next = curr -> next;
                copyTail = copyTail -> next;
            }
            
            curr -> next = curr -> next -> next;
            curr = curr -> next;
        }
        return copyHead; 
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Ignore the newline after T
    while (T--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Node *head = NULL, *tail = NULL;
        for (int i = 0; i < arr.size(); ++i) {
            append(&head, &tail, arr[i]);
        }

        getline(cin, input);
        stringstream ss2(input);
        vector<int> arr2;
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Node *temp = head;
        for (int i = 0; i < arr2.size(); i += 2) {
            int a = arr2[i];
            int b = arr2[i + 1];

            Node *tempA = head;
            Node *tempB = head;
            for (int j = 1; j < a; ++j) {
                tempA = tempA->next;
            }
            for (int j = 1; j < b; ++j) {
                tempB = tempB->next;
            }

            tempA->random = tempB;
        }

        Solution ob;
        Node *res = ob.copyList(head);

        if (validation(head, res)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}

// } Driver Code Ends
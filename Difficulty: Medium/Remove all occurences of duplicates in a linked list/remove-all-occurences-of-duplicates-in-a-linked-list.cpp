//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/



class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // code here
         if(!head || !head->next) return head;
        Node* pre= NULL;
        Node* curr=head;
        Node* nextnode;
    
        while(curr){
            nextnode=curr->next;
            bool flag=false;
            while(nextnode && curr->data==nextnode->data){
                flag=true;
                Node* del=nextnode;
                nextnode=nextnode->next;
                delete del;
            }
            if(flag){
                if(pre!=NULL){
                    pre->next=nextnode;
                }
                else{
                    head=nextnode;
                }
                delete curr;
            }
            else{
                pre=curr;
            }
            curr=nextnode;
        }
        return head;
    }
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <bits/stdc++.h>
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


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/

// } Driver Code Ends
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
class Solution{
public:
    int getNthFromLast(Node *head, int n)
    {
           // Your code here
        //   sbse phle linked list ka length find kregein.
        // aur agr linked list ka size km hoga n se then return -1
        
        
        
        int length = 0;
        
        
        Node* i = head;
        
        while( i )
        {
            length++;
            
            i = i -> next;
        }
        
        if( length < n )
        {
            return -1;
        }
        
        int cnt = 0;
        
        int ans = -1;
        
        Node* j = head;
        
        int idx = length - n + 1;
        
        while( j )
        {
            cnt++;
            
            if( cnt == idx )
            {
                ans = j -> data;
                break;
            }
            
            j = j -> next;
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
    cout<<obj.getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
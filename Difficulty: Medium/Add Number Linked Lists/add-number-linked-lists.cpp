//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
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

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
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

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        string s1, s2;
        
        Node* i = num1;
        Node* j = num2;
        
        while( i )
        {
            string ch = to_string( i -> data );
            s1 += ch;
            i = i -> next;
        }
        
        while( j )
        {
            string temp = to_string( j -> data) ;
            s2 += temp;
            j = j -> next;
        }
        
        int idx = 0;
        
        while( s1[idx] == '0' )
        {
            idx++;
        }
        
        s1 = s1.substr(idx);
        
        idx = 0;
        
        while( s2[idx] == '0' )
        {
            idx++;
        }
        
        s2 = s2.substr(idx);
        
        int n = s1.size(), m = s2.size();
        
        if( n == 0 and m == 0 )
        {
            Node* zero = new Node(0);
            return zero;
        }
        int itr_s1 = n - 1, itr_s2 = m - 1;
        
        int carry = 0;
        
        string finalAns;
        while( itr_s1 > -1 and itr_s2 > -1 )
        {
            finalAns.push_back( ((carry + s1[itr_s1] - '0' + s2[itr_s2] - '0') % 10 ) + '0' );
            carry = (carry + s1[itr_s1] - '0' + s2[itr_s2] - '0') / 10;
            itr_s1--;
            itr_s2--;
        }
        
        while( itr_s1 > -1 )
        {
            finalAns.push_back( (( carry + s1[itr_s1] - '0' ) % 10) + '0' );
            carry = ( carry + s1[itr_s1] - '0' ) / 10;
            itr_s1--;
        }
        
        while( itr_s2 > -1 )
        {
            finalAns.push_back( ((carry + s2[itr_s2] - '0') % 10 ) + '0' );
            carry = (carry + s2[itr_s2] - '0') / 10;
            itr_s2--;
        }
        
        if( carry )
        {
            finalAns.push_back( carry + 48 );
        }
        
        
        // cout<< finalAns;
        // return nullptr;
        
        reverse( begin(finalAns), end(finalAns) );
        
        Node* dummyNode = new Node(0);
        j = dummyNode;
        for(int i = 0; i < finalAns.size(); i++ )
        {
            int insert_value = finalAns[i] - 48;
            Node* temp = new Node( insert_value );
            j -> next = temp;
            j = j -> next;
        }
        
        return dummyNode ->next;

    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
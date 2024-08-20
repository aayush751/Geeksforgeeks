//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    
    
    void solve( Node* root, unordered_map< Node*, Node* > &mp )
    {
        // es function me ye kr rhe hain ki sare child k parent ko value bna rhe hain and child ko key bna rhe hain
        queue< Node* > q;
        q.push( root );
        
        while( !q.empty() )
        {
            int size =  q.size();
            
            for(int i = 0; i < size; i++ )
            {
                Node* curr = q.front();
                q.pop();
                
                if( curr -> left )
                {
                    mp[curr -> left] = curr;
                    q.push( curr -> left );
                }
                
                if( curr -> right )
                {
                    mp[curr -> right] = curr;
                    q.push( curr -> right );
                }
            }
        }
    }
    
    Node* findTarget( Node* root, int target )
    {
          if (!root) return nullptr;
    if (root->data == target) return root;
    Node* left = findTarget(root->left, target);
    if (left) return left;
    return findTarget(root->right, target);
    }
    
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        if (!root) return 0;

    std::unordered_map<Node*, Node*> parent_map;
    solve(root, parent_map);

    Node* targetNode = findTarget(root, target);
    if (!targetNode) return 0; // Target not found

    std::unordered_map<Node*, bool> visited;
    std::queue<Node*> q;
    q.push(targetNode);
    visited[targetNode] = true;
    int time = 0;

    while (!q.empty()) {
        int size = q.size();
        bool isBurning = false;

        for (int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();

            // Check left child
            if (current->left && !visited[current->left]) {
                isBurning = true;
                visited[current->left] = true;
                q.push(current->left);
            }

            // Check right child
            if (current->right && !visited[current->right]) {
                isBurning = true;
                visited[current->right] = true;
                q.push(current->right);
            }

            // Check parent
            if (parent_map[current] && !visited[parent_map[current]]) {
                isBurning = true;
                visited[parent_map[current]] = true;
                q.push(parent_map[current]);
            }
        }

        if (isBurning) time++;
    }

    return time;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends
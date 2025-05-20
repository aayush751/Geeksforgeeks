//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
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

/*
class Node {
  public:
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
    int minTime(Node* root, int target) {
        // code here
        queue<Node*> que;

        que.push(root);

        unordered_map<Node*, Node*> parent; // To store parent of each node
        parent[root] = nullptr;

        Node* tar = nullptr; // Pointer to store target node

        while (!que.empty()) {
            Node* curr = que.front();
            que.pop();

            // Locate the target node
            if (curr->data == target) {
                tar = curr;
            }

            // Map left child to parent
            if (curr->left) {
                que.push(curr->left);
                parent[curr->left] = curr;
            }

            // Map right child to parent
            if (curr->right) {
                que.push(curr->right);
                parent[curr->right] = curr;
            }
        }

        // Step 2: Simulate burning using BFS from target node
        unordered_map<Node*, bool> visited; // Track visited nodes to prevent re-burning
        int t = -1;                         // Time counter
        que.push(tar);                      // Start BFS from target node

        while (!que.empty()) {
            int n = que.size(); // Nodes burning at current second

            while (n--) {
                Node* curr = que.front();
                que.pop();

                visited[curr] = true; // Mark current node as burned

                // Spread to left child
                if (curr->left && !visited[curr->left]) {
                    que.push(curr->left);
                }

                // Spread to right child
                if (curr->right && !visited[curr->right]) {
                    que.push(curr->right);
                }

                // Spread to parent
                if (parent[curr] && !visited[parent[curr]]) {
                    que.push(parent[curr]);
                }
            }
            t++; // Increment time after processing current level
        }
        return t;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
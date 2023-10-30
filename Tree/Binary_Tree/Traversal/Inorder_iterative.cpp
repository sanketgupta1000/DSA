//Problem Link: https://practice.geeksforgeeks.org/problems/inorder-traversal/1?page=2&category=Tree&sortBy=submissions

//Solution:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

//iterative solution

typedef pair<Node*, char> pnc;

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root)
    {
        //necessary DS
        //will store in stack like this: {Node pointer n, character c}
        //n denotes which node's traversal is currently going on
        //c can take values: 'L' and 'R'
        //'L' means we are currently traversing left sub tree of n, and similarly for 'R'
        stack<pnc> stk;
        vector<int> ans;
        //this string will store the last operation: "push" or "pop"
        string last_op;
        
        //initializing
        stk.push({root, 'L'});
        last_op = "push";
        
        //now traversing
        while(!(stk.empty()))
        {
            if((stk.top().second=='L')&&(last_op=="push"))
            {
                //just pushed a node into stack
                //will do its left traversal now
                if(stk.top().first->left)
                {
                    stk.push({stk.top().first->left, 'L'});
                }
                else
                {
                    //set the last operation to pop to indicate that left traversal has been done
                    last_op = "pop";
                }
            }
            else if((stk.top().second=='L')&&(last_op=="pop"))
            {
                //completed left traversal of a node
                //adding in ans
                ans.push_back(stk.top().first->data);
                
                //now starting its right traversal
                stk.top().second = 'R';
                if(stk.top().first->right)
                {
                    stk.push({stk.top().first->right, 'L'});
                    last_op = "push";
                }
            }
            else
            {
                //completed right traversal of a node
                stk.pop();
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        Solution ob;
        vector<int> res = ob.inOrder(root);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
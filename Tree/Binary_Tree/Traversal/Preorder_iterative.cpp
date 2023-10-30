//Problem Link: https://practice.geeksforgeeks.org/problems/preorder-traversal/1?page=2&category=Tree&sortBy=submissions

//Solution:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
vector<int> preorder(struct Node* root);

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> res = preorder(root);
        for (int i : res)
            cout << i << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends

typedef pair<Node*, char> pnc;

/* A binary tree node has data, pointer to left child
   and a pointer to right child  

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

//iterative solution
//Function to return a list containing the preorder traversal of the tree.
vector <int> preorder(Node* root)
{
    //necessary DS
    stack<pnc> stk;
    vector<int>ans;
    string last_op;
    
    //initializing
    stk.push({root, 'L'});
    last_op = "push";
    
    //traversing
    while(!(stk.empty()))
    {
        if((stk.top().second=='L')&&(last_op=="push"))
        {
            ans.push_back(stk.top().first->data);
            if(stk.top().first->left)
            {
                stk.push({stk.top().first->left, 'L'});
            }
            else
            {
                last_op = "pop";
            }
        }
        else if((stk.top().second=='L')&&(last_op=="pop"))
        {
            stk.top().second = 'R';
            if(stk.top().first->right)
            {
                stk.push({stk.top().first->right, 'L'});
                last_op = "push";
            }
        }
        else
        {
            stk.pop();
        }
    }
    return ans;
    
}
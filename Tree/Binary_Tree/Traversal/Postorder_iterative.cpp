//Problem Link: https://practice.geeksforgeeks.org/problems/postorder-traversal/1?page=2&category=Tree&sortBy=submissions

//Solution:

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

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

/* Computes the number of nodes in a tree. */
vector <int> postOrder(struct Node* root);

/* Driver program to test size function*/
int main()
{
  int t;
  cin>>t;
  getchar();
  while (t--)
  {
  	 string inp;
     getline(cin, inp);
     struct Node* root = buildTree(inp);

     vector <int> res = postOrder(root);
     for (int i = 0; i < res.size (); i++)
        cout << res[i] << " ";
     cout << endl;
  }
  return 0;
}
// } Driver Code Ends

typedef pair<Node*, char> pnc;

//User function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

//iterative solution
//Function to return a list containing the postorder traversal of the tree.
vector <int> postOrder(Node* root)
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
            ans.push_back(stk.top().first->data);
            stk.pop();
        }
    }
    return ans;
    
}
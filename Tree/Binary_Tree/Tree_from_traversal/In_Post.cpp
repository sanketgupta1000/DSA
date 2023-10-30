//Problem Link: https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1?page=4&category=Tree&sortBy=submissions

//Solution:

//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends




/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//recursive approach

//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n)
{
    if(n==0) return nullptr;
    int rootval = post[n-1];
    Node * root = new Node(rootval);
    
    //finding index of root in inorder
    int rootInd;
    for(rootInd = 0; in[rootInd]!=rootval; rootInd++);
    
    root->left = buildTree(in, post, rootInd);
    root->right = buildTree(in+rootInd+1, post+rootInd, n-rootInd-1);
    
    return root;
}

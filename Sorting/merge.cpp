//Problem Link: https://www.geeksforgeeks.org/problems/merge-sort/1

//Solution:

//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    private:
    //utility function to copy n elements from A (starting from index a) to B (starting from index b)
    void copyarr(int A[], int B[], int n, int a, int b)
    {
        for(int i = 0; i<n; i++)
        {
            B[b] = A[a];
            b++;
            a++;
        }
    }
    
    public:
    void merge(int A[], int B[], int arr[], int leftsize, int rightsize)
    {
        int a = 0, b = 0, i = 0;
        while((a<leftsize)&&(b<rightsize))
        {
            if(A[a]<=B[b])
            {
                arr[i] = A[a];
                a++;
            }
            else
            {
                arr[i] = B[b];
                b++;
            }
            i++;
        }
        if(a==leftsize)
        {
            copyarr(B, arr, rightsize-b, b, i);
        }
        else if(b==rightsize)
        {
            copyarr(A, arr, leftsize-a, a, i);
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(r>l)
        {
            int mid = (l+r-1)/2;
            int leftsize = mid+1;
            int rightsize = (r-l+1)-leftsize;
            
            int A[leftsize], B[rightsize];
            //copying left and right halfs
            copyarr(arr, A, leftsize, 0, 0);
            copyarr(arr, B, rightsize, mid+1, 0);
            
            //recursive call
            mergeSort(A, 0, leftsize-1);
            mergeSort(B, 0, rightsize-1);
            
            //now merging
            merge(A, B, arr, leftsize, rightsize);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends
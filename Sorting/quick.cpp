//Problem Link: https://www.geeksforgeeks.org/problems/quick-sort/1

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
    //utility
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        //base condition
        if(low<high)
        {
            //partitioning
            int pivotInd = partition(arr, low, high);
            //now recursively sorting left and right partitions
            quickSort(arr, low, pivotInd-1);
            quickSort(arr, pivotInd+1, high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        //getting pivot
        int pivot = low;
        
        int i = low, j = high;
        
        //iterating and creating partition
        while(i<j)
        {
            while(arr[i]<=arr[pivot])
            {
                i++;
            }
            while(arr[j]>arr[pivot])
            {
                j--;
            }
            if(i<j)
            {
                swap(arr[i], arr[j]);
            }
        }
        
        //placing pivot in correct position
        swap(arr[j], arr[pivot]);
        return j;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends
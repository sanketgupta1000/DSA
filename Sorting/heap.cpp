//Problem Link: https://practice.geeksforgeeks.org/problems/heap-sort/1?page=2&category=Sorting&sortBy=submissions

//Solution:

//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    private:
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        //assuming max index as i
        int maxi = i;
        int left = (2*i)+1;
        int right = (2*i)+2;
        
        //updating maxi
        if((left<n)&&(arr[left]>arr[maxi]))
        {
            maxi = left;
        }
        
        if((right<n)&&(arr[right]>arr[maxi]))
        {
            maxi = right;
        }
        
        //swapping
        if(maxi!=i)
        {
            swap(arr[i], arr[maxi]);
            heapify(arr, n, maxi);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    {
        for(int i = (n/2)-1; i>=0; i--)
        {
            heapify(arr, n, i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //building max heap
        buildHeap(arr, n);
        
        for(int i = 0; i<n; i++)
        {
            //swapping the first and last elements
            swap(arr[0], arr[n-i-1]);
            
            //maintaining the max heap property
            heapify(arr, n-i-1, 0);
        }
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends
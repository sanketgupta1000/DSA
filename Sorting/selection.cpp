//Problem Link: https://practice.geeksforgeeks.org/problems/selection-sort/1?page=2&category=Sorting&sortBy=submissions

//Solution:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// } Driver Code Ends
class Solution
{
    private:
    int size;
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
    public:
    int select(int arr[], int i)
    {
        int min_i = i;
        for(int j = (i+1); j<size; j++)
        {
            if(arr[j]<arr[min_i])
            {
                min_i = j;
            }
        }
        return min_i;
    }
     
    void selectionSort(int arr[], int n)
    {
       size = n;
       for(int i = 0; i<(n-1); i++)
       {
           int min_i = select(arr, i);
           swap(arr[i], arr[min_i]);
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
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    Solution ob;  
    ob.selectionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends
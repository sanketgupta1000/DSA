//Problem Link: https://practice.geeksforgeeks.org/problems/radix-sort/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

//Solution:

//{ Driver Code Starts
//Initial Template for C++

#include  <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
//User function Template for C++

void countSort(int arr[], int n, int dig)
{
    //making countarray
    int countArr[10] = {};
    
    //filling countArr
    for(int i = 0; i<n; i++)
    {
        countArr[(arr[i]/int(pow(10, dig)))%10]++;
    }
    
    //filling prefixSum
    for(int i = 1; i<10; i++)
    {
        countArr[i]+=countArr[i-1];
    }
    
    //sorted array
    int sorted[n];
    
    //iterating arr from back
    for(int i = n-1; i>=0; i--)
    {
        sorted[countArr[(arr[i]/int(pow(10, dig)))%10]-1] = arr[i];
        countArr[(arr[i]/int(pow(10, dig)))%10]--;
    }
    
    //copying in arr
    for(int i = 0; i<n; i++)
    {
        arr[i] = sorted[i];
    }
    
}

void radixSort(int arr[], int n) 
{ 
    //finding max
    int max = arr[0];
    for(int i = 1; i<n; i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    
    //getting the number of digits in max
    int maxDig = log10(max)+1;
    
    //calling count sort from LSD
    for(int i = 0; i<maxDig; i++)
    {
        countSort(arr, n, i);
    }
} 

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
  
        radixSort(arr, n); 
        
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        
        cout<<endl;
    }
    return 0; 
} 
// } Driver Code Ends
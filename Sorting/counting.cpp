//Problem Link: https://practice.geeksforgeeks.org/problems/counting-sort/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

//Solution:

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        
        //making countArray to count frequencies
        int countArray[26] = {};
        
        //filling it
        for(int i = 0; i<arr.size(); i++)
        {
            countArray[arr[i]-'a']++;
        }
        
        //making it prefix Sum
        for(int i = 1; i<26; i++)
        {
            countArray[i]+=countArray[i-1];
        }
        
        char sorted[arr.size()+1] = {};
        
        //iterating arr backwards and filling sorted array
        for(int i = arr.size()-1; i>=0; i--)
        {
            sorted[countArray[arr[i]-'a']-1] = arr[i];
            countArray[arr[i]-'a']--;
        }
        
        return string(sorted);
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}

// } Driver Code Ends
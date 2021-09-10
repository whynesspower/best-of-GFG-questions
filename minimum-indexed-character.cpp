// code written by whynespower
// question link https://practice.geeksforgeeks.org/problems/minimum-indexed-character-1587115620/1#


// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        unordered_map<char, long long>ss;
        for(long long  i=0; i<str.length(); i++){
            if(ss.find(str[i])==ss.end()){
                ss[str[i]]=i;
            }
        }
        
        long long  ans=INT_MAX;
        
        for(long long i=0; i<patt.length(); i++){
            auto it= ss.find(patt[i]);
            if( it !=ss.end()){
                ans=min(ans, it->second);
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        else return ans;
        // Your code here
    }
};

// { Driver Code Starts.

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        string str;
        string patt;
        cin>>str;
        cin>>patt;
        Solution obj;
        cout<<obj.minIndexChar(str, patt)<<endl;
    }
	return 0;
}
  // } Driver Code Ends
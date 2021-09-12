// written by whynespower
// linedin : whynesspower
// star mark this repo for more wonderful questions

// video explanation here https://youtu.be/27fJEAh-6wU


#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
  public:
    int rightmostNonZeroDigit(int n, int arr[]){
        int countOf5 = 0;
        long long LastDigit =1;
        
        for(int i = 0; i < n; i++) {
            while(arr[i] > 0 && arr[i] % 5 == 0) {
                arr[i] = arr[i] / 5;
                countOf5++;
            }
        }
        
        for(int i = 0; i < n; i++) {
            while(countOf5 != 0&& arr[i] > 0 && arr[i] % 2 == 0) {
                arr[i] = arr[i] / 2;
                countOf5--;
            }
        }
        
        for(int i = 0; i < n; i++) {
            LastDigit = ((LastDigit % 10)*(arr[i] % 10)) % 10;
        }
        
        if(countOf5 > 0 && LastDigit != 0) 
            return 5;
        else if(LastDigit != 0)
            return LastDigit % 10;
        else 
            return -1;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;++i){
            cin>>A[i];
        }
        Solution ob;
        cout << ob.rightmostNonZeroDigit(n, A) << endl;
    }
    return 0; 
}   // } Driver Code Ends
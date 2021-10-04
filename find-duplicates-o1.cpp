// https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1#

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        int count=0;
        //raverse the given array from i= 0 to n-1 elements
        //  Go to index arr[i]%n and increment its value by n.
        for(int i=0;i<n;i++){
            int index=arr[i]%n;
            arr[index]+=n;
        }
        vector<int>ans;
        // Now traverse the array again and print all those 
        // indexes i for which arr[i]/n is greater than 1
        for(int i=0;i<n;i++){
            if(arr[i]/n>=2){
                ans.push_back(i);
                count++;
            }
        }
        if(count==0)ans.push_back(-1);
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
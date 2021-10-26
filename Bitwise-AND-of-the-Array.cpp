/*
Question Link-- 
https://practice.geeksforgeeks.org/problems/7ba682ec660335b1627f2183f63bd2c8a37391ec/1

MY LINEDIN ---  https://www.linkedin.com/in/whynesspower
comments have been added for explanation 
Video Solution -- https://youtu.be/--1uP_gcOCg

*/


#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int count(int N, vector<int> A,int X)
    {
        int mask=0,ans=N;
        // 0001000000000010===x
        for(int i=30;i>=0;i--){
            if((X>>i)&1){ 
                mask^=(1ll<<i);
                continue;
            }
            // 0000000000000110==A[0]
            // 0000000000000010==X
            int ct=0;
            int alt_mask=mask^(1ll<<i);
            for(auto &j:A){
                if((j&alt_mask)==alt_mask)
                    ct++;
            }
            ans=min(ans,N-ct);
        }
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> A(N);
        for(auto &i:A)
            cin>>i;
        Solution obj;
        int ans = obj.count(N, A, X);
        cout<<ans<<endl;
    }
}
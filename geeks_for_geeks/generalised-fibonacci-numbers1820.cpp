//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    long long mod;
    void multiply(vector<vector<long long>>& A,vector<vector<long long>>& B){
        
        vector<vector<long long>> temp(3,vector<long long>(3,0));
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    temp[i][j] = (temp[i][j] + ((A[i][k] % mod) * (B[k][j] % mod)) % mod) % mod;
                }
            }
        }
        
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                A[i][j]=temp[i][j];
        
        return;        
        
    }
    
    void power(vector<vector<long long>> &M,long long n){
        if(n==1) return;
     
        vector<vector<long long>> temp(3,vector<long long>(3,0));
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                temp[i][j]=M[i][j];
                
        power(M,n/2);
        multiply(M,M);
        
        if(n%2==1) multiply(M,temp);
        
        return;
    }
    
  public:
    long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
        // code here
        mod=m;
    
        if(n==1) return 1%mod;
        if(n==2) return 1%mod;
        
        vector<vector<long long>> M(3,vector<long long>(3,0));
       
        M[0][0]=a;
        M[0][1]=b;
        M[0][2]=c;
        M[1][0]=1;
        M[2][2]=1;
       
        power(M,n-2);
       
       long long ans=0;;
       
       for(int i=0;i<3;i++){
           ans=(ans+M[0][i])%mod;
       }
       
        return ans%mod;        
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a,b,c,n,m;
        
        cin>>a>>b>>c>>n>>m;

        Solution ob;
        cout << ob.genFibNum(a,b,c,n,m) << endl;
    }
    return 0;
}
// } Driver Code Ends

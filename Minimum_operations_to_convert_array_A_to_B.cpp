// https://practice.geeksforgeeks.org/problems/minimum-insertions-to-make-two-arrays-equal/1?page=1&company[]=Codenation&sortBy=submissions
// C++

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minInsAndDel(int a[], int b[], int n, int m) {
        // code here
        vector<int> temp;
        int len=0;// lcs
        // temp.push_back(a[0]);
        for(int i=0; i<m; i++){
            if(binary_search(a,a+n,b[i])){
                auto it =lower_bound(temp.begin(),temp.end(),b[i]);
                if(it==temp.end()){
                    len++;
                    temp.push_back(b[i]);
                }else{
                    *it=b[i];
                }
                    
            }
        }
        return n+m-2*len;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}
// } Driver Code Ends

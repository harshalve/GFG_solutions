// https://practice.geeksforgeeks.org/problems/box-stacking/1?page=1&company[]=Codenation&sortBy=submissions
// C++
// Time Complexity : O(n²)
// Space Complexity : O(n)


//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
    struct box{
        int l,w,h;
    };
    
    public:
    bool static compare(box a,box b){
        if(a.w*a.l > b.w*b.l)
            return true;
        else
            return false;
    }
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    int maxHeight(int height[],int width[],int length[],int n)
    {
        //Your code here
        int len=3*n;
        box b[len];
        int j=0;
        for(int i=0;i<n;i++){
            b[j].h=height[i];
            b[j].l=min(width[i],length[i]);
            b[j].w=max(width[i],length[i]);
            j++;
            b[j].h=length[i];
            b[j].l=min(width[i],height[i]);
            b[j].w=max(width[i],height[i]);
            j++;
            b[j].h=width[i];
            b[j].l=min(length[i],height[i]);
            b[j].w=max(length[i],height[i]);
            j++;
        }
        
        
        
        sort(b,b+len,compare);
        
        int LIS[len];//longest increasing subsequence
        int ans=0;
        
        for(int i=0;i<len;i++){
            LIS[i]=b[i].h;
            for(int j=i-1;j>=0;j--){
                if(b[j].l>b[i].l && b[j].w>b[i].w){
                    LIS[i]=max(LIS[i],LIS[j]+b[i].h);
                }
            }
            ans=max(ans,LIS[i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	
// } Driver Code Ends

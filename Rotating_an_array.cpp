// https://practice.geeksforgeeks.org/problems/reversal-algorithm5340/1?page=1&company[]=Codenation&sortBy=submissions

class Solution{   
public:
    void leftRotate(int arr[], int n, int d) {
        // code here
        d=d%n;
        int a[n];
        for(int i=0;i<n;i++)a[i]=arr[i];
        
        for(int i=0;i<n;i++){
            arr[(i-d+n)%n]=a[i];
        }
        
    }
};

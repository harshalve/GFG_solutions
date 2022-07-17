// https://practice.geeksforgeeks.org/problems/element-appearing-once2552/1?page=1&company[]=Codenation&sortBy=submissions
// C++ Solution

class Solution{
public:	
	int search(int A[], int N){
	    //code
	    int x=0;
	    
	    for(int i=0;i<N;i++){
	        x^=A[i];
	    }
	    return x;
	}
};

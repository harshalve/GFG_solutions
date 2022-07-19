// https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
// C++
// Time Complexity : O( N*LogN )
// Space Complexity : O( N )


#include<bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
    int len=1;
    temp.emplace_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>temp.back()){
            temp.emplace_back(arr[i]);
            len++;
        }else{
            int index=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            temp[index]=arr[i];
        }
    }
    return len;
}

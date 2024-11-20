#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        if(n>m){
            return findMedianSortedArrays(nums2,nums1);
        }
        int i=0,j=n,mid1,mid2,l1,l2,r1,r2;
        while(i<=j){
            mid1=(i+j)/2;
            mid2=(n+m+1)/2 - mid1;

            l1= mid1==0 ? INT_MIN : nums1[mid1-1];
            r1= mid1==n ? INT_MAX : nums1[mid1];
            l2= mid2==0 ? INT_MIN : nums2[mid2-1];
            r2= mid2==n ? INT_MAX : nums2[mid2];

            if(l1<=r2 && l2<=r1){
                return (n+m)%2 ?  max(l1,l2): (max(l1,l2)+min(r1,r2))/2.0;
            } 
            if(l1 > r2){
                j=mid1-1;
            }else{
                i=mid1+1;
            }
        }
        return 0;
    }
};
int main(){
    Solution a;
    // int res = a.findMedianSortedArrays({1,2,3,1,1,3});
    // cout << res << endl;
}
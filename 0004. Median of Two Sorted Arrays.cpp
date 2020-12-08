#include<bits/stdc++.h>
using namespace std;

//2020.10.14
/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Transform the original problem into finding the kth largest number,
so that the median is actually the (m+n)/2th smallest number. assume m+n is odd

Compare the two A[k/2-1] and B[k/2-1], which respectively represent the k/2-th smallest element of A and the k/2-th smallest element of B.
If A[k/2-1]<B[k/2-1], the elements from A[0] to A[k/2-1] are all in the k smallest elements after the combination of A and B .
In other words, A[k/2-1] cannot be greater than the k-th smallest value after the two arrays are merged, so we can discard them.

A similar conclusion exists when A[k/2-1]>B[k/2-1].

When A[k/2-1]=B[k/2-1], the k-th smallest number is the equivalent element, and we will mark it as m.

Recursion here we use. And it ends at
1) When A or B is empty, directly return to A[k-1] or B[k-1]
2) When k = 1, return min(A[0],B[0])
3) When A[k/2-1] == B[k/2-1], return A[k/2-1] or B[k/2-1]

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), left = (m + n + 1) / 2, right = (m + n + 2) / 2;
        int total=m+n;
        return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
    }
    int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        int m = nums1.size(), n = nums2.size();
        //either vector is empty
        if (i == m) return nums2[j + k - 1];
        if (j == n) return nums1[i + k - 1];

        if (k == 1) return min(nums1[i], nums2[j]);

        //k/2 larger than m, no need to consider vector 1
        int midVal1 = (i + k / 2 - 1 < m) ? nums1[i + k / 2 - 1] : INT_MAX;
        //k/2 larger than n, no need to consider vector 2
        int midVal2 = (j + k / 2 - 1 < n) ? nums2[j + k / 2 - 1] : INT_MAX;

        if (midVal1 < midVal2) {
            return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
        } else {
            return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
        }
    }
};

int main(){
    vector<int> a1={1,3};
    vector<int> a2={2};
    vector<int> b1={1,2};
    vector<int> b2={3,4};
    vector<int> c1={0,0};
    vector<int> c2={0,0};
    vector<int> d1={};
    vector<int> d2={1};
    vector<int> e1={2};
    vector<int> e2={};
    Solution X;
    double tmp=X.findMedianSortedArrays(b1,b2);
    cout<<tmp;
    return 0;
}

/*
Description
最长等差序列/最长等差数列

Given an array of integers X and an integer step, find the length of the longest subsequence of X where integers in this subsequence form an arithmetic sequence with difference of step.

Sample Input

The string form of an array is in the first line.

The second lind is an integer (string form).

2 4 1 7 -2 -3 -5
-3
Sample Output

An integer.

4
Explanation of Sample

The longest desired subsequence is [4, 1, -2, -5], and the length is 4.

Constraints of 10 test cases

Case 1: 0<X.length<10

Case 2-4: 100<X.length<1000

Case 5-7: 1000<X.length<10000

Case 8-10: 10000<X.length<100000


*/
#include <cstdio>
#include <map>
using namespace std;
int main(){
    int a[100005];
    int n = 0;
    map<int,int>dp;
    while (scanf("%d",&a[n])) {
        n++;
        char ch = getchar();
        if (ch == '\n')
            break;
    }
    int tar;
    scanf("%d",&tar);
    int ans=0;
    for(int i=0;i<n;i++){
        dp[a[i]] = dp[a[i]-tar] + 1;
        if(ans<dp[a[i]])
            ans=dp[a[i]];
    }
    printf("%d\n",ans);
    return 0;
}

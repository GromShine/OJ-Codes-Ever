/*
最长公共连续子序列/最长公共连续子数列
The Longest Common Consecutive Subsequence of X and Y
Description

Given 2 arrays X and Y, return the MAXIMUM length of the longest common consecutive subsequence. If no such subsequence exists, return 0.

A consecutive subsequence of X is a slice of X, which means X[i:j], 0≤i<j≤length(X)−1.

X and Y only contain integers.

Sample Input

Two lines of string forms of arrays (split by space).

1 5 7 3 4 5
7 3 4 4 5 7 -2
Sample Output

An integer.

3
Explanation of Sample

Explanation: The longest common consecutive subsequence is [7,3,4] (X[2:4] and Y[0:2])

Constraints of 10 test cases

Case 1: 1<X.length, Y.length<10

Case 2-4: 1<X.length, Y.length<300

Case 5-7: 1<X.length, Y.length<3000

Case 8-10: 1<X.length, Y.length<10000
*/
#include <vector>
#include <iostream>
using namespace std;

int findLength(vector<int> a,vector<int> b){
    int c[2][10005];
    int bi;
    int MXL = -1;
    for(int i=0;i<a.size();i++){
        bi = i&1;
        for (int j=0;j <= b.size();j++){
            if(i==0||j==0)
                c[bi][j]=0;
            else if(a[i]==b[j-1]){
                c[bi][j] = c[1-bi][j-1]+1;
                if(c[bi][j] > MXL){
                    MXL=c[bi][j];
                }
            }
            else{
                c[bi][j] = 0;
            }
        }
    }
    return MXL;
}

int main(){
    vector<int> a;
    vector<int> b;
    int i = 0;
    while (cin >> i) {
        a.push_back(i);
        char ch = getchar();
        if (ch == '\n')
            break;
    }
    while (cin >> i) {
        b.push_back(i);
        char ch = getchar();
        if (ch == '\n')
            break;
    }
    cout << findLength(a, b) << "\n";
}

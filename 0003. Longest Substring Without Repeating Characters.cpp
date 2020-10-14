#include<bits/stdc++.h>
using namespace std;

//2020.10.14
/*
Given a string s, find the length of the longest substring without repeating characters.

Scanning from left to right, the right cursor moves actively, and the left cursor moves lazily.
(When the number at the current position of the right cursor appears twice, use the left cursor to update
 the occurrence array to make sure there are no repeated letters between the two cursors.)
Each element will only be scanned once, complexity O(n)
*/

int lengthOfLongestSubstring(string s) {
    int len=s.length();
    int ans=0;
    int occur[500];
    memset(occur,0,sizeof(occur));
    for(int left=0,right=0;right<s.length();right++){
        occur[s[right]]++;
        while(occur[s[right]]>1)
            occur[s[left++]]--;
        ans=max(ans,right-left+1);
    }
    return ans;
}

int main(){
    string s1="bbbbb";
    string s2="pwwkew";
    string s3="";

    printf("%d %d %d",lengthOfLongestSubstring(s1),lengthOfLongestSubstring(s2),lengthOfLongestSubstring(s3));
    return 0;
}

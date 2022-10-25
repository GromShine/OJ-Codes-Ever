#include<bits/stdc++.h>
using namespace std;

//2020.10.14
/*
Given a string s, return the longest palindromic substring in s.

*/

string longestPalindrome(string s) {

    //special case
    int len1=s.length();
    if(len1==1)return s;
    string ns="#";
    for(int i=0;i<len1;i++){// get the preprocessed string
            ns+=s[i];
            ns+="#";
    }
    //cout<<ns<<endl;
    int len2=ns.length();//The length of the new string
    //cout<<len2<<endl;

    int p[len2];
    /*p[i] records the radius of the palindrome string centered on the i-th character of the new string (including the i-th character)
    Every two steps of diffusion in the new string, although only one valid character is actually scanned,
    it is equivalent to calculating two characters in the original string*/

    for(int i=0;i<len2;i++)
        p[i]=0;//initialize array

    //Double pointers, they are one-to-one correspondence and must be updated at the same time
    int mxR=0;
    /*mxR represents the farthest boundary of the record currently extending to the right,
    that is, the rightmost position of the palindrome substring that can be obtained by using
    the "central diffusion method" from the beginning to the present.*/
    int center=0;
    //center is the index value of the palindrome center of the above maxRight
    int mxLen=1;//The length of the longest palindrome substring of the original string
    int st=0;//The starting position of the longest palindrome substring of the original string

    for(int i=0;i<len2;i++){
        if(i<mxR){
            int mirror=2*center-i;
            //p[i] = min(mxR - i, p[mirror]);
            p[i]=mxR-i>p[mirror]?p[mirror]:mxR-i;
            //cout<<"p[i]: "<<p[i]<<endl;

        }
        int left=i-(p[i]+1);
        int right=i+(p[i]+1);

        while(left>=0 && right< len2 && ns[left]==ns[right]){//Guarantee not to cross the boundary
            p[i]++;
            left--;
            right++;
        }

        if(i+p[i]>mxR){
            mxR=i+p[i];
            center=i;
        }
        if(p[i]>mxLen){
            mxLen=p[i];
            st=(i-mxLen)/2;
        }
    }
    //cout<<mxLen<<endl;
    string res=s.substr(st,mxLen);
    //cout<<res<<endl;
    return res;
}

int main(){
    string s1 = "babad";
    string s2 = "cbbd";
    string s3 = "a";
    string s4 = "ac";
    cout<<longestPalindrome(s1)<<endl;
    cout<<longestPalindrome(s2)<<endl;
    cout<<longestPalindrome(s3)<<endl;
    cout<<longestPalindrome(s4)<<endl;
    //cout<<
    return 0;
}

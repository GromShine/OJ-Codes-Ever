#include<bits/stdc++.h>
//2020.10.14
/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Create a Map<number, where it appears>. Take down the corresponding position of each number. You can get the answer after scanning it.
Complexity O(N*map)
*/
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int,int>sig;
        for(int i=0;i<nums.size();i++){
            if(sig.count(target-nums[i])!=0){
                res.push_back(i);
                res.push_back(sig[target-nums[i]]);
                break;
            }
            sig[nums[i]]=i;
        }
        return res;
    }
int main(){
    vector<int>v ;
    v.push_back(3);
    v.push_back(3);
    v.push_back(4);
    v.push_back(15);
    int tar=6;
    vector<int> w=twoSum(v,tar);
    for(int i=0;i<w.size();i++)
        printf("%d\n",w[i]);
    return 0;
}



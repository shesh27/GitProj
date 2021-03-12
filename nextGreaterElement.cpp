/*
You are given two integer arrays nums1 and nums2 both of unique elements, where nums1 is a subset of nums2.
Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, return -1 for this number.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> hash;
    vector<int> ans;
    
    for(int i = 0; i < nums2.size(); i++){
        for(int j = i+1; j < nums2.size(); j++){
            if(nums2[j] > nums2[i]){
                hash[nums2[i]] = nums2[j];
                break;
            }
        }
        if(hash[nums2[i]] == 0){
            hash[nums2[i]] = -1;
        }
    }
    
    for(int i = 0; i < nums1.size(); i++){
        ans.push_back(hash[nums1[i]]);
    }
    return ans;
}

// driver code.

int main(){
  vector<int> v1{3,4,2,5,3}, v2{4,2,4,3}, ans;

  ans = nextGreaterElement(v1, v2);

  for(auto& a : ans){
      cout << a <<" ";
  }
  return 0;
}

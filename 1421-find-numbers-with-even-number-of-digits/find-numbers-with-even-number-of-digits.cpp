#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int evenCount=0;
        for(int number:nums ){
            int digits = 0;
            while(number > 0){
                number = number / 10;
                digits++;
            }
            
            if(digits % 2 == 0){
                evenCount++;
            }
        }
        return evenCount;
    }
};
class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1;
        int sum = 0;
        while(n != 0){
            int digit = n % 10;
            prod *= digit;
            sum += digit;
            n = n / 10; // fix: reduce n
        }
        return prod - sum;
    }
};

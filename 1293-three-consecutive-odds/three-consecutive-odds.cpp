class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
     if (arr.size() < 3)
        return false;

    int n = arr.size();
    int window = 0;

    for (int i = 0; i < 3; i++)
        window += arr[i] % 2;

    if (window == 3)
        return true;

    for (int i = 3; i < n; i++)
    {
        window += arr[i] % 2;
        window -= arr[i - 3] % 2;

        if (window == 3)
            return true;
    }

    return false;   
    }
};
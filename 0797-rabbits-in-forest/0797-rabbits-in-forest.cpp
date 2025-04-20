class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> mp;
        int sum = 0;

        // Count how many times each answer appears
        for (auto i : answers) mp[i]++;

        for (auto i : mp) {
            // i.first = x (answer), i.second = count
            int group = i.second / (i.first + 1);  // Full groups
            if (i.second % (i.first + 1)) group++; // Add one if leftovers

            sum += (group * (i.first + 1));
        }

        return sum;
    }
}; // <--- This was likely missing

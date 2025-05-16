class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> f(n, 1);     // f[i]: length of longest valid subsequence ending at i
        vector<int> g(n, -1);    // g[i]: previous index in the subsequence
        int mx = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && f[i] < f[j] + 1 && check(words[i], words[j])) {
                    f[i] = f[j] + 1;
                    g[i] = j;
                    mx = max(mx, f[i]);
                }
            }
        }

        vector<string> ans;
        for (int i = 0; i < n; ++i) {
            if (f[i] == mx) {
                for (int j = i; j >= 0; j = g[j]) {
                    ans.push_back(words[j]);
                    if (g[j] == -1) break;
                }
                break;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    bool check(const string& s, const string& t) {
        if (s.size() != t.size()) return false;
        int cnt = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) ++cnt;
        }
        return cnt == 1;
    }
};

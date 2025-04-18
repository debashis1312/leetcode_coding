class Solution {
public:
    string countAndSay(int n) {
        string curr = "1";
        if(n == 1) return curr;

        for(int i=1;i<n;i++){
            string temp = "";
            int cnt = 1;

            for(int j=0;j<curr.size()-1;j++){
                if(curr[j] == curr[j+1]) cnt++;
                else{
                    temp += to_string(cnt);
                    temp += curr[j];
                    cnt = 1;
                }
            }

            temp += to_string(cnt);
            temp += curr[curr.size()-1];
            curr = temp;
        }

        return curr;
    }
};
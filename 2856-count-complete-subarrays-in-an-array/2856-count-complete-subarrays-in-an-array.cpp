class Solution {
public:
    int countCompleteSubarrays(vector<int>& v) {
        int n = v.size();
        
        unordered_set<int> st(v.begin(),v.end());
        int dis = st.size();
        
        int ans=0;
        unordered_map<int,int> m;
        for(int i=0,j=0;i<n;i++){
           m[v[i]]++;
           while(m.size()==dis){
            ans+=n-i;
            m[v[j]]--;
            if(m[v[j]]==0)
             m.erase(v[j]);
            j++; 
           }
        }
        return ans;
    }
};
class Solution {
public:
    
    int F(string s, int k) {
        int count=0;
        vector<int>map(26,0);
        int l=0,r=0;
        while(r<s.size()){
            map[s[r]-'A']++;
            int t=*max_element(map.begin(),map.end());
            while((r+1-l-t)>k){
                map[s[l]-'A']--;
                t=*max_element(map.begin(),map.end());
                l++;
            }
            if(r-l-t<=k) count=max(count,r-l+1);
            r++;
        }
        return count;
    }
    


    int characterReplacement(string s, int k) {
        int ans=F(s,k);
        return ans;
    }
};
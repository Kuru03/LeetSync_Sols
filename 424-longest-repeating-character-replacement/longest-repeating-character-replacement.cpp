class Solution {
public:
    int maxfreq(unordered_map<char,int>charFrequencyStore){
        int  t=0;
        for(auto it:charFrequencyStore){
            t=max(t,it.second);
        }
        return t;
    }
    int characterReplacement(string s, int k) {
        int start=0,end=0;
        int n=s.size();
        unordered_map<char,int> charFrequencyStore;
        int  ans=0;
        while(end<n){
            charFrequencyStore[s[end]]++;
            int maxFrequency=maxfreq(charFrequencyStore);
            int mistakes=(end-start+1)-maxFrequency;
            while(k<mistakes){
                charFrequencyStore[s[start]]--;
                start++; 
                maxFrequency=maxfreq(charFrequencyStore);
                mistakes=(end-start+1)-maxFrequency;
            }
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
        
    }
};
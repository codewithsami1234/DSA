class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        int l=0,r=0,len=0;
        while(r<n){
            if(mp.find(s[r])!=mp.end()){
                if(mp[s[r]]+1>l)
                l=mp[s[r]] +1;
            }
            mp[s[r]]=r;
            len =max(len,r-l+1);
            r++;
        }
        return len;
    }
};
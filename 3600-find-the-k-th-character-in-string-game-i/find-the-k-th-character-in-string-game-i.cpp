class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.length()<k){
            int c = s.length();
            string ok = "";
            for(int i = 0 ; i< c; i++){
                char n = s[i];
                if( n== 'z'){
                    ok+='a';
                }else{
                    ok+=(char)(n+1);
                }
            }
            s+=ok;
        }
        return s[k-1];
    }
};
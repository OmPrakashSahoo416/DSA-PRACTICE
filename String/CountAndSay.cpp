class Solution {
public:
    string func(string &s){
        int n = s.size();
        string ans = "";
        int i = 0;
        for(i = 0; i < n; i++){
            int ct = 0;
            int j = i;
            char ch = s[i];
            while(j < n){
                if(s[j] == ch){
                    ct++;
                }else{
                    j--;
                    break;
                }
                j++;
            }
            i = j;
            ans += to_string(ct) + ch;
        }
        return ans;
    }
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 1; i < n; i++){
            ans = func(ans);
        }
        return ans;
    }
};
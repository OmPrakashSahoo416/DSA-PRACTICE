class Solution {
public:
    string reverseWords(string s) {
        string str = "";
        string ans = "";
        for(int i = s.size() - 1; i >= 0; i--){
            char ch = ' ';
            if(s[i] == ch){
                if(str.size() != 0){
                    reverse(str.begin(), str.end());
                    ans += str;
                    ans+= " ";
                }
                str = "";
            }else{
                str += s[i];
            }
        }
        if(str.size() != 0){
            reverse(str.begin(), str.end());
            ans += str;
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};
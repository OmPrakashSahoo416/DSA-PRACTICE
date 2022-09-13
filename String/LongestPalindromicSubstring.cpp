class Solution {
public:
    int lenPalindrome(int i, int j, string &s){
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            i--;
            j++;
        }
        ++i;
        --j;
        return (j - i + 1);
        
    }
    string longestPalindrome(string s) {
        string ans;
        ans += s[0];
        int mxLen = 1;
        int i1 = 0;
        for(int i = 0; i < s.size(); i++){
            int l1 = lenPalindrome(i, i, s);
            int l2 = lenPalindrome(i, i + 1, s);
            int curr_len = max(l1, l2);
            if(curr_len > mxLen){
                mxLen = curr_len;
                if(mxLen % 2 == 1){
                    i1 = i - (mxLen / 2);
                }else{
                    i1 = (i + 1) - (mxLen / 2);
                }
                ans = s.substr(i1, mxLen);
            }
        }
        return ans;
    }
};
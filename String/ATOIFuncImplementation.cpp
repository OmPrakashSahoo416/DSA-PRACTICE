class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        int ans = 0;
        int sign = 1;
        int ind = 0;
        bool p = true, n = true;
        reverse(s.begin(), s.end());
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == ' '){
                s.pop_back();
                i = s.size();
            }else{
                break;
            }
        }
        reverse(s.begin(), s.end());
        if(s[0] == '-'){
            ind = 1;
            sign = -1;
        }
        if(s[0] == '+'){
            ind = 1;
        }
        for(int i = ind; i < s.size(); i++){
            char ch = s[i];
            if(ch == ' '){
                return num;
            }
            if(ch < '0' || ch > '9'){
                return num;
            }else{
                // f = false;
                num = (num * 10 + (ch - '0'));
                if(num > INT_MAX && sign == 1){
                    p = false;
                    break;
                }else if(num > INT_MAX && sign == -1){
                    n = false;
                    break;
                }
            }
        }
        if(sign == 1){
            int ans = INT_MAX;
            if(p)return num;
            else return ans;
        }else{
            int ans = INT_MIN;
            if(n)return num * (sign);
            else return ans;
        }
    }
};
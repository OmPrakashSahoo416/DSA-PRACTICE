class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        int ind = 0;
        if(strs.size() == 1){
            return strs[0];
        }
        while(true){
            int ct = 0;
            for(int i = 0; i < n - 1; i++){
                if(ind == strs[i].size() || ind == strs[i + 1].size()){
                    return ans;
                }else{
                    if(strs[i][ind] == strs[i + 1][ind]){
                        ct++;
                    }else{
                        return ans;
                    }
                }
            }
            ans += strs[0][ind];
            ind++;
        }
        return ans;
    }
};
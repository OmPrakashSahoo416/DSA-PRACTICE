class Solution {
public:
    bool isAnagram(string s, string t) {
       vector<int> v(26,0);
       bool ans = true;
        for(int i = 0; i<s.size(); i++){
            v[s[i] - 'a']++;
        }
        for(int i = 0; i<t.size(); i++){
            v[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(v[i] != 0) ans = false;
        }
        return ans;
    }
};
vector<int> stringMatch(string &str, string &pat) {
    vector<int>ans;
    int n = str.size();
    int m = pat.size();
    for(int i = 0; i < n; i++){
        string s = str.substr(i,m);
        if(s == pat){
            ans.push_back(i);
        }
    }
    return ans;
}

int compareVersion(string version1, string version2) {
    vector<int>v1;
    vector<int>v2;
    int n1 = 0, n2 = 0; 
    for(int i = 0; i < version1.size(); i++){
        if(version1[i] == '.'){
            v1.push_back(n1);
            n1 = 0;
        }else{
            n1 = (n1 * 10) + int(version1[i] - '0');
        }
    }
    for(int i = 0; i < version2.size(); i++){
        if(version2[i] == '.'){
            v2.push_back(n2);
            n2 = 0;
        }else{
            n2 = (n2 * 10) + int(version2[i] - '0');
        }
    }
    v1.push_back(n1);
    v2.push_back(n2);
    int lo = 0, hi = 0;
    while(lo < v1.size() && hi < v2.size()){
        if(v1[lo] < v2[hi]){
            return -1;
        }
        else if(v1[lo] > v2[hi]){
            return 1;
        }else{
            lo++;
            hi++;
        }
    }
    if(lo == version1.size() && hi == version2.size()){
        return 0;
    }else if(lo != v1.size()){
        for(int i = lo; i < v1.size(); i++){
            if(v1[i] != 0)return 1;
        }
    }else if(hi != v2.size()){
        for(int i = hi; i < v2.size(); i++){
            if(v2[i] != 0)return -1;
        }
    }
    return 0;
}
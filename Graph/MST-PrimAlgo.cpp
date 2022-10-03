class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int key[V];
        bool mst[V];
        int parent[V];
        int ans = 0;
        for(int i = 0; i < V; i++) {
            key[i] = INT_MAX;
            mst[i] = false;
            parent[i] = i;
        }
        parent[0] = -1;
        set<pair<int, int>>st; // {value, node}
        key[0] = 0;
        st.insert({0, 0});
        while(!st.empty()){
            auto it = st.begin();
            int node = it -> second;
            mst[node] = true;
            
            for(auto itt : adj[node]) {
                int wt = itt[1];
                int child = itt[0];
                if(mst[child] == false && wt < key[child]) {
                    parent[child] = node;
                    key[child] = wt;
                    st.insert({wt, child});
                    
                }
            }
            st.erase(it);
        }
        vector<pair<int, int>>vp;
        for(int i = 1; i < V; i++){
            vp.push_back({parent[i], i});
        }
        for(int i = 0; i < vp.size(); i++) {
            int par = vp[i].first;
            int x = vp[i].second;
            for(auto it : adj[par]){
                if(it[0] == x){
                    ans += it[1];
                    break;
                }
            }
        }

        return ans;
    }
};

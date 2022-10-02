class Solution
{
    public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>>st; //{dis, node}
        vector<int>dis(V, 1e9);
        st.insert({0,S});
        dis[S] = 0;
        while(st.size() != 0){
            auto it = st.begin();
            int node = it -> second;
            for(int i = 0; i < adj[node].size(); i++){
                int x = adj[node][i][0]; //node
                int y = adj[node][i][1]; //weight
                
                if(dis[node] + y < dis[x]){
                    dis[x] = dis[node] + y;
                    st.insert({dis[x], x});
                }
            }
            st.erase(it);
        }
        return dis;
    }
};

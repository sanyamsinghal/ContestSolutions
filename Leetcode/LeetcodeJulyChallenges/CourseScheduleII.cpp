class Solution {
public:
    vector<bool>instack;
    bool dfs_cycle_TS(int node, vector<int>&ans, unordered_map<int,vector<int>> &graph, vector<bool> &vis) {
        
        vis[node] = true;
        instack[node] = true;
        
        for(int child : graph[node]) {
            if(!vis[child]) {
                if(dfs_cycle_TS(child, ans, graph, vis))
                    return true;
            }
            else if(instack[child]) {
                return true;
            }
        }
        
        ans.push_back(node);
        instack[node] = false;
        return false;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int>ans;
        unordered_map<int,vector<int>>graph;
        instack.resize(n, false);
        for(int i=0; i<p.size(); i++) {
            graph[p[i][1]].push_back(p[i][0]);
        }
        
        vector<bool>vis(n, false);
        
        for(int i=0; i<n; i++){
            if(!vis[i])
                if(dfs_cycle_TS(i, ans, graph, vis))
                    return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
private:
    vector<bool> connected;
    void dfs(vector<vector<int>>& isConnected, int city)
    {
        connected[city] = true;
        for(int i = 0; i < isConnected.size(); ++i)
            if(!connected[i] && isConnected[city][i]) dfs(isConnected, i);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int prov = 0;
        connected.assign(isConnected.size(), false);
        for(int i = 0; i < isConnected.size(); ++i)
            if(!connected[i]) ++prov, dfs(isConnected, i);
        return prov;
    }
};
class Solution {
private:
    vector<bool> crooms;
    unordered_set<int> keys;
    void dfs(vector<vector<int>>& rooms, int key)
    {
        if(crooms[key] || !keys.contains(key)) return;
        crooms[key] = true;
        for(auto& k : rooms[key]) keys.insert(k), dfs(rooms, k);
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        keys.insert(0), crooms.assign(rooms.size(), false);
        for(int i = 0; i < rooms.size(); ++i) dfs(rooms, i);
        return find(crooms.begin(), crooms.end(), false) == crooms.end() ? true : false;
    }
};
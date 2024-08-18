class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        int lockNum = rooms.size();
        unordered_set<int> keys({0}), ukeys;
        while(lockNum && !keys.empty())
        {
            int key = *keys.begin();
            if(!ukeys.contains(key)) keys.insert(rooms[key].begin(), rooms[key].end()), --lockNum;
            ukeys.insert(key), keys.erase(key);
        }
        return lockNum ? false : true;
    }
};
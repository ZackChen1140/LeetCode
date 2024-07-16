class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> row_map = {{vector<int>({-1}), 0}};
        for(auto& row : grid) row_map.count(row) ? ++row_map[row] : row_map[row] = 1;
        for(int c = 0; c < grid.size(); ++c)
        {
            vector<int> ccol;
            for(int r = 0; r < grid.size(); ++r) ccol.emplace_back(grid[r][c]);
            if(row_map.count(ccol)) row_map[vector<int>({-1})] += row_map[ccol];
        }
        return row_map[vector<int>({-1})];
    }
};
class Solution {
public:
    void dfs(vector <bool> &vis, vector < vector <int>> &rooms, int curr){
        vis[curr] = true;
        for(auto &i : rooms[curr])
            if(!vis[i])
                dfs(vis, rooms, i);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int len = rooms.size();
        vector <bool> vis(len, false);
        dfs(vis, rooms, 0);
        return count(vis.begin(), vis.end(), true) == len;
    }
};

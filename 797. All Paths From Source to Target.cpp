// backtracking solution
// runtime : 12ms beats 79.94%
// memory : 10.6 MB beats 81.98%

class Solution {
public:
    void backTracking(vector <vector <int> > &vec, vector <int> &path, vector < vector <int> > graph, int curr){
        path.push_back(curr);
        if(curr == graph.size() - 1){
            vec.push_back(path);
        }
        else{
            for(auto i : graph[curr]){
                backTracking(vec, path, graph, i);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector <vector <int> > vec;
        vector <int> path;
        backTracking(vec, path, graph, 0);
        return vec;
    }
};

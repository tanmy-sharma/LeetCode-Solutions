// BFS Solution
// Runtime 22.6 %
// Space 37.1%
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start >= arr.size()){
            return false;
        }
        vector <int> vec;
        for(int i = 0 ; i < arr.size(); i++){
            if(arr[i] == 0){
                vec.push_back(i);
            }
        }
        if(vec.size() == 0){
            return false;
        }
        queue <int> q;
        map <int, int> mp;
        mp[start]++;
        q.push(start);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int top = q.front();
                q.pop();
                if(vec.end() != find(vec.begin(), vec.end(), top)){
                    return true;
                }
                mp[top]++;
                if(top - arr[top] >= 0 && mp.find(top - arr[top]) == mp.end()){
                    q.push(top - arr[top]);
                }
                if(top + arr[top] < arr.size() && mp.find(top + arr[top]) == mp.end()){
                    q.push(top + arr[top]);
                }
            }
        }
        return false;
    }
};

// Recursive Solution
// Runtime 69.8%
// Space Complexity 68.85%
class Solution {
public:
    bool solve(vector <int> &arr, int start, int n, vector <int> &vec){
        if(start > n || start < 0 || vec[start]){
            return false;
        }
        if(arr[start] == 0){
            return true;
        }
        vec[start] = 1;
        return solve(arr, start - arr[start], n, vec) || solve(arr, start + arr[start], n, vec);
    }
    bool canReach(vector<int>& arr, int start) {
        vector <int> vec(arr.size(), 0);
        return solve(arr, start, arr.size() - 1, vec);
    }
};

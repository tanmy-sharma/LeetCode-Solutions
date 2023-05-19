class Solution {
public:
    string solve(const string &s, int &i){
        string ans;
        int len = s.size();
        while(i < len && s[i] != ']'){
            if(!isdigit(s[i]))
                ans += s[i++];
            else{
                int num = 0;
                while(i < len && isdigit(s[i]))
                    num = 10*num + s[i++] - 48; 

                i++;
                string temp = solve(s, i);
                i++;

                while(num--) ans += temp;
            }
        }
        return ans;
    }
    string decodeString(string s) {
        int i = 0;
        return solve(s, i);
    }
};

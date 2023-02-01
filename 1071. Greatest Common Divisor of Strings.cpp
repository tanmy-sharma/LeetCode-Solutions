// recursive solution
// time beats 30% 8 ms
// memory beats 23.57% 8.5 MB

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str2.length() > str1.length()){
            return gcdOfStrings(str2, str1);
        }
        if(str2.empty()){
            return str1;
        }
        if(str1.substr(0, str2.length()) != str2){
            return "";
        }
        return gcdOfStrings(str1.substr(str2.length(), str1.length()), str2);
    }
};


// replacing length with size
// runtime beats 61.25% 4 ms
// memory beats 23.57 % 8.4 MB

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str2.size() > str1.size()){
            return gcdOfStrings(str2, str1);
        }
        if(str2.empty()){
            return str1;
        }
        if(str1.substr(0, str2.size()) != str2){
            return "";
        }
        return gcdOfStrings(str1.substr(str2.size(), str1.size()), str2);
    }
};


// non recursive solution
// runtime 3 ms 83.39%
// memory 6.8 MB 97.68%
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.size(), len2 = str2.size();
        int gcd = __gcd(len1, len2);
        string ans = str1.substr(0, gcd);
        for(int i = 0 ; i < len1; i++){
            if(str1[i] != ans[i%gcd]){
                return "";
            }
        }
        for(int i = 0 ; i < len2; i++){
            if(str2[i] != ans[i%gcd]){
                return "";
            }
        }
        return ans;
    }
};

class Solution {
public:
    static bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int maxVowels(string s, int k) {
        int max_vowels = count_if(s.begin(), s.begin() + k, isVowel);
        if(max_vowels == k){
            return k;
        }
        int curr_vowels = max_vowels, len = s.size();
        for(int i = k; i < len; i++){
            curr_vowels += isVowel(s[i]) - isVowel(s[i-k]);
            max_vowels = max(max_vowels, curr_vowels);
            if(max_vowels == k){
                return k;
            }
        }
        return max_vowels;
    }
};

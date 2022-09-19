class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0){
            return 0;
        }
        
        unordered_set<char> hash;
        
        queue<char> q ;
        int maxLen = 0;
        int currlen=0;
        int end=0;
        while(end!=s.length()){
            char checkChar = s[end];
            if(hash.find(checkChar)==hash.end()){
                q.push(checkChar);
                hash.insert(checkChar);
                currlen++;
            }
            else{
                while(q.front()!=checkChar){
                    hash.erase(hash.find(q.front()));
                    q.pop();
                    currlen--;
                }
                q.pop();
                q.push(checkChar);
            }
            maxLen = currlen>maxLen?currlen:maxLen;
            end++;
        }
        
        return maxLen;
        
    }
};
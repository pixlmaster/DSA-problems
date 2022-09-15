class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() & 1 ){
            return {};
        }
        vector<int> hash(100001,0);
        
        sort(changed.begin(),changed.end());
        
        for(int i=0;i<changed.size();i++){
            hash[changed[i]]++;
        }
        
        vector<int> ans;
        
        int count=0;
        for(int i=0;count<changed.size()/2;){
            if(changed[i]>50000){
                return {};
            }
            // cout<<changed[i]<<" "<<hash[changed[i]]<<endl;
            if(hash[changed[i]]==0){
                i++;
                
            }
            else if( hash[2*changed[i]]>0){                
                count++;
                hash[changed[i]]--;
                hash[2*changed[i]]--;
                if(hash[changed[i]]<0){
                    return {};
                }
                ans.push_back(changed[i]);
                i++;
            }
            else{
                return {};
            }
        }
        
        return ans;
        
    }
};
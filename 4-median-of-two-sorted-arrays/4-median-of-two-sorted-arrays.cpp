class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        if(m<n){
            return findMedianSortedArrays(nums2,nums1);
        }
        

        int actualmid = (m+n+1)/2;
        int l1=0;
        int r1 = n;
        
        
        while(l1<=r1){
            // cout<<"actualmid "<<actualmid<<endl;
            int lmid = (l1+r1+1)/2;
            int rmid = actualmid-lmid;
            // cout<<"l1 "<<l1<<endl;
            // cout<<"r1 "<<r1<<endl;
            // cout<<"lmid "<<lmid<<endl;
            
            int leftmid1 = lmid-1<0?INT_MIN:nums1[lmid-1];
            int leftmid2 = rmid-1<0?INT_MIN:nums2[rmid-1];
            
            int rightmid1 = lmid<n?nums1[lmid]:INT_MAX;
            int rightmid2 = rmid<m?nums2[rmid]:INT_MAX;
            
            
            if(leftmid1<=rightmid2 && leftmid2<=rightmid1){
                if((m+n)&1==1){
                    return max(leftmid1,leftmid2);
                }
                else{
                    return 1.0*(max(leftmid1,leftmid2)+min(rightmid1,rightmid2))/2;
                }
            }
            else if(leftmid1>rightmid2){
                r1=lmid-1;
            }
            else{
                l1=lmid;
            }
            
            
        }
        
        
        
        return 0.0;
        
    }
};
class Solution {
public:
void merge(vector<int>& nums1,vector<int>& nums2,vector<int>& ans){
    int n=nums1.size();
    int m=nums2.size();
    int i=0;
    int j=0;
    
    while(i<n && j<m){
        if(nums1[i]<=nums2[j]){
            ans.push_back(nums1[i]);
            i++;
        }else{
            ans.push_back(nums2[j]);
            j++; 
        }
    }
    while(i<n){
        ans.push_back(nums1[i]);
        i++;
    }
     while(j<m){
        ans.push_back(nums2[j]);
        j++;
    }

}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>ans;
        merge(nums1,nums2,ans);
        int k=n+m;
        if(k%2==1){
            return ans[k/2];

        }else{
            double p=(ans[(k/2)-1]+ans[k/2])/2.0;
            return p;

        }
        return 0;


        
        
        
    }
};
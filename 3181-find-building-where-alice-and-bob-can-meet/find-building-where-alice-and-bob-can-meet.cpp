class Solution {
public:

void buildSegmentTree(int i,int l,int r,int n,vector<int>& heights,vector<int>& segmentTree){
    if(l==r){
        segmentTree[i]=l;
        return ;
    }
    int mid=l+(r-l)/2;
    buildSegmentTree(2*i+1,l,mid,n,heights,segmentTree);
    buildSegmentTree(2*i+2,mid+1,r,n,heights,segmentTree);
    int leftMaxIdx=segmentTree[2*i+1];
    int rightMaxIdx=segmentTree[2*i+2];
    if(heights[leftMaxIdx]>=heights[rightMaxIdx]){
        segmentTree[i]=leftMaxIdx;
    }else{
        segmentTree[i]=rightMaxIdx;
    }
}
int query(int start,int end,int i,int l,int r,vector<int>& segmentTree,vector<int>& heights){
    if(start>r || end<l){
        return -1;
    }
    if(l>=start && r<=end){
        return segmentTree[i];
    }
    int mid=l+(r-l)/2;
    int leftMaxIdx=query(start,end,2*i+1,l,mid,segmentTree,heights);
    int rightMaxIdx=query(start,end,2*i+2,mid+1,r,segmentTree,heights);
    if(leftMaxIdx==-1) return rightMaxIdx;
    if(rightMaxIdx==-1) return leftMaxIdx;
    if(heights[leftMaxIdx]>=heights[rightMaxIdx]){
        return leftMaxIdx;
    }
    else{
        return rightMaxIdx;
    }

}
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size();
        vector<int>segmentTree(4*n);
        buildSegmentTree(0,0,n-1,n,heights,segmentTree);
        vector<int>result;
        for(auto it:queries){
            
            int start=it[0];
            int end=it[1];
            int maxIdx=max(start,end);
            int minIdx=min(start,end);
            if(start==end){
                result.push_back(start);
                continue;
            }
            else if(heights[maxIdx]>heights[minIdx]){
                result.push_back(maxIdx);
                continue;
            }else{
                int l=maxIdx+1;
                int r=n-1;
                int result_idx=INT_MAX;
                while(l<=r){
                    int mid_idx=(l+r)/2;
                    int idx=query(l,mid_idx,0,0,n-1,segmentTree,heights);
                    if(idx!=-1 && heights[idx]>max(heights[start],heights[end])){
                        
                        result_idx=min(result_idx,idx);
                        r=mid_idx-1;
                    }else{
                        l=mid_idx+1;
                    }
                }
                (result_idx==INT_MAX)?result.push_back(-1):result.push_back(result_idx);
            }

            
            
        }  
        return result;  
    }
};
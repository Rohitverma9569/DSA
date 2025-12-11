class NumArray {
public:
vector<int>segmentTree;
int n;
void buildSegmentTree(int i,int l,int r,vector<int>& nums){
    if(l==r){
        segmentTree[i]=nums[l];
        return ;
    }
    int mid=(l+r)/2;
    buildSegmentTree(2*i+1,l,mid,nums);
    buildSegmentTree(2*i+2,mid+1,r,nums);
    segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
}
    NumArray(vector<int>& nums) {
        n=nums.size();
        segmentTree.resize(4*n);
        buildSegmentTree(0,0,n-1,nums);   
    }
    void updateQuery(int ind,int val,int i,int l,int r){
        if(l==r){
            segmentTree[i]=val;
            return;
        }
        int mid=(l+r)/2;
        if(ind<=mid){
            updateQuery(ind,val,2*i+1,l,mid);

        }else{
            updateQuery(ind,val,2*i+2,mid+1,r);
        }
        segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
    }
    
    void update(int index, int val) {
       updateQuery(index,val,0,0,n-1);    
    }
    int sumQuery(int start,int end,int i,int l,int r){
        int mid=(l+r)/2;
        if(l>end || r<start){
            return 0;
        }
        if(l>=start && r<=end){
            return segmentTree[i];
        }
        else{
            return sumQuery(start,end,2*i+1,l,mid)+sumQuery(start,end,2*i+2,mid+1,r);
        }
    }

    
    int sumRange(int left, int right) {
        return sumQuery(left,right,0,0,n-1);   
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n=apple.size();
        int m=capacity.size();
        sort(capacity.begin(),capacity.end());
        int count=0;
        int sa=0;
        for(int i=0;i<n;i++){
            sa+=apple[i];
        }
        int j=m-1;
        while(sa>0 && j>=0){
            int bas=capacity[j];
            sa=sa-bas;
            count++;
            j--;
        }
        if(j>=-1){
            return count;
        }
        return -1;
        
        
    }
};
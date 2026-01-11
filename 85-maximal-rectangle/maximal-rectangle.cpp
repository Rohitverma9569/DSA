class Solution {
    private:
    vector<int> prevSmallerElement(vector<int>heights,int n){
        stack<int> st;
        vector<int> leftSmaller(n);
        for(int i=0;i<n;i++){
            if(st.empty()){
                
                leftSmaller[i]=-1;
            }
            else{
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
             }
             leftSmaller[i]=st.empty()?-1 :st.top();
            }
            st.push(i);
        }
        return leftSmaller;
        }
    vector<int> nextSmallerElement(vector<int>& arr,int n){
        vector<int> result(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                result[i]=n;

            }
            else{
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }
                result[i]=st.empty()? n :st.top();

            }
            st.push(i);
        }
        return result;        
    };
    int largestRectangleArea(vector<int>& heights,int n) {
       vector<int> next(n);
        next=nextSmallerElement(heights,n);
        vector<int>prev(n);
        prev=prevSmallerElement(heights,n);
        int area=INT_MIN;
        for(int i=0;i<n;i++){
           int l=heights[i];
           int b=next[i]-prev[i]-1;
           int newArea=l*b;
           area=max(area,newArea);
        }
        return area;       
    };
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() ||  matrix[0].empty()) return 0;
        int n=matrix.size();
        int m=matrix[0].size();
        int maxArea=0;
        vector<int> heights(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    heights[j]++;
                }
                else{
                    heights[j]=0;
                }
            }
            maxArea=max(maxArea,largestRectangleArea(heights,m));
        }
        
        return maxArea;

        
    }
};
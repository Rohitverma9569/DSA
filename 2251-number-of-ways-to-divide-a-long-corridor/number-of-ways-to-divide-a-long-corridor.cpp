class Solution {
public:
    int numberOfWays(string corridor) {
       int n=corridor.size();
       int count=0;
       const int mod=1e9+7;
       vector<int>seats;
       for(int i=0;i<n;i++){
        if(corridor[i]=='S'){
            count++;
            seats.push_back(i);
        }
       }
       if(count==0 || count%2!=0){
        return 0;
       }
       
       int prev_seat=seats[1];
       long long ans=1;
       for(int i=2;i<count;i+=2){
        int curr=seats[i];
        int m=curr-prev_seat;
        ans=(ans*m)%mod;
        prev_seat=seats[i+1];
       }
       return ans;



        
    }
};
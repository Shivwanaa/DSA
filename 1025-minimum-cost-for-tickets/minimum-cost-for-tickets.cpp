class Solution {
public:

vector<vector<int>>dp;
    int check(vector<int>& days, vector<int>& costs,int i,int cd){
        while(i<days.size() && days[i]<=cd){
            i++;
        }
        if(i>=days.size()){
            return 0;
        }
        if(dp[i][cd]!=-1){
            return dp[i][cd];
        }

        int day1=costs[0]+check(days,costs,i+1,days[i]);
        int day7=costs[1]+check(days,costs,i+1,days[i]+6);
        int day30=costs[2]+check(days,costs,i+1,days[i]+29);
        return dp[i][cd]= min({day1,day7,day30});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp=vector<vector<int>>(days.size()+1,vector<int>(days[days.size()-1]+1,-1));
        return check(days,costs,0,0);
    }
};
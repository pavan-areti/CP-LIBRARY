    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back({intervals[0][0],intervals[0][1]});

        for(int i=1;i<intervals.size();i++){
            int start = ans.back()[0];
            int end = ans.back()[1];
            if(intervals[i][0]<=end){
                if(intervals[i][1]<=end){
                    continue;
                }
                else{
                    ans.pop_back();
                    ans.push_back({start,intervals[i][1]});
                }
            }
            else{
                ans.push_back({intervals[i][0],intervals[i][1]});
            }
        }
        return ans;
    }

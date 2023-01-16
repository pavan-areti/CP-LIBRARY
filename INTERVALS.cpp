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

// online insertion in o(n) when already non overlapping and sorted;
   vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> res;
        //case 1: no overlapping case before the merge intervals
		//compare ending point of intervals to starting point of newInterval
        while(i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }                           
        if(i<n)newInterval[0] = min(newInterval[0], intervals[i][0]);
		//case 2: overlapping case and merging of intervals
        while(i < n && newInterval[1] >= intervals[i][0]){
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        // case 3: no overlapping of intervals after newinterval being merged
        while(i < n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }

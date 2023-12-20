// populating the range
vector<long long int> generate(vector<int> &nums){
   int n = nums.size();
   vector<long long int> preSum(n, nums[0]);
   for (int i = 1; i < n; i++)
   {
     preSum[i] = preSum[i - 1] + nums[i];
   }
  return preSum;
}

//get range sum
long long sum(int i, int j, const vector<long long> &preSum)
{
  if (i == 0)
        return preSum[j];
  return preSum[j] - preSum[i - 1];
}

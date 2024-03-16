when we solve tabulation dp problems we often optimise the space complexity by reducing the dimensions of the dp array, Here are few observatios related to that

### Combination
when we want combinations we dont care about the ordering so we will put the adding value in the outer loop, so all instances of that element will come at once.

### Permutation
when we want permutation, we care about the order, we put the adding value in the inner loop.

### 0/1 
in this kind of problems we have to take each element only once, so we will iterate from the end, so when  we dp[j] , dp[j-k](k>0) will be from i-1th row.

### unbound knapsack
in this kind of problem we can use the same element many times so we iterate from the start, suppose 3 is a value that is included to make a sum of 6, same can be used for 9 also. so if we use dp[6] it will contain the current iteration value.

### when its required to do with exactly n elements
In this kind of problem we cant use the previous dp[i-1] vlaues directly for dp[i], as previous one is created with i-1 values. so we need to create a new empty array and then we can use the previous row as per the requirements.

### when using memoisation to do the dp
In this case when some state is present think whether all things comes to this state are same or we want them to be different, if we want them to be different return the summations instead using the dp to check if the state is visited or not.

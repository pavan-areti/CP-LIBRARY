- In a monotonic stack if we are moving from the right then that means we are putting only the elements greater than or less than from 
right side in the stack
- If we are retaining the greater ones then we will be popping the less than's, so the condition will be s.top()<current then remove.
same for the other side as well

- One more observation is that when we are leaving the greater thans in the stacks, the stack will contain the asc order numbers
- You will be popping till we find the greater element, so the count of popped elements will be equal to the number of ascending
elements till the number which is greater than h[ i ]
- So when we pop some element, all the elements between the h[i] and the element being popped are less than both the values.
because the being popped element is in the stack because no other element till now is greater than that.

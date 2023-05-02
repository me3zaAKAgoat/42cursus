<h1 align="center">Push_Swap Algorithm </h1>

- Retrive the Longest Increasing Subsequence (LIS).
- Any number that isn't part of the LIS should be pushed to **STACK_B**.
- Iterate through the numbers in **STACK_B**.
  - Calculate the number of moves it would take on each stack to have the numbers put in their correct place.
    > ```
    > 1- It’s between stack_A[size_of_stack_A - 1] and stack_A[0]. [2,
    > 3] (You only need to check this once).
    > (2- It’s between stack_A[i] and stack_A[i + 1]. [3, 8]. i starting
    > from 0 to <size_of_stack_A / 2>, in our case, size_of_stack_A =
    > 6).
    > 3- It’s between stack_A[j] and stack_A[j - 1]. [1, 2], j going from
    > <size_of_stack_A - 1> to <size_of_stack_A / 2>.
    > 4- None of the above. In this case, the number is the maximum of
    > both stacks. Here we have to find the position of the maximum
    > number of stack A(which is index 3, position of ‘9’ in our
    > example), that’s where ‘10’ needs to be placed.
    >
    > ```
- Evaluate which number has the smallest sum of the absolute value of moves needed in both stacks.
- Move that number to **STACK_A**.
  **since ra rra rb rrb are the moves we use to put each number in its correct place, we can use rr and rrr whenever theres a an equal number of similarly signed number of moves that should be made on both stacks**
- Repeat untill **STACK_B** is empty.

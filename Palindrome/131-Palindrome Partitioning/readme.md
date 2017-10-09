# palindrome partitioning

Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

## solution
The idea is as follows:\
a. We store temporary partitioning results for the part we have already checked, and move on to the rest of the string;
b. We need to check all possible ways of getting a palindrome containing the first char in the left string; every time we find that palindrome,
we add this palindrome to the stored results, and do the same work for the rest string;


Hence, we can create a recursive function to do the work. It takes as input the original string, starting point and temporary results vector.
Starting from the starting index, we go through all possible length of substring and check if it's a palindrome. If so, we would do some work
including manipulating temporary results vector and calling this function recursively.


See details in codes.

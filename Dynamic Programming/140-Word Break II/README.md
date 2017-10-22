Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

Return all such possible sentences.

For example, given
```
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].
```
A solution is ```["cats and dog", "cat sand dog"]```.

## Idea 1
One way of doing this is to use recursion. Think about it, you start from the beginning of the string, and check the first char to see if
it's in the dict. If so, we save this into a temporary string, and for the rest of the string, we call the recursive function. If not, we move
to the next character and check substring from the first element to this emelent.

Now we can see this recursive function should take as input:
* string s
* wordDict
* a temporary string to store word breaks so far
* a pointer indicating where do we need to start the substring

Inside the recursive function is a for loop, starting from the pointer and to the end of the string. Each iteration we do the following:
* construct the substring we want to find
* find if it's in the wordDict
* if we can find this substring in the dictionary, we then add this substirng to the temporary result, and call this recursive function with
pointer pointing to the position where the substring we add ends + 1.

However, this recursive would turn out to be TLE. One way to getting rid of this TLE is to check if there exists a break or not. Only if there
is a break would we do the word break.

## Idea 2
Another is DP. Samely, we let dp[i] be a vector<string> to store the break of the substring [0,1, ..., i]. We also need a ```vector<int> 
found``` to store the position where the substring can be broken into several words to expedite the construction. The whole DP works in a single
for loop iterating the whole string.

In this loop, we do the following:
* if ```found``` is not empty, we then have to check each case, namely for each successfully reconstructed substring in the found, we extract the substring that is not included, and check 
if this last substring is in the wordDict. If so, we have to create the new substring, and add it to dp[i]
* also, we have to check if the substring [0,1,...,i] is existent in the wordDict. If it is existent, we add it to dp[i] as well.

Finally, our answer is stored at the end of the last element of dp, which is a vector<string>.

Again, this approach would have MLE problem. One way of tackling this is to add a judgement first as well.

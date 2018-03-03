# Problem
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
```
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
```
Note: Each word is guaranteed not to exceed L in length.

## Idea
The idea is common, simply run greedy algorithm and keep monitoring the length. Every time we cannot add more words in one 
line, stop and take care of this current line.

When we create the text for the current line, we need to divide the problem into different cases:

* case 1: we reach the end of the words __OR__ there's only one word in the line: 

in this case, we follow the left justification. Namely, put words as left as possible and pad " " at the end if needed.

* case 2: we have several words to concatenate and this is not the last line:

in this case, we follow the left and right justification rule. Thus, computing the spaces between words are crucial. What needs
to be mentioned is that the spaces on the left would be more than the right ones if we cannot divide them evenly. Here we need 
residuals to help us: simply using __%__ calcualtion to find how many left blanks need to have more spaces than others.

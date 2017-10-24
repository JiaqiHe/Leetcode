# Problem
Sort a linked list in O(n log n) time using constant space complexity.

## Idea
This problem looks very very intimidating to me, even though I know using mergesort is the way.

So let's implement it step by step!

* Step 1: Split the whole linked list into two approximately equal-length sublists
Ok, for this goal, we can use one classic approach that is quite commonly used when solving linked lists problems: we create two pointers, one
is called `fast`, and the other `slow`. Just as the names imply, `fast` pointer goes fast by two elements each time, and `slow` pointer only
goes by one element each time. While it is allowed for `fast` pointer to go two elements further, we would update these two pointers. So the 
end condition is that `fast` pointer can no longer go further, either there is one or no element ahead of it.

Then, where the `slow` pointer currently stands is the ideal end point of the first half of the list.

We then can extract the second half of the list, and this list's head is: `slow->next`.

How to extract the first half? Here is the trick: just get rid of the second half! So we set `slow->next = NULL` and we get the first half with head `head`.

* Step 2: Sort two sublists
This is so easy because we have the function `sortList` and we are implement it right now, after we are done, this function shall work just fine! Just call this function and save the sorted answer to 
some new pointers, say `first` and `second`. 

* Step 3: Merge two sorted sublists
Now we have two sorted sublists, we have to merge into one long whole list. We can do the following:

Every time we select the smaller element between `first` and `second`, add it to the answer. And as we have chosen one element, the sublist that has been
taken one element should update its head pointer by going to the next element. Keep doing so until at least one sublist is empty. If there is one
sublist whose head doesn't point to `NULL`, it means we haven't connected them to the whole list, then add it to the end of the result, and we
are done!

To sum up, each step is not that hard as imagined, but this problem does integrate several techniques together, good problem!

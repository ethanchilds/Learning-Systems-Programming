Working through primary linked list functions on my own, so this look like a naive solution at the moment.

The particular functions I would like to work through are:
-[x] insert()
-[x] pushback()
-[x] pushfront()
-[] delete()
-[] popback()
-[] popfront()
-[] reverse()

## Thoughts as of 11/12/26

I messed around for a bit thinking about how I would implement this. I originally had the pop and push functions made unique to their functionality and I was using a tail pointer, however, after some thought, when I came back to finish what I was working on, I decided to remove the tail pointer in favor of making the push functions both special cases of one insert function.

Obviously, any optimized linked list should consider the tail pointer, but I prefer the style of having push and pop functions serving as special cases of insert and delete, rather than completely unique functions.

I completed the insert functions and will finish the delete functions tomorrow, but I would very much like to implement linked list reversal in C as it is something I have done before in python, but not C.


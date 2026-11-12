Working through primary linked list functions on my own, so this look like a naive solution at the moment.

The particular functions I would like to work through are:
- [x] insert()
- [x] pushback()
- [x] pushfront()
- [x] delete()
- [x] popback()
- [x] popfront()
- [x] reverse()

## Thoughts as of 11/11/26

I messed around for a bit thinking about how I would implement this. I originally had the pop and push functions made unique to their functionality and I was using a tail pointer, however, after some thought, when I came back to finish what I was working on, I decided to remove the tail pointer in favor of making the push functions both special cases of one insert function.

Obviously, any optimized linked list should consider the tail pointer, but I prefer the style of having push and pop functions serving as special cases of insert and delete, rather than completely unique functions.

I completed the insert functions and will finish the delete functions tomorrow, but I would very much like to implement linked list reversal in C as it is something I have done before in python, but not C.

## Thoughs as of 11/12/26
Today I completed the functions I wanted to do with the implementation of `delete()`, its pop derivatives, and the `reverse`. Nothing too exciting to report on the implementation of these. For `delete()` and its derivatives, they are implemented as I said, with `popback()` and `popfront()` being special cases of the delete function. In order to deal with error handling, these functions require a passed in `int` to contain the popped value, giving us the ability to return status codes instead of a popped element.

`reverse()` ended up being incredibly simple and actually not really different from the python implementation I've done before, just flipping pointers and maintaining the next value carefully.

In implementing this code, I realized my talk about the tail pointer forcing us to not have `push` and `pop` functions act as derivatives of `insert()` and `delete()`, was completely false. I would simply need to wire these functions to make use of the tail pointer based on the index provided, which is essentially how I am handling the `0` index already, so the code for this would actually not be very complicated. However, I probably won't be implementing this feature for now, and I will stick with the singly linked list without a tail pointer.

A couple of things I am interested in coming back to this directory for:
- [] Making the functionalities of this program type agnostic.
- [] Proper testing implemented in C. Just like the dynamic array, I am still not sure what this will look like.
- [] Investigating other implementations of this data structure in C. I am sure the optimal solution exists or some more considerations can be made to have better code, but I will need to do some research for this.



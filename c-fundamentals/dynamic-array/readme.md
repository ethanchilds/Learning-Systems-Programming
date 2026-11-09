Working through primary array functions on my own, so the solutions may be a bit naive for now.

In particular I want to work:
- [x] append()
- [x] insert()
- [x] delete()
- [x] pop()
- [x] remove()
- [x] resize()


## Thoughts as of 11/7/26
Currently I would like to mark off resize, but it needs to be refactored for downsizing as well as upsizing.

I would also like to rework insert and append because it is currenty the case that insert is a a special case of append, but append should be a special case of insert.

## Thoughts as of 11/8/26

Completed the major implementation pieces of  dynamic array. With `append()` and `pop()` acting as special cases of `insert()` and `delete()` respectively, both of those functions become incredibly simple.

Today I had to consider what returns would like for functions in C and I am still not super happy with what I did, but it works for now. Originally, I had decided to return the same pointer pointing to the passed in array for most functions as I had read that was the standard for functions in `<stdlib.h>`, but I quickly realized I need to be more expressive with my return statements when implementing `pop()`. This function in particular challenged me in that I needed to return an `int` value, but the function was calling `downsize()` which originally returned `NULL` in case of failure and I had to differentiate between an index failure and a memory reallocation failure, so I landed on returning status codes and filling an int with the pooped element.

With `insert()` and `delete()` completed, I believe any other array functionalities would be quite trivial, so I am not going to implement them at this moment.

A couple things I am interested in coming back for:
- [] Making the functionalities type independent, adjusting to however `dynamicArray` is initialized.
- [] Proper testing and what that looks like in C, I am not too sure yet.
- [] Considering implementations done by C pros. I am sure dynamic array implementation is a mostly solved problem as far as best practice goes and I would like to see what that looks like.

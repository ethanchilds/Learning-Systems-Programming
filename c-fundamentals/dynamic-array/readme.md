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

## Thoughts at the beginning of 11/20/26
As I was digging into implementations of hash tables, I made the realization that I would actually like to be able to use the data structures that I am creating. While what I have created so far does allow me to include my dynamic array code in any file, I am going to have to remember both the initialization convention that I used when writing this code and need code that works for different types.

Technically, the initialization convention doesn't matter too much as it is two lines of code, however, I would personally prefer a function that simply creates a dynamic array and returns a pointer that I can then apply helper functions to. In the previous implementation of this data structure, my worry was not about the interface of my code, but understanding how the code worked under the hood, so this code is not built for external use by nature. I would like to revist this code with a focus on interface.

Another consideration I have for interface design is generic data structures, which I realize isn't a simple discussion in C. I do not have any desire to implement code that has `float_array`, `string_array`, `int_array`, etc. I want a single dynamic array, that is type flexible, but also type safe, so I am going to be working based on the following article: [Type Safe Generic Data Structures in C](https://danielchasehooper.com/posts/typechecked-generic-c-data-structures/). 

## Thoughts at the end of 11/20/26
Today did not go at all how I planned. I spent most my time trying to understand code and I think I really only half got it. I spent quite a bit of time with the following resources trying to implement the type-agnostic dynamic array:
- [Tsoding's video on the header technique and using macros for type generality](https://www.youtube.com/watch?v=gtk3RZHwJUA)
- [stb_ds, which seems to be a gold standard library as far as interface works](https://github.com/nothings/stb/blob/master/stb_ds.h)
- [This repo which seems to follow in the footsteps of stb_ds](https://github.com/eignnx/dynarray/tree/master)

Part of went wrong today is that I am really not confident in the code I produced, and I used AI to try to bridge that gap to what feels like resounding failure. The goal of this work is to become strong in a systems programming language and my confidence in what I produced reflects the progress I made towards that goal.

Tomorrow I would like to spend more time with Tsoding's youtube video to try and better understand everything I am doing and WHY I am doing it, but for now, I have a passable interface for type-agnostic dynamic arrays. I would also like to ensure that type-saftey is a priority in this code tomorrow.

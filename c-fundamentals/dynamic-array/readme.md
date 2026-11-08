Working through primary array functions on my own, so the solutions may be a bit naive for now.

In particular I want to work:
- [] size()
- [] capacity()
- [] is_empty()
- [x] append()
- [x] insert()
- [] delete()
- [] pop()
- [] remove()
- [] resize()


## Thoughts as of 11/7/26
Currently I would like to mark off resize, but it needs to be refactored for downsizing as well as upsizing.

I would also like to rework insert and append because it is currenty the case that insert is a a special case of append, but append should be a special case of insert.

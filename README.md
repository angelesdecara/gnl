# gnl

## Things that need checking

This markdown gives errors in fsoares tests. However, the moulinette hasn't found them.

I had some fantastic reviewers that told me
1. check all calloc, malloc and read are protected and if fail, free everything before returning NULL
2. don't set a pointer to NULL, as is currenty done in this version in get_next_line.c in line 24.
I should have just freed it and that would be it.

I got the feeling maybe my ft_calloc is not 100% leak free.

Let's now try minitalk!


# Working on gnl

* idea:
	read buffer size
	search up to newline or end of string
	 -> store remainer (leftover of buffer size - line ) in static variabe
	 -> return line (with remainer before if it exists)

* Done with:
  -> allocate with calloc a string of size buffer size; check if allocation has worked
  -> subsubstr(buffer, remainer) allocates line, joins remainer if exist to line, allocates remainer and fills it and returns line (combined with function saveremain)

* Issues:
  -> when printing out with write is printing whole line (that was compiling with -DBUFFER_SIZE=42)
  -> when compiling with DBUFFER_SIZE=2 or small I only get those characters, so not joining

 * Ideas?
  -> Thinking of first calling saveremain so that reads buffer and if there's end of line, separate
  -> Or use ft_strchr to see if buffer contains eol or end of string:
  		+ if yes, separate in return + remain
		+ if not, remain = buffer

  * WORKING!! but need to normineet it and test it!

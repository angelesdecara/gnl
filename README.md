
# Working on gnl

* 25/02/2023
  -> altnl not working, cuts line short => shall we append \n to remainer?

* idea:
	read buffer size
	search up to newline or end of string
	 -> store remainer (leftover of buffer size - line ) in static variabe
	 -> return line (with remainer before if it exists)

* Done with:
  -> allocate with calloc a string of size buffer size; check if allocation has worked
  -> subsubstr(buffer, remainer) allocates line, joins remainer if exist to line, allocates remainer and fills it and returns line (combined with function saveremain)

* Issues:
  -> added _if_ at beginning when there was remainer read and contained end of line  
  -> plenty of leaks, code pushed, let's break into functions?
  -> do we need to free str?
  -> checking with alternate nl file, and whether I need more space on remain?

 * Ideas?
  -> Thinking of first calling saveremain so that reads buffer and if there's end of line, separate
  -> Or use ft_strchr to see if buffer contains eol or end of string:
  		+ if yes, separate in return + remain
		+ if not, remain = buffer
 * Adding function to use in lines 4-6 (while remainer != \n) and later in if remainer, lines 60-65 
   + lines 4 to 6 are:
         i = 0;
        while (remainer[i] != '\n')
            i++;
        str = ft_calloc(i + 2, sizeof(char));
        ft_strlcpy(str, remainer, i + 1);
        str[i] = '\n';
      
   + lines 60 to 65 are:
     i = 0;
        while (line[i] != '\0' && line[i] != '\n')
            i++;
        str = ft_calloc(ft_strlen(remainer) + i + 2, sizeof(char));
        ft_strlcpy(str, remainer, ft_strlen(remainer) + 2);

 * Issues with leaks, seems to be in else that finishes in line 56 (ft_bzero). Wondering if should remove the bzero and free line there 
 * Issues with end of files or one line with no end of line: doesnt return null, returns empty

 * Reunderstanding the logic of my gnl:
 	1/ allocate to buffer number of reading chars; if reading wrong, return null
	2/ if the remainer included a \n, then dont read any more as we had read more than one line. Return from remainer.
	3/ if not, then read 

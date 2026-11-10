`streamstat` is a simple command line utility which reads a file or standard input and reports:
- Total number of bytes.
- Total number of words.
- Total number of newline characters.

This should work on ordinary and binary files:
```bash
$ ./streamstat example.txt
```

and should also accept standard input:

```bash
$ cat example.txt | ./streamstat -
```

so, this program will only accept one argument: either a file path or `-`.

This is essentially `wc` in Linux.

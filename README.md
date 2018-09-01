# ClipThat
A Windows CLI app which takes input and copies it to your clipboard.

***Please bear with me, this is the very first app I've ever written in C++.***

[Download it here](https://github.com/xDrixxyz/ClipThat/releases/latest)

Input can be provided in 1 of 2 ways:

- Via command-line arguments to the ClipThat executable.
- Piping the output of another app into the ClipThat executable's stdin using the Windows pipe character (`|`).

ClipThat will then clear the current contents of your clipboard, take the input, and copy it's contents into your clipboard.

*Note: It is **HIGHLY** recommended that you put ClipThat in your PATH environment variable if you want to have easy access to it.*

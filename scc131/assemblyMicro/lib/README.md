This directory contains some initialisation code and linker configuration. A lot of the code and
constructs will be taught eventually, so you might not understand everything at first.

Don't add anything here, put your own source files in the src folder.

## link.ld

This file tells the linker how to lay out all the `.text` and `.data` sections on the board. This one tells
the linker to concatenate all these sections together and store them in flash memory. It is also responsible
for ensuring the vector table gets put in the correct location in memory.

Some of these memory location details are exposed as constants the assembly code can use. For example, the
startup script uses the `_stack_end` variable to initialise the stack pointer register.

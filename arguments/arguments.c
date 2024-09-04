#include <stdio.h>


/*
    ArgC: argument count
    Argv: argument vector

    Example:

    $ ./arguments "Hello World"
    
    will output

    There are 2 arugments to this process.
    The argument #0 is "./arguments"
    The argument #1 is "Hello World"
*/
int main(int argc, char **argv) {
    printf(
        "There are %d arguments to this process.\n",
        argc
    );

    for (int i = 0; i < argc; i++) {
        printf(
            "The argument #%d is \"%s\"\n",
            i,
            argv[i]
        );
    }

    return 0;
}
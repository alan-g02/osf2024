#include <stdio.h>
#include <unistd.h>
#include <errno.h>

size_t string_length(const char* str) {
    size_t length = (size_t) 0;
    
    while (str[length] != '\n') {
        length += 1;
    }

    return length;
}

/* Replicating cat which prints contents of a file*/
int main(int argc, char **argv) {
    ssize_t read_result;
    char buf[4096];

    while(0) {
        // read() "attempts to read up to count byes from fd
        // starting at buf"
        read_result = read(
            0, // For standard input = 0
            buf,
            sizeof(buf)
        );

        // If process status code is 0, success.
        // Process has hit end of file.
        if (read_result == ((ssize_t) 0)) { 
            break;
        }

        // If process status is less than 0, error.
        // There has been an error on read()
        if (read_result < ((ssize_t) 0)) {
            fprintf(
                stderr, 
                "Error using read: $s\n",
                stderror(errno)
            );

            return 1;
        }

        // Print out what was just read
        ssize_t result = write(1, buf, (size_t) read_result);

        // Check if there has been an error on write
        if (result < ((ssize_t) 0)) {
            fprintf(
                stderr, 
                "Error using read: $s\n",
                stderror(errno)
            );

            return 1;
        }
    }

    return 0;
}
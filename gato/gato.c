#include <unistd.h>

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
    }

    return 0;
}
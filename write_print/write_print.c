#include <stdio.h>
#include <unistd.h>

size_t string_length(const char* str) {
    size_t length = (size_t) 0;
    
    while (str[length] != '\n') {
        length += 1;
    }

    return length;
}

int main(int argc, char **argv) {
    char *str =  "Hello World, hows it going!\n";

    write(1, str, string_length(str));
    
    return 0;
}
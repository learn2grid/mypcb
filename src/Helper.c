/*
MIT License

Copyright (c) 2020 Lee Choon Siong

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "Helper.h"

int set_homedir(void) {
    struct passwd *pw = getpwuid(getuid());
    assert(pw != NULL);
    
    return (chdir(pw->pw_dir));
}

void print_usage_and_exit(void) {
    fprintf(stderr, "Usage: my_pcb YEAR MONTH PCB_AMOUNT\n");
    fprintf(stderr, "\n\tYEAR         from %d to %d\n", MIN_YEAR_RANGE, MAX_YEAR_RANGE);
    fprintf(stderr, "\tMONTH        from 1 to 12\n");
    fprintf(stderr, "\tPCB_AMOUNT   from 0 (0.00) to %d (%d.00)\n", MAX_PCB, MAX_PCB/100);
    fprintf(stderr, "\n\te.g.\n\t PCB for 2018 Jan is $1234.56, so enter:\n\t my_pcb 2018 01 123456\n");
    
    exit(1);
}

bool validYear(int year) {
    if (year >= MIN_YEAR_RANGE && year <= MAX_YEAR_RANGE) {
        return true;
    }
    
    return false;
}

bool validMonth(int month) {
    if (month >= 1 && month <= 12) {
        return true;
    }
    
    return false;
}

bool validPCB(const char *value) {
    char *temp = (char *)calloc(1, sizeof(strlen(value))+ 1);
    temp = (char *)value;

    // Numbers only
    while (*temp != '\0') {
        if (!isdigit(*temp)) {
            return false;
        }
        
        temp++;
    }
    
    int number = atoi(value);
    
    // Make sure valid within acceptable range
    if (number < MIN_PCB || number > MAX_PCB) {
        return false;
    }
    
    return true;
}

char *left_padding(int count, const char *ch, const char *value) {
    char *str = (char *)calloc(1, sizeof(strlen(value)) + count);
    *str = *((char *)ch); // assign first padding character
    
    // start with i = 1 because of above assignment
    for (int i = 1; i < count; ++i) {
        strcat(str, ch);
    }
    
    strcat(str, value);
    
    return str;
}

char *right_padding(int total_size, const char *ch, const char *value) {
    // Allocate enough space for the string plus padding character and NUL
    char *str = (char *)calloc(1, total_size + 1);
    
    // Number of padding character required
    size_t count = total_size - strlen(value);
    
    strlcpy(str, value, total_size - count + 1); // + 1 for NUL    
    
    for (size_t i = 0; i < count; ++i) {
        strcat(str, ch);
    }
    
    return str;
}

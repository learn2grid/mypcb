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

#ifndef Helper_h
#define Helper_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <pwd.h>
#include "PCBFile.h"

#define MIN_YEAR_RANGE 1970
#define MAX_YEAR_RANGE 2040
#define MIN_PCB 0
#define MAX_PCB 1000000

extern int set_homedir(void);
extern void print_usage_and_exit(void);

extern bool validYear(int);
extern bool validMonth(int);
extern bool validPCB(const char *);

extern char *left_padding(int, const char *, const char *);
extern char *right_padding(int, const char *, const char *);

#endif /* Helper_h */

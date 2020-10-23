/*
	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	A program to generate data file for PCB submission.
	
	Copyright (C) 2018 Lee Choon Siong
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
#define MAX_YEAR_RANGE 2020
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

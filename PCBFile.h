/*
	Copyright (C) 2018 Lee Choon Siong

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	A program to generate data file for PCB submission.
	
	by lcs
*/

#ifndef PCBFile_h
#define PCBFile_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <setjmp.h>
#include "Helper.h"
#include "PCBData.h"

extern char *data_line1;
extern char *data_line2;

extern void read_data_file(void);
extern void generate_data(const char *year, const char *month, const char *total_mtd_amount, const char *mtd_amount);
extern void write_data_file(const char *line1, const char *line2);

#endif /* PCBFile_h */

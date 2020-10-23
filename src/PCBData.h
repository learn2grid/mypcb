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


#ifndef PCBData_h
#define PCBData_h

#include <stdio.h>
#include <stdlib.h>

struct PCBData {
    /*
     Remember to allocate memory space for pointers below!
     */
    
    // With 1 byte for NUL
    char employer_record_type[2]; // H - 'Header'
    char employer_number_1[11]; // right justify with zero padding
    char employer_number_2[11]; // right justify with zero padding
    char *year_of_deduction; // YYYY
    char *month_of_deduction; // 01 - 12
    char *total_mtd_amount; // right justify with zero padding and two decimal points
    char total_mtd_record[6]; // right justify with zero padding
    char total_cp38_amount[11]; // right justify with zero padding and two decimal points
    char total_cp38_record[6]; // right justify with zero padding
    char transaction_record_type[2]; // D - 'Detail'
    char tax_reference_no[11]; // right justify with zero padding
    char wife_code[2]; // 0 - 9
    char employee_name[61]; // left justify with spaces
    char old_ic_no[13]; // leave blank if not applicable
    char new_ic_no[13]; // leave blank if not applicable
    char passport_no[13]; // leave blank if not applicable (left justify)
    char country_code[3]; // refer to country code list
    char *mtd_amount; // right justify with zero padding and two decimal points
    char cp38_amount[9]; // right justify with zero padding and two decimal points
    char employee_no[11]; // left justify
};

extern struct PCBData *new_pcbdata(void);
extern void print_pcb_data(const struct PCBData *pcb_data);

#endif /* PCBData_h */

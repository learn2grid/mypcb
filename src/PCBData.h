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

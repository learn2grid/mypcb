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

#include "PCBData.h"

struct PCBData *new_pcbdata(void) {
    struct PCBData *ptr_pcbdata;
    ptr_pcbdata = (struct PCBData *)calloc(1, sizeof(struct PCBData));
    
    if (ptr_pcbdata == NULL) {
        fprintf(stderr, "Out of memory!\n");
        exit(1);
    }
    
    return ptr_pcbdata;
}

void print_pcb_data(const struct PCBData *pcb_data) {
    printf("Record Type: '%s'\n", pcb_data->employer_record_type);
    printf("Employer Number 1: '%s'\n", pcb_data->employer_number_1);
    printf("Employer Number 2: '%s'\n", pcb_data->employer_number_2);
    printf("Year of Deduction: '%s'\n", pcb_data->year_of_deduction);
    printf("Month of Deduction: '%s'\n", pcb_data->month_of_deduction);
    printf("Total MTD Amount: '%s'\n", pcb_data->total_mtd_amount);
    printf("Total MTD Record: '%s'\n", pcb_data->total_mtd_record);
    printf("Total CP38 Amount: '%s'\n", pcb_data->total_cp38_amount);
    printf("Total CP38 Record: '%s'\n", pcb_data->total_cp38_record);
    printf("Transaction Record Type: '%s'\n", pcb_data->transaction_record_type);
    printf("Tax Reference No.: '%s'\n", pcb_data->tax_reference_no);
    printf("Wife Code: '%s'\n", pcb_data->wife_code);
    printf("Employee Name: '%s'\n", pcb_data->employee_name);
    printf("Old IC No.: '%s'\n", pcb_data->old_ic_no);
    printf("New IC No.: '%s'\n", pcb_data->new_ic_no);
    printf("Passport No.: '%s'\n", pcb_data->passport_no);
    printf("Country Code: '%s'\n", pcb_data->country_code);
    printf("MTD Amount: '%s'\n", pcb_data->mtd_amount);
    printf("CP38 Amount: '%s'\n", pcb_data->cp38_amount);
    printf("Employee No.: '%s'\n", pcb_data->employee_no);
}

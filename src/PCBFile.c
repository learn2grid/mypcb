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


#include "PCBFile.h"

#define PCB_CONF_FILE "mypcb.conf"

#define RECORD_1_SIZE 58
#define RECORD_2_SIZE 137

static jmp_buf readJump;
static jmp_buf writeJump;

char *data_line1;
char *data_line2;

static struct PCBData *ptrPCB;

static const char *data_file_name(void) {
    char *file_name = (char *)calloc(1, 15);
    strlcpy(file_name, "PCB_", 5);
    strcat(file_name, ptrPCB->year_of_deduction);
    strcat(file_name, ptrPCB->month_of_deduction);
    strcat(file_name, ".txt");
    
    return file_name;
}

static bool read_one_field(FILE *fp, const char *scan_format, void *var_ptr) {
    int scan_result = fscanf(fp, scan_format, var_ptr);
    
    if (scan_result == 1)
        return true;
    
    if (scan_result == EOF)
        return false;
    
    longjmp(readJump, errno);
}

static struct PCBData *read_struct_from_file(FILE *fp) {
    assert(fp != NULL);
    
    struct PCBData *ptr_pcb = new_pcbdata();
    
    if (!read_one_field(fp, "%[^\n]\n", ptr_pcb->employer_record_type))
        return NULL;
    
    if (!read_one_field(fp, "%[^\n]\n", ptr_pcb->employer_number_1))
        return NULL;
    
    if (!read_one_field(fp, "%[^\n]\n", ptr_pcb->employer_number_2))
        return NULL;
    
    ptr_pcb->year_of_deduction = (char *)calloc(1, 5);
    
    if (!read_one_field(fp, "%[^\n]\n", ptr_pcb->year_of_deduction))
     return NULL;
    
    ptr_pcb->month_of_deduction = (char *)calloc(1, 3);
    
    if (!read_one_field(fp, "%[^\n]\n", ptr_pcb->month_of_deduction))
     return NULL;
    
    ptr_pcb->total_mtd_amount = (char *)calloc(1, 11);
    
    if (!read_one_field(fp, "%[^\n]\n", ptr_pcb->total_mtd_amount))
     return NULL;
    
    if (!read_one_field(fp, "%[^\n]\n", ptr_pcb->total_mtd_record))
        return NULL;
    
    if (!read_one_field(fp, "%[^\n]\n", ptr_pcb->total_cp38_amount))
        return NULL;
    
    if (!read_one_field(fp, "%[^\n]\n", ptr_pcb->total_cp38_record))
        return NULL;
    
    if (!read_one_field(fp, "%[^\n]\n", ptr_pcb->transaction_record_type))
        return NULL;
    
    if (!read_one_field(fp, "%[^\n]\n", ptr_pcb->tax_reference_no))
        return NULL;
    
    if (!read_one_field(fp, "%[^\n]\n", ptr_pcb->wife_code))
        return NULL;
    
    if (!read_one_field(fp, "%[^\n]\n", ptr_pcb->employee_name))
        return NULL;
    
    if (!read_one_field(fp, "%[^\n]\n", ptr_pcb->old_ic_no))
        return NULL;
    
    if (!read_one_field(fp, "%[^\n]\n", ptr_pcb->new_ic_no))
        return NULL;
    
    if (!read_one_field(fp, "%[^\n]\n", ptr_pcb->passport_no))
        return NULL;
    
    if (!read_one_field(fp, "%[^\n]\n", ptr_pcb->country_code))
        return NULL;
    
    ptr_pcb->mtd_amount = (char *)calloc(1, 9);
    
    if (!read_one_field(fp, "%[^\n]\n", ptr_pcb->mtd_amount))
     return NULL;
    
    if (!read_one_field(fp, "%[^\n]\n", ptr_pcb->cp38_amount))
        return NULL;
    
    if (!read_one_field(fp, "%[^\n]\n", ptr_pcb->employee_no))
        return NULL;
    
    return ptr_pcb;
}

void read_data_file(void) {
    FILE *fp = NULL;
    int error;
    
    if ((error = setjmp(readJump)) == 0) {
        if ((fp = fopen(PCB_CONF_FILE, "r")) == NULL) {
            longjmp(readJump, errno);
        }
        
        ptrPCB = read_struct_from_file(fp);
        
        fclose(fp);
    } else {
        if (fp == NULL) {
            printf("Could not open file!\n");
            printf("File '%s' expected to be in %s\n", PCB_CONF_FILE, getwd(NULL));
        } else {
            fprintf(stderr, "Invalid data near offset %lu, %d: %s\n", (long unsigned int)ftello(fp), error, strerror(error));
            fclose(fp);
        }
    }
}

void generate_data(const char *year, const char *month, const char *total_mtd_amount, const char *mtd_amount) {
    data_line1 = (char *)calloc(1, RECORD_1_SIZE);
    data_line2 = (char *)calloc(1, RECORD_2_SIZE);
    
    ptrPCB->year_of_deduction = (char *)year;
    ptrPCB->month_of_deduction = (char *)month;
    ptrPCB->total_mtd_amount = (char *)total_mtd_amount;
    ptrPCB->mtd_amount = (char *)mtd_amount;
    
    strlcpy(data_line1, ptrPCB->employer_record_type, 2);
    strcat(data_line1, ptrPCB->employer_number_1);
    strcat(data_line1, ptrPCB->employer_number_2);
    strcat(data_line1, ptrPCB->year_of_deduction);
    strcat(data_line1, ptrPCB->month_of_deduction);
    strcat(data_line1, ptrPCB->total_mtd_amount);
    strcat(data_line1, ptrPCB->total_mtd_record);
    strcat(data_line1, ptrPCB->total_cp38_amount);
    strcat(data_line1, ptrPCB->total_cp38_record);
    strlcpy(data_line2, ptrPCB->transaction_record_type, 2);
    strcat(data_line2, ptrPCB->tax_reference_no);
    strcat(data_line2, ptrPCB->wife_code);
    strcat(data_line2, right_padding(60, " ", ptrPCB->employee_name));
    strcat(data_line2, right_padding(12, " ", " "));
    strcat(data_line2, ptrPCB->new_ic_no);
    strcat(data_line2, right_padding(12, " ", " "));
    strcat(data_line2, right_padding(2, " ", " "));
    strcat(data_line2, ptrPCB->mtd_amount);
    strcat(data_line2, ptrPCB->cp38_amount);    
    strcat(data_line2, right_padding(10, " ", ptrPCB->employee_no));
}

void write_data_file(const char *line1, const char *line2) {
    FILE *fp = NULL;
    int error;
    
    if ((error = setjmp(writeJump)) == 0) {
        if ((fp = fopen(data_file_name(), "w")) == NULL)
            longjmp(writeJump, errno);
        
        if (fprintf(fp, "%s\n", data_line1) < 0 || fprintf(fp, "%s\n", data_line2) < 0) {
            longjmp(writeJump, errno);
        }
    } else {
        if (fp == NULL) {
            printf("Could not open file!\n");
            printf("File '%s' expected to be in %s\n", data_file_name(), getwd(NULL));
        } else {
            fprintf(stderr, "Invalid data near offset %lu, %d: %s\n", (long unsigned int)ftello(fp), error, strerror(error));
        }
    }
    
    if (fclose(fp) != 0) {
        fprintf(stderr, "Could not write data file: %s\n", strerror(errno));
    }
    
    printf("Data file written to %s/%s\n", getwd(NULL), data_file_name());
}

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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Helper.h"
#include "PCBData.h"
#include "PCBFile.h"

#ifndef CFGDIR
#  define CFGDIR "/etc"
#endif

#ifndef OUTPUTDIR
#  define OUTPUTDIR "/tmp"
#endif

//#define PCB_CONF_DIR "Root/Projects/mypcb/conf"
//#define PCB_DATA_OUTPUT_DIR "Desktop"

const char *PCB_CONF_DIR = CFGDIR;
const char *PCB_DATA_OUTPUT_DIR OUTPUTDIR;

const char *year;
const char *month;
const char *total_mtd_amount;
const char *mtd_amount;

int main(int argc, const char * argv[]) {
    if (argc != 4) {
        print_usage_and_exit();
    }
    
    int i;
    bool error = false;
    
    // Parse command-line arguments, make sure all argumenets are valid before
    // proceed further.
    for (i = 1; i < argc && !error; ++i) {
        int int_number = 0;
        
        switch (i) {
            case 1:
                int_number = atoi(argv[i]);
                
                if (validYear(int_number)) {
                    year = argv[i];
                } else {
                    error = true;
                }
                
                break;
            case 2:
                int_number = atoi(argv[i]);
                
                if (validMonth(int_number)) {
                    // Only to padding if length is 1
                    if (strlen(argv[i]) == 1) {
                        month = left_padding(1, "0", argv[i]);
                    } else {
                        month = argv[i];
                    }
                } else {
                    error = true;
                }
                
                break;
            case 3:
                if (validPCB(argv[i])) {
                    total_mtd_amount = left_padding((int)(10 - strlen(argv[i])), "0", argv[i]);
                    mtd_amount = left_padding((int)(8 - strlen(argv[i])), "0", argv[i]);
                } else {
                    error = true;
                }
                
                break;
            default:
                print_usage_and_exit();
                break;
        }
    }
    
    if (error) {
        print_usage_and_exit();
    }
    
    // Change directory to configuration file directory
    if (set_homedir() != 0 || chdir(PCB_CONF_DIR) != 0) {
        perror("Could not chdir to configuration directory!");
        exit(1);
    }
    
    // Process configuration file
    read_data_file();
    
    // Generate new data file, merge with values from configuration file
    generate_data(year, month, total_mtd_amount, mtd_amount);
    
    // Change directory to output file directory
    if (set_homedir() != 0 || chdir(PCB_DATA_OUTPUT_DIR) != 0) {
        perror("Could not chdir to data output directory!");
        exit(1);
    }
    
    // Write output file
    write_data_file(data_line1, data_line2);
    
    return 0;
}

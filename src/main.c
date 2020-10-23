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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Helper.h"
#include "PCBData.h"
#include "PCBFile.h"

#ifndef CFGDIR
#define CFGDIR "/etc"
#endif

#ifndef OUTPUTDIR
#define OUTPUTDIR "/tmp"
#endif

//#define PCB_CONF_DIR "Root/Projects/mypcb/conf"
//#define PCB_DATA_OUTPUT_DIR "Desktop"

const char *PCB_CONF_DIR = CFGDIR;
const char *PCB_DATA_OUTPUT_DIR = OUTPUTDIR;

const char *year;
const char *month;
const char *total_mtd_amount;
const char *mtd_amount;

int main(int argc, const char * argv[]) {
    // Make sure user pass in the correct config and output directories
    // Due to how the gcc is run inside the Makefile, the above two #define statements become useless now...
    if (strcmp(PCB_CONF_DIR, "") == 0 || strcmp(PCB_DATA_OUTPUT_DIR, "") == 0) {
        perror("Please specify configuration and output directories when running `make`\ne.g. make sysconfdir=$HOME/etc outputdir=$HOME/desktop all ");
        exit(1);
    }

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

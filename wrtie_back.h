#include "write_back.h"
#include <iostream>

void write_back()
{
  //writes back to register file
    if(reg_write = 0)
    {
        d_mem[r] = value; 
    }
    if(mem_write = 0)
    {
        d_mem[r] = value;
    }
    else
    {
        reg_write = 1;
        registe_file[r] = value;
    }
        
  //increment total_clocl_cycles by 1 when one instruction is finished
  total_clock_cycles = total_clock_cycles + 1;
}
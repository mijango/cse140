#include "write_back.h"
#include <iostream>

void write_back(int rr, int value)
{
  //where rr represents the 70 and value represents 1b
  //memory 0x70 is modified to 0x1b
  //writes back to register file
    if(reg_write = 0)
    {
        d_mem[rr] = value; 
    }
    if(mem_write = 1)
    {
        d_mem[rr] = value;
    }
    else
    {
        reg_write = 1;
        registerfile[rr] = value;
        registernames[rr];
    }
        
  //increment total_clocl_cycles by 1 when one instruction is finished
  total_clock_cycles = total_clock_cycles + 1;
}

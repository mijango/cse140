#include "mem.h"
#include <iostream>

//receive memory address to write for SW
void mem(int rr, int address)
{
    int new_value = 0;
    int d_mem[32] = 0;
    //each entry will be considered as one 4-byte memory space
    //if mem_read
    if(mem_read = 1)
    {
        //for lw
        new_value = d_mem[address/4];
        //calling write_back to update
        write_back(rr, new_value);
    }
    if()
    {
        //for sw
        new_value = registerfile[rr];
        write_back(address, new_value);
    }
    else
    {
        //call write back to update for I/R
        write_back(rr, address);
    }
}

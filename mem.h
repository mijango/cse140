#include "mem.h"
#include <iostream>

//receive memory address to write for SW
void mem()
{
    int d_mem[32] = 0;
    //each entry will be considered as one 4-byte memory space
    //if mem_read
    if(mem_read = 1)
    {
        int mem_data = d_mem[ int address/4];
        write_back(rt, mem_data);
    }
    else
    {
        mem_write = 1;
        d_mem[address/4] = register_file[rt];
        write_back(r, address);
    }
}
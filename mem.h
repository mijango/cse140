#include <iostream>
#include <string>
#include <unordered_map>
#include "write_back.h"

//receive memory address to write for SW
void mem(int alu_result, Data data, std::unordered_map<std::string, int> &cu, int d_mem[], int regs[], int total_clock_cycles)
{
    int new_value = 0;
    int rt = data.rt;
    int address = alu_result;

    //each entry will be considered as one 4-byte memory space
    //if mem_read
    if(cu["mem_read"] == 1)
    {
        //for lw
        new_value = d_mem[address/4];
        //calling write_back to update

        //alu_result - /address
        write_back(data, new_value, cu, d_mem, total_clock_cycles);
    }
    //if mem_write
    else if(cu["mem_write"] == 1)
    {
        //for sw
        // new_value = registerfile[rt];
        write_back(data, address, cu, d_mem, total_clock_cycles);
    } else {
        //passing result only
        //write_back()
    }
}

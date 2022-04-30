#include <iostream>
#include <string>
#include <unordered_map>
#include "write_back.h"

//receive memory address to write for SW
void mem(int alu_result, Data &data, std::unordered_map<std::string, int> &cu, int d_mem[], std::unordered_map<std::string, int> &regs)
{
    int new_value = 0;
    int address = alu_result;

    //each entry will be considered as one 4-byte memory space
    //if mem_read
    if(cu["mem_read"] == 1)
    {
        //for lw
        new_value = d_mem[address/4];
        //calling write_back to update
        write_back(data, new_value, cu, regs, d_mem);
    }
    //if mem_write
    else if(cu["mem_write"] == 1)
    {
        //for sw
        write_back(data, address, cu, regs, d_mem);
    } else if(cu["branch"] == 1){
        
    } else if(cu["jump"] == 1){
        
    } else {
        //passing result only
        write_back(data, alu_result, cu, regs, d_mem);
    }
}

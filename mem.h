#include <iostream>
#include <string>
#include <unordered_map>
#include "write_back.h"

//receive memory address to write for SW
void mem(Data data, std::unordered_map<std::string, int> &cu, int d_mem[])
{
    int new_value = 0;
    int rr, address;

    //each entry will be considered as one 4-byte memory space
    //if mem_read
    if(cu["mem_read"] = 1)
    {
        //for lw
        new_value = d_mem[address/4];
        //calling write_back to update
        write_back(rr, new_value, cu);
    }
    if(cu["write"] = 1)
    {
        //for sw
        new_value = registerfile[rr];
        write_back(address, new_value, cu);
    }
    else
    {
        //call write back to update for I/R
        write_back(rr, address,cu);
    }
}

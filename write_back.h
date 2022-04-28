#include <iostream>
#include <string>
#include <unordered_map>

void write_back(int rr, int value, std::unordered_map<std::string, int> &cu)
{
  //where rr represents the 70 and value represents 1b
  //memory 0x70 is modified to 0x1b
  //writes back to register file
    if(cu["reg_write"] == 0)
    {
        d_mem[rr] = value; 
    }
    else if(cu["mem_write"] == 1)
    {
        d_mem[rr] = value;
    }
    else
    {
        //cu["reg_write"] = 1;
        registerfile[rr] = value;
        registernames[rr];
    }
        
  //increment total_clocl_cycles by 1 when one instruction is finished
  total_clock_cycles = total_clock_cycles + 1;
}

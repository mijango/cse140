#include <iostream>
#include <string>
#include <unordered_map>

void write_back(Data &data, int value, std::unordered_map<std::string, int> &cu, int regs[], int total_clock_cycles)
{
  //where rr represents the 70 and value represents 1b

  //memory 0x70 is modified to 0x1b
  //writes back to register file
    if(cu["mem_to_reg"] == 0)
    {
        if(cu["reg_dst"] == 1) {
          regs[data.rd] = value;
        } else {
          regs[data.rt] = value;
        } 
        
    }
    else {
        if(cu["reg_dst"] == 1) {
          regs[data.rd] = value;
        } else {
          regs[data.rt] = value;
        } 
    }
        
  //increment total_clocl_cycles by 1 when one instruction is finished
  //total_clock_cycles = total_clock_cycles + 1;
}

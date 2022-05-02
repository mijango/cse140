#include <iostream>
#include <string>
#include <unordered_map>

void write_back(Data &data, int value, std::unordered_map<std::string, int> &cu, std::unordered_map<std::string, int> &regs, int d_mem[])
{

  //writes back to register file
    if(cu["mem_to_reg"] == 0)
    {
        if(cu["reg_dst"] == 1) {
          regs[data.rdName] = value;
          if(cu["mem_write"] == 1) {
            d_mem[value/4] = data.rt;
          }
        } else {
          regs[data.rtName] = value;
        } 
        
    }
    else {
        if(cu["reg_dst"] == 1) {
          regs[data.rdName] = value;
        } else {
          regs[data.rtName] = value;
        } 
    }
}

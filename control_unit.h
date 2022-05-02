#include <iostream>
#include <unordered_map>

void control_unit(std::string opcode, std::unordered_map<std::string, int> &cu)
{
  //receive the 6 bit opcode value and generate 9 control signals

  // R format add, sub, and, or, slt, nor
  if (opcode == "000000") 
    {                      
        cu["reg_write"] = 1;
        cu["reg_dst"] = 1;
        cu["branch"] = 0;
        cu["alu_src"] = 0;
        cu["inst_type"] = 1;
        cu["mem_write"] = 0;
        cu["mem_to_reg"] = 0;
        cu["mem_read"] = 0;
        cu["jump"] = 0;
    }
    // LW
    if (opcode == "100011")
    { 
        cu["reg_write"] = 1;
        cu["reg_dst"] = 0;
        cu["branch"] = 0;
        cu["alu_src"] = 1;
        cu["inst_type"] = 0;
        cu["mem_write"] = 0;
        cu["mem_to_reg"] = 1;
        cu["mem_read"] = 1;
        cu["jump"] = 0;
    }
    // SW
    if (opcode == "101011")
    { 
        cu["reg_write"] = 0;
        cu["branch"] = 0;
        cu["alu_src"] = 1;
        cu["inst_type"] = 0;
        cu["mem_write"] = 1;
        cu["mem_read"] = 0;
        cu["jump"] = 0;
    }
    // BEQ
    if (opcode == "000100")
    { 
        cu["reg_write"] = 0;
        cu["branch"] = 1;
        cu["alu_src"] = 0;
        cu["inst_type"] = 0;
        cu["mem_write"] = 0;
        cu["mem_read"] = 0;
        cu["jump"] = 0;
    }
    // J and JAL
    if (opcode == "000011" || opcode == "000010") 
    {
        cu["reg_write"] = 0;
        cu["branch"] = 0;
        cu["mem_write"] = 0;
        cu["mem_read"] = 0;
        cu["jump"] = 1;
    }
}
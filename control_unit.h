#include "control_unit.h"
#include <iostream>

void control_unit(string opcode)
{
  //receive the 6 bit opcode value and generate 9 control signals
  // r format add,sub,and,or,slt,nor
  if (opcode == "000000") 
    {                      
        reg_write = 1;
        reg_dst = 1;
        branch = 0;
        alu_src = 0;
        inst_type = 1;
        mem_write = 0;
        mem_to_reg = 0;
        mem_read = 0;
        jump = 0;
    }
    // lw
    if (opcode == "100011")
    { 
        reg_write = 1;
        reg_dst = 0;
        branch = 0;
        alu_src = 1;
        inst_type = 0;
        mem_write = 0;
        mem_to_reg = 1;
        mem_read = 1;
        jump = 0;
    }
    // sw
    if (opcode == "101011")
    { 
        reg_write = 0;
        branch = 0;
        alu_src = 1;
        inst_type = 0;
        mem_write = 1;
        mem_read = 0;
        jump = 0;
    }
    // beq
    if (opcode == "000100")
    { 
        reg_write = 0;
        branch = 1;
        alu_src = 0;
        inst_type = 0;
        mem_write = 0;
        mem_read = 0;
        jump = 0;
    }
    // J format
    if (opcode == "000011" || opcode == "000010") 
    {
        reg_write = 0;
        branch = 0;
        mem_write = 0;
        mem_read = 0;
        jump = 1;
    }
}
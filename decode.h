#include <string>
#include "conversions.h"
#include "control_unit.h"
#include "alu_control.h"
#include "Data.h"

//use return instruction from fetch() here
//rtype instructions
 int opcode, rs, rt, rd, shamt, funct, immediate;
 std::string aluOp;

 //declared functions
 std::string readOpcode(std::string opcode, Data &data);
 void rtypeInstruction(std:: string code, std::unordered_map<std::string, int> &regs, std::string names[], Data &data, int &pc);
 void itypeInstruction(std::string code, std::unordered_map<std::string, int> &regs, std::string names[], Data &data);
 void jtypeInstruction(std::string code, std::unordered_map<std::string, int> &regs, std::string names[], Data &data, int &pc);
 void jumpTarget(std::string instruction, int &jump_target, int next_pc);
 

//decode()  will read instruction values from a register file and use the control units
void decode(std::string instruction, std::unordered_map<std::string, int> &cu, std::unordered_map<std::string, int> &regs, std::string names[], int &jump_target, int &next_pc, Data &data, int &pc)
{
    //get type of instruction, from bits 31-26
    data.type = readOpcode(instruction.substr(0,6), data);
    data.opcode = instruction.substr(0,6);

    //calling control_unit function to update and generate control signals
    control_unit(data.opcode, cu);

    //reading registers depending on type of instruction
    if(data.type == "r") {
        rtypeInstruction(instruction, regs, names, data, pc);
    }
    else if(data.type == "j") {
        jtypeInstruction(instruction, regs, names, data, pc);
    }
    else {
        itypeInstruction(instruction, regs, names, data);
    }

    jumpTarget(instruction, jump_target, next_pc);

}


 //reading in opcode to find type
std::string readOpcode(std::string opcode, Data &data) {
  
  if(opcode == "000000") {
    data.opcode = opcode;
    return "r";
  }
  else if(opcode == "000010" || opcode == "000011") {
    data.opcode = opcode;
    return "j";
  }
  else {
    data.opcode = opcode;
    return "i";
  }
}


//decoding a register instruction
void rtypeInstruction(std:: string code, std::unordered_map<std::string, int> &regs, std::string names[], Data &data, int &pc) {
  std::string operation = "";

  //finding registers and shamt
  data.rs = binaryToDec(code.substr(6,5));
  data.rt = binaryToDec(code.substr(11,5));
  data.rd = binaryToDec(code.substr(16,5));
  data.shamt = binaryToDec(code.substr(21,5));

  //reading register values from hash table
  data.rsName = names[data.rs];
  data.rs = regs[data.rsName];

  data.rtName = names[data.rt];
  data.rt = regs[data.rtName];

  data.rdName = names[data.rd];
  data.rd = regs[data.rdName];

  //finding operation and funct
  data.funct = binaryToDec(code.substr(26,6));

  //getting alu op
  data.aluOp = alu_control(data.funct);

  if(data.funct == 8) {
    operation = "jr";
    //reading $ra for pc
    pc = regs["$ra"];
  }
}


//decoding a immediate instruction
void itypeInstruction(std::string code, std::unordered_map<std::string, int> &regs, std::string names[], Data &data) {
  std::string operation = "";

  //finding registers and shamt
  data.rs = binaryToDec(code.substr(6,5));
  data.rt = binaryToDec(code.substr(11,5));
  data.immediate = binaryToDec(code.substr(16,16));

  //reading register values from hash table
  data.rsName = names[data.rs];
  data.rs = regs[data.rsName];

  data.rtName = names[data.rt];
  data.rt = regs[data.rtName];

   //converting op
  int op = binaryToDec(code.substr(0,6));

  if(op == 4) {
    operation = "beq";
    //getting alu op for beq
    data.aluOp = alu_control("01");
    return;
  } else if(op == 35) {
    operation = "lw";
    //getting alu op for lw
    data.aluOp = alu_control("00");
    return;
  } else if(op == 43) {
    operation = "sw";
    //getting alu op for sw
    data.aluOp = alu_control("00");
    return;
  }
}


//decoding a jump instruction
void jtypeInstruction(std::string code, std::unordered_map<std::string, int> &regs, std::string names[], Data &data, int &pc) {
  std::string operation = "";

  //finding address
  data.immediate = binaryToDec(code.substr(6, 26));

  //finding operation
  int op = binaryToDec(code.substr(0,6));

  if(op == 2) {
    operation = "j";
  }
  else if(op == 3) {
    operation = "jal";
    regs["$ra"] = pc;
  }
}


void jumpTarget(std::string instruction, int &jump_target, int next_pc) {
  std::string temp;
  std::string nextPCbinary = decToBinary(next_pc);

  //shift left 2
  temp = nextPCbinary.substr(0, 4) + instruction.substr(6, 26) + "00";
  //setting the jump target equal to an integer value
  jump_target = binaryToDec(temp);
}
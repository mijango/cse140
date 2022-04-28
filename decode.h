#include <string>
#include "conversions.h"
#include "control_unit.h"
#include "alu_control.h"
#include "Data.h"

//rtype instructions
 int opcode, rs, rt, rd, shamt, funct, immediate;
 std::string aluOp;
 Data data;

//decode()  will read instruction values from a register file and use the control units
Data decode(std::string instruction, std::unordered_map<std::string, int> &cu, std::unordered_map<std::string, int> &regs, std::string names[])
{
    //get type of instruction, from bits 31-26
    data.type = readOpcode(instruction.substr(0,6));
    data.opcode = binaryToDec(data.type);

    //calling control_unit function to update and generate control signals
    control_unit(cu);

    //reading registers depending on type of instruction
    if(data.type == "r") {
        rtypeInstruction(instruction, regs);
    }
    else if(data.type == "j") {
        jtypeInstruction(instruction, regs);
    }
    else {
        itypeInstruction(instruction, regs);
    }

    return data;
}

 //reading in opcode to find type
std::string readOpcode(std::string opcode) {
  
  if(data.opcode == "000000") {
    return "r";
  }
  else if(data.opcode == "000010" || opcode == "000011") {
    return "j";
  }
  else {
    return "i";
  }
}

//decoding a register instruction
void rtypeInstruction(std:: string code, std::unordered_map<std::string, int> &regs, std::string names[]) {
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
  data.aluOp = alu_control("10", data.funct);

  if(funct == 32) {
    operation = "add";
  }
  else if(funct == 33) {
    operation = "addu";
  }
  else if(funct == 36) {
    operation = "addu";
  }
  else if(funct == 8) {
    operation = "jr";
  }
  else if(funct == 39) {
    operation = "nor";
  }
  else if(funct == 37) {
    operation = "or";
  }
  else if(funct == 42) {
    operation = "slt";
  }
  else if(funct == 43) {
    operation = "sltu";
  }
  else if(funct == 0) {
    operation = "sll";
  }
  else if(funct == 2) {
    operation = "srl";
  }
  else if(funct == 34) {
    operation = "sub";
  }
  else if(funct == 35) {
    operation = "subu";
  }

}

//decoding a immediate instruction
void itypeInstruction(std::string code, std::unordered_map<std::string, int> &regs, std::string names[]) {
  std::string operation = "";

  //finding registers and shamt
  data.rs = binaryToDec(code.substr(6,5));
  data.rt = binaryToDec(code.substr(11,5));
  data.immediate = binaryToDec(code.substr(16,16));

  //reading register values from hash table
  data.rsName = names[data.rs];
  data.rs = regs[data.rsName];

  data.rtname = names[data.rt];
  data.rt = regs[data.rtName];
  
  //finding op
  data.opcode = binaryToDec(code.substr(0,6));

  if(data.opcode == 8) {
    operation = "addi";
  }
  else if(data.opcode == 9) {
    operation = "addiu";
  }
  else if(data.opcode == 12) {
    operation = "andi";
  }
  else if(data.opcode == 4) {
    operation = "beq";
    //getting alu op for beq
    data.aluOp = alu_control("01");
    return;
  }
  else if(data.opcode == 5) {
    operation = "bne";
  }
  else if(data.opcode == 36) {
    operation = "lbu";
  }
  else if(data.opcode == 37) {
    operation = "lhu";
  }
  else if(data.opcode == 48) {
    operation = "ll";
  }
  else if(data.opcode == 15) {
    operation = "lui";
  }
  else if(data.opcode == 35) {
    operation = "lw";
    //getting alu op for lw
    data.aluOp = alu_control("00");
    return;
  }
  else if(data.opcode == 13) {
    operation = "ori";
  }
  else if(data.opcode == 10) {
    operation = "slti";
  }
  else if(data.opcode == 11) {
    operation = "sltiu";
  }
  else if(data.opcode == 40) {
    operation = "sb";
  }
  else if(data.opcode == 56) {//
    operation = "sc";
  }
  else if(data.opcode == 41) {
    operation = "sh";
  }
  else if(data.opcode == 43) {
    operation = "sw";
    //getting alu op for sw
    data.aluOp = alu_control("00");
    return;
  }
}

//decoding a jump instruction
void jtypeInstruction(std::string code, std::unordered_map<std::string, int> &regs, std::string names[]) {
  std::string operation = "";

  //finding address
  data.immediate = binaryToDec(code.substr(6, 26));

  //finding operation
  data.opcode = binaryToDec(code.substr(0,6));

  if(data.opcode == 2) {
    operation = "j";
  }
  else if(data.opcode == 3) {
    operation = "jal";
  }
}

std::string signExtension(std::string immediate) { 
  std::string extended = "";
  //immediate is 16 bits, add 16 zeros in front
  extended = "0000000000000000";
  extended += immediate;
  return extended;
}
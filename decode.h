#include <string>
#include "conversions.h"
#include "control_unit.h"

//rtype instructions
 int rs, rt, rd, shamt, funct;

//decode() will read instruction values from a register file and use the control units
void decode(std::string instruction, std::unordered_map<std::string, int> cu, std::unordered_map<std::string, int> regs)
{
    //get type of instruction, from bits 31-26
    std::string type = readOpcode(instruction.substr(0,6));

    //calling control_unit function to update and generate control signals
    control_unit();
    if(type == "r") {
        rtypeInstruction(instruction, cu, regs);
    }
    else if(type == "j") {
        jtypeInstruction(instruction, cu, regs);
    }
    else {
        itypeInstruction(instruction, cu, regs);
    }
}

 //reading in opcode and matching type
std::string readOpcode(std::string opcode) {
  
  
  if(opcode == "000000") {
    return "r";
  }
  else if(opcode == "000010" || opcode == "000011") {
    return "j";
  }
  else {
    return "i";
  }
}

//decoding a register instruction
void rtypeInstruction(std:: string code, std::string instruction, std::unordered_map<std::string, int> cu, std::unordered_map<std::string, int> regs) {
  std::string operation = "";

  //finding operation and funct
  funct = binaryToDec(code.substr(26,6));

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

  //finding registers and shamt
  rs = binaryToDec(code.substr(6,5));
  rt = binaryToDec(code.substr(11,5));
  rd = binaryToDec(code.substr(16,5));
  shamt = binaryToDec(code.substr(21,5));

}

//decoding a immediate instruction
void itypeInstruction(std::string code, std::string instruction, std::unordered_map<std::string, int> cu, std::unordered_map<std::string, int> regs) {
  std::string operation = "";
  int rs, rt, op, immediate;

  //finding registers and shamt
  rs = binaryToDec(code.substr(6,5));
  rt = binaryToDec(code.substr(11,5));
  immediate = binaryToDec(code.substr(16,16));
  
  //finding op
  op = binaryToDec(code.substr(0,6));

  if(op == 8) {
    operation = "addi";
  }
  else if(op == 9) {
    operation = "addiu";
  }
  else if(op == 12) {
    operation = "andi";
  }
  else if(op == 4) {
    operation = "beq";
  }
  else if(op == 5) {
    operation = "bne";
  }
  else if(op == 36) {
    operation = "lbu";
  }
  else if(op == 37) {
    operation = "lhu";
  }
  else if(op == 48) {//
    operation = "ll";
  }
  else if(op == 15) {//
    operation = "lui";
  }
  else if(op == 35) {
    operation = "lw";
  }
  else if(op == 13) {
    operation = "ori";
  }
  else if(op == 10) {
    operation = "slti";
  }
  else if(op == 11) {
    operation = "sltiu";
  }
  else if(op == 40) {
    operation = "sb";
  }
  else if(op == 56) {//
    operation = "sc";
  }
  else if(op == 41) {
    operation = "sh";
  }
  else if(op == 43) {
    operation = "sw";
  }

}

//decoding a jump instruction
void jtypeInstruction(std::string code, std::string instruction, std::unordered_map<std::string, int> cu, std::unordered_map<std::string, int> regs) {
  std::string operation = "";
  int op, immediate;

  //finding operation
  op = binaryToDec(code.substr(0,6));

  if(op == 2) {
    operation = "j";
  }
  else if(op == 3) {
    operation = "jal";
  }

  //finding address
  immediate = binaryToDec(code.substr(6, 26));
}

std::string signExtension(std::string immediate) { 
  std::string extended = "";
  //immediate is 16 bits, add 16 zeros in front
  extended = "0000000000000000";
  extended += immediate;
  return extended;
}
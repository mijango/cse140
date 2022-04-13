//  cse140 Computer Architecture
//  single cycle cpu program that executes 10 instructions
//  by Luis Mora and Marianela Garcia Mijango

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

int registerfile[32] = {0};
string textfile = "sample_part1.text";

//global variables
int pc = 0;
int jump_target = 0;
int alu_zero = 0;
int branch_target = 0;
int total_clock_cycles = 0;
//control unit functions
int reg_write, reg_dst;
int branch, alu_src, inst_type, mem_write, mem_to_reg;
int mem_read, jump;

//helper functions
string readOpcode(string);
int binaryToDec(string);
void rtypeInstruction(string);
void jtypeInstruction(string);
void itypeInstruction(string);
string signExtension(string);


//other functions
void branch_target()
{

}
void jump_target()
{

}

void decode(string instruction)
{
    //get type of instruction, from bits 31-26
    string type = readOpcode(instruction.substr(0,6));
    
    if(type == "r") {
        rtypeInstruction(instruction);
    }
    else if(type == "j") {
        jtypeInstruction(instruction);
    }
    else {
        itypeInstruction(instruction);
    }
}

void execute(string registerOne, string registerTwo, string alu_op)
{
    //update alu_zero integer
    //calculate branch target
    //update branch_target

    string function = "";
    int one = binaryToDec(registerOne);
    int two = binaryToDec(registerTwo);
    int result;

    if(alu_op == "0000") {//AND
        function = "AND";
    } else if("0001") {//OR
        function = "OR";
    } else if("0010") {//add
        function = "add";
    } else if("0110") {//subtract
        function = "subtract";
    } else if("0111") {//set-on-less-than
        function = "set-on-less-than";
    } else if("1100") {//NOR
        function = "NOR";
    }
}

void mem()
{
    int d_mem[32] = 0;
    //each entry will be considered as one 4-byte memory space

    //receive memory address for LW AND SW
    
    //mem executes references instructions: LW, SW

}

void writebrack()
{
  //writes back to register file

  //increment total_clocl_cycles by 1 when one instruction is finished
  total_clock_cycles = total_clock_cycles + 1;
}

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
//fetch () function that grabs one instruction per cycle
string fetch(int pc)
{
    //variable where pc + 4 is stored
    int next_pc = 0;
    string instruction;
    fstream file;
    string line;
    file.open(textfile);

    int current = 1;
    int target = pc/4;
    while(getline(file, line)) {
        if(current == target) {
        pc += 4;
        instruction = line;
        next_pc = pc + 4;
        break;
        return line;
        }
        current++;
    }
    return "empty";
}
main()
{

    //output for sample_part1.txt
    cout << "total_clock_cycles 1:" << endl;
    cout << "$t3 is modified to" << << endl;
    cout << "pc is modified to" << << endl;

    cout << "total_clock_cycles 2:" << endl;
    cout << "$t5 is modified to" << << endl;
    cout << "pc is modified to" << << endl;

    cout << "total_clock_cycles 3:" << endl;
    cout << "$s1 is modified to" << << endl;
    cout << "pc is modified to" << << endl;

    cout << "total_clock_cycles 4:" << endl;
    cout << "pc is modified to" << << endl;

    cout << "total_clock_cycles 5:" << endl;
    cout << "memory 0x70 is modified to" <<  << endl;
    cout << "pc is modified to" << << endl;

    cout << "Program terminated:" << endl;
    cout << "total executime is " << << "cycles" << endl;   

    //output for sample_part2.txt
    cout << "total_clock_cycles 1:" << endl;
    cout << "$ra is modified to" <<  << endl;
    cout << "pc is modified to" << << endl;

    cout << "total_clock_cycles 2:" << endl;
    cout << "$t0 is modified to" << << endl;
    cout << "pc is modified to" << << endl;

    cout << "total_clock_cycles 3:" << endl;
    cout << "$v0 is modified to" << << endl;
    cout << "pc is modified to" << << endl;

    cout << "total_clock_cycles 4:" << endl;
    cout << "pc is modified to" << << endl;

    cout << "total_clock_cycles 5:" << endl;
    cout << "memory 0x70 is modified to" <<  << endl;
    cout << "pc is modified to" << << endl;

    cout << "Program terminated:" << endl;
    cout << "total executime is " << << "cycles" << endl;     
}

//reading in opcode and matching type
string readOpcode(string opcode) {
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

//converting the binary given as string into decimal value
int binaryToDec(string str) {
  int binaryVal = 0;
  double decimalVal = 0;
  //converting to decimal
  for(int i = str.size()-1, exponent = 0; i >= 0; i--, exponent++) {
    binaryVal = stoi(str.substr(i,1));
    decimalVal += binaryVal*pow(2,exponent);
  }
  int result = decimalVal;
  return result;
}

//converting the binary given as string into decimal value
string decToBinary(int i) {
  //converting to decimal
  string s = bitset<32>(i).to_string();
  return s;
}

//decoding a register instruction
void rtypeInstruction(string code) {
  string operation = "";
  int rs, rt, rd, shamt, funct;

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



//   //printing instruction
//   cout<<"Instruction Type: R"<<endl;
//   cout<<"Operation: "<<operation<<endl;
//   cout<<"Rs: $"<<rs<<endl;
//   cout<<"Rt: $"<<rt<<endl;
//   cout<<"Rd: $"<<rd<<endl;
//   cout<<"Shamt: "<<shamt<<endl;
//   cout<<"Funct: "<<funct<<endl;
}

//decoding a immediate instruction
void itypeInstruction(string code) {
  string operation = "";
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
  
//   //printing instruction
//   cout<<"Instruction Type: I"<<endl;
//   cout<<"Operation: "<<operation<<endl;
//   cout<<"Rs: $"<<rs<<endl;
//   cout<<"Rt: $"<<rt<<endl;
//   cout<<"Immediate: "<<immediate<<endl;
}

string signExtension(string immediate) 
  {     
      string extended = "";
      //keep positive 
      extended = "0000000000000000";
      extended += immediate;
      return extended;
  }

//decoding a jump instruction
void jtypeInstruction(string code) {
  string operation = "";
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

  //printing instruction
  cout<<"Instruction Type: J"<<endl;
  cout<<"Operation: "<<operation<<endl;
  cout<<"Immediate: "<<immediate<<endl;
}
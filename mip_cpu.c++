//  cse140 Computer Architecture
//  single cycle cpu program that executes 10 instructions
//  by Luis Mora and Marianela Garcia Mijango

#include <iostream>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;

string textfiles[] = {"sample_part1.text", "sample_part2.text"};

//global variables
int pc = 0;
int jump_target = 0;
int alu_zero = 0;
int branch_target = 0;
int total_clock_cycles = 0;

//registers and their mapped values
string registernames[] = {"$zero, $at, $v0, $v1, $a0, $a1, $a2, $a3, $t0, $t1, $t2, $t3, $t4, $t5, $t6, $t7, $s0, $s1, $s2, $s3, $s4, $s5, $s6, $s7, $t8, $t9, $k0, $k1, $gp, $sp, $fp, $ra"};
int registerfile[32] = {0};

//variable where pc + 4 is stored
int next_pc = 0;

//Global control unit signals
int reg_write = 0;
int reg_dst = 0;
int branch = 0;
int alu_src = 0;
int inst_type = 0;
int mem_write = 0;
int mem_to_reg = 0;
int mem_read = 0;
int jump = 0;


//receive memory address to write for SW
void mem()
{
    int d_mem[32] = 0;
    //each entry will be considered as one 4-byte memory space
    //if mem_read
    if(mem_read = 1)
    {
        int mem_data = d_mem[ int address/4];
        write_back(rt, mem_data);
    }
    else
    {
        mem_write = 1;
        d_mem[address/4] = register_file[rt];
        write_back(r, address);
    }
}

void write_back()
{
  //writes back to register file
    if(reg_write = 0)
    {
        d_mem[r] = value; 
    }
    if(mem_write = 0)
    {
        d_mem[r] = value;
    }
    else
    {
        reg_write = 1;
        registe_file[r] = value;
    }
        
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

main()
{
    //mappign registers and labels to hashtable
    unordered_map<string, int> regs;
    for(int i = 0; i < sizeof(registernames)/sizeof(registernames[0]); i++) {
      regs[registernames[i]] = registerfile[i];
    }
    
    // //output for sample_part1.txt
    // cout << "total_clock_cycles 1:" << endl;
    // cout << "$t3 is modified to" << << endl;
    // cout << "pc is modified to" << << endl;

    // cout << "total_clock_cycles 2:" << endl;
    // cout << "$t5 is modified to" << << endl;
    // cout << "pc is modified to" << << endl;

    // cout << "total_clock_cycles 3:" << endl;
    // cout << "$s1 is modified to" << << endl;
    // cout << "pc is modified to" << << endl;

    // cout << "total_clock_cycles 4:" << endl;
    // cout << "pc is modified to" << << endl;

    // cout << "total_clock_cycles 5:" << endl;
    // cout << "memory 0x70 is modified to" <<  << endl;
    // cout << "pc is modified to" << << endl;

    // cout << "Program terminated:" << endl;
    // cout << "total executime is " << << "cycles" << endl;   

    // //output for sample_part2.txt
    // cout << "total_clock_cycles 1:" << endl;
    // cout << "$ra is modified to" <<  << endl;
    // cout << "pc is modified to" << << endl;

    // cout << "total_clock_cycles 2:" << endl;
    // cout << "$t0 is modified to" << << endl;
    // cout << "pc is modified to" << << endl;

    // cout << "total_clock_cycles 3:" << endl;
    // cout << "$v0 is modified to" << << endl;
    // cout << "pc is modified to" << << endl;

    // cout << "total_clock_cycles 4:" << endl;
    // cout << "pc is modified to" << << endl;

    // cout << "total_clock_cycles 5:" << endl;
    // cout << "memory 0x70 is modified to" <<  << endl;
    // cout << "pc is modified to" << << endl;

    // cout << "Program terminated:" << endl;
    // cout << "total executime is " << << "cycles" << endl;     
}

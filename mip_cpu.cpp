//  cse140 Computer Architecture
//  single cycle cpu program that executes 10 instructions
//  by Luis Mora and Marianela Garcia Mijango

#include <iostream>
#include <cmath>
#include <string>
#include <unordered_map>
#include "fetch.h"
#include "decode.h"
#include "execute.h"
#include "mem.h"

using namespace std;

string textfiles[] = {"sample_part1.txt", "sample_part2.txt"};
Data dat;

//global variables
int pc = 0;
int jump_target = 0;
int alu_zero = 0;
int branch_target = 0;
int total_clock_cycles = 0;
int next_pc = 0;

//registers and their mapped values
string registernames[] = {"$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7", "$t8", "$t9", "$k0", "$k1", "$gp", "$sp", "$fp", "$ra"};
int registerfile[32] = {0};
unordered_map<string, int> regs;

//Global control unit signals
string controlsignals[] = {"reg_write", "reg_dst", "branch", "alu_src", "inst_type", "mem_write", "mem_to_reg", "mem_to_reg", "mem_read", "jump"};
int controlvalues[10] = {0};
unordered_map<string, int> cu;

//Dmem memory locations
int d_mem[32] = {0};

//print function declaration
void print();

int main()
{
    //mapping registers and labels to hashtable
    for(int i = 0; i < sizeof(registernames)/sizeof(registernames[0]); i++) {
      regs[registernames[i]] = registerfile[i];
    }
    regs["$t1"] = 32;
    regs["$t2"] = 5;
    regs["$s0"] = 7*16;

    //mapping control signals to ints;
    for(int i = 0; i < sizeof(controlvalues)/sizeof(controlvalues[0]); i++) {
      cu[controlsignals[i]] = controlvalues[i];
    }

    d_mem[28] = 5;
    d_mem[29] = 16;

    bool readFile = true;
    while(readFile) {

      //call fetch
      string instruction = fetch(pc, next_pc, textfiles[0]);

      if(instruction == "empty") {
        readFile = false;
      } else {

        //call decode
        decode(instruction, cu, regs, registernames, jump_target, next_pc, dat);

        //call execute
        int alu_result = execute(dat, alu_zero, branch_target, next_pc);

        if(cu["branch"] == 1) {
          pc = branch_target;
        } else {
          //call mem
          mem(alu_result, dat, cu, d_mem, regs, total_clock_cycles);
        }

        total_clock_cycles = total_clock_cycles + 1;

        print();
      }
    }
    cout<<" program terminated:\ntotal execution time is " << total_clock_cycles <<" cycles";
}

void print() {
  if(dat.type == "r") { 
    cout << " total_clock_cycles " << total_clock_cycles << " :" << endl;
    cout << dat.rdName << " is modified to " << hex << regs[dat.rdName] << endl;
    cout << "pc is modified to 0x" << hex << pc << endl;
  } else if(dat.type == "i") {
    cout << " total_clock_cycles " << total_clock_cycles << " :" << endl;
    if(binaryToDec(dat.opcode) == 43) {
      cout << dat.rsName << " is modified to " << hex << regs[dat.rsName] << endl;
    } else if(binaryToDec(dat.opcode) == 4) {
    } else {
      cout << dat.rtName << " is modified to " << hex << regs[dat.rtName] << endl;
    }
    cout << "pc is modified to 0x" << hex << pc << endl;
  } else {
    cout << " total_clock_cycles " << total_clock_cycles << " :" << endl;
    cout << "pc is modified to 0x" << hex << pc << endl;
  }
}
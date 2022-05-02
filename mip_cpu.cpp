//  CSE140 Computer Architecture
//  single cycle cpu program that executes 12 instructions
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

//global variables
int pc = 0;
int jump_target = 0;
int alu_zero = 0;
int branch_target = 0;
int total_clock_cycles = 0;
int next_pc = 0;
Data dat;//custom class for passing variables

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
    for(int i = 0; i < sizeof(registernames)/sizeof(registernames[1]); i++) {
      regs[registernames[i]] = registerfile[i];
    }

    //mapping control signals to ints;
    for(int i = 0; i < sizeof(controlvalues)/sizeof(controlvalues[0]); i++) {
      cu[controlsignals[i]] = controlvalues[i];
    }

    //asking user for input file name
    string textFile;
    cout<<"Enter the program file name to run:\n";
    cin>>textFile;
    cout<<endl;
    if(textFile == "sample_part1.txt") {
      //register values for test file 1
      regs["$t1"] = 32;
      regs["$t2"] = 5;
      regs["$s0"] = 7*16;
      //mememory values for test file 1
      d_mem[28] = 5;
      d_mem[29] = 16;
    } else if(textFile == "sample_part2.txt") {
      //register values for test file 2
      regs["$s0"] = 32;
      regs["$a0"] = 5;
      regs["$a1"] = 2;
      regs["$a3"] = 10;
    } else {
      cout<<"File not found\n";
      return -1;
    }

    //loop for cpu data path
    bool readFile = true;
    while(readFile) {

      //call fetch
      string instruction = fetch(pc, next_pc, textFile);

      if(instruction == "empty") {
        readFile = false;
      } else {

        //call decode
        decode(instruction, cu, regs, registernames, jump_target, next_pc, dat, pc);

        //for jtype, skip
        if(cu["jump"] == 1) {
          pc = jump_target;
          total_clock_cycles = total_clock_cycles + 1;
          print();
          continue;
        }

        //call execute
        int alu_result = execute(dat, alu_zero, branch_target, pc);

        //for branch, skip
        if(cu["branch"] == 1) {
          pc = branch_target;
        } else {
          //call mem
          mem(alu_result, dat, cu, d_mem, regs);
        }

        //increment cycle count and print
        total_clock_cycles++;
        print();
      }
    }
    cout<<"program terminated:\ntotal execution time is " << total_clock_cycles <<" cycles";
}


void print() {
  cout << "total_clock_cycles " << total_clock_cycles << ":" << endl;

  if(dat.type == "r") { 

    if(dat.funct != 8) {
      cout << dat.rdName << " is modified to 0x" << hex << regs[dat.rdName] << endl;
    }
    cout << "pc is modified to 0x" << hex << pc << endl << endl;

  } else if(dat.type == "i") {
  
    if(binaryToDec(dat.opcode) == 43) {
      cout << "memory 0x" << regs[dat.rsName] << " is modified to 0x" << hex << d_mem[(dat.rs + dat.immediate)/4] << endl;
    } else if(binaryToDec(dat.opcode) == 4) {//skip for beq
    } else {
      cout << dat.rtName << " is modified to 0x" << hex << regs[dat.rtName] << endl;
    }
    cout << "pc is modified to 0x" << hex << pc << endl << endl;

  } else if(dat.type == "j") {
    
    if(binaryToDec(dat.opcode) == 3) {
      cout<< "$ra is modified to 0x" << hex << regs["$ra"] << endl;
    }
    cout << "pc is modified to 0x" << hex << pc << endl << endl;

  } else {
    cout << "pc is modified to 0x" << hex << pc << endl << endl;
  }
}
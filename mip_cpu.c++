//  cse140 Computer Architecture
//  single cycle cpu program that executes 10 instructions
//  by Luis Mora and Marianela Garcia Mijango

#include <iostream>
#include <cmath>
#include <string>
#include <unordered_map>
#include <conversions.h>
#include <fetch.h>
#include <decode.h>
#include <execute.h>
#include "mem.h"
#include "write_back.h"
#include "control_unit.h"

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
string modify_register;

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

main()
{
    //mappign registers and labels to hashtable
    unordered_map<string, int> regs;

    for(int i = 0; i < sizeof(registernames)/sizeof(registernames[0]); i++) {
      regs[registernames[i]] = registerfile[i];
    }

    cout<<hex<<regs[modify_register]<<endl;

    bool readFile = true;

    while(readFile) {
      
      //call fetch
      string instruction = fetch(pc, next_pc, textfile[0]);

      if( == "empty") {
        readfile = false;
        cout<<"program terminated:\ntotal execution time is" << total_clock_cycles <<"cycles";
      } else {

        //call decode
        decode(instruction);
        //call execute
        execute();
        //call mem
        mem();
        //call writeback
        write_back();
      }
    }
    
    // //output for sample_part1.txt and part2.txt excluding program termination
    cout << "total_clock_cycles" << total_clock_cycles ":" << endl;
    cout << " "" " modify_register "is modified to" << hex << regs [modify_register]<< endl;
    cout << "pc is modified to" << hex << regs [modify_register] << endl; 
}

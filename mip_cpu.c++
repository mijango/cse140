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
int reg_write, reg_dst;//add more

//helper functions
string readOpcode(string);
int binaryToDec(string);
void registerInstruction(string);
void jumpInstruction(string);
void immediateInstruction(string);


//other functions
void branch_target()
{

}
void jump_target()
{

}

void decode(string instruction)
{
    //integer registerfile array with 32 entries initialized to have all zeros

    //get type of instruction, from bits 31-26
    string type = readOpcode(instruction.substr(0,6);
    
    if(type == "r") {
        registerInstruction(instruction);
    }
    else if(type == "j") {
        jumpInstruction(instruction);
    }
    else {
        immediateInstruction(instruction);
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
}

void writebrack()
{

}

void control_unit()
{

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

    //out for sample_part2.txt
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
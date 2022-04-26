#include <string>
#include <conversions.h>

//computation with alu
void execute(std::string registerOne, std::string registerTwo, std::string alu_op, int alu_zero)
{
    //update alu_zero integer
    //calculate branch target
    //update branch_target

    int one = binaryToDec(registerOne);
    int two = binaryToDec(registerTwo);
    int result;

    //ALU OP
    if(alu_op == "0000") {//AND
        result = one & two;
    } else if(alu_op == "0001") {//OR
        result = one | two;
    } else if(alu_op == "0010") {//add
        result = one + two;
    } else if(alu_op == "0110") {//subtract
        result = one - two;
    } else if(alu_op == "0111") {//set-on-less-than
        if(one < two) {
          result = 1;
        } else {
          result = 0;
        }
    } else if(alu_op == "1100") {//NOR
        result = ~(one | two);
    }

    //Zero_output
    if(result == 0) {
      alu_zero = 1;
    } else {
      alu_zero = 0;
    }

    //Branch target address
    
}

void jumpTarget(std::string instruction, int jump_target, int next_pc) {
  std::string temp;
  std::string nextPCbinary = decToBinary(next_pc);

  //getting the first four 4 bits of the next_pc value and adding the 26 bits from the instruction
  temp = nextPCbinary.substr(0, 4) + instruction.substr(3, 26) + "00";
  //setting the jump target equal to an integer value
  jump_target = binaryToDec(temp);
}

int branchTarget(std::string immediate, int next_pc)
{   
    //shift left immediate value by 2
    std::string shifted = immediate.substr(0,30) + "00";
    //add next pc to shifted immediate to calculte the branch address
    int target = binaryToDec(shifted) + next_pc;
    return target;
}
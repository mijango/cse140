#include <string>

int branchTarget(std::string immediate, int &next_pc);

//computation with alu
int execute(Data &dat, int &alu_zero, int &branch_target, int &next_pc)
{
    //update alu_zero integer
    //calculate branch target
    //update branch_target

    int one;
    int two;

    if(dat.type == "r") {
      one = dat.rs;
      two = dat.rt;
    } else if(dat.type == "i") {
      one = dat.rs;
      two = dat.immediate;
    }

    int result = 0;

    //ALU OP computations
    if(dat.aluOp == "0000") {//AND
        result = one & two;
    } else if(dat.aluOp == "0001") {//OR
        result = one | two;
    } else if(dat.aluOp == "0010") {//add
        result = one + two;
    } else if(dat.aluOp == "0110") {//subtract
        result = one - two;
    } else if(dat.aluOp == "0111") {//set-on-less-than
        if(one < two) {
          result = 1;
        } else {
          result = 0;
        }
    } else if(dat.aluOp == "1100") {//NOR
        result = ~(one | two);
    }    

    //Zero_output
    if(result == 0) {
      alu_zero = 1;
    } else {
      alu_zero = 0;
    }

    branch_target = branchTarget(decToBinary(dat.immediate), next_pc);

    return result;
}

int branchTarget(std::string immediate, int &next_pc)
{   
    //shift left immediate value by 2
    std::string shifted = immediate.substr(2,30) + "00";
    //add next pc to shifted immediate to calculte the branch address
    int target = binaryToDec(shifted) + next_pc;
    return target;
}
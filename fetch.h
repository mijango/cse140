#include <string>
#include <fstream>
#include <iostream>

//string fetch () function that grabs one instruction per cycle
std::string fetch(int &pc, int &next_pc, std::string textfile)
{   
    //represents instruction
    std::string instruction;
    //represents file
    std::ifstream file(textfile);
    //represents line
    std::string line;

    int current = 0;
    int target = pc/4;
    //if no instruction is fetch, print empty
    instruction = "empty";
    //get line from file
    while(std::getline(file, line)) {
        //if current and target are the same
        if(current == target) {
            //increment pc variable by 4
            pc += 4;
            instruction = line;
            break;
        }
        current++;
    }
    file.close();
    //storing pc + 4 
    next_pc = pc + 4;
    return instruction;
}
#include <string>
#include <fstream>

//string fetch () function that grabs one instruction per cycle
std::string fetch(int pc, int next_pc, std::string textfile  )
{  
    std::string instruction;
    std::fstream file;
    std::string line;
    file.open(textfile);

    int current = 1;
    int target = pc/4;
    instruction = "empty";
    while(std::getline(file, line)) {
        if(current == target) {
        pc += 4;
        instruction = line;
        break;
        }
        current++;
    }
    next_pc = pc + 4;
    return instruction;
}
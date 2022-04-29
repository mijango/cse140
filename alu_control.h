#include <string>

//get alu_op code for rtypes
std::string alu_control(int funct) {
  if(funct == 32) {
    return "0010"; //add
  } else if (funct == 34) {
    return "0110"; //sub
  } else if (funct == 36) {
    return "0000"; //AND
  } else if (funct == 37) {
    return "0001"; //OR
  } else if (funct == 42) {
    return "0111"; //SLT
  }
   else if (funct == 39) {
    return "1100"; //NOR
  }
  return "";
}

//get alu_op code for sw, lw and jeq
std::string alu_control(std::string type) {
  //lw and sw types
  if(type == "00") {
    return "0010"; //add
  }
  //beq type
  return "0110";
}
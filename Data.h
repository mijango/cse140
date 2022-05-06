 #include <string>

//This is a user-defined class to save the instructions data values and names
//it will be used to print the instrucitons data

 class Data {
  public:
    int rs, rt, rd, shamt, funct, immediate;
    std::string aluOp, rsName, rtName, rdName, type, opcode;

    Data() {
      rs = rt = rd = shamt = funct = 0;
      aluOp = "";
      rsName = "";
      rtName = "";
      rdName = "";
      type = "";
      opcode = "";
    }

    //operator = overload 
    Data operator = (const Data& d) const {
      Data dat;
      dat.opcode = d.opcode;
      dat.rs = d.rs;
      dat.rt = d.rt;
      dat.rd = d.rd;
      dat.shamt = d.shamt;
      dat.funct = d.funct;
      dat.aluOp = d.aluOp;
      dat.rsName = d.rsName;
      dat.rtName = d.rtName;
      dat.rdName = d.rdName;
      return dat;
      }
 };
 #include <string>

 class Data {
  public:
    int rs, rt, rd, shamt, funct, immediate;
    std::string aluOp, rsName, rtName, rdName, type, opcode;

    Data() {
      opcode, rs, rt, rd, shamt, funct = 0;
      aluOp = "";
      rsName = "";
      rtName = "";
      rdName = "";
    }

    // //copy constructor
    // Data (const Data &d) {
    //   this->opcode = d.opcode;
    //   this->rs = d.rs;
    //   this->rt = d.rt;
    //   this->rd = d.rd;
    //   this->shamt = d.shamt;
    //   this->funct = d.funct;
    //   this->aluOp = d.aluOp;
    //   this->rsName = d.rsName;
    //   this->rtName = d.rtName;
    //   this->rdName = d.rdName;
    // }

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
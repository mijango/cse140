 #include <string>

 class Data {
  public:
    int opcode, rs, rt, rd, shamt, funct;
    std::string aluOp, rsName, rtName, rdName, type;

    Data() {
      opcode, rs, rt, rd, shamt, funct = 0;
      aluOp = rsName, = rtName = rdName = "";
    }

    Data(int opcode, int rs, int rt, int rd, int shamt, int funct, std::string aluOp) {
      this->opcode = opcode;
      this->rs = rs;
      this->rt = rt;
      this->rd = rd;
      this->shamt = shamt;
      this->funct = funct;
      this->aluOp = aluOp;
      this->rsName = rsName;
      this->rtName = rtName;
      this->rdName = rdName;
    }
 };
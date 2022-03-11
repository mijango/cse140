//  cse140 Computer Architecture
//  single cycle cpu program that executes 10 instructions
//  by Luis Mora and Marianela Garcia Mijango

int registerfile[32] = 0;

//global variables
int pc = 0;
int jump_target = 0;
int alu_zero = 0;
int branch_target = 0;
int total_clock_cycles = 0;
int reg_write, reg_dst;//add more


//other functions
void branch_target()
{

}
void jump_target()
{

}

void decode()
{
    //integer registerfile array with 32 entries initialized to have all zeros
    int registerfile[32] = {};
}
void execute()
{
    //update alu_zero integer
    //calculate branch target
    //update branch_target
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
void fetch()
{
    //variable where pc + 4 is stored
    int next_pc = 0;
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
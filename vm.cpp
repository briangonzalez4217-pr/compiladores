#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Instruction{
public:

    string name;
    string arg1;
    string arg2;

    Instruction(string n, string a1="", string a2=""){
        name = n;
        arg1 = a1;
        arg2 = a2;
    }
};

class CPU{

public:

    int PC = 0;
    string IR = "";

    int ACC = 0;

    int MAR = 0;
    int MBR = 0;

    int AL = 0;
    int AH = 0;
    int BL = 0;
    int BH = 0;

    void printRegisters(){

        cout << "PC: " << PC << endl;
        cout << "IR: " << IR << endl;
        cout << "ACC: " << ACC << endl;
        cout << "MAR: " << MAR << endl;
        cout << "MBR: " << MBR << endl;
        cout << "AL: " << AL << endl;
        cout << "AH: " << AH << endl;
        cout << "BL: " << BL << endl;
        cout << "BH: " << BH << endl;

        cout << "-----------------------" << endl;
    }
};

class Memory{

public:

    vector<int> data = {10,12,0,0,0,0,0,0};

};

class VM{

public:

    CPU cpu;
    Memory memory;

    vector<Instruction> program;

    void loadProgram(){

        program.push_back(Instruction("START"));
        program.push_back(Instruction("MOVE","AL","0"));
        program.push_back(Instruction("MOVE","BL","1"));
        program.push_back(Instruction("ADD","AL","BL"));
        program.push_back(Instruction("STO","2"));
        program.push_back(Instruction("STOP"));
    }

    void run(){

        while(cpu.PC < program.size()){

            Instruction inst = program[cpu.PC];

            // FETCH
            cout << "FETCH" << endl;

            cpu.IR = inst.name;

            cpu.printRegisters();

            // DECODE
            cout << "DECODE" << endl;

            cpu.printRegisters();

            // EXECUTE
            cout << "EXECUTE" << endl;

            if(inst.name == "MOVE"){

                int addr = stoi(inst.arg2);

                cpu.MAR = addr;
                cpu.MBR = memory.data[addr];

                if(inst.arg1 == "AL")
                    cpu.AL = cpu.MBR;

                if(inst.arg1 == "BL")
                    cpu.BL = cpu.MBR;

            }

            if(inst.name == "ADD"){

                if(inst.arg1 == "AL" && inst.arg2 == "BL")
                    cpu.ACC = cpu.AL + cpu.BL;

            }

            if(inst.name == "STO"){

                int addr = stoi(inst.arg1);

                memory.data[addr] = cpu.ACC;

            }

            if(inst.name == "STOP"){
                cout << "Programa terminado." << endl;
                break;
            }

            cpu.printRegisters();

            cpu.PC++;
        }

        cout << endl;
        cout << "Resultado final ACC = " << cpu.ACC << endl;

    }
};

int main(){

    VM vm;

    vm.loadProgram();

    vm.run();

    return 0;
}
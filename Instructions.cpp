#include <iostream>
using namespace std;

#include "Instructions.h"

#define ll long long

// MSB is the sign bit so we deal with (bits - 1)

bool within_range(ll decimal, int bits)
{
    ll upper_limit = (1 << (bits - 1)) - 1;
    ll lower_limit = -(1 << (bits - 1));
    return (decimal > upper_limit || decimal < lower_limit) ? 0 : 1;
}

// Register 0 can't be changed so if rd is 0, we just return

// R-type
void ADD(int rd, int rs1, int rs2)
{
    if(rd == 0) return;
    registers[rd] = registers[rs1] + registers[rs2];
    PC += 4;
}
void SUB(int rd, int rs1, int rs2)
{
    if(rd == 0) return;
    registers[rd] = registers[rs1] - registers[rs2];
    PC += 4;
}
void AND(int rd, int rs1, int rs2)
{
    if(rd == 0) return;
    registers[rd] = registers[rs1] & registers[rs2];
    PC += 4;
}
void OR(int rd, int rs1, int rs2)
{
    if(rd == 0) return;
    registers[rd] = registers[rs1] | registers[rs2];
    PC += 4;
}
void XOR(int rd, int rs1, int rs2)
{
    if(rd == 0) return;
    registers[rd] = registers[rs1] ^ registers[rs2];
    PC += 4;
}
void SLL(int rd, int rs1, int rs2)
{
    
}
void SRL(int rd, int rs1, int rs2)
{
    
}
void SRA(int rd, int rs1, int rs2)
{
    
}
void SLT(int rd, int rs1, int rs2)
{
    
}
void SLTU (int rd, int rs1, int rs2)
{
    
}

// I-type
void ADDI (int rd, int rs1, int imm)
{
    if(rd == 0) return;
    if(!within_range(imm,12)){
        cout << "\"imm\" not in allowed range\n";
        exit(1);
    }
    registers[rd] = registers[rs1] + imm;
    PC += 4;
}
void ANDI (int rd, int rs1, int imm)
{
    if(rd == 0) return;
    registers[rd] = registers[rs1] & imm;
    PC += 4;
}
void ORI (int rd, int rs1, int imm)
{
    if(rd == 0) return;
    registers[rd] = registers[rs1] | imm;
    PC += 4;
}
void XORI (int rd, int rs1, int imm)
{
    if(rd == 0) return;
    registers[rd] = registers[rs1] ^ imm;
    PC += 4;
}
void SLLI (int rd, int rs1, int imm)
{
    
}
void SRLI (int rd, int rs1, int imm)
{
    
}
void SRAI (int rd, int rs1, int imm)
{
    
}
void JALR (int rd, int rs1, int imm)
{
    
}
void LW (int rd, int rs1, int imm)
{
    
}
void LH (int rd, int rs1, int imm)
{
    
}
void LB (int rd, int rs1, int imm)
{
    
}
void LHU (int rd, int rs1, int imm)
{
    
}
void LBU (int rd, int rs1, int imm)
{
    
}
void SLTI (int rd, int rs1, int imm)
{
    
}
void SLTIU (int rd, int rs1, int imm)
{
    
}


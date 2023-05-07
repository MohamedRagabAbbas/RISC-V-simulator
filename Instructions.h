#include <iostream>
using namespace std;

inline int PC = 0;                 // program counter
inline int registers[32] = {0};    // initial value of all registers is 0

// R-type   
void ADD (int rd, int rs1, int rs2);
void SUB (int rd, int rs1, int rs2);
void OR (int rd, int rs1, int rs2);
void AND (int rd, int rs1, int rs2);
void XOR (int rd, int rs1, int rs2);
void SLL (int rd, int rs1, int rs2);
void SRL (int rd, int rs1, int rs2);
void SRA (int rd, int rs1, int rs2);
void SLT (int rd, int rs1, int rs2);
void SLTU (int rd, int rs1, int rs2);

// I-type
void ADDI (int rd, int rs1, int imm);
void ANDI (int rd, int rs1, int imm);
void ORI (int rd, int rs1, int imm);
void XORI (int rd, int rs1, int imm);
void SLLI (int rd, int rs1, int imm);
void SRLI (int rd, int rs1, int imm);
void SRAI (int rd, int rs1, int imm);
void JALR (int rd, int rs1, int imm);
void LW (int rd, int rs1, int imm);
void LH (int rd, int rs1, int imm);
void LB (int rd, int rs1, int imm);
void LHU (int rd, int rs1, int imm);
void LBU (int rd, int rs1, int imm);
void SLTI (int rd, int rs1, int imm);
void SLTIU (int rd, int rs1, int imm);

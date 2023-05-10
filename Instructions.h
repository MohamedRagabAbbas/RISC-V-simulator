#include <iostream>
#include <map>
using namespace std;

#define ll long long


inline int PC = 0;                 // program counter
inline int registers[32] = {0};    // initial value of all registers is 0
inline map<int,int> memory;        // {address, value}
inline map<int,vector<string>> addressToInstruction; // maps each address to instruction so I can access instruction using PC
inline map<string,int> addressOfLabel;

/*
 IMPORTANT:
 Take care of signed/unsigned
 */

// R-type   
void ADD (int rd, int rs1, int rs2);    // done
void SUB (int rd, int rs1, int rs2);    // done
void AND (int rd, int rs1, int rs2);    // done
void OR (int rd, int rs1, int rs2);     // done
void XOR (int rd, int rs1, int rs2);    // done
void SLL (int rd, int rs1, int rs2);    // done
void SRL (int rd, int rs1, int rs2);    // done
void SRA (int rd, int rs1, int rs2);    // done
void SLT (int rd, int rs1, int rs2);    // done
void SLTU (int rd, int rs1, int rs2);   // done

// I-type
void ADDI (int rd, int rs1, int imm);   // done
void ANDI (int rd, int rs1, int imm);   // done
void ORI (int rd, int rs1, int imm);    // done
void XORI (int rd, int rs1, int imm);   // done
void SLLI (int rd, int rs1, int imm);   // done
void SRLI (int rd, int rs1, int imm);   // done
void SRAI (int rd, int rs1, int imm);   // done
void JALR (int rd, int rs1, int imm);
void LW (int rd, int base, int offset); // done
void LH (int rd, int base, int offset);
void LB (int rd, int base, int offset);
void LHU (int rd, int base, int offset);
void LBU (int rd, int base, int offset);
void SLTI (int rd, int rs1, int imm);
void SLTIU (int rd, int rs1, int imm);

// S-type
void SW (int rs1, int base, int offset); // done
void SH (int rs1, int base, int offset);
void SB (int rs1, int base, int offset);

// B-type
void BEQ (int rs1, int rs2, string label);
void BEQ (int rs1, int rs2, int offset);
void BNE (int rs1, int rs2, string label);
void BNE (int rs1, int rs2, int offset);
void BLT (int rs1, int rs2, string label);
void BLT (int rs1, int rs2, int offset);
void BLTU (int rs1, int rs2, string label);
void BLTU (int rs1, int rs2, int offset);
void BGE (int rs1, int rs2, string label);
void BGE (int rs1, int rs2,int offset);
void BGEU (int rs1, int rs2, string label);
void BGEU (int rs1, int rs2,int offset);



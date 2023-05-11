#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


#define ll long long


extern int PC;                 // program counter
extern int registers[32];   // initial value of all registers is 0
extern map<int, int> memory;        // {address, value}
extern map<string, int> labelAddress;

//Utility functions
void print(map<string, int>& m);
void print(vector<vector<string>> v);
void print(vector<string> v);
/*
 IMPORTANT:
 Take care of signed/unsigned
 */

 // R-type   
void ADD(int rd, int rs1, int rs2);    // done
void SUB(int rd, int rs1, int rs2);    // done
void AND(int rd, int rs1, int rs2);    // done
void OR(int rd, int rs1, int rs2);     // done
void XOR(int rd, int rs1, int rs2);    // done
void SLL(int rd, int rs1, int rs2);    // done
void SRL(int rd, int rs1, int rs2);    // done
void SRA(int rd, int rs1, int rs2);    // done
void SLT(int rd, int rs1, int rs2);    // done
void SLTU(int rd, int rs1, int rs2);   // done

// I-type
void ADDI(int rd, int rs1, int imm);   // done
void ANDI(int rd, int rs1, int imm);   // done
void ORI(int rd, int rs1, int imm);    // done
void XORI(int rd, int rs1, int imm);   // done
void SLLI(int rd, int rs1, int imm);   // done
void SRLI(int rd, int rs1, int imm);   // done
void SRAI(int rd, int rs1, int imm);   // done
void JALR(int rd, int rs1, int imm);
void LW(int rd, int base, int offset); // done
void LH(int rd, int base, int offset); // done
void LB(int rd, int base, int offset); // done
void LHU(int rd, int base, int offset); // done
void LBU(int rd, int base, int offset); // done
void SLTI(int rd, int rs1, int imm);	// done
void SLTIU(int rd, int rs1, int imm);	// done

// S-type
void SW(int rs1, int base, int offset); // done
void SH(int rs1, int base, int offset); // done
void SB(int rs1, int base, int offset); // done

// B-type
void BEQ(int rs1, int rs2, string label);
void BNE(int rs1, int rs2, string label);
void BLT(int rs1, int rs2, string label);
void BLTU(int rs1, int rs2, string label);
void BGE(int rs1, int rs2, string label);
void BGEU(int rs1, int rs2, string label);

// U-type
void LUI(int rd, int imm);//done
void AUIPC(int rd, int imm);
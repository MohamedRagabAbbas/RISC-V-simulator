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
void ADD(int rd, int rs1, int rs2);    // done and tested
void SUB(int rd, int rs1, int rs2);    // done and tested
void AND(int rd, int rs1, int rs2);    // done and tested
void OR(int rd, int rs1, int rs2);     // done and tested
void XOR(int rd, int rs1, int rs2);    // done and tested
void SLL(int rd, int rs1, int rs2);    // done and tested
void SRL(int rd, int rs1, int rs2);    // done and tested
void SRA(int rd, int rs1, int rs2);    // done and tested
void SLT(int rd, int rs1, int rs2);    // done and tested
void SLTU(int rd, int rs1, int rs2);   // done and tested

// I-type
void ADDI(int rd, int rs1, int imm);   // done and tested
void ANDI(int rd, int rs1, int imm);   // done and tested
void ORI(int rd, int rs1, int imm);    // done and tested
void XORI(int rd, int rs1, int imm);   // done and tested
void SLLI(int rd, int rs1, int imm);   // done and tested
void SRLI(int rd, int rs1, int imm);   // done and tested
void SRAI(int rd, int rs1, int imm);   // done and tested
void JALR(int rd, int rs1, int imm);	//done
void JAL(int rd, string label);			//done
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
void BEQ(int rs1, int rs2, string label); // done
void BNE(int rs1, int rs2, string label); // done
void BLT(int rs1, int rs2, string label); // done
void BLTU(int rs1, int rs2, string label); // done
void BGE(int rs1, int rs2, string label); // done
void BGEU(int rs1, int rs2, string label); // done

// U-type
void LUI(int rd, int imm);//done
void AUIPC(int rd, int imm); // done
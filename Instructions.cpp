#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#include "Instructions.h"

#define ll long long

// MSB is the sign bit so we deal with (bits - 1)

// Register 0 can't be changed so if rd is 0, we just return

// R-type

void twosComplement(string& binary)
{
    bool firstOne = 0;
    for (int i = binary.length() - 1; i >= 0; i--)
    {
        if (firstOne)
            binary[i] = binary[i] == '0' ? '1' : '0';
        if (binary[i] == '1')
            firstOne = 1;
    }
}

string decimalToBinary_Signed(int decimal)
{
    bool isNegative = 0;
    if (decimal < 0)
    {
        decimal = -1 * decimal;
        isNegative = 1;
    }
    string r = "";
    while (decimal > 0)
    {
        r += to_string(decimal % 2);
        decimal /= 2;
    }
    reverse(r.begin(), r.end());
    while (r.length() != 32)
        r.insert(r.begin(), '0');
    if (isNegative)
        twosComplement(r);
    return r;
}
string decimalToBinary_Unsigned(int decimal)
{
    if (decimal < 0)
        decimal = -1 * decimal;
    string r = "";
    while (decimal > 0)
    {
        r += decimal % 2;
        decimal /= 2;
    }
    reverse(r.begin(), r.end());
    while (r.length() != 32)
        r.insert(r.begin(), '0');
    return r;
}
int binaryToDecimal(string binary) {
    int result = 0;
    int len = binary.length();
    for (int i = 0; i < len; i++) {
        if (binary[i] == '1') {
            result += pow(2, len - i - 1);
        }
    }
    return result;
}

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
    if(rd == 0) return;
    int shift_amount = registers[rs2];
    if(shift_amount > 31 || shift_amount < 0){
        cout << "Left shift amount " << "\"" << shift_amount << "\" is not in range\n";
        exit(1);
    }
    registers[rd] = registers[rs1] << registers[rs2];
    PC += 4;
}
void SRL(int rd, int rs1, int rs2)
{
    if(rd == 0) return;
    
    int shift_amount = registers[rs2];
    if(shift_amount > 31 || shift_amount < 0){
        cout << "Right shift amount " << "\"" << shift_amount << "\" is not in range\n";
        exit(1);
    }
    
    registers[rd] = (registers[rs1] >> registers[rs2]);
    PC += 4;
}
void SRA(int rd, int rs1, int rs2)
{
    if(rd == 0) return;
    
    int shift_amount = registers[rs2];
    if(shift_amount > 31 || shift_amount < 0){
        cout << "Right shift amount " << "\"" << shift_amount << "\" is not in range\n";
        exit(1);
    }
    
    registers[rd] = registers[rs1] >> registers[rs2];
    PC += 4;
    
}
void SLT(int rd, int rs1, int rs2)
{
    if(rd == 0) return;
    registers[rd] = (registers[rs1] < registers[rs2]) ? 1 : 0;
    PC += 4;
    
}
void SLTU (int rd, int rs1, int rs2)
{
    if(rd == 0) return;
    if(rd == 0) return;
    registers[rd] = (registers[rs1] < registers[rs2]) ? 1 : 0;
    PC += 4;
}



// I-type
void ADDI (int rd, int rs1, int imm)
{
    if(rd == 0) return;
    if(imm > ((1 << 11) - 1) || imm < -(1 << 11)){
        cout << "\"imm\" not in allowed range\n";
        exit(1);
    }
    registers[rd] = registers[rs1] + imm;
    PC += 4;
}
void ANDI (int rd, int rs1, int imm)
{
    if(imm > ((1 << 11) - 1) || imm < -(1 << 11)){
        cout << "\"imm\" not in allowed range\n";
        exit(1);
    }
    if(rd == 0) return;
    registers[rd] = registers[rs1] & imm;
    PC += 4;
}
void ORI (int rd, int rs1, int imm)
{
    if(rd == 0) return;
    if(imm > ((1 << 11) - 1) || imm < -(1 << 11)){
        cout << "\"imm\" not in allowed range\n";
        exit(1);
    }
    registers[rd] = registers[rs1] | imm;
    PC += 4;
}
void XORI (int rd, int rs1, int imm)
{
    if(rd == 0) return;
    if(imm > ((1 << 11) - 1) || imm < -(1 << 11)){
        cout << "\"imm\" not in allowed range\n";
        exit(1);
    }
    registers[rd] = registers[rs1] ^ imm;
    PC += 4;
}
void SLLI (int rd, int rs1, int imm)
{
    if(rd == 0) return;
    int shift_amount = imm;
    if(shift_amount > 31 || shift_amount < 0){
        cout << "Left shift amount " << "\"" << shift_amount << "\" is not in range\n";
        exit(1);
    }
    registers[rd] = registers[rs1] << imm;
    PC += 4;
}
void SRLI (int rd, int rs1, int imm)
{
    if(rd == 0) return;
    int shift_amount = imm;
    if(shift_amount > 31 || shift_amount < 0){
        cout << "Right shift amount " << "\"" << shift_amount << "\" is not in range\n";
        exit(1);
    }
    registers[rd] = registers[rs1] >> imm;
    PC += 4;
}
void SRAI (int rd, int rs1, int imm)
{
    if(rd == 0) return;
    int shift_amount = imm;
    if(shift_amount > 31 || shift_amount < 0){
        cout << "Right shift amount " << "\"" << shift_amount << "\" is not in range\n";
        exit(1);
    }
    registers[rd] = registers[rs1] >> imm;
    PC += 4;
}
void JALR (int rd, int rs1, int imm)
{
    if(rd == 0) return;
    
}
void LW (int rd, int base, int offset)
{
    if(rd == 0) return;
    if(offset > ((1 << 11) - 1) || offset < -(1 << 11)){
        cout << "\"offset\" not in allowed range\n";
        exit(1);
    }
    registers[rd] = memory[registers[base] + offset];
    PC += 4;
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

// S-type

void SW (int rs1, int base, int offset)
{
    if(base == 0) return;
    if(offset > ((1 << 11) - 1) || offset < -(1 << 11)){
        cout << "\"offset\" not in allowed range\n";
        exit(1);
    }
    memory[registers[base] + offset] = registers[rs1];
    PC += 4;
}
void SH (int rs1, int base, int offset)
{
    if(base == 0) return;
}
void SB (int rs1, int base, int offset)
{
    if(base == 0) return;
}

// B-type
void BEQ (int rs1, int rs2, string label)
{
    
    if(registers[rs1] == registers[rs2]){
        if(addressOfLabel.count(label)){
            PC = addressOfLabel[label];
        }
        else{
            cout << "Label not found\n";
            exit(1);
        }
    }
    else{
        PC += 4;
    }
}


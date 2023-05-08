#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

#include "Instructions.h"

#define ll long long

// Global Variables

vector<vector<string>> parsedInstructions; // each vector in this 2D vector is an instruction (ex: [addi,t0,t1,5])
ifstream InstructionsInput;

// Functions

bool check_address(ll); // checks if address is within range
int find_reg(string); // return a register's position in the array when given its name/number
string regNumToName(string);    // x0 -> zero
void open_file(string);
vector <string> clean();
vector<vector<string>> parse(vector<string> &); // transform comma separated string to vector - addi t0, t1, 5 -> [addi,t0,t1,5]

void printRegisterContents();
void printOriginalInstructions();
void printCleanedInstructions(vector<string> &);
void printParsedInstructions();

string lowercase(string); // lower-case all instruction words as they are case-insensitive (account for user's choice)
void remove_spaces(vector<string> &);
void run_program();



int main(){
    cout << "Welcome to RV32I Simulator!\n";
    string file_name;
    cout << "Enter the name of the assembly file with the extension (ex: file.txt): ";
    cin >> file_name;

//    ll address;
//    cout << "Enter address of first instruction: ";
//    cin >> address;
//    while(!check_address(address)){
//        cout << "Address not in range. Enter an address between 0 and 2^32 - 1: ";
//        cin >> address;
//    }
//    PC = (int)address;
    
    open_file(file_name);
    vector<string> cleaned_instructions = clean();
    parsedInstructions = parse(cleaned_instructions);
    
    printOriginalInstructions();
    printCleanedInstructions(cleaned_instructions);
    printParsedInstructions();
    
    run_program();
}

bool check_address(ll address)
{
    return (address < 0 || address > (1LL << 32) - 1) ? 0 : 1;
}

string lowercase(string s)
{
    for(int i = 0; i < (int)s.size(); i++){
        s[i] = tolower(s[i]);
    }
    return s;
}

void open_file(string file_name)
{
    InstructionsInput.open("/Users/omar_bahgat/Documents/normal/normal/normal/assembly.txt");
    while(!InstructionsInput.is_open()) {
        cout << "Error in opening \"" << file_name << "\"\n";
        cout << "Enter the name of the assembly file with the extension (ex: file.txt): ";
        cin >> file_name;
    }
}

void remove_spaces(vector<string> & instructions)
{
    vector<string> modified_instructions;
    string temp = "";
    for(string s : instructions){
        for(char c : s){
            if(c != ' ') temp += c;
        }
        modified_instructions.push_back(temp);
        temp = "";
    }
    instructions = modified_instructions;
}

vector<string> clean()
{
    vector<string> instructions;
    string single_instruction = "";
    
    string line, word;
    
    while(getline(InstructionsInput,line)){
        stringstream str(line);
        getline(str, word, ' ');
        if(word.size() == 0) continue;
        word = lowercase(word);
        single_instruction += word;
        single_instruction += ',';
        while(getline(str, word, ',')){
            single_instruction += word;
            single_instruction += ',';
        }
        instructions.push_back(single_instruction);
        single_instruction = "";
    }
    
    remove_spaces(instructions);
    InstructionsInput.close();
        
    return instructions;
}

vector<vector<string>> parse(vector<string> &instructions)
{
    vector<vector<string>> parsed_instructions;
    vector<string> single_instruction;
    
    string word = "";
    for(string s : instructions){
        for(char c : s){
            if(c != ','){
                word += c;
            }
            else if(word.size() != 0){
                single_instruction.push_back(word);
                word = "";
            }
        }
        parsed_instructions.push_back(single_instruction);
        single_instruction.clear();
    }
    
    return parsed_instructions;
}

void run_program(){
    
    for(vector<string> v : parsedInstructions){
        
        if(v[0] == "add"){
            ADD(find_reg(v[1]), find_reg(v[2]), find_reg(v[3]));
        }
        else if(v[0] == "sub"){
            SUB(find_reg(v[1]), find_reg(v[2]), find_reg(v[3]));
        }
        else if(v[0] == "or"){
            OR(find_reg(v[1]), find_reg(v[2]), find_reg(v[3]));
        }
        else if(v[0] == "and"){
            AND(find_reg(v[1]), find_reg(v[2]), find_reg(v[3]));
        }
        else if(v[0] == "xor"){
            XOR(find_reg(v[1]), find_reg(v[2]), find_reg(v[3]));
        }
        else if(v[0] == "sll"){
            
        }
        else if(v[0] == "srl"){
            
        }
        else if(v[0] == "sra"){
            
        }
        else if(v[0] == "slt"){
            
        }
        else if(v[0] == "sltu"){
            
        }
        else if(v[0] == "addi"){
            ADDI(find_reg(v[1]), find_reg(v[2]), stoi(v[3]));
        }
        else if(v[0] == "andi"){
            ANDI(find_reg(v[1]), find_reg(v[2]), stoi(v[3]));
        }
        else if(v[0] == "ori"){
            ORI(find_reg(v[1]), find_reg(v[2]), stoi(v[3]));
        }
        else if(v[0] == "xori"){
            XORI(find_reg(v[1]), find_reg(v[2]), stoi(v[3]));
        }
        else if(v[0] == "slli"){
            
        }
        else if(v[0] == "srli"){
            
        }
        else if(v[0] == "srai"){
            
        }
        else if(v[0] == "jalr"){
            
        }
        else if(v[0] == "lw"){
            
        }
        else if(v[0] == "lh"){
            
        }
        else if(v[0] == "lb"){
            
        }
        else if(v[0] == "lhu"){
            
        }
        else if(v[0] == "lbu"){
            
        }
        else if(v[0] == "slti"){
            
        }
        else if(v[0] == "sltiu"){
            
        }
        printRegisterContents();
    }
}

int find_reg(string reg)
{
    if(reg == "zero" || reg == "x0") return 0;
    if(reg == "ra" || reg == "x1") return 1;
    if(reg == "sp" || reg == "x2") return 2;
    if(reg == "gp" || reg == "x3") return 3;
    if(reg == "tp" || reg == "x4") return 4;
    if(reg == "t0" || reg == "x5") return 5;
    if(reg == "t1" || reg == "x6") return 6;
    if(reg == "t2" || reg == "x7") return 7;
    if(reg == "s0" || reg == "x8") return 8;
    if(reg == "s1" || reg == "x9") return 9;
    if(reg == "a0" || reg == "x10") return 10;
    if(reg == "a1" || reg == "x11") return 11;
    if(reg == "a2" || reg == "x12") return 12;
    if(reg == "a3" || reg == "x13") return 13;
    if(reg == "a4" || reg == "x14") return 14;
    if(reg == "a5" || reg == "x15") return 15;
    if(reg == "a6" || reg == "x16") return 16;
    if(reg == "a7" || reg == "x17") return 17;
    if(reg == "s2" || reg == "x18") return 18;
    if(reg == "s3" || reg == "x19") return 19;
    if(reg == "s4" || reg == "x20") return 20;
    if(reg == "s5" || reg == "x21") return 21;
    if(reg == "s6" || reg == "x22") return 22;
    if(reg == "s7" || reg == "x23") return 23;
    if(reg == "s8" || reg == "24") return 24;
    if(reg == "s9" || reg == "25") return 25;
    if(reg == "s10" || reg == "26") return 26;
    if(reg == "s11" || reg == "27") return 27;
    if(reg == "t3" || reg == "28") return 28;
    if(reg == "t4" || reg == "29") return 29;
    if(reg == "t5" || reg == "30") return 30;
    if(reg == "t6" || reg == "31") return 31;
    
    cout << "Invalid register. Exitting Program\n";
    return 1;
    // exit
}

string regNumToName(int i)
{
    if(i == 0) return "zero";
    else if (i == 1) return "ra";
    else if (i == 2) return "sp";
    else if (i == 3) return "gp";
    else if (i == 4) return "tp";
    else if (i == 5) return "t0";
    else if (i == 6) return "t1";
    else if (i == 7) return "t2";
    else if (i == 8) return "s0";
    else if (i == 9) return "s1";
    else if (i == 10) return "a0";
    else if (i == 11) return "a1";
    else if (i == 12) return "a2";
    else if (i == 13) return "a3";
    else if (i == 14) return "a4";
    else if (i == 15) return "a5";
    else if (i == 16) return "a6";
    else if (i == 17) return "a7";
    else if (i == 18) return "s2";
    else if (i == 19) return "s3";
    else if (i == 20) return "s4";
    else if (i == 21) return "s5";
    else if (i == 22) return "s6";
    else if (i == 23) return "s7";
    else if (i == 24) return "s8";
    else if (i == 25) return "s9";
    else if (i == 26) return "s10";
    else if (i == 27) return "s11";
    else if (i == 28) return "t3";
    else if (i == 29) return "t4";
    else if (i == 30) return "t5";
    else if (i == 31) return "t6";
    
    return 0;
}

void printOriginalInstructions()
{
    InstructionsInput.open("/Users/omar_bahgat/Documents/normal/normal/normal/assembly.txt");
    
    cout << "\n-------- Original Instructions --------\n\n";

    string line = "";
    while(getline(InstructionsInput, line)){
        cout << line << "\n";
    }
    InstructionsInput.close();
}

void printCleanedInstructions(vector<string> &instructions)
{
    cout << "\n-------- Cleaned Instructions --------\n\n";
    for(string s : instructions){
        cout << s << "\n";
    }
}

void printParsedInstructions()
{
    cout << "\n-------- Parsed Instructions --------\n\n";
    for(vector<string> v : parsedInstructions){
        for(string s : v){
            cout << s << " ";
        }
        cout << "\n";
    }
}

void printRegisterContents()
{
    cout << "\n--------- Register Contents ---------\n\n";
    for(int i = 0; i < 32; i++){
        cout << "The content in register x" << i << " (" << regNumToName(i) << "): " << registers[i] << "\n";
    }
    cout << "-------------------------------------\n";
    cout << "Program Counter: " << PC << "\n";
    cout << "-------------------------------------\n";
}



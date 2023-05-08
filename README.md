# RISC-V Simulator

## Overview
This repo includes the design and implementation of the RISC-V Simulator. The simulator supports the RV32I base integer instruction set according to
the specifications found here: https://riscv.org/technical/specifications. All forty user-level instructions (listed in
page 130 of the RISC-V Instruction Set Manual – Volume I: Unprivileged ISA are implemented.


## Simulation

### Inputs

#### Assembly Program
The user should input a program to be simulated by specifying a text file that contains the instructions. The user should also specify the program starting address. The input program is terminated by any of the following 3 instructions: ECALL, EBREAK, and FENCE.

#### Program Data
The user should specify any data required by the program to be initially loaded in the memory. For each data item, both its value and memory address should be specified. This information should also be provided through a text file.

### Outputs
The simulator starts by reading the inputs provided by the user and then it simulates the input program’s execution by keeping track of the **program counter value**, the **register file contents**, and the **memory contents**. The program also repeatedly outputs all these values (after each instruction’s execution) until the program ends.

.globl f
f:
addi $29, $29, -4
sw $31, 0($29)
addi $29, $29, -4
sw $30, 0($29)
addi $29, $29, -4
sw $3, 0($29)
addi $29, $29, -4
sw $3, 0($29)
lw $3, 0($29)
addi $29, $29, 4
addi $29, $29, -4
addi $29, $29, -4
sw $3, 0($29)
lw $3, 4($29)
li $3, 1
sw $3, 4($29)
lw $3, 0($29)
addi $29, $29, 4
_continue_0: 
lw $2, 0($29)
beq $2, $0, _break_1
nop
addi $29, $29, -4
sw $3, 0($29)
lw $3, 4($29)
li $3, 0
sw $3, 4($29)
lw $3, 0($29)
addi $29, $29, 4
j _continue_0
nop
_break_1:

li $2, 19937
lw $31, 12($29)
lw $30, 8($29)
addiu $29, $29, 16
jr $31
nop



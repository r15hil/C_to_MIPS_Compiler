.globl while_break_nested
while_break_nested:
addi $29, $29, -4
sw $31, 0($29)
addi $29, $29, -4
sw $30, 0($29)
addi $29, $29, -4
sw $3, 0($29)
addi $29, $29, -4
li $3, 100
sw $3, 0($29)
lw $3, 0($29)
addi $29, $29, 4
addi $29, $29, -4
addi $29, $29, -4
sw $8, 0($29)
addi $29, $29, -4
li $8, 100
sw $8, 0($29)
lw $8, 0($29)
addi $29, $29, 4
addi $29, $29, -4
_continue_0: 
addi $29, $29, -4
sw $8, 0($29)
lw $2, 12($29)
li $8, 0

slt $2, $8, $2
lw $8, 0($29)
addi $29, $29, 4
beq $2, $0, _break_1
nop
addi $29, $29, -4
sw $10, 0($29)
addi $29, $29, -4
sw $10, 0($29)
lw $10, 0($29)
addi $29, $29, 4
addi $29, $29, -4
addi $29, $29, -4
sw $11, 0($29)
addi $29, $29, -4
li $11, 35
sw $11, 0($29)
lw $11, 0($29)
addi $29, $29, 4
addi $29, $29, -4
_continue_2: 
addi $29, $29, -4
sw $11, 0($29)
lw $2, 44($29)
li $11, 0

slt $2, $11, $2
lw $11, 0($29)
addi $29, $29, 4
beq $2, $0, _break_3
nop
addi $29, $29, -4
sw $13, 0($29)
lw $13, 36($29)
sw $13, 36($29)
lw $13, 0($29)
addi $29, $29, 4
addi $29, $29, 32
addi $29, $29, -4
sw $14, 0($29)
lw $14, -4($29)
li $14, 15
sw $14, -4($29)
lw $14, 0($29)
addi $29, $29, 4
addi $29, $29, -8
addi $29, $29, -4
sw $15, 0($29)
lw $14, 20($29)
lw $15, 4($29)

sub $14, $14, $15
sltiu $14, $14, 1
lw $15, 0($29)
addi $29, $29, 4
beq $14, $0, _falsy_4
addi $29, $29, -24
j _break_3
nop
_falsy_4:
addi $29, $29, -4
sw $16, 0($29)
lw $16, 20($29)
lw $0, 20($29)
addi $16, $16, -1
sw $16, 20($29)
lw $16, 0($29)
addi $29, $29, 4
addi $29, $29, -4
sw $25, 0($29)
lw $25, 12($29)
addi $29, $29, -4

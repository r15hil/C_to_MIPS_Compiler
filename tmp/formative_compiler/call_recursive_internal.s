.globl f
f:
addi $29, $29, -4
sw $31, 0($29)
addi $29, $29, -4
sw $30, 0($29)
addi $29, $29, -4
move $2, $4
sw $2, 0($29)
addi $29, $29, -4
sw $8, 0($29)
lw $3, 4($29)
li $8, 0

sub $3, $3, $8
sltiu $3, $3, 1
lw $8, 0($29)
addi $29, $29, 4
beq $3, $0, _falsy_0
li $2, 0
lw $31, 8($29)
lw $30, 4($29)
addiu $29, $29, 12
jr $31
nop
_falsy_0:
addi $29, $29, -4
sw $9, 0($29)
addi $29, $29, -4
sw $10, 0($29)
lw $10, 8($29)
lw $4, 8($29)
addi $29, $29, -4
sw $11, 0($29)
li $11, 1

subu $4, $4, $11
lw $11, 0($29)
addi $29, $29, 4
jal f
nop
move $9, $2

addu $2, $10, $9
lw $10, 0($29)
addi $29, $29, 4
lw $9, 0($29)
addi $29, $29, 4
lw $31, 8($29)
lw $30, 4($29)
addiu $29, $29, 12
jr $31
nop



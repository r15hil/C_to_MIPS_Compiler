.globl bsqrt
bsqrt:
addi $29, $29, -4
sw $31, 0($29)
addi $29, $29, -4
sw $30, 0($29)
addi $29, $29, -4
move $2, $4
sw $2, 0($29)
addi $29, $29, -4
move $2, $5
sw $2, 0($29)
addi $29, $29, -4
move $2, $6
sw $2, 0($29)
addi $29, $29, -4
sw $8, 0($29)
addi $29, $29, -4
sw $9, 0($29)
addi $29, $29, -4
sw $10, 0($29)
lw $9, 20($29)
lw $10, 20($29)

mult $9, $10
mflo $3
lw $10, 0($29)
addi $29, $29, 4
lw $9, 0($29)
addi $29, $29, 4
lw $8, 4($29)

slt $3, $3, $8
lw $8, 0($29)
addi $29, $29, 4
beq $3, $0, _falsy_1
lw $2, 4($29)
lw $31, 16($29)
lw $30, 12($29)
addiu $29, $29, 20
jr $31
nop
addi $29, $29, 0
j _end_0
_falsy_1:
lw $2, 8($29)
lw $31, 16($29)
lw $30, 12($29)
addiu $29, $29, 20
jr $31
nop
addi $29, $29, 0
_end_0:


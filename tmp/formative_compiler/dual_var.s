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
sw $8, 0($29)
addi $29, $29, -4
sw $8, 0($29)
lw $8, 0($29)
addi $29, $29, 4
addi $29, $29, -4
addi $29, $29, -4
sw $8, 0($29)
lw $8, 12($29)
li $8, 1234
sw $8, 12($29)
lw $8, 0($29)
addi $29, $29, 4
addi $29, $29, -4
sw $9, 0($29)
lw $9, 4($29)
lw $9, 12($29)
sw $9, 4($29)
lw $9, 0($29)
addi $29, $29, 4
lw $2, 0($29)
lw $31, 20($29)
lw $30, 16($29)
addiu $29, $29, 24
jr $31
nop

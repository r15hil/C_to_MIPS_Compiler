.globl post_inc
post_inc:
addi $29, $29, -4
sw $31, 0($29)
addi $29, $29, -4
sw $30, 0($29)
addi $29, $29, -4
sw $3, 0($29)
addi $29, $29, -4
li $3, 1
sw $3, 0($29)
lw $3, 0($29)
addi $29, $29, 4
addi $29, $29, -4
addi $29, $29, -4
sw $8, 0($29)
addi $29, $29, -4
li $8, 0
sw $8, 0($29)
lw $8, 0($29)
addi $29, $29, 4
addi $29, $29, -4
addi $29, $29, -4
sw $8, 0($29)
lw $8, 4($29)
addi $29, $29, -4
sw $9, 0($29)
addi $29, $29, -4
sw $10, 0($29)
lw $9, 20($29)
lw $8, 20($29)
addi $10, $9, 1
sw $10, 20($29)
lw $10, 0($29)
addi $29, $29, 4
lw $9, 0($29)
addi $29, $29, 4
sw $8, 4($29)
lw $8, 0($29)
addi $29, $29, 4
addi $29, $29, -4
sw $8, 0($29)
addi $29, $29, -4
sw $11, 0($29)
lw $11, 16($29)
lw $8, 8($29)

addu $2, $11, $8
lw $11, 0($29)
addi $29, $29, 4
lw $8, 0($29)
addi $29, $29, 4
lw $31, 20($29)
lw $30, 16($29)
addiu $29, $29, 24
jr $31
nop



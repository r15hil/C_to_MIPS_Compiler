.data
.text

.globl g
g:
addi $29, $29, -4
sw $31, 0($29)
addi $29, $29, -4
sw $30, 0($29)
addi $29, $29, --464928560
addi $29, $29, -4
sw $3, 0($29)
addi $29, $29, --464928560

addu $2, $2, $3
lw $3, 0($29)
addi $29, $29, 4
lw $31, -929857116($29)
lw $30, -929857120($29)
addiu $29, $29, -929857112
jr $31
nop



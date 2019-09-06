# Assembly reference

## Registers

There are
* 8 address registers : a1 to a8
* 8 data registers : d1 to d8
* a stack pointer named sp
* an instruction pointer named ip, not directly modifiable

## Instructions

### Operand size @

By default, operands are assumed to be 'long', i.e. 32 bits. The size of operands may be changed at any time by specifying:
* @b for bytes : 8 bits
* @w for words : 16 bits
* @l for longs : 32 bits

### Memory addressing [

There is only one way to address a memory cell (whatever the size): an address register preceded by the '[' operator.

### Identifiers #

A constant value may be defined and addressed using the '#' operator.

The following instruction defines the constant named 'foo' with the value 5:
```
#foo < 5
```

### Labels :

A label may be defined using the ':' operator. Labels may be used for jumps or to address a particular data location.
When compiled, they are just transformed into a memory cell location.

The following instruction defines a label named 'printStringOut':
```
:printStringOut
```

### Assignments

#### Load <

The '<' operator loads data into a register.

The following instruction loads the value 10 in register d2:
```
d2 < 10
```

The following instruction loads the value at address specified by a4 in register d1:
```
d1 < [a4
```

### Calls

A call is a jump to a code location after pushing the value of ip on the stack.
The next return instruction will pop back ip and continue execution just after the call was made.

The following instruction calls code at address specified by the 'printCharLine' label:
```
=> :printCharLine
```

The following instruction returns from the previous call:
```
<=
```

### Jumps

TODO

### Math

There are four math operators : + - * /

A math instruction is of the form:
```
Op1 + Op2
```
where Op1 and Op2 may be any register, not a memory cell.

The result of the operation is stored in the first operand.

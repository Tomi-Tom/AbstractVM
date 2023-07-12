# AbstractVM
![C++](https://img.shields.io/badge/C++%20-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)

AbstractVM is a machine that uses a stack to compute simple arithmetic expressions. These arithmetic expressions are provided to the machine as basic assembly programs.

## <img src="https://media.giphy.com/media/iY8CRBdQXODJSCERIr/giphy.gif" width="35"> Usage

```bash
./AbstractVM [file]

# or

./AbstractVM

# or

./AbstractVM --live
```

file: A file `.avm` containing instructions written in the assembly language.

## <img src="https://media2.giphy.com/media/QssGEmpkyEOhBCb7e1/giphy.gif?cid=ecf05e47a0n3gi1bfqntqmob8g9aid1oyj2wr3ds3mg700bl&rid=giphy.gif" width ="25"> Commands

| Command | Description |
| --- | --- |
| push | Pushes the value at the top of the stack. |
| pop | Unstacks the value from the top of the stack. |
| dump | Displays each value of the stack. |
| clear | Clears the stack. |
| dup | Duplicates the value at the top of the stack. |
| swap | Swaps the two values at the top of the stack. |
| assert | Asserts that the value at the top of the stack is equal to the one passed as parameter for this instruction. |
| add | Unstacks the first two values on the stack, adds them together and stacks the result. |
| sub | Unstacks the first two values on the stack, subtracts them, then stacks the result. |
| mul | Unstacks the first two values on the stack, multiplies them, then stacks the result. |
| div | Unstacks the first two values on the stack, divides them, then stacks the result. |
| mod | Unstacks the first two values on the stack, calculates the modulus, then stacks the result. |
| print | Asserts that the value at the top of the stack is an 8-bit integer. (If not, see the instruction assert), then interprets it as an ASCII value and displays the corresponding character on the standard output. |
| exit | Terminate the execution of the current program. |

## <img src="https://media2.giphy.com/media/QssGEmpkyEOhBCb7e1/giphy.gif?cid=ecf05e47a0n3gi1bfqntqmob8g9aid1oyj2wr3ds3mg700bl&rid=giphy.gif" width ="25"> Examples

```bash
./avm
push int32(42)
push int32(33)
add
push float(44.55)
mul
push double(42.42)
push int32(42)
dump
pop
assert double(42.42)
exit
```

## <picture><img src = "https://github.com/0xAbdulKhalid/0xAbdulKhalid/raw/main/assets/mdImages/about_me.gif" width = 50px></picture> Contributor

[<img src="https://github.com/Tomi-Tom.png?size=85" width=85><br><sub>Tom Bariteau-Peter</sub>](https://github.com/Tomi-Tom)
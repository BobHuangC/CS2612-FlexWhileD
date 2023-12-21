# InputRequirements

The input of this program should be a .l file, below is some requirements for the input file.

The .l file should only contain the second part of the classical .l file, which is the rules part. That means the .l file should begin with %% and end with %%.

The rules part should contain at least one rule, while one rule is defined as a regular expression and a syntax part, the requirements for the regular expression and the syntax part are listed below.

## Regular Expression Requirements

1. For each rule, if the regular expression contains a "{" or a "}", it should be escaped by a "\", for example, the regular expression "a{1" should be written as "a\\{1".

## Syntax Requirements

1. For each rule, the syntax part (which explains the rule to process the regular expression) should starts with a  "{" and ends with a"}".

2. For each rule, between the "{" and "}", there should be a valid WhileDeref program.

3. The standard of whileDeref program is listed below.

```
表达式的抽象语法树定义如下：
Inductive expr : Type :=
    | EConst (n: Z): expr                       // 常量
    | EVar (x: var_name): expr                  // 变量
    | EBinop (op: binop) (e1 e2: expr): expr    // 二元运算符
    | EUnop (op: unop) (e: expr): expr          // 单元运算符
    | EDeref (e: expr): expr.                   // 取地址上的值


程序语句的抽象语法树定义如下：
Inductive com : Type :=
    | CSkip: com                                // 空语句
    | CAsgnVar (x: var_name) (e: expr): com     // 给变量赋值
    | CAsgnDeref (e1 e2: expr): com             // 给地址赋值
    | CSeq (c1 c2: com): com                    // 顺序执行语句
    | CIf (e: expr) (c1 c2: com): com           // 条件语句
    | CWhile (e: expr) (c: com): com.           // 循环语句



具体包含的表达式如下:
E :: = N | 
       V | 
       E+E | E-E | E*E | E/E | E%E |
       E<E | E<=E | E==E | E!=E | E>=E | E>E |
       E&&E | E||E | !E |
       *E

具体包含的语句如下:
C :: = SKIP |
       V = E |
       *E = E |
       C ; C |
       if (E) then { C } else { C } |
       while (E) do { C }
```

4. For each rule, the length of the syntax should be less than 1000 characters.

5. The syntax shouldn't be empty(which is also the requirement of valid WhileDeref program).
# InputRequirements

The input of this program should be a .l file, below is some requirements for the input file.

1. The .l file should only contain the second part of the classical .l file, which is the rules part. That means the .l file should begin with %% and end with %%.

2. The rules part should contain at least one rule, while one rule is defined as a regular expression and a syntax part, the requirements for the regular expression and the syntax part are listed below.

3. Two rules can't occur in the same line, AKA, if the before rule ends in some line, the next rule must begin at least in the next line, but can't begin in the same line with the end of the before rule.

4. For each rule, the regular expression and the syntax part must be separated by at least a space.

## Regular Expression Requirements

1. For each rule, if the regular expression contains a "{" or a "}", it should be escaped by a "\", for example, the regular expression "a{1" should be written as "a\\{1".

2. The regular expression cannot contain Spaces. If you must, the final result will have an edge containing Spaces, please note that this is not an output error.

3. The escape characters we implement are as follows: "\\[", "\\]", "\\{", "\\}", "\\\\", "\\"", "\\t", "\\n", "\\r".

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
E :: = N | V | -E | E+E | E-E | E*E | E/E | E%E |
       E<E | E<=E | E==E | E!=E | E>=E | E>E |
       E&&E | E||E | !E |
       *E

具体包含的语句如下:
C :: = SKIP |
       var V |
       V = E |
       *E = E |
       C ; C |
       if (E) then { C } else { C } |
       while (E) do { C }
```

4. For each rule, the length of the ast of syntax should be less than 3000 characters(for we only apply 3000 characters to store the ast of each rule).

5. The syntax shouldn't be empty(which is also the requirement of valid WhileDeref program).

## Note

1. The output NFA has the form as follows:
260 ----> 261   _A-Za-z
261 ----> 262   ε
262 ----> 264   ε
262 ----> 263   _A-Za-z0-9
263 ----> 262   ε
264 is a final state. Endinfo:
{
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
}
The AST of the endinfo:
SEQ(ASGN(VAR(n),CONST(100)),SEQ(ASGN(VAR(m),CONST(10)),SEQ(ASGN(VAR(m),MUL(UMINUS(VAR(n)),VAR(n))),ASGN(VAR(m),MINUS(DEREF(VAR(n)),CONST(1))))))

For each edge x ----> y s, s is a single char or a char set,
such as ε, a or \t\n\r.
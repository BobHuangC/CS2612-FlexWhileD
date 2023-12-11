#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lang.h"

struct expr * new_expr_ptr() {
  struct expr * res = (struct expr *) malloc(sizeof(struct expr));
  if (res == NULL) {
    printf("Failure in malloc.\n");
    exit(0);
  }
  return res;
}

struct cmd * new_cmd_ptr() {
  struct cmd * res = (struct cmd *) malloc(sizeof(struct cmd));
  if (res == NULL) {
    printf("Failure in malloc.\n");
    exit(0);
  }
  return res;
}

struct expr * TConst(unsigned int value) {
  struct expr * res = new_expr_ptr();
  res -> t = T_CONST;
  res -> d.CONST.value = value;
  return res;
}

struct expr * TVar(char * name) {
  struct expr * res = new_expr_ptr();
  res -> t = T_VAR;
  res -> d.VAR.name = name;
  return res;
}

struct expr * TBinOp(enum BinOpType op, struct expr * left, struct expr * right) {
  struct expr * res = new_expr_ptr();
  res -> t = T_BINOP;
  res -> d.BINOP.op = op;
  res -> d.BINOP.left = left;
  res -> d.BINOP.right = right;
  return res;
}

struct expr * TUnOp(enum UnOpType op, struct expr * arg) {
  struct expr * res = new_expr_ptr();
  res -> t = T_UNOP;
  res -> d.UNOP.op = op;
  res -> d.UNOP.arg = arg;
  return res;
}

struct expr * TDeref(struct expr * arg) {
  struct expr * res = new_expr_ptr();
  res -> t = T_DEREF;
  res -> d.DEREF.arg = arg;
  return res;
}

struct cmd * TDecl(char * name) {
  struct cmd * res = new_cmd_ptr();
  res -> t = T_DECL;
  res -> d.DECL.name = name;
  return res;
}

struct cmd * TAsgn(struct expr * left, struct expr * right) {
  struct cmd * res = new_cmd_ptr();
  res -> t = T_ASGN;
  res -> d.ASGN.left = left;
  res -> d.ASGN.right = right;
  return res;
}

struct cmd * TSeq(struct cmd * left, struct cmd * right) {
  struct cmd * res = new_cmd_ptr();
  res -> t = T_SEQ;
  res -> d.SEQ.left = left;
  res -> d.SEQ.right = right;
  return res;
}

struct cmd * TIf(struct expr * cond, struct cmd * left, struct cmd * right) {
  struct cmd * res = new_cmd_ptr();
  res -> t = T_IF;
  res -> d.IF.cond = cond;
  res -> d.IF.left = left;
  res -> d.IF.right = right;
  return res;
}

struct cmd * TWhile(struct expr * cond, struct cmd * body) {
  struct cmd * res = new_cmd_ptr();
  res -> t = T_WHILE;
  res -> d.WHILE.cond = cond;
  res -> d.WHILE.body = body;
  return res;
}

void print_binop(enum BinOpType op) {
  switch (op) {
  case T_PLUS:
    printf("PLUS");
    break;
  case T_MINUS:
    printf("MINUS");
    break;
  case T_MUL:
    printf("MUL");
    break;
  case T_DIV:
    printf("DIV");
    break;
  case T_MOD:
    printf("MOD");
    break;
  case T_LT:
    printf("LT");
    break;
  case T_GT:
    printf("GT");
    break;
  case T_LE:
    printf("LE");
    break;
  case T_GE:
    printf("GE");
    break;
  case T_EQ:
    printf("EQ");
    break;
  case T_NE:
    printf("NE");
    break;
  case T_AND:
    printf("AND");
    break;
  case T_OR:
    printf("OR");
    break;
  }
}

void get_binop(enum BinOpType op, char* binop_return) {
  char* ret = binop_return;
  switch (op) {
  case T_PLUS:
    strcat(ret, "PLUS");
    break;
  case T_MINUS:
    strcat(ret, "MINUS");
    break;
  case T_MUL:
    strcat(ret, "MUL");
    break;
  case T_DIV:
    strcat(ret, "DIV");
    break;
  case T_MOD:
    strcat(ret, "MOD");
    break;
  case T_LT:
    strcat(ret, "LT");
    break;
  case T_GT:
    strcat(ret, "GT");
    break;
  case T_LE:
    strcat(ret, "LE");
    break;
  case T_GE:
    strcat(ret, "GE");
    break;
  case T_EQ:
    strcat(ret, "EQ");
    break;
  case T_NE:
    strcat(ret, "NE");
    break;
  case T_AND:
    strcat(ret, "AND");
    break;
  case T_OR:
    strcat(ret, "OR");
    break;
  }
}

void print_unop(enum UnOpType op) {
  switch (op) {
  case T_UMINUS:
    printf("UMINUS");
    break;
  case T_NOT:
    printf("NOT");
    break;
  }
}

void get_unop(enum UnOpType op, char* unop_return) {
  char* ret = unop_return;
  switch (op) {
  case T_UMINUS:
    strcat(ret, "UMINUS");
    break;
  case T_NOT:
    strcat(ret, "NOT");
    break;
  }
}

void print_expr(struct expr * e) {
  switch (e -> t) {
  case T_CONST:
    printf("CONST(%d)", e -> d.CONST.value);
    break;
  case T_VAR:
    printf("VAR(%s)", e -> d.VAR.name);
    break;
  case T_BINOP:
    print_binop(e -> d.BINOP.op);
    printf("(");
    print_expr(e -> d.BINOP.left);
    printf(",");
    print_expr(e -> d.BINOP.right);
    printf(")");
    break;
  case T_UNOP:
    print_unop(e -> d.UNOP.op);
    printf("(");
    print_expr(e -> d.UNOP.arg);
    printf(")");
    break;
  case T_DEREF:
    printf("DEREF(");
    print_expr(e -> d.DEREF.arg);
    printf(")");
    break;
  }
}

void get_expr(struct expr *e, char* expr_return) {
  char* ret = expr_return;
  switch (e -> t) {
  case T_CONST:
    strcat(ret, "CONST(");
    char str[100];
    sprintf(str, "%d", e -> d.CONST.value);
    strcat(ret, str);
    strcat(ret, ")");
    break;
  case T_VAR:
    strcat(ret, "VAR(");
    strcat(ret, e -> d.VAR.name);
    strcat(ret, ")");
    break;
  case T_BINOP:
    get_binop(e -> d.BINOP.op, ret);
    strcat(ret, "(");
    get_expr(e -> d.BINOP.left, ret);
    strcat(ret, ",");
    get_expr(e -> d.BINOP.right, ret);
    strcat(ret, ")");
    break;
  case T_UNOP:
    get_unop(e -> d.UNOP.op, ret);
    strcat(ret, "(");
    get_expr(e -> d.UNOP.arg, ret);
    strcat(ret, ")");
    break;
  case T_DEREF:
    strcat(ret, "DEREF(");
    get_expr(e -> d.DEREF.arg, ret);
    strcat(ret, ")");
    break;
  }
}


void print_cmd(struct cmd * c) {
  switch (c -> t) {
  case T_DECL:
    printf("DECL(%s)", c -> d.DECL.name);
    break;
  case T_ASGN:
    printf("ASGN(");
    print_expr(c -> d.ASGN.left);
    printf(",");
    print_expr(c -> d.ASGN.right);
    printf(")");
    break;
  case T_SEQ:
    printf("SEQ(");
    print_cmd(c -> d.SEQ.left);
    printf(",");
    print_cmd(c -> d.SEQ.right);
    printf(")");
    break;
  case T_IF:
    printf("IF(");
    print_expr(c -> d.IF.cond);
    printf(",");
    print_cmd(c -> d.IF.left);
    printf(",");
    print_cmd(c -> d.IF.right);
    printf(")");
    break;
  case T_WHILE:
    printf("WHILE(");
    print_expr(c -> d.WHILE.cond);
    printf(",");
    print_cmd(c -> d.WHILE.body);
    printf(")");
    break;
  }
}

// get_cmd is a function that takes a pointer to a struct cmd and a pointer to a char array
void* get_cmd(struct cmd * c, char* cmd_return) {
  char* ret = cmd_return;
  switch (c -> t) {
  case T_DECL:
    strcat(ret, "DECL(");
    strcat(ret, c -> d.DECL.name);
    strcat(ret, ")");
    break;
  case T_ASGN:    
    strcat(ret, "ASGN(");
    get_expr(c -> d.ASGN.left, ret);
    strcat(ret, ",");
    get_expr(c -> d.ASGN.right, ret);
    strcat(ret, ")");
    break;
  case T_SEQ:
    strcat(ret, "SEQ(");
    get_cmd(c -> d.SEQ.left, ret);
    strcat(ret, ",");
    get_cmd(c -> d.SEQ.right, ret);
    strcat(ret, ")");
    break;
  case T_IF:
    strcat(ret, "IF(");
    get_expr(c -> d.IF.cond, ret);
    strcat(ret, ",");
    get_cmd(c -> d.IF.left, ret);
    strcat(ret, ",");
    get_cmd(c -> d.IF.right, ret);
    strcat(ret, ")");
    break;
  case T_WHILE:
    strcat(ret, "WHILE(");
    get_expr(c -> d.WHILE.cond, ret);
    strcat(ret, ",");
    get_cmd(c -> d.WHILE.body, ret);
    strcat(ret, ")");
    break;
  }
}

unsigned int build_nat(char * c, int len) {
  int s = 0, i = 0;
  for (i = 0; i < len; ++i) {
    if (s > 429496729) {
      printf("We cannot handle natural numbers greater than 4294967295.\n");
      exit(0);
    }
    if (s == 429496729 && c[i] > '5') {
      printf("We cannot handle natural numbers greater than 4294967295.\n");
      exit(0);
    }
    s = s * 10 + (c[i] - '0');
  }
  return s;
}

char * new_str(char * str, int len) {
  char * res = (char *) malloc(sizeof(char) * (len + 1));
  if (res == NULL) {
    printf("Failure in malloc.\n");
    exit(0);
  }
  strcpy(res, str);
  return res;
}


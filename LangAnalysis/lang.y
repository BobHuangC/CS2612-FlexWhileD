%{
	// this part is copied to the beginning of the parser 
	#include <stdio.h>
	#include "lang.h"
	#include "lexer.h"
	void yyerror(char *);
	int yylex(void);
        struct glob_item_list * root;
%}

%union {
unsigned int n;
char * i;
struct expr * e;
void * none;
}

// Terminals
%token <n> TM_NAT

%token <none>  TM_INT_TYPE TM_CHAR_TYPE
%token <none>  TM_ENUM_TYPE
%token <none>  TM_STRUCT_TYPE
%token <none>  TM_UNION_TYPE
%token <none>  TM_TYPEDEF_TYPE

%token <none> TM_DEREFERENCE
%token <none> TM_COMMA

%token <none> TM_LEFT_BRACE TM_RIGHT_BRACE
%token <none> TM_LEFT_PAREN TM_RIGHT_PAREN
%token <none> TM_LEFT_BRACKET TM_RIGHT_BRACKET
%token <none> TM_SEMICOL
%token <i> TM_IDENT

// Nonterminals
%type <e> NT_WHOLE

%type <e> NT_FIELD_LIST
%type <e> NT_ARGUMENT_TYPE_LIST
%type <e> NT_ARGUMENT_TYPE_LIST_inner

%type <e> NT_ENUM_ELE_LIST

%type <e> NT_LEFT_TYPE

%type <e> NT_NAMED_RIGHT_TYPE_EXPR
%type <e> NT_ANNON_RIGHT_TYPE_EXPR

%type <e> NT_GLOB_ITEM
%type <e> NT_GLOB_ITEM_LIST


// Priority
%right TM_COMMA
%left TM_LEFT_BRACE TM_RIGHT_BRACE
%right TM_DEREFERENCE
%left TM_LEFT_BRACKET TM_RIGHT_BRACKET TM_LEFT_PAREN TM_RIGHT_PAREN
%right TM_SEMICOL



%%

NT_WHOLE:
  NT_GLOB_ITEM_LIST
  {
    $$ = $1;
    root = $$;
  }
;

NT_GLOB_ITEM_LIST:
  NT_GLOB_ITEM
  {
    $$ = TGCons($1, TGNil());
  }
| NT_GLOB_ITEM NT_GLOB_ITEM_LIST 
  {
    $$ = TGCons($1, $2);
  }
;

NT_ARGUMENT_TYPE_LIST_inner:
    TM_LEFT_PAREN NT_ARGUMENT_TYPE_LIST TM_RIGHT_PAREN
    {
        $$ = $2;
    }
;


NT_ARGUMENT_TYPE_LIST:
    {$$ = TTNil();}
|  NT_LEFT_TYPE NT_ANNON_RIGHT_TYPE_EXPR TM_COMMA NT_ARGUMENT_TYPE_LIST
  {
    $$ = TTCons($1, $2, $4);
  }
|  NT_LEFT_TYPE TM_COMMA NT_ARGUMENT_TYPE_LIST
  {
    $$ = TTCons($1, TOrigType(""), $3);
  }
|  NT_LEFT_TYPE NT_ANNON_RIGHT_TYPE_EXPR
  {
    $$ = TTCons($1, $2, TTNil());
  }
|  NT_LEFT_TYPE
  {
    $$ = TTCons($1, TOrigType(""), TTNil());
  }
;  


NT_ENUM_ELE_LIST:
  TM_IDENT
  {
    $$ = TECons($1, TENil());
  }
| TM_IDENT TM_COMMA NT_ENUM_ELE_LIST
  {
    $$ = TECons($1, $3);
  }
;



NT_FIELD_LIST:
  {
    $$ = TTNil();
  }
| NT_LEFT_TYPE NT_NAMED_RIGHT_TYPE_EXPR TM_SEMICOL NT_FIELD_LIST
  {
    $$ = TTCons($1, $2, $4);
  }
;




NT_ANNON_RIGHT_TYPE_EXPR:
TM_LEFT_PAREN NT_ANNON_RIGHT_TYPE_EXPR TM_RIGHT_PAREN
  {
    $$ = $2;
  }
| TM_DEREFERENCE NT_ANNON_RIGHT_TYPE_EXPR
  {
    $$ = TPtrType($2);
  }
| TM_DEREFERENCE
{
    $$ = TPtrType(TOrigType(""));
}
| NT_ANNON_RIGHT_TYPE_EXPR TM_LEFT_BRACKET TM_NAT TM_RIGHT_BRACKET
  {
    $$ = TArrayType($1, $3);
  }
| NT_ANNON_RIGHT_TYPE_EXPR NT_ARGUMENT_TYPE_LIST_inner
  {
    $$ = TFuncType($1, $2);
  }
| NT_ARGUMENT_TYPE_LIST_inner
  {
    $$ = TFuncType(TOrigType(""), $1);
  }
;




NT_NAMED_RIGHT_TYPE_EXPR:
TM_LEFT_PAREN NT_NAMED_RIGHT_TYPE_EXPR TM_RIGHT_PAREN
  {
    $$ = $2;
  }
| TM_IDENT
  {
    $$ = TOrigType($1);
  }
| TM_DEREFERENCE NT_NAMED_RIGHT_TYPE_EXPR
  {
    $$ = TPtrType($2);
  } 
| NT_NAMED_RIGHT_TYPE_EXPR TM_LEFT_BRACKET TM_NAT TM_RIGHT_BRACKET
  {
    $$ = TArrayType($1, $3);
  }
| NT_NAMED_RIGHT_TYPE_EXPR NT_ARGUMENT_TYPE_LIST_inner
  {
    $$ = TFuncType($1, $2);
  }
;







NT_LEFT_TYPE:
  TM_STRUCT_TYPE TM_IDENT TM_LEFT_BRACE NT_FIELD_LIST TM_RIGHT_BRACE
  {
    $$ = TNewStructType($2, $4);
  }
| TM_STRUCT_TYPE TM_LEFT_BRACE NT_FIELD_LIST TM_RIGHT_BRACE
  {
    $$ = TNewStructType(NULL, $3);
  }
| TM_STRUCT_TYPE TM_IDENT
  {
    $$ = TStructType($2); 
  }

| TM_UNION_TYPE TM_IDENT TM_LEFT_BRACE NT_FIELD_LIST TM_RIGHT_BRACE
  {
    $$ = TNewUnionType($2, $4);
  }
| TM_UNION_TYPE TM_LEFT_BRACE NT_FIELD_LIST TM_RIGHT_BRACE
  {
    $$ = TNewUnionType(NULL, $3);
  }
| TM_UNION_TYPE TM_IDENT
  {
    $$ = TUnionType($2);
  }

| TM_ENUM_TYPE TM_IDENT TM_LEFT_BRACE NT_ENUM_ELE_LIST TM_RIGHT_BRACE
  {
    $$ = TNewEnumType($2, $4);
  }
| TM_ENUM_TYPE TM_LEFT_BRACE NT_ENUM_ELE_LIST TM_RIGHT_BRACE
  {
    $$ = TNewStructType(NULL, $3);
  }
| TM_ENUM_TYPE TM_IDENT
  {
    $$ = TEnumType($2);
  }

|  TM_INT_TYPE
  {
    $$ = TIntType();
  }
| TM_CHAR_TYPE
  {
    $$ = TCharType();
  }
| TM_IDENT
  {
    $$ = TDefinedType($1);
  }
;





NT_GLOB_ITEM:
  TM_STRUCT_TYPE TM_IDENT TM_LEFT_BRACE NT_FIELD_LIST TM_RIGHT_BRACE TM_SEMICOL
  {
    $$ = TStructDef($2, $4);
  }
| TM_STRUCT_TYPE TM_IDENT TM_SEMICOL
  {
    $$ = TStructDecl($2);
  }

| TM_UNION_TYPE TM_IDENT TM_LEFT_BRACE NT_FIELD_LIST TM_RIGHT_BRACE TM_SEMICOL
  {
    $$ = TUnionDef($2, $4);
  }
| TM_UNION_TYPE TM_IDENT TM_SEMICOL
  {
    $$ = TUnionDecl($2);
  }

| TM_ENUM_TYPE TM_IDENT TM_LEFT_BRACE NT_ENUM_ELE_LIST TM_RIGHT_BRACE TM_SEMICOL
  {
    $$ = TEnumDef($2, $4);
  }
| TM_ENUM_TYPE TM_IDENT TM_SEMICOL
  {
    $$ = TEnumDecl($2);
  }

| TM_TYPEDEF_TYPE NT_LEFT_TYPE NT_NAMED_RIGHT_TYPE_EXPR TM_SEMICOL
  {
    $$ = TTypeDef($2, $3);
  }

| NT_LEFT_TYPE NT_NAMED_RIGHT_TYPE_EXPR TM_SEMICOL
  {
    $$ = TVarDef($1, $2);
  }
;






%%

void yyerror(char* s)
{
    fprintf(stderr , "%s\n",s);
}

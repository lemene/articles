%token_type {int}  
   
%left PLUS MINUS.   
%left DIVIDE TIMES.  
   
%include {   
#include <stdio.h>  
#include <assert.h>
}  
   
%syntax_error {  
  printf("Parse Error\n");  
}   
   
program ::= expr(A).   { printf("Result: %d\n", A); }  
   
expr(A) ::= expr(B) MINUS  expr(C).   { A = B - C; }  
expr(A) ::= expr(B) PLUS  expr(C).   { A = B + C; }  
expr(A) ::= expr(B) TIMES  expr(C).   { A = B * C; }  
expr(A) ::= expr(B) DIVIDE expr(C).  { A = B / C; }   // not checking C == 0
expr(A) ::= INTEGER(B). { A = B; } 

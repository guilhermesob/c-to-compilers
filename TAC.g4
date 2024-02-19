grammar TAC;

// Lexer rules
WS : [ \t\r\n]+ -> skip; // skip whitespaces
ID : [a-zA-Z]+;
NUMBER : [0-9]+;
OPERATOR : ('+' | '-' | '*' | '/');

// Parser rules
tac_program : tac_instruction+;

tac_instruction : ID '=' expr
                | 'goto' ID
                ;

expr : ID OPERATOR ID
     | ID OPERATOR NUMBER
     ;


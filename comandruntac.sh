# generated lexer and parser files
antlr4 -Dlanguage=C TAC.g4

#run your TAC compiler with input TAC code

./tac_compiler input.tac

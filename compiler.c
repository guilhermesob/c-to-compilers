#include <stdio.h>
#include "TACLexer.h"
#include "TACParser.h"

int main(int argc, char *argv[]) {
    // Create ANTLR input stream from stdin
    pANTLR3_INPUT_STREAM input;
    input = antlr3FileStreamNew((pANTLR3_UINT8)argv[1], ANTLR3_ENC_8BIT);

    // Create lexer
    pTACLexer lexer;
    lexer = TACLexerNew(input);
    pANTLR3_COMMON_TOKEN_STREAM tokens;
    tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lexer));

    // Create parser
    pTACParser parser;
    parser = TACParserNew(tokens);

    // Parse the input
    tac_program_return program = parser->tac_program(parser);

    // Get the AST root node
    pANTLR3_COMMON_TREE_NODE_STREAM nodes;
    nodes = antlr3CommonTreeNodeStreamNewTree(program.tree, ANTLR3_SIZE_HINT);

    // Do something with the AST
    // For simplicity, just print the tree
    printf("AST:\n%s\n", program.tree->toStringTree(program.tree)->chars);

    // Clean up
    nodes->free(nodes);
    parser->free(parser);
    tokens->free(tokens);
    lexer->free(lexer);
    input->close(input);

    return 0;
}

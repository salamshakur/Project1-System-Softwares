/* for main.c */
void    fileReader(int argc, char ** argv);

/* for lex.c */
void    scanner();
void    printSource();
int     getReserved(char * name);
int     getSpecial(char * name);
void    printTable();
void    printList();
void    ERROR_Lex(int val);

/* for vm.c */
void    virtual();
void    fetch();
char  * getOperationName(int op);
void    initialize();
void    execute(instr ir);
void    printInstructions(int n, instr * ir);
void    printRun(instr ir);
void    printStack();
void    printRegisters();
int     base(int l, int base);
void    ERROR_StackOverflow();

/* for syn.c */
void    parser();
void    program();
void    block();
void    constDeclaration();
void    varDeclaration();
void    procDeclaration();
void    statementDeclaration();
void    conditionDeclaration();
void    expressionDeclaration();
int     rel_opDeclaration(int tokenType);
void    termDeclaration();
void    factorDeclaration();
int     lookUp();
void    insert();
void    emit(int op, int r, int l, int m);
void    ERROR_Syn(int val);
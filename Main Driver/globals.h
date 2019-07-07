/* for main.c */
FILE   * fp;

/* for lex.c */
table  * lexemes;
token  * arr;
char     c;
int      countId  = 0;
int      countNum = 0;
int      countSym = 0;
int      countTb  = 0;
char     tempID[maxChar + 1];
char     tempNum[maxInt + 1];
char     tempSym[maxSym + 1];

/* for vm.c */
instr *  ir;
int   *  ds;   // datastack
int   *  rf;   // register file
int      pc;   // program counter
int      bp;   // base pointer
int      gp;   // global pointer
int      sp;   // stack pointer
int      hlt;  // halt flag

/* for syn.c */
symbol * symTable;
int      symCount;
int      lexCount;
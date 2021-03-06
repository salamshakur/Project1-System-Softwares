void scanner()
{
    lexemes = malloc(sizeof(table));
    arr = malloc(sizeof(token) * 100000);
    lexemes->arr = arr;
    
    printSource();
    
    while(!feof(fp))
    {
        c = fgetc(fp);

        if(isalpha(c))
        {
            while((isalnum(c)) && !ispunct(c))
            {   
                if(countId >= maxChar)
                    ERROR_Lex(3);
                tempID[countId] = c;
                countId++;
                c = fgetc(fp);
            }
            tempID[countId] = '\0';

            token tk;
            strcpy(tk.name, tempID);
            tk.tokenType = getReserved(tk.name);
            lexemes->arr[countTb] = tk;
            lexemes->size = countTb + 1;
            memset(tempID, 0, sizeof(tempID));
            countId = 0;
            countTb++;
        }

        if(isdigit(c))
        {
            while(!ispunct(c) && !isspace(c))
            {
                if(isalpha(c))
                    ERROR_Lex(1);
                if(countNum >= maxInt)
                    ERROR_Lex(2);
                tempNum[countNum] = c;
                countNum++;
                c = fgetc(fp);
            }
            tempNum[countNum] = '\0';

            token tk;
            strcpy(tk.name, tempNum);
            tk.tokenType = numbersym;
            lexemes->arr[countTb] = tk;
            lexemes->size = countTb + 1;
            memset(tempNum, 0, sizeof(tempNum));
            countNum = 0;
            countTb++;
        }

        if(ispunct(c))
        {
            if(c == ':')
            {
                tempSym[countSym] = c;
                countSym++;

                c = fgetc(fp);

                if(c != '=')
                {
                    ERROR_Lex(4);
                }
                else
                {  
                    tempSym[countSym] = c;
                    countSym++;
                    tempSym[countSym] = '\0';

                    token tk;
                    strcpy(tk.name, tempSym);
                    tk.tokenType = getSpecial(tk.name);
                    lexemes->arr[countTb] = tk;
                    lexemes->size = countTb + 1;
                    memset(tempSym, 0, sizeof(tempSym));
                    countSym = 0;
                    countTb++;
                }
            }
            else if(c == '/')
            {
                tempSym[countSym] = c;
                countSym++;
                c = fgetc(fp);

                if(c != '*')
                {
                    tempSym[countSym] = '\0';
                    token tk;
                    strcpy(tk.name, tempSym);
                    tk.tokenType = getSpecial(tk.name);
                    lexemes->arr[countTb] = tk;
                    lexemes->size = countTb + 1;
                    memset(tempSym, 0, sizeof(tempSym));
                    countSym = 0;
                    countTb++;
                }
               
               if(c == '*')
               {
                   int flag = 1;
                   while(flag)
                   {   
                        c = fgetc(fp);

                        while(c != '*')
                        {   
                            c = fgetc(fp);
                            if(feof(fp))
                                ERROR_Lex(5);
                        }

                        c = fgetc(fp);
                        
                        if(c == '*')
                            ungetc(c, fp);

                        if(c == '/')
                            flag = 0;       
                   }
                   memset(tempSym, 0, sizeof(tempSym));
                   countSym = 0;
               }

            }
            else if(c == '!')
            {
                tempSym[countSym] = c;
                countSym++;
                c = fgetc(fp);

                if(c != '=')
                {
                    ERROR_Lex(4);
                }
                else
                {
                    tempSym[countSym] = c;
                    countSym++;
                    tempSym[countSym] = '\0';

                    token tk;
                    strcpy(tk.name, tempSym);
                    tk.tokenType = getSpecial(tk.name);
                    lexemes->arr[countTb] = tk;
                    lexemes->size = countTb + 1;
                    memset(tempSym, 0, sizeof(tempSym));
                    countSym = 0;
                    countTb++;
                }
            }
            else if(c == '<')
            {
                tempSym[countSym] = c;
                countSym++;
                c = fgetc(fp);

                if(c == '>')
                {
                    tempSym[countSym] = c;
                    countSym++;
                    tempSym[countSym] = '\0';

                    token tk;
                    strcpy(tk.name, tempSym);
                    tk.tokenType = getSpecial(tk.name);
                    lexemes->arr[countTb] = tk;
                    lexemes->size = countTb + 1;
                    memset(tempSym, 0, sizeof(tempSym));
                    countSym = 0;
                    countTb++;
                }
                else if(c == '=')
                {
                    tempSym[countSym] = c;
                    countSym++;
                    tempSym[countSym] = '\0';

                    token tk;
                    strcpy(tk.name, tempSym);
                    tk.tokenType = getSpecial(tk.name);
                    lexemes->arr[countTb] = tk;
                    lexemes->size = countTb + 1;
                    memset(tempSym, 0, sizeof(tempSym));
                    countSym = 0;
                    countTb++;
                }
                else
                {
                    tempSym[countSym] = '\0';

                    token tk;
                    strcpy(tk.name, tempSym);
                    tk.tokenType = getSpecial(tk.name);
                    lexemes->arr[countTb] = tk;
                    lexemes->size = countTb + 1;
                    memset(tempSym, 0, sizeof(tempSym));
                    countSym = 0;
                    countTb++;
                }
                
            }
            else if(c == '>')
            {
                tempSym[countSym] = c;
                countSym++;
                c = fgetc(fp);

                if(c != '=')
                {
                    tempSym[countSym] = '\0';

                    token tk;
                    strcpy(tk.name, tempSym);
                    tk.tokenType = getSpecial(tk.name);
                    lexemes->arr[countTb] = tk;
                    lexemes->size = countTb + 1;
                    memset(tempSym, 0, sizeof(tempSym));
                    countSym = 0;
                    countTb++;
                }
                
                if(c == '=')
                {
                    tempSym[countSym] = c;
                    countSym++;
                    tempSym[countSym] = '\0';

                    token tk;
                    strcpy(tk.name, tempSym);
                    tk.tokenType = getSpecial(tk.name);
                    lexemes->arr[countTb] = tk;
                    lexemes->size = countTb + 1;
                    memset(tempSym, 0, sizeof(tempSym));
                    countSym = 0;
                    countTb++;
                }
            } 
            else
            {
                tempSym[countSym] = c;
                countSym++;
                tempSym[countSym] = '\0';

                token tk;
                strcpy(tk.name, tempSym);
                tk.tokenType = getSpecial(tk.name);
                lexemes->arr[countTb] = tk;
                lexemes->size = countTb + 1;
                memset(tempSym, 0, sizeof(tempSym));
                countSym = 0;
                countTb++;
            }
        }
    }

    printTable();
    printList();
}

int getReserved(char name[maxChar])
{
    if (strcmp(name, "const")     == 0) return constsym;
    if (strcmp(name, "var")       == 0) return varsym;
    if (strcmp(name, "procedure") == 0) return procsym;
    if (strcmp(name, "call")      == 0) return callsym;
    if (strcmp(name, "begin")     == 0) return beginsym;
    if (strcmp(name, "end")       == 0) return endsym;
    if (strcmp(name, "if")        == 0) return ifsym;
    if (strcmp(name, "then")      == 0) return thensym;
    if (strcmp(name, "else")      == 0) return elsesym;
    if (strcmp(name, "while")     == 0) return whilesym;
    if (strcmp(name, "do")        == 0) return dosym;
    if (strcmp(name, "read")      == 0) return readsym;
    if (strcmp(name, "write")     == 0) return writesym;
    if (strcmp(name, "odd")       == 0) return oddsym;
    if (strcmp(name, "mult")      == 0) return multsym;
    return identsym;
}

int getSpecial(char name[maxSym])
{
    if (strcmp(name, "+")   == 0) return plussym;
    if (strcmp(name, "-")   == 0) return minussym;
    if (strcmp(name, "*")   == 0) return multsym;
    if (strcmp(name, "/")   == 0) return slashsym;
    if (strcmp(name, "(")   == 0) return lparentsym;
    if (strcmp(name, ")")   == 0) return rparentsym;
    if (strcmp(name, "=")   == 0) return eqsym;
    if (strcmp(name, ",")   == 0) return commasym;
    if (strcmp(name, ".")   == 0) return periodsym;
    if (strcmp(name, "<")   == 0) return lessym;
    if (strcmp(name, ">")   == 0) return gtrsym;
    if (strcmp(name, ";")   == 0) return semicolonsym;
    if (strcmp(name, ":=")  == 0) return becomessym;
    if (strcmp(name, "<>")  == 0) return neqsym;
    if (strcmp(name, "<=")  == 0) return leqsym;
    if (strcmp(name, ">=")  == 0) return geqsym;
    ERROR_Lex(4);
}

void printSource()
{
    char c;
    printf("\nSource Program: \n");
    while(!feof(fp))
    {
        c = fgetc(fp);

        if(c != EOF)
            printf("%c", c);
    }
    printf("\n\n");

    rewind(fp);
}

void printTable()
{
    printf("Lexeme Table: \n");
    printf("lexeme \t token type \n");
    int j = lexemes->size;
    for(int i = 0; i < j; i++)
    {
        printf("%s \t %d \n", lexemes->arr[i].name, lexemes->arr[i].tokenType);
    }
    printf("\n\n");
}

void printList()
{
    printf("Lexeme List: \n");
    int j = lexemes->size;
    for(int i = 0; i < j; i++)
    {
        token tk = lexemes->arr[i];
        if(tk.tokenType == identsym || tk.tokenType == numbersym)
            printf("%d %s ", tk.tokenType, tk.name);
        else
            printf("%d ", tk.tokenType);
    }
    printf("\n\n");
}

void ERROR_Lex(int val)
{
    char * message;
    switch(val)
    {
        case 1: message = "Variable des not start with letter.";  break;
        case 2: message = "Number too long."; break;
        case 3: message = "Name too long."; break;
        case 4: message = "Invalid symbols."; break;
        case 5: message = "Comment not properly closed."; break;
    }
    printf("Error hit! %s \n", message);
    exit(1);
}

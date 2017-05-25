

enum tokens{TYPE,NAME,NUMBER,STRING,OPERATOR,IF,ELSE,ELSEIF,WHILE,FUNCTION,EQUA,
                       OTHER,RETURN};

typedef struct Token
{
    char *value;//la valeur du 
    enum tokens tok;//le token approprier
}Token;


//
typedef struct Tokens
{
    Token *this;// le token de ce noeud
    struct Tokens *svt;// le suivant 
}Tokens;


Tokens *Tokens_Add(Tokens *t,enum tokens tok,char *value)
{
    Tokens *tmp =(Tokens *)malloc(sizeof(Tokens));
    tmp->this = (Token *) malloc(sizeof(Token));
    tmp->this->value = (char *)malloc(strlen(value));
    strcpy(tmp->this->value,value);
    tmp->this->tok = tok;
    tmp->svt = NULL;
    if(t == NULL)   return tmp;
    Tokens *tmp1 = t;
    while(tmp1->svt)
        tmp1 = tmp1->svt;
    tmp1->svt = tmp;
    return t;
}//fin de la fonction






Tokens *Lexer(char *chaine)
{
    Tokens *toks = NULL;
    int taille = strlen(chaine);
    char c[2] = {' ','\0'};
    char lexeme[300] = "";
    int e;
    e = 0;
    for(int i=0;i<taille;i++)
    {
        c[0] = chaine[i];
        if((c[0]==' ' || c[0]=='\n' || c[0]=='\t'))
        {
            if(strcmp(lexeme,"") == 0)
                ;//do nothing
            else if (estMotCle(lexeme) && strcmp(lexeme,"return") == 0)
                toks = Tokens_Add(toks,RETURN,lexeme);
            else if(estType(lexeme))
                 toks = Tokens_Add(toks,TYPE,lexeme);
            else if(estNombre(lexeme))
                toks = Tokens_Add(toks,NUMBER,lexeme);
            else if(strcmp(lexeme,"if") == 0)
                toks = Tokens_Add(toks,IF,lexeme);
             else if(strcmp(lexeme,"elseif") == 0)
                toks = Tokens_Add(toks,ELSEIF,lexeme);
             else if(strcmp(lexeme,"else") == 0)
                toks = Tokens_Add(toks,ELSE,lexeme);
             else if(strcmp(lexeme,"while") == 0)
                toks = Tokens_Add(toks,WHILE,lexeme);
             else if(strcmp(lexeme,"function") == 0)
                toks = Tokens_Add(toks,FUNCTION,lexeme);
             else 
                toks = Tokens_Add(toks,NAME,lexeme);
            strcpy(lexeme,"");
            continue;
        }
        
        if(c[0] == ';' || c[0]==','|| c[0]=='.'|| c[0]=='('|| c[0]==')'|| c[0]=='{'|| c[0]=='}')
            {
                    if(strcmp(lexeme,"") == 0)
                ;//do nothing
            else if(estType(lexeme))
                 toks = Tokens_Add(toks,TYPE,lexeme);
            else if(estNombre(lexeme))
                toks = Tokens_Add(toks,NUMBER,lexeme);
            else if(strcmp(lexeme,"if") == 0)
                toks = Tokens_Add(toks,IF,lexeme);
             else if(strcmp(lexeme,"elseif") == 0)
                toks = Tokens_Add(toks,ELSEIF,lexeme);
             else if(strcmp(lexeme,"else") == 0)
                toks = Tokens_Add(toks,ELSE,lexeme);
             else if(strcmp(lexeme,"while") == 0)
                toks = Tokens_Add(toks,WHILE,lexeme);
             else if(strcmp(lexeme,"function") == 0)
                toks = Tokens_Add(toks,FUNCTION,lexeme);
             else 
                toks = Tokens_Add(toks,NAME,lexeme);

                toks = Tokens_Add(toks,OTHER,c);
                strcpy(lexeme,"");
                continue;
            } 
        if(c[0] == '=')
        {
            if(strcmp(lexeme,"") == 0)
                ;//do nothing
            else if(estType(lexeme))
                 toks = Tokens_Add(toks,TYPE,lexeme);
            else if(estNombre(lexeme))
                toks = Tokens_Add(toks,NUMBER,lexeme);
            else if(strcmp(lexeme,"if") == 0)
                toks = Tokens_Add(toks,IF,lexeme);
             else if(strcmp(lexeme,"elseif") == 0)
                toks = Tokens_Add(toks,ELSEIF,lexeme);
             else if(strcmp(lexeme,"else") == 0)
                toks = Tokens_Add(toks,ELSE,lexeme);
             else if(strcmp(lexeme,"while") == 0)
                toks = Tokens_Add(toks,WHILE,lexeme);
             else if(strcmp(lexeme,"function") == 0)
                toks = Tokens_Add(toks,FUNCTION,lexeme);
             else 
                toks = Tokens_Add(toks,NAME,lexeme);
                strcpy(lexeme,"");
                strcat(lexeme,c);
                if(i+1<taille && chaine[i+1] == '=')
                        {
                            c[0] = chaine[i++];
                            strcat(lexeme,c);
                            toks = Tokens_Add(toks,OPERATOR,lexeme);
                              strcpy(lexeme,"");
                                continue;
                        }
                toks = Tokens_Add(toks,EQUA,c);
                strcpy(lexeme,"");
                continue;
        }
        if(c[0] == '+' || c[0] == '-' || c[0] == '/' || c[0] == '*' || c[0] == '%')
            {
                 if(strcmp(lexeme,"") == 0)
                ;//do nothing
            else if(estType(lexeme))
                 toks = Tokens_Add(toks,TYPE,lexeme);
            else if(estNombre(lexeme))
                toks = Tokens_Add(toks,NUMBER,lexeme);
            else if(strcmp(lexeme,"if") == 0)
                toks = Tokens_Add(toks,IF,lexeme);
             else if(strcmp(lexeme,"elseif") == 0)
                toks = Tokens_Add(toks,ELSEIF,lexeme);
             else if(strcmp(lexeme,"else") == 0)
                toks = Tokens_Add(toks,ELSE,lexeme);
             else if(strcmp(lexeme,"while") == 0)
                toks = Tokens_Add(toks,WHILE,lexeme);
             else if(strcmp(lexeme,"function") == 0)
                toks = Tokens_Add(toks,FUNCTION,lexeme);
             else 
                toks = Tokens_Add(toks,NAME,lexeme);

                toks = Tokens_Add(toks,OPERATOR,c);
                strcpy(lexeme,"");
                continue;
            }

            if(c[0] == '\"')
            {
                 if(strcmp(lexeme,"") == 0)
                ;//do nothing
            else if(estType(lexeme))
                 toks = Tokens_Add(toks,TYPE,lexeme);
            else if(estNombre(lexeme))
                toks = Tokens_Add(toks,NUMBER,lexeme);
            else if(strcmp(lexeme,"if") == 0)
                toks = Tokens_Add(toks,IF,lexeme);
             else if(strcmp(lexeme,"elseif") == 0)
                toks = Tokens_Add(toks,ELSEIF,lexeme);
             else if(strcmp(lexeme,"else") == 0)
                toks = Tokens_Add(toks,ELSE,lexeme);
             else if(strcmp(lexeme,"while") == 0)
                toks = Tokens_Add(toks,WHILE,lexeme);
             else if(strcmp(lexeme,"function") == 0)
                toks = Tokens_Add(toks,FUNCTION,lexeme);
             else 
                toks = Tokens_Add(toks,NAME,lexeme);

                
               while(1 )
               { 
                   i++;
                   if(i>=taille) {
                       strcat(lexeme,c);
                       break;
                   }
                  if(c[0]!='\\' && chaine[i]=='\"')
                   {
                        strcat(lexeme,c);
                        break;
                   }
                     strcat(lexeme,c);
                    c[0] = chaine[i];
                   
               }
               strcat(lexeme,"\"");
                toks = Tokens_Add(toks,STRING,lexeme);
                strcpy(lexeme,"");
                continue;
            }


            if(c[0] == '<' || c[0] == '>' || c[0] == '|' || c[0] == '&' || c[0] == '!')
            {
                   if(strcmp(lexeme,"") == 0)
                ;//do nothing
            else if(estType(lexeme))
                 toks = Tokens_Add(toks,TYPE,lexeme);
            else if(estNombre(lexeme))
                toks = Tokens_Add(toks,NUMBER,lexeme);
            else if(strcmp(lexeme,"if") == 0)
                toks = Tokens_Add(toks,IF,lexeme);
             else if(strcmp(lexeme,"elseif") == 0)
                toks = Tokens_Add(toks,ELSEIF,lexeme);
             else if(strcmp(lexeme,"else") == 0)
                toks = Tokens_Add(toks,ELSE,lexeme);
             else if(strcmp(lexeme,"while") == 0)
                toks = Tokens_Add(toks,WHILE,lexeme);
             else if(strcmp(lexeme,"function") == 0)
                toks = Tokens_Add(toks,FUNCTION,lexeme);
             else 
                toks = Tokens_Add(toks,NAME,lexeme);
                  strcpy(lexeme,"");
                  strcat(lexeme,c);
                
                if(i+1<taille)
                    if(chaine[i+1] == '=' || chaine[i+1] == '|' || chaine[i+1] == '&')
                             {   
                                 i = i+1;
                                 c[0] = chaine[i];
                                  strcat(lexeme,c);
                              }
                   
                    toks = Tokens_Add(toks,OPERATOR,lexeme);
                    strcpy(lexeme,"");
                    continue;        
                
            }//end if

            strcat(lexeme,c);
            if(i+1 == taille)
                {
                      if(strcmp(lexeme,"") == 0)
                ;//do nothing
            else if(estType(lexeme))
                 toks = Tokens_Add(toks,TYPE,lexeme);
            else if(estNombre(lexeme))
                toks = Tokens_Add(toks,NUMBER,lexeme);
            else if(strcmp(lexeme,"if") == 0)
                toks = Tokens_Add(toks,IF,lexeme);
             else if(strcmp(lexeme,"elseif") == 0)
                toks = Tokens_Add(toks,ELSEIF,lexeme);
             else if(strcmp(lexeme,"else") == 0)
                toks = Tokens_Add(toks,ELSE,lexeme);
             else if(strcmp(lexeme,"while") == 0)
                toks = Tokens_Add(toks,WHILE,lexeme);
             else if(strcmp(lexeme,"function") == 0)
                toks = Tokens_Add(toks,FUNCTION,lexeme);
             else 
                toks = Tokens_Add(toks,NAME,lexeme);

                }//fin if
         }//fin for 

           
              
   /* Tokens *tmp = toks;
    while(tmp)
    {
        printf("%s %d\n",tmp->this->value,tmp->this->tok);
        tmp = tmp->svt;
    }*/

    return toks;
}//fin de la fonction

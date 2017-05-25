

enum tree {DECLVAR , DECFUNCT , AFFICHAGE , AFFECTATION , TIF,TELSEIF,TELSE,BOUCLE,USEFUNC,TRETURN};



typedef struct Trees{
    enum tree type;
    Tokens *toks;
    struct Trees *svt;
}Trees;

Trees *Trees_Add(Trees *tr,enum tree type,Tokens *toks)
{
    Trees *tmp = (Trees *)malloc(sizeof(Trees));
    tmp->type = type;
    tmp->toks = toks;
    tmp->svt = NULL;
    if( tr == NULL) return tmp;
    Trees *tmp1 = tr;
    while(tmp1->svt)
        tmp1 = tmp1->svt;
    tmp1->svt = tmp;
    return tr;
}//fin fonction


Trees *Parser(Tokens *toks)
{
    Trees *trs = NULL; // Trees ou on va stocker le resultat du parser
    Tokens *tmp = toks;

    while(tmp)//la boucle de lecture
    {


         if(tmp->this->tok == RETURN)
        {
            Tokens *newt = NULL;
            while(tmp)
            {
                    newt = Tokens_Add(newt,tmp->this->tok,tmp->this->value);

                     if(strcmp(tmp->this->value,";") == 0)
                    break;
                    tmp = tmp->svt;
            }// while
            
            trs = Trees_Add(trs,TRETURN,newt);
        }// if tok == type;
      
      /*    le cas d un declarage d une variable */
        if(tmp->this->tok == TYPE)
        {
            Tokens *newt = NULL;
            while(tmp)
            {
                    newt = Tokens_Add(newt,tmp->this->tok,tmp->this->value);

                     if(strcmp(tmp->this->value,";") == 0)
                    break;
                    tmp = tmp->svt;
            }// while
            
            trs = Trees_Add(trs,DECLVAR,newt);
        }// if tok == type;

        /*  Le cas d un affichage*/
       else if(tmp->this->tok == NUMBER || tmp->this->tok == NAME || tmp->this->tok == STRING || tmp->this->tok == OPERATOR || 
            tmp->this->tok == OTHER && strcmp(tmp->this->value,"(")==0)
        {
            Tokens *newt = NULL;
            while(tmp)
            {   
                    newt = Tokens_Add(newt,tmp->this->tok,tmp->this->value);

                     if(strcmp(tmp->this->value,";") == 0)
                    break;
                    tmp = tmp->svt;
            }// while
            trs = Trees_Add(trs,AFFICHAGE,newt);
        }//fin cas de l affichage



        /*le cas d une condition if*/
        else if(tmp->this->tok == IF)
        {
             Tokens *newt = NULL;
             int pile_bracket = 0;
             int avec_bracket = 0;
            while(tmp)
            {
                    newt = Tokens_Add(newt,tmp->this->tok,tmp->this->value);
                    if(strcmp(tmp->this->value,"{")==0)
                       { pile_bracket++;
                       avec_bracket++;}
                     if(strcmp(tmp->this->value,"}")==0) 
                        pile_bracket--;
                    if(avec_bracket!=0 && pile_bracket == 0 )
                        break;
                     if(strcmp(tmp->this->value,";") == 0 && pile_bracket == 0)
                    break;
                    tmp = tmp->svt;
            }// while
            trs = Trees_Add(trs,TIF,newt);
        }//fin cas condition

        /*le cas d une condition else if*/
        else if(tmp->this->tok == ELSEIF)
        {
            Tokens *newt = NULL;
             int pile_bracket = 0;
             int avec_bracket = 0;
            while(tmp)
            {
                    newt = Tokens_Add(newt,tmp->this->tok,tmp->this->value);
                    if(strcmp(tmp->this->value,"{")==0)
                       { pile_bracket++;
                       avec_bracket++;}
                     if(strcmp(tmp->this->value,"}")==0) 
                        pile_bracket--;
                    if(avec_bracket!=0 && pile_bracket == 0 )
                        break;
                     if(strcmp(tmp->this->value,";") == 0 && pile_bracket == 0)
                    break;
                    tmp = tmp->svt;
            }// while
            trs = Trees_Add(trs,TELSEIF,newt);
        }//fin cas condition


        /*le cas d une condition else */
       else  if(tmp->this->tok == ELSE)
        {
            Tokens *newt = NULL;
             int pile_bracket = 0;
             int avec_bracket = 0;
            while(tmp)
            {
                    newt = Tokens_Add(newt,tmp->this->tok,tmp->this->value);
                    if(strcmp(tmp->this->value,"{")==0)
                       { pile_bracket++;
                       avec_bracket++;}
                     if(strcmp(tmp->this->value,"}")==0) 
                        pile_bracket--;
                    if(avec_bracket!=0 && pile_bracket == 0 )
                        break;
                     if(strcmp(tmp->this->value,";") == 0 && pile_bracket == 0)
                    break;
                    tmp = tmp->svt;
            }// while
            trs = Trees_Add(trs,TELSE,newt);
        }//fin cas condition


         /*le cas d une boucle */
       else  if(tmp->this->tok == WHILE)
        {
             Tokens *newt = NULL;
             int pile_bracket = 0;
             int avec_bracket = 0;
            while(tmp)
            {
                    newt = Tokens_Add(newt,tmp->this->tok,tmp->this->value);
                    if(strcmp(tmp->this->value,"{")==0)
                       { pile_bracket++;
                       avec_bracket++;}
                     if(strcmp(tmp->this->value,"}")==0) 
                        pile_bracket--;
                    if(avec_bracket!=0 && pile_bracket == 0 )
                        break;
                     if(strcmp(tmp->this->value,";") == 0 && pile_bracket == 0)
                    break;
                    tmp = tmp->svt;
            }// while
            trs = Trees_Add(trs,BOUCLE,newt);
        }//fin cas condition


        else if (tmp->this->tok == FUNCTION)
        {
              Tokens *newt = NULL;
             int pile_bracket = 0;
             int avec_bracket = 0;
            while(tmp)
            {
                    newt = Tokens_Add(newt,tmp->this->tok,tmp->this->value);
                    if(strcmp(tmp->this->value,"{")==0)
                       { pile_bracket++;
                       avec_bracket++;}
                     if(strcmp(tmp->this->value,"}")==0) 
                        pile_bracket--;
                    if(avec_bracket!=0 && pile_bracket == 0 )
                        break;
                    
                    tmp = tmp->svt;
            }// while
            trs = Trees_Add(trs,DECFUNCT,newt);
        }//fin partie fonction


        if(tmp)
            tmp = tmp->svt;//passer à l element suivant
    }  //fin while



    /*  AFFICHAGE   */
    Trees *qq = trs;
    while(qq)
    {
         Tokens *qq1 = qq->toks;
    while(qq1)
    {
        printf("%s ",qq1->this->value);
        qq1 = qq1->svt;
    }
    printf("\n");//affichage
        qq = qq->svt;
    }
return trs;
}//fin fonction
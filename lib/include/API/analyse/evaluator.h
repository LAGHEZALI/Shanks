

char *Fonction_utiliser(Fonction *fct,int n,Parametre *p,AllFonction *allf,Env *envi,char *bakibi, FILE *output);
char *AllFonction_utiliser(AllFonction *allf,char *name,int n,Parametre *p,Env *envi,char *bakibi, FILE *output);



Env  *gerer_declaration(Tokens *toks,Env *envi)
{
    int type = -1;
    if(strcmp(toks->this->value,"var") == 0) type = 0;
    if(strcmp(toks->this->value,"string") == 0) type = 1;
    if(strcmp(toks->this->value,"List") == 0) type = 2;
    if(strcmp(toks->this->value,"Queue") == 0) type = 3;
    if(strcmp(toks->this->value,"Stack") == 0) type = 4;
    if(strcmp(toks->this->value,"Fenetre") == 0) type = 5;
    char name[100];
    char valeur[1000];
    char vvv[3000] = "";
    char essai[3000] = "";

    Tokens *tmp = toks;
    tmp = tmp->svt;
    while(tmp)
    {
        strcpy(name,tmp->this->value);
        tmp = tmp->svt;
        strcpy(vvv,"");
        if(tmp!=NULL && tmp->this->tok == EQUA)
        {
            tmp = tmp->svt;
            
            while(tmp!=NULL && strcmp(tmp->this->value,";")!=0 && strcmp(tmp->this->value,",")!=0)
            {
                if(tmp->this->tok == NAME && 
                    (tmp->svt == NULL || (strcmp(tmp->svt->this->value,"(") !=0 && strcmp(tmp->svt->this->value,".") !=0)  )
                        )// cas of variable
                    strcat(vvv,AllVariable_valeur(envi->allv,tmp->this->value));
                else if(tmp->this->tok == NAME && strcmp(tmp->svt->this->value,"(") !=0)
                {
                    char nomF[100] = "";
                    strcpy(nomF,tmp->this->value);
                    tmp = tmp->svt;//(
                    tmp = tmp->svt;
                    int nbr = 0;
                    Parametre *p = NULL;
                    while(strcmp(tmp->this->value,")") !=0)
                    {
                        tmp = tmp->svt;
                    }//fin while

                }
                else 
                    strcat(vvv,tmp->this->value);
                tmp = tmp->svt;
            }
            
            
        }//if
        envi->allv = AllVariable_ajouter(envi->allv,new_Variable(type,name,calculerExpressionNv1(vvv,valeur)));
        printf("declaration ---->%s=%s\n",name,AllVariable_valeur(envi->allv,name));
        if(tmp)
            tmp = tmp->svt;
    }
    return envi;
}//fin de la fonction






/*cette fonction prend les element de Trees et il l evalue */
const char  *Evalutor(Trees *trs ,Env *envi,char  *bakibi, FILE *output)
{
    Trees  *tmp = trs;
   
    char ab[500];

    int etat_condition = 0;
    while(tmp)
    {
        
        //cas d affichage 
        if(tmp->type==AFFICHAGE)
        {   
            char res[1000];
                Tokens *tmp1= tmp->toks;
                if(tmp1->this->tok == NAME && tmp1->svt && tmp1->svt->this->tok == EQUA) // le cas d affectation
                {
                     printf("affecation---> %s \n",calculerExpressionNv0(tmp1->svt->svt,envi,res,output));
                     envi->allv = AllVariable_modifier(envi->allv,tmp1->this->value,calculerExpressionNv0(tmp1->svt->svt,envi,res,output));
                     
                }
                else 
                    printf("affichage---> %s\n",calculerExpressionNv0(tmp->toks,envi,res,output));
                    /*affichage*/
                    fprintf(output,"%s\n",calculerExpressionNv0(tmp->toks,envi,res,output));
                    /*affichage*/
        }//fin if

        //cas de declaration d une variable
         if(tmp->type==DECLVAR)
         {
                gerer_declaration(tmp->toks,envi);
            
         }//end cas de la declaration
    
        /*la cas d une condition */
         if(tmp->type == TIF)
         { 
             if(tmp->svt && (tmp->svt->type == TELSE|| tmp->svt->type == TELSEIF) )
             etat_condition = 1;
            Tokens *tmp1 = tmp->toks;
            Tokens *condition = NULL;
            Tokens *execution = NULL;
            tmp1 = tmp1->svt;
            while(tmp1) // lire la dondition 
            {
                if(strcmp(tmp1->this->value,")") == 0)
                  {  condition = Tokens_Add(condition,tmp1->this->tok,tmp1->this->value); break;}
                     condition = Tokens_Add(condition,tmp1->this->tok,tmp1->this->value);
                tmp1 = tmp1->svt;
            }
            tmp1 = tmp1->svt;// --->{
            char res[100]="";
            strcpy(res,calculerExpressionNv0(condition,envi,res,output));
            strcat(res,">=1");
            strcpy(res,calculerExpressionNv1(res,res));
            if(strcmp(res,"1") == 0)
                {   
                     etat_condition = 0;//ca veut dire que la condtion est executer
                    if(strcmp(tmp1->this->value,"{") == 0)
                        {   
                            tmp1 = tmp1->svt;
                            while(tmp1)
                            {
                                if(strcmp(tmp1->this->value,"}") == 0)
                                   { tmp1 = tmp1->svt;break;}
                                    execution = Tokens_Add(execution,tmp1->this->tok,tmp1->this->value);
                                tmp1 = tmp1->svt;
                            }
                            Trees *trees = Parser(execution);
                            Evalutor(trees,envi,bakibi,output);
                        }
                        else 
                        {
                             while(tmp1)
                            {
                            
                                    execution = Tokens_Add(execution,tmp1->this->tok,tmp1->this->value);
                                tmp1 = tmp1->svt;
                            }
                            Trees *trees = Parser(execution);
                          
                            strcpy(bakibi,Evalutor(trees,envi,bakibi,output));
                          
                            if(strcmp(bakibi,"") !=0 )
                                return calculerExpressionNv1(bakibi,bakibi);
                        }
                }

         }// fin  if

         /*la cas d une condition */
         if(tmp->type == TELSEIF)
         { 
              if(etat_condition != 0) {
             if(tmp->svt && (tmp->svt->type == TELSE|| tmp->svt->type == TELSEIF) )
             etat_condition = 1;
            Tokens *tmp1 = tmp->toks;
            Tokens *condition = NULL;
            Tokens *execution = NULL;
            tmp1 = tmp1->svt;
            while(tmp1) // lire la dondition 
            {
                if(strcmp(tmp1->this->value,")") == 0)
                  {  condition = Tokens_Add(condition,tmp1->this->tok,tmp1->this->value); break;}
                     condition = Tokens_Add(condition,tmp1->this->tok,tmp1->this->value);
                tmp1 = tmp1->svt;
            }
            tmp1 = tmp1->svt;
            char res[100]="";
            strcpy(res,calculerExpressionNv0(condition,envi,res,output));
            strcat(res,">=1");
            strcpy(res,calculerExpressionNv1(res,res));
            if(strcmp(res,"1") == 0)
                {   
                     etat_condition = 0;//ca veut dire que la condtion est executer
                    if(strcmp(tmp1->this->value,"{") == 0)
                        {   
                            tmp1 = tmp1->svt;
                            while(tmp1)
                            {
                                if(strcmp(tmp1->this->value,"}") == 0)
                                     { tmp1 = tmp1->svt;break;}
                                    execution = Tokens_Add(execution,tmp1->this->tok,tmp1->this->value);
                                tmp1 = tmp1->svt;
                            }
                            Trees *trees = Parser(execution);
                           Evalutor(trees,envi,bakibi,output);
                        }
                        else 
                        {
                             while(tmp1)
                            {
                            
                                    execution = Tokens_Add(execution,tmp1->this->tok,tmp1->this->value);
                                tmp1 = tmp1->svt;
                            }
                              Trees *trees = Parser(execution);
                          
                            strcpy(bakibi,Evalutor(trees,envi,bakibi,output));
                          
                            if(strcmp(bakibi,"") !=0 )
                                return calculerExpressionNv1(bakibi,bakibi);
                        }
                }
              }
         }//fin elseif

/*la cas d une condition */
         if(tmp->type == TELSE)
         { 
              if(etat_condition != 0) {
           
            Tokens *tmp1 = tmp->toks;
            Tokens *execution = NULL;
            tmp1 = tmp1->svt;
                     etat_condition = 0;//ca veut dire que la condtion est executer
                    if(strcmp(tmp1->this->value,"{") == 0)
                        {   
                            tmp1 = tmp1->svt;
                            while(tmp1)
                            {
                                if(strcmp(tmp1->this->value,"}") == 0)
                                     { tmp1 = tmp1->svt;break;}
                                    execution = Tokens_Add(execution,tmp1->this->tok,tmp1->this->value);
                                tmp1 = tmp1->svt;
                            }
                            Trees *trees = Parser(execution);
                            Evalutor(trees,envi,bakibi,output);
                        }
                        else 
                        {
                             while(tmp1)
                            {
                            
                                    execution = Tokens_Add(execution,tmp1->this->tok,tmp1->this->value);
                                tmp1 = tmp1->svt;
                            }
                             Trees *trees = Parser(execution);
                          
                            strcpy(bakibi,Evalutor(trees,envi,bakibi,output));
                          
                            if(strcmp(bakibi,"") !=0 )
                                return calculerExpressionNv1(bakibi,bakibi);
                        }
                
              }
         }//fin elseif
         

 /*la cas d une condition */
         if(tmp->type == BOUCLE)
         { 
            
            Tokens *tmp1 = tmp->toks;
            Tokens *condition = NULL;
            Tokens *execution = NULL;
            tmp1 = tmp1->svt;
            while(tmp1) // lire la dondition 
            { 
                if(strcmp(tmp1->this->value,")") == 0)
                  {  condition = Tokens_Add(condition,tmp1->this->tok,tmp1->this->value); break;}
                     condition = Tokens_Add(condition,tmp1->this->tok,tmp1->this->value);
                tmp1 = tmp1->svt;
            }
            tmp1 = tmp1->svt;
            Tokens *reap=tmp1;
            char res[100]="";
            strcpy(res,calculerExpressionNv0(condition,envi,res,output));
            strcat(res,">=1");
            strcpy(res,calculerExpressionNv1(res,res));
            while(strcmp(res,"1") == 0)
                {    
                    tmp1 = reap;
                     etat_condition = 0;//ca veut dire que la condtion est executer
                    if(strcmp(tmp1->this->value,"{") == 0)
                        {   
                            tmp1 = tmp1->svt;
                            while(tmp1)
                            {
                                if(strcmp(tmp1->this->value,"}") == 0)
                                     { tmp1 = tmp1->svt;break;}
                                    execution = Tokens_Add(execution,tmp1->this->tok,tmp1->this->value);
                                tmp1 = tmp1->svt;
                            }
                            Trees *trees = Parser(execution);
                            Evalutor(trees,envi,bakibi,output);
                        }
                        else 
                        {
                             while(tmp1)
                            {
                            
                                    execution = Tokens_Add(execution,tmp1->this->tok,tmp1->this->value);
                                tmp1 = tmp1->svt;
                            }
                            // execution du coeur de la boucle 
                            Trees *trees = Parser(execution);
                          
                            strcpy(bakibi,Evalutor(trees,envi,bakibi,output));
                          
                            if(strcmp(bakibi,"") !=0 )
                                return calculerExpressionNv1(bakibi,bakibi);
                        }
                        //reprendre la boucle
                        strcpy(res,"");
                         strcpy(res,calculerExpressionNv0(condition,envi,res,output));
                        strcat(res,">=1");
                        strcpy(res,calculerExpressionNv1(res,res));
                }

         }// fin  boucle

      
         else if(tmp->type == TRETURN)
         {
            strcpy(bakibi, calculerExpressionNv0(tmp->toks->svt,envi,bakibi,output));
             return (const char *)bakibi;
         }

         if(tmp->type == DECFUNCT)
         {
            
             Tokens *tmp1= tmp->toks;
             tmp1 = tmp1->svt;
             char nom_fonction[100] = "";
             strcpy(nom_fonction,tmp1->this->value);//copier le nom de la fonction 
             
             tmp1 = tmp1->svt;// les parametres
             AllVariable *lv = NULL;
             int nbr = 0;
              int type = -1;
                tmp1 = tmp1->svt;
             while(strcmp(tmp1->this->value,")")!=0)
             { 
                 nbr++;
                    if(strcmp(tmp1->this->value,",")==0)
                        tmp1 = tmp1->svt;
                    if(strcmp(tmp1->this->value,"var") == 0) type = 0;
                    if(strcmp(tmp1->this->value,"string") == 0) type = 1;
                     if(strcmp(tmp1->this->value,"List") == 0) type = 2;
                    if(strcmp(tmp1->this->value,"Queue") == 0) type = 3;
                    if(strcmp(tmp1->this->value,"Stack") == 0) type = 4;
                    if(strcmp(tmp1->this->value,"Fenetre") == 0) type = 5;
                    char name_variable[100];
                    tmp1 = tmp1->svt;
                    strcpy(name_variable,tmp1->this->value);
                    lv = AllVariable_ajouter(lv,new_Variable(type,name_variable,""));
                 tmp1 = tmp1->svt;
             }//fin while 
             tmp1 = tmp1->svt;tmp1 = tmp1->svt;// reading content
             char content_f[5000] = "";
             int pile = 0;
             while(!(strcmp(tmp1->this->value,"}")==0 && pile ==0) )
             {
                 if(strcmp(tmp1->this->value,"{")==0)
                    pile ++;
                if(strcmp(tmp1->this->value,"}")==0)
                    pile --;
                 strcat(content_f,tmp1->this->value);
                 
                tmp1 = tmp1->svt;
             }
             Fonction *fct = new_Fonction(type,nom_fonction,lv,content_f);
             envi->allf = AllFonction_add(envi->allf,fct);
             tmp1 = tmp1->svt;//-->}
             printf("%s %d-> %s\n",nom_fonction,nbr,content_f);
         }

        tmp = tmp->svt;//it suivantes
    }//fin while
    return "";
}//fin de la fonction
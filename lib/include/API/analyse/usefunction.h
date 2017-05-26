



Env *Evalutor(Trees *trs ,Env *envi,char  *bakibi, FILE *output);


/* utiliser une fonction */

char *Fonction_utiliser(Fonction *fct,int n,Parametre *p,AllFonction *allf,Env *envi,char *bakibi, FILE *output)
{
        
       
     
       AllVariable *tmp = fct->allv;

    AllVariable *myvr = NULL;// la nouvelle liste de variable 
    while(tmp)
    { 
        fct->allv = AllVariable_modifier(fct->allv,tmp->v->nom,p->valeur);
        myvr = AllVariable_ajouter(myvr,tmp->v);
        p = p->svt;// le parametre suivant
        tmp = tmp->svt;// la variable suivant 
    }
    AllVariable *tmp1 = envi->allv;
    while(tmp1) // on ajoute tout les varialbe qui soit parameter ou pas dans la nouvelle liste de variable
    {
        myvr = AllVariable_ajouter(myvr,tmp1->v);
        tmp1 = tmp1->svt;
    }
    
    Tokens *toks = Lexer(fct->content);
    Trees *tres = Parser(toks);
    
     Env *envi1 = NULL;
     envi1 = (Env *) malloc(sizeof(Env));
     envi1->allv = myvr;
     envi1->allf = envi->allf;
     char mm[10000]="";
   envi1 =  Evalutor(tres,envi1,bakibi,output);
    return bakibi;
}// fin de la fonction 

















// les methode d une fenetre
char *methode_Fenetre(Variable *v,char *name,int n,Parametre *p,AllFonction *allf,Env *envi,char *bakibi)
{ 

    

    int e = 0;
     if(strcmp(name,"creerFenetre") == 0 && n == 1)
    {
        v->val->fen = new_Fenetre_shanks(calculerExpressionNv1(p->valeur,p->valeur),NORMAL,new_Taille(100,155),P_CENTER);
        Fenetre_setContainer(v->val->fen,new_Fixed());

        return "\"vous avez cree une fenetre . \"";
    }
    else if(strcmp(name,"creerFenetre") == 0 && n == 3)
    {
        char tm[1000];
        int x = atoi(calculerExpressionNv1(p->svt->valeur,tm));
        int  y = atoi(calculerExpressionNv1(p->svt->svt->valeur,tm));
       v->val->fen = new_Fenetre_shanks(calculerExpressionNv1(p->valeur,tm),NORMAL,new_Taille(x,y),P_CENTER);
       Fenetre_setContainer(v->val->fen,new_Fixed());

      return "\"vous avez cree une fenetre .\" ";
    }
    else if(strcmp(name,"montrer") == 0 && n == 0)
    {
        if(v->val->fen == NULL)
            return " \"la fenetre n'est pas encore creer .\" ";
        gtk_widget_show_all (v->val->fen->this);
        return " \"la fenetre est maintenant visible.\" ";
    }
    else if(strcmp(name,"actualiser") == 0 && n == 0)
    {
        if(v->val->fen == NULL)
            return " \"la fenetre n'est pas encore creer .\" ";
        gtk_widget_show_all (v->val->fen->this);
        return " \"la fenetre est maintenant visible.\" ";
    }
    else if(strcmp(name,"bye") == 0 && n == 0)
    {
        if(v->val->fen == NULL)
            return " \"la fenetre n'est pas encore creer .\" ";
         gtk_widget_hide (v->val->fen->this);
         return " \"la fenetre est maintenant invisible.\" ";
    }
     else if(strcmp(name,"ajouterBoutton") == 0 && n == 3)
    {
        if(v->val->fen == NULL)
            return " \"la fenetre n'est pas encore creer .\" ";
         char tm[1000]; 
        Container *c =Fenetre_getContainer(v->val->fen);
          int x = atoi(calculerExpressionNv1(p->svt->valeur,tm));
        int  y = atoi(calculerExpressionNv1(p->svt->svt->valeur,tm));
        Component *cpn = new_Button(calculerExpressionNv1(p->valeur,tm));
        Fixed_add(c,cpn->this,x,y);
         return " \"vous avez ajouter un boutton\" ";
    }
    else if(strcmp(name,"ajouterLabel") == 0 && n == 3)
    {
        if(v->val->fen == NULL)
            return " \"la fenetre n'est pas encore creer .\" ";
         char tm[1000]; 
        Container *c =Fenetre_getContainer(v->val->fen);
          int x = atoi(calculerExpressionNv1(p->svt->valeur,tm));
        int  y = atoi(calculerExpressionNv1(p->svt->svt->valeur,tm));
        Component *cpn = new_Label(calculerExpressionNv1(p->valeur,tm),0,0);
        Fixed_add(c,cpn->this,x,y);
         return " \"vous avez ajouter une label.\" ";
    }
     else if(strcmp(name,"ajouterEntry") == 0 && n == 2)
    {
        if(v->val->fen == NULL)
            return " \"la fenetre n'est pas encore creer .\" ";
         char tm[1000]; 
        Container *c =Fenetre_getContainer(v->val->fen);
          int x = atoi(calculerExpressionNv1(p->valeur,tm));
        int  y = atoi(calculerExpressionNv1(p->svt->valeur,tm));
        Component *cpn = new_Entry(NULL);
        Fixed_add(c,cpn->this,x,y);
         return " \"vous avez ajouter un entry.\" ";
    }
    else if(strcmp(name,"ajouterTextview") == 0 && n == 5)
    {
        if(v->val->fen == NULL)
            return " \"la fenetre n'est pas encore creer .\" ";
         char tm[1000]; 
        Container *c =Fenetre_getContainer(v->val->fen);
        int  tx = atoi(calculerExpressionNv1(p->svt->valeur,tm));
        int  ty = atoi(calculerExpressionNv1(p->svt->svt->valeur,tm));
        int  x = atoi(calculerExpressionNv1(p->svt->svt->svt->valeur,tm));
        int  y = atoi(calculerExpressionNv1(p->svt->svt->svt->svt->valeur,tm));
        Component *cpn =new_TextView(1);
        gtk_widget_set_size_request (cpn->this,tx, ty);
        Container *tmp = new_Frame(calculerExpressionNv1(p->valeur,tm),10);
        tmp = Frame_add(tmp,cpn->this);
        Fixed_add(c,tmp->this,x,y);
         return " \"vous avez ajouter un textView.\" ";
    }

    return "\"cette fonction n'est pas encore disponible\"";
}// fin fonction










// utilier une fonction
char *AllFonction_utiliser(AllFonction *allf,char *name,int n,Parametre *p,Env *envi,char *bakibi, FILE *output)
{
    AllFonction *tmp = allf;

    while(tmp)
    {
        if(strcmp(tmp->fct->name,name) == 0 && n == tmp->fct->nbr)
            return Fonction_utiliser(tmp->fct,n,p,allf,envi,bakibi,output);
        tmp = tmp->svt ;
    }
    
    if(strcmp(name,"historique") == 0 &&  n == 0)
    {
        FILE *file;
        
        strcpy(bakibi,"\"");
        file = fopen("historique.txt", "r");

        int i=0;        
        gchar line[256];

        while (fgets(line, sizeof(line), file))
        {
            sprintf(bakibi , "%s %d -- %s \\n",bakibi,++i,line);
            printf( "%s %d -- %s \\n",bakibi,i,line);
        }
        strcat(bakibi,"\"");
        fclose(file);
       // return bakibi;

    }
    else  if(strcmp(name,"historique") == 0 &&  n == 1)
    {
        FILE *file;
        int x = atoi(calculerExpressionNv1(p->valeur,bakibi));
        strcpy(bakibi,"\"");
        file = fopen("historique.txt", "r");

        int i=0;        
        gchar line[256];

        while (fgets(line, sizeof(line), file))
        {
            ++i;
          
                if(i == x)
                {
                     sprintf(bakibi,"\\t   %s \\n",line);
                }
        }
        strcat(bakibi,"\"");
        fclose(file);
        return "\"le rang historique est non valide .\"";

    }
    else  if(strcmp(name,"executerHisto") == 0 &&  n == 1)
        {
            FILE *file;
            int x = atoi(calculerExpressionNv1(p->valeur,bakibi));
            strcpy(bakibi,"\"");
            file = fopen("historique.txt", "r");

            int i=0;        
            gchar line[256];

            while (fgets(line, sizeof(line), file))
            {
                ++i;
            
                    if(i == x)
                    {
                        

                          FILE *output = fopen("lib/include/TEST/out","w+");
                        Tokens *toks = Lexer(line);
                        Trees    *trs   = Parser(toks);
                        Evalutor(trs,&global,bakibi,output);
                        fclose(output);
                        char *azz = readFromFile("lib/include/TEST/out",azz);

                        sprintf(bakibi,"\\t   %s \\n",azz);
                    }
            }
            strcat(bakibi,"\"");
            fclose(file);
            return "\"le rang historique est non valide .\"";

        }

    return " ";
}//fin de la fonction



/*   utilisation des fenetre */
char *Methode_utiliser(Variable *v,char *name,int n,Parametre *p,AllFonction *allf,Env *envi,char *bakibi)
{

    if(v == NULL)
        return "\"cette variable n est pas encore declare .\"";
    int type = v->type;

    if(type  == 5)
        return methode_Fenetre(v,name,n,p,allf,envi,bakibi);




    return " ";
}









const char  *Evalutor(Trees *trs ,Env *envi,char  *bakibi, FILE *output);


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
    
     Env envi1;
     envi1.allv = myvr;
     envi1.allf = envi->allf;
     strcpy(bakibi,Evalutor(tres,&envi1,bakibi,output));
    return bakibi;
}// fin de la fonction 

















// les methode d une fenetre
char *methode_Fenetre(Variable *v,char *name,int n,Parametre *p,AllFonction *allf,Env *envi,char *bakibi)
{
     if(strcmp(name,"creerFenetre") == 0 && n == 1)
    {
        v->val->fen = new_Fenetre(calculerExpressionNv1(p->valeur,p->valeur),NORMAL,new_Taille(100,155),P_CENTER);
        Fenetre_agrandir(v->val->fen);
        return "\"vous avez cree une fenetre . \"";
    }
    else if(strcmp(name,"creerFenetre") == 0 && n == 3)
    {
        char tm[1000];
        int x = atoi(calculerExpressionNv1(p->svt->valeur,tm));
        int  y = atoi(calculerExpressionNv1(p->svt->svt->valeur,tm));
       v->val->fen = new_Fenetre(calculerExpressionNv1(p->valeur,tm),NORMAL,new_Taille(x,y),P_CENTER);
       

      return "\"vous avez cree une fenetre .\" ";
    }
    else if(strcmp(name,"montrer") == 0 && n == 0)
    {
        if(v->val->fen == NULL)
            return " \"la fenetre n'est pas encore creer .\" ";
        Fenetre_setVisible(v->val->fen,1);
        return " \"la fenetre est maintenant visible.\" ";
    }
    else if(strcmp(name,"bye") == 0 && n == 0)
    {
        if(v->val->fen == NULL)
            return " \"la fenetre n'est pas encore creer .\" ";
        
        gtk_widget_destroy (GTK_WIDGET(v->val->fen->this));
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
         return " \"la fenetre est maintenant invisible.\" ";
    }
    else if(strcmp(name,"ajouterLabel") == 0 && n == 3)
    {
        if(v->val->fen == NULL)
            return " \"la fenetre n'est pas encore creer .\" ";
         char tm[1000]; 
        Container *c =Fenetre_getContainer(v->val->fen);
          int x = atoi(calculerExpressionNv1(p->svt->valeur,tm));
        int  y = atoi(calculerExpressionNv1(p->svt->svt->valeur,tm));
        Component *cpn = new_Label(calculerExpressionNv1(p->valeur,tm),0,1);
        Fixed_add(c,cpn->this,x,y);
         return " \"la fenetre est maintenant invisible.\" ";
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

    return " ";
}//fin de la fonction



/*   utilisation des fenetre */
char *Methode_utiliser(Variable *v,char *name,int n,Parametre *p,AllFonction *allf,Env *envi,char *bakibi)
{
    int type = v->type;

    if(type  == 5)
        return methode_Fenetre(v,name,n,p,allf,envi,bakibi);




    return " ";
}





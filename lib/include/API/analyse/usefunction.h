



Env *Evalutor(Trees *trs ,Env *envi,char  *bakibi, FILE *output);


/* utiliser une fonction */

char *Fonction_utiliser(Fonction *fct,int n,Parametre *p,AllFonction *allf,Env *envi,char *bakibi, FILE *output)
{
        
       
     
       AllVariable *tmp = fct->allv;
       Parametre *pp = p;

    AllVariable *myvr = NULL;// la nouvelle liste de variable 
    while(tmp)
    { 
        fct->allv = AllVariable_modifier(fct->allv,tmp->v->nom,pp->valeur);
        myvr = AllVariable_ajouter(myvr,tmp->v);
        pp = pp->svt;// le parametre suivant
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
   strcpy(bakibi,"");
    return "";
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
     else if(strcmp(name,"ajouterBouton") == 0 && n == 3)
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
    else if(strcmp(name,"ajouterCheckbox") == 0 && n == 3)
    {
        if(v->val->fen == NULL)
            return " \"la fenetre n'est pas encore creer .\" ";
         char tm[1000]; 
        Container *c =Fenetre_getContainer(v->val->fen);
        int x = atoi(calculerExpressionNv1(p->svt->valeur,tm));
        int  y = atoi(calculerExpressionNv1(p->svt->svt->valeur,tm));
        Component *cpn = new_CheckBox(calculerExpressionNv1(p->valeur,tm));
        Fixed_add(c,cpn->this,x,y);
         return " \"vous avez ajouter un CheckBox.\" ";
    }
    else if(strcmp(name,"ajouterCombo") == 0 && n >= 3 )
    {
        if(v->val->fen == NULL)
            return " \"la fenetre n'est pas encore creer .\" ";
         char tm[1000]; 
        Container *c =Fenetre_getContainer(v->val->fen);
        int x = atoi(calculerExpressionNv1(p->valeur,tm));
        int y = atoi(calculerExpressionNv1(p->svt->valeur,tm));

        Parametre *pp=p->svt->svt;

        Component *cp = new_Component();
        cp->type = COMBOBOX;
        cp->this = gtk_combo_box_text_new ();

        while(pp){
            gtk_combo_box_text_append_text( GTK_COMBO_BOX_TEXT(cp->this) , calculerExpressionNv1(pp->valeur,tm) );
            pp = pp->svt;
        }

        gtk_combo_box_set_active(GTK_COMBO_BOX(cp->this),0);

        Fixed_add(c,cp->this,x,y); 

         return " \"vous avez ajouter un ComboBox.\" ";
    }
    else if(strcmp(name,"ajouterRadios") == 0 && n >= 4 )
    {
        if(v->val->fen == NULL)
            return " \"la fenetre n'est pas encore creer .\" ";
        char tm[1000]; 
        Container *c =Fenetre_getContainer(v->val->fen);
        int x = atoi(calculerExpressionNv1(p->valeur,tm));
        int y = atoi(calculerExpressionNv1(p->svt->valeur,tm));
        int orientation = atoi(calculerExpressionNv1(p->svt->svt->valeur,tm));

        GtkWidget *box,*first;
        if(orientation==0)
            box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 2);
        else
            box = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 2);

        gtk_box_set_homogeneous (GTK_BOX (box), TRUE);

        first = gtk_radio_button_new_with_label (NULL,calculerExpressionNv1(p->svt->svt->svt->valeur,tm));
        gtk_box_pack_start (GTK_BOX (box), first, TRUE, TRUE, 2);

        Parametre *pp = p->svt->svt->svt->svt;

        while(pp){
            GtkWidget *radTmp = gtk_radio_button_new_with_label_from_widget (
                                                GTK_RADIO_BUTTON (first),
                                                calculerExpressionNv1(pp->valeur,tm)    
                                    );
            gtk_box_pack_start (GTK_BOX (box), radTmp, TRUE, TRUE, 2);

            pp = pp->svt;
        }

        Fixed_add(c,box,x,y); 

         return " \"vous avez ajouter un/des Radio Bouton(s) .\" ";
    }
    else if(strcmp(name,"ajouterMenu") == 0 && n >= 3 )
    {
        if(v->val->fen == NULL)
            return " \"la fenetre n'est pas encore creer .\" ";
        char tm[1000]; 
        Container *c =Fenetre_getContainer(v->val->fen);
        int x = atoi(calculerExpressionNv1(p->valeur,tm));
        int y = atoi(calculerExpressionNv1(p->svt->valeur,tm));

        GtkWidget *menuBar  =   gtk_menu_bar_new();
        GtkWidget *menu,*first ,*item;

        Parametre *pp = p->svt->svt;
        int fst=0;

        while(pp){

            fst=0;
            menu  =   gtk_menu_new();

            char * pch;
            pch = strtok (calculerExpressionNv1(pp->valeur,tm),",");

            while (pch != NULL)
            {
                if(fst==0){
                    first = gtk_menu_item_new_with_label(pch);   
                    gtk_menu_item_set_submenu(GTK_MENU_ITEM(first),menu);
                    fst=1;
                }
                else{
                    item = gtk_menu_item_new_with_label(pch);  
                    gtk_menu_shell_append(GTK_MENU_SHELL(menu),item); 
                }
                pch = strtok (NULL, ",");
            }
            
            gtk_menu_shell_append(GTK_MENU_SHELL(menuBar),first);
        
            pp = pp->svt;
        }

        Fixed_add(c,menuBar,x,y); 

         return " \"vous avez ajouter un Menu .\" ";
    }

    return "\"cette fonction n'est pas encore disponible\"";
}// fin fonction





char *methode_List(Variable *v,char *name,int n,Parametre *p,AllFonction *allf,Env *envi,char *bakibi) 
{

    if(strcmp(name,"add") == 0 &&  n == 1)
    {
        
    }

    return("\"Erreur ! Cette Fonction n'existe pas\"");
}



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

        else if(strcmp(name,"aide") == 0 &&  n == 0)
        {
            char *tompon1 = readFromFile("aide.txt",tompon1);
            
                fprintf(output,"%s\n",tompon1);
                return "\"\"";
        }

    return " ";
}//fin de la fonction



char *methode_Liste(Variable *v,char *name,int n,Parametre *p,AllFonction *allf,Env *envi,char *bakibi)
{


 if(strcmp(name,"insererDevant") == 0 && n == 1)
    {
          char tm[1000]; 
        
         
        float  valeur = atof(calculerExpressionNv1(p->valeur,tm));
        Val *tp = (Val *)malloc(sizeof(Val));
        tp->value = (char *)malloc(sizeof(char)*strlen(p->valeur));
        strcpy(tp->value,p->valeur);
        tp->fen = NULL;
        tp->svt = v->val;
        v->val = tp;
        return " \"l element est bien ajouter a la liste devant .\" ";
        
    }

    if(strcmp(name,"insererDerriere") == 0 && n == 1)
    {
          char tm[1000]; 
        
         
        float  valeur = atof(calculerExpressionNv1(p->valeur,tm));
        Val *tp = (Val *)malloc(sizeof(Val));
        tp->value = (char *)malloc(sizeof(char)*strlen(p->valeur));
        strcpy(tp->value,p->valeur);
        tp->fen = NULL;
        tp->svt = NULL;
        if(v->val == NULL)
            v->val = tp;
        else {
            Val *tmp =  v->val;
            while(tmp->svt)
                tmp = tmp->svt;
            tmp->svt = tp;
        }
        
        return " \"l element est bien ajouter a la liste derriere .\" ";
        
    }

  else if(strcmp(name,"montrer") == 0 && n == 0)
    {
          char tompon[10000] = "";
          Val *tmp = v->val;
          while(tmp)
          {
              strcat(tompon,tmp->value);
              strcat(tompon,"\t");
              tmp =tmp->svt;
          }
          sprintf(bakibi,"\"%s\"",tompon);
          return bakibi;
    }
    if(strcmp(name,"element") == 0 && n == 1)
    {
        char tm[10000]="";
        int  in = atoi(calculerExpressionNv1(p->valeur,tm));
          char tompon[10000] = "";
          Val *tmp = v->val;
          int i = 1;
          while(tmp)
          {  
              if( i == in)
              {
                   sprintf(bakibi,"\"%s\"",tmp->value);
                   return bakibi;
              }
              i++;
              tmp =tmp->svt;
          }
          sprintf(bakibi,"\"erreur : l indice n existe pas .\"");
          return bakibi;
    }
    else if(strcmp(name,"size") == 0 && n == 0)
    {
          char tompon[10000] = "";
          Val *tmp = v->val;
          char i = -1;
          while(tmp)
          {
                i++;
              tmp =tmp->svt;
          }
          sprintf(bakibi,"\"%d\"",i);
          return bakibi;
    }

    else if(strcmp(name,"sort") == 0 && n == 0)
    {
          char tompon[1000] = "";
          Val *tmp = v->val;
          Val *tmp1 = NULL;
          while(tmp)
          {
              tmp1 = tmp->svt;
               while(tmp1)
               {
                   if(atof(tmp->value)>atof(tmp1->value))
                   {
                       strcpy(tompon,tmp->value);
                       strcpy(tmp->value,tmp1->value);
                       strcpy(tmp1->value,tompon);
                   }
                   tmp1 = tmp1->svt;
               }
              tmp =tmp->svt;
          }
       
          return "\"\"";
    }
    else if(strcmp(name,"sortD") == 0 && n == 0)
    {
          char tompon[1000] = "";
          Val *tmp = v->val;
          Val *tmp1 = NULL;
          while(tmp)
          {
              tmp1 = tmp->svt;
               while(tmp1)
               {
                   if(atof(tmp->value)< atof(tmp1->value))
                   {
                       strcpy(tompon,tmp->value);
                       strcpy(tmp->value,tmp1->value);
                       strcpy(tmp1->value,tompon);
                   }
                   tmp1 = tmp1->svt;
               }
              tmp =tmp->svt;
          }
       
          return "\"\"";
    }
     else if(strcmp(name,"supprimer") == 0 && n ==1)
    {
          char tompon[10000] = "";
          char tm[1000] = "";
           int  in = atoi(calculerExpressionNv1(p->valeur,tm));
          
          char i = 1;
          if(v->val == NULL)
            return "\"Erreur La liste est Vide \"";
            if(in == 1)
            {
                Val *e = v->val;
                v->val = v->val->svt;
                free(e);
                return "\"\"";
            }
            Val *tmp1 = v->val->svt;
            Val *tmp = v->val;
          while(tmp1)
          {
               i++;
              if(i == in)
              {
                    Val *e = tmp1;
                    tmp->svt = tmp1->svt;
                    free(e);
                    return "\"\"";
              }
               
              tmp =tmp->svt;
              tmp1 = tmp1->svt;
          }
          
        return "\"Erreur L indice est errone  \"";
    }

    return " \"Cette fonction n 'existe pas .\" ";;
}





/*   utilisation des fenetre */
char *Methode_utiliser(Variable *v,char *name,int n,Parametre *p,AllFonction *allf,Env *envi,char *bakibi)
{

    if(v == NULL)
        return "\"cette variable n est pas encore declare .\"";
    int type = v->type;

    if(type  == 5)
        return methode_Fenetre(v,name,n,p,allf,envi,bakibi);

    if(type == 2)
        return methode_Liste(v,name,n,p,allf,envi,bakibi);

    return " ";
}





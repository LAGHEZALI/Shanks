
typedef struct Parametre{
    char valeur[1000];
    struct Parametre *svt;
} Parametre;

typedef struct Fonction {//Sd d une fonction
    int type ;
    char *name;
    int nbr;
    AllVariable *allv;
    char *content;
} Fonction;



typedef struct AllFonction{//tout les fonction
    Fonction *fct;
    struct AllFonction *svt;
}AllFonction;


/*ajouter un nouveau parameter*/
Parametre *Parametre_ajouter(Parametre *p,char *valeur)
{  
    Parametre *pt = (Parametre *)malloc(sizeof(Parametre));
            pt->svt = NULL;
         if(estNombre(valeur))
            strcpy(pt->valeur,valeur);
        else 
        sprintf(pt->valeur,"\"%s\"",valeur);
    if(p == NULL)   return pt;
    Parametre *tmp = p;
    while(tmp->svt)
        {tmp = tmp->svt;}
    tmp->svt = pt;
    return p;
}


/* creation d une nouvelle fonction */
Fonction *new_Fonction(int type,char *name,AllVariable *allv,char *content)
{
    Fonction *fct = (Fonction *)malloc(sizeof(Fonction));
    fct->type  = type;
    fct->name =(char *)malloc(strlen(name));
    strcpy(fct->name,name);
     fct->content =(char *)malloc(strlen(content));
    strcpy(fct->content,content);
    int nbr  = 0;
    AllVariable *tmp = allv;
    while(tmp)
    {
        nbr++;
        tmp = tmp->svt;
    }
    fct->nbr = nbr;
    fct->allv = allv;
    return fct;
}





/*  Ajouter une fonction*/
AllFonction *AllFonction_add(AllFonction *allf,Fonction *fct)
{
    AllFonction *tp = (AllFonction *)malloc(sizeof(AllFonction));
    tp->svt = NULL;
    tp->fct = fct;
    if(allf == NULL) return  tp;
    AllFonction *tmp = allf;
    while(tmp)
    {
        if(strcmp(tmp->fct->name,fct->name) == 0 && fct->nbr == tmp->fct->nbr)
            return allf;    
        tmp = tmp->svt ;
    }
    tmp->svt = tp;
    return allf;
}//fin de la fonction 


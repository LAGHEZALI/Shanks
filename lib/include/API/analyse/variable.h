
typedef struct Val{
    char *value;
    Fenetre *fen;
    struct Val *svt;
}Val;

typedef struct Variable {
    int type ;
    char *nom;
    Val *val;
}Variable;

typedef struct AllVariable{
    Variable *v;
    struct AllVariable *svt;
}AllVariable;




/*  Creation d une nouvelle variable */
Variable *new_Variable(int type,char *nom,char *valeur)
{
    Variable *v = (Variable *)malloc(sizeof(Variable));
    v->type = type;
    v->nom = (char *)malloc(strlen(nom));
    strcpy(v->nom,nom);
   if(valeur == NULL && type   != 5)
        v->val = NULL;
    else if (valeur == NULL)
    {
         v->val = (Val *)malloc(sizeof(Val));
     v->val->value = (char *)malloc(strlen(valeur));
    strcpy(v->val->value,"");
    v->val->fen = NULL;
    v->val->svt = NULL;
    }
    else {
         v->val = (Val *)malloc(sizeof(Val));
     v->val->value = (char *)malloc(strlen(valeur));
    strcpy(v->val->value,valeur);
    v->val->fen = NULL;
    v->val->svt = NULL;
    }
    return v;
}//fin de la fonction


/*  Modifier une variable */
Variable *Variable_modifier(Variable *v,char *valeur)
{
    int taille  = strlen(valeur);
    if(v->val == NULL)
    {
            v->val = (Val *)malloc(sizeof(Val));
            v->val->value = (char *)malloc(strlen(valeur));
            strcpy(v->val->value,valeur);
    }

    v->val->value = (char *)realloc(v->val->value,taille);
     strcpy(v->val->value,valeur);
    return v;
}//fin de la fonction 

/* cette fonction ajoute une varialbe à une liste de varialbe */
AllVariable *AllVariable_ajouter(AllVariable *allv,Variable *v)
{ 
    AllVariable *tp = (AllVariable *)malloc(sizeof(AllVariable));
    tp->v = new_Variable(v->type,v->nom,v->val->value);
    tp->svt = NULL;
    if(allv == NULL)    return tp;
    AllVariable  *tmp = allv;
    while(tmp->svt)
    { 
        if(strcmp(tmp->v->nom,v->nom) == 0)
            return allv;
        tmp = tmp->svt;
    } 
    tmp->svt = tp;
    return allv;
}//fin de la fonction

/*cette fonction  permet de modifier une variable */
AllVariable *AllVariable_modifier(AllVariable *allv,char *nom,char *valeur)
{
     AllVariable  *tmp = allv;
    while(tmp)
    {
        if(strcmp(tmp->v->nom,nom) == 0)
            {
                tmp->v  = Variable_modifier(tmp->v,valeur);
                break;
            }
        tmp = tmp->svt;
    }
    return allv; 
}//fin de la fonction 


/* cette fonction retourn une valeur de d une variable */
char *AllVariable_valeur(AllVariable *allv,char *nom)
{
      AllVariable  *tmp = allv;
    while(tmp)
    {
        if(strcmp(tmp->v->nom,nom) == 0)
            {
                if(tmp->v->val == NULL) break;
                else return tmp->v->val->value;
            }
        tmp = tmp->svt;
    }

    return "";
}// fin de la donction


Variable *AllVariable_trouve(AllVariable *allv,char *nom)
{
       AllVariable  *tmp = allv;
    while(tmp)
    {
        if(strcmp(tmp->v->nom,nom) == 0)
            {
                if(tmp->v->val == NULL) break;
                else return tmp->v;
            }
        tmp = tmp->svt;
    }
     return NULL;
}//fin 






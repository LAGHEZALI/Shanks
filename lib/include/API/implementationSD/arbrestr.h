

/*
    initialisation dun nv arbre
        Sortie:
            NULL 
*/
ArbreStr *new_ArbreStr()
{return NULL;};//fin de la fct




/*
    Ajouter un element dans l ArbreStr
        Entree:
            racine  le noeud actuelle
            element la chaine a ajouter
        Sortie:
            arbre avec element ajouter
*/
ArbreStr *ArbreStr_ajouter(ArbreStr *a,char *e)
{
    if(a == NULL)
    {
        ArbreStr *tmp = (ArbreStr *)malloc(sizeof(ArbreStr));//alloca
        tmp->fg = tmp->fd = NULL;//affec
        tmp->contenu = (char *)malloc(strlen(e));
        strcpy(tmp->contenu,e);
        return tmp;
    }//si racine est NULL

    if(estNombre(e))//si lement qu on va ajouter  et un nombre
    {
            a->fd = ArbreStr_ajouter(a->fd,e);
            return a;//l element a été ajoute donc on retourne le noeud
    }//fin if
    int cat = estOperation(e);//verifier l operation et retourner laquelle
    int cat_nd = estOperation(a->contenu);// si le noeud est un nombre donc cat_nd
                                                                  //    =0 sinon cat_nd = type d operation 
    ArbreStr *tmp = (ArbreStr *)malloc(sizeof(ArbreStr));//alloca
    tmp->fg = tmp->fd = NULL;//affec
    tmp->contenu = (char *)malloc(strlen(e));
     strcpy(tmp->contenu,e);//copier le contenu                                                                  
    if(1<=cat && cat<=5) //si l operation est parmi : + - / * %
    {
        if(cat_nd == 0)//si le contenu du noeud est une nombre
        {
            tmp->fg = a;
            return tmp;
        }//fin if
        else // si le noeud contient une operation  
        {
            if( cat_nd <cat)
            {
                tmp->fg = a->fd;
                 a->fd = tmp;    
            }
            else 
            {
                tmp->fg = a;
                return tmp;
            }
            return a;//le retoure 
        }//fin else

    }// fin if de + - * / 
   else //pour tout les autre operation
   {
        if(cat_nd == 0)//si le contenu du noeud est une nombre
        {
            tmp->fg = a;
            return tmp;
        }//fin if
         if( cat_nd <cat)
            {
                tmp->fg = a->fd;
                 a->fd = tmp;    
            }
            else 
            {
                tmp->fg = a;
                return tmp;
            }
         a->fd = tmp;  
   }//fin else

    
   return a;//le reour final du noeud en  cours
}//fin de la fonction




/*
    cette fonction affiche le contenu de   l arbre 
        Entree:
            a l arbre qu on veut afficher
        Sortie:
            VOID
*/
void ArbreStr_afficherInfixe(ArbreStr *a)
{
    if(a == NULL)
        return;
    ArbreStr_afficherInfixe(a->fg);
    printf("%s\n",a->contenu);
    ArbreStr_afficherInfixe(a->fd);
}//fin de la fonction


/*
    Cette fonction permet de calculer à partir des element de l arbre et 
    donner une valuer ss forme d une chaine cara
        Entree :
            a l arbre 
            valeur est un tompon de memoire qui va servir pur stocker a chaque fois le resultat
        Sortie:
            Une chaine de caractere contenant la valeur
*/
const char *ArbreStr_value(ArbreStr *a,char valeur[300])
{
    if( a == NULL)
        return "0"; //si le noeud et null
    if(a->fg == NULL && a->fd == NULL)//si lenoeudest une feuille
        return a->contenu;// on retourne le contenu de la feuille (valeur)
    if(a->fg== NULL)//si le noeud droite est  vide
        {
            int cat_op = estOperation(a->contenu);
            float vd;
            char valeur_fd[300];
            strcpy(valeur_fd,ArbreStr_value(a->fd,valeur));
             sscanf(valeur_fd,"%f",&vd);
            if(cat_op == 1)
                sprintf(valeur,"%f",+vd);
            if(cat_op == 2)
                sprintf(valeur,"%f",-vd);
            else
                sprintf(valeur,"%d",0);
            return valeur;

        }//fin 
    char valeur_fg[300];
    char valeur_fd[300];
    strcpy(valeur,"");
    strcpy(valeur_fg,ArbreStr_value(a->fg,valeur));
    strcpy(valeur_fd,ArbreStr_value(a->fd,valeur));
    float vg,vd;
    sscanf(valeur_fg,"%f",&vg);
    sscanf(valeur_fd,"%f",&vd);
    int cat_op = estOperation(a->contenu);
    switch(cat_op)
    {
        case 1: sprintf(valeur,"%f",vg+vd);break;
        case 2: sprintf(valeur,"%f",vg-vd);break;
        case 3: sprintf(valeur,"%f",vg*vd);break;
        case 4: sprintf(valeur,"%f",vg/vd);break;
        case 5: sprintf(valeur,"%d",(int)vg%(int)vd);break;

        case 16: sprintf(valeur,"%d",(int)vg==(int)vd);break;
        case 17: sprintf(valeur,"%d",(int)vg!=(int)vd);break;

        case 10: sprintf(valeur,"%d",(int)vg&&(int)vd);break;
        case 11: sprintf(valeur,"%d",(int)vg || (int)vd);break;

        case 12: sprintf(valeur,"%d",(int)vg < (int)vd);break;
        case 13: sprintf(valeur,"%d",(int)vg<=(int)vd);break;
        case 14: sprintf(valeur,"%d",(int)vg>(int)vd);break;
        case 15: sprintf(valeur,"%d",(int)vg>=(int)vd);break;
        default: sprintf(valeur,"%d",0);break;

        
    }
    return valeur;
}//fi de la fonction
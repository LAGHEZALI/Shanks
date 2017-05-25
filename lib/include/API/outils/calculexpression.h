


ArbreStr *new_ArbreStr();
ArbreStr *ArbreStr_ajouter(ArbreStr *a,char *e);
const char *ArbreStr_value(ArbreStr *a,char valeur[300]);
void ArbreStr_afficherInfixe(ArbreStr *a);
/*
    Cette fonction premet d' à partir d une chaine de caractere de 
    donner un resultat
        Entree;
            chaine la chaine de caractere
        Sortie:
            une chaine de cractere contenant resultat  
*/
char *calculerExpressionNv3(char *chaine,char valeur[300])
{
    int taille = strlen(chaine);//taille de la chaine à traiter
    char lecture[300];// la chaine avec laquelle on va effectuer la traitment
    strcpy(lecture,"");//init
    strcpy(valeur,"");//init 
    int e = 1;
    char c[2]={' ','\0'};
    char result[300];
    ArbreStr *a = new_ArbreStr();
    for(int i =0;i<taille;i++)
    {
        c[0] = chaine[i];//affectation en c
        if(c[0] == ' ')
            continue;
        if(estNombre(c) || c[0]=='.')
        {
            if(e ==  1)
            strcat(lecture,c);// on continue l affectation
            else
            {
                a = ArbreStr_ajouter(a,lecture);//on entre la chaine dans l arbre
                strcpy(lecture,c);//reiniatioalisation
                e = 1;
            }//fin else
        }//fin if est nmobre
        else//si le la car entre est une operation
        {
            if( e == 2)
                strcat(lecture,c);// on continue l affectation
            else 
            {
                 a = ArbreStr_ajouter(a,lecture);//on entre la chaine dans l arbre
                strcpy(lecture,c);//reiniatioalisation
                e = 2;
            }//fin else
        }//fin else
    }//fin for
    
     
     a = ArbreStr_ajouter(a,lecture);//ajout du dernier element 
    strcpy(valeur,ArbreStr_value(a,result));
    return valeur;
}//fin de la fonction




/*
    Cette fonction permet de calculer en plus de calculerExpressionNv3
    on peut ajouter les parentheses:
            Entree: 
                chaine la chaine à traiter
                valeur le tompont
            Sortie:
                la valeur finale
*/
char *calculerExpressionNv2(char *chaine,char valeur[300])
{
    int pile = 0;//la pile
    int taille = strlen(chaine);//la taille de la chiane à traiter
    char lecture[500];//la chaine de lecture
    char c[2] = {' ','\0'};//le cara de lecture
    char elm_pile[100];//les element de la pile

    strcpy(valeur,"");
    strcpy(lecture,"");
    strcpy(elm_pile,"");
    int e  = 0;//pas encore commencer
    for(int i=0;i<taille;i++)
    {
        c[0] = chaine[i];//lecture
        if(c[0] == '(')// on incremente la pile
            pile++;
        if(c[0] == ')')//on decremente la pile
            pile--;
       
     if(e == 0 && c[0]=='(') // si (  doncon commence à inserer dans la pile
          {
                e = 2;
                strcpy(elm_pile,"");//on vide la pile pour une nvl utilisation
        }
        else  if(e==2 && pile!=0)//si on pas encore rencorter )
        {
            strcat(elm_pile,c);
        }
       else  if(e ==2 && pile == 0)// si la pile est vide
            {
                e = 0;
                strcat(lecture,calculerExpressionNv2(elm_pile,valeur));
                 strcpy(elm_pile,"");//on vide la pile pour une nvl utilisation
            }
        else
         strcat(lecture,c);
        
    }//fin de for
    return calculerExpressionNv3(lecture,valeur);//on applique la fct de niv 2 
}//fin de la fonction



/*
    Cette fonction permer de formater une chaine de caracetere
        Entree:
            chaine la chaine,
            valeur le tompon
        Sortie:
            la chaine de caractere
*/
char *formaterUneChaine(char *chaine,char *valeur)
{
    strcpy(valeur,"");
    int taille = strlen(chaine);
    char c[2] = {' ','\0'};
    for(int i=0;i<taille;i++)
    {
        c[0] = chaine[i];
        if(c[0] == '\"' || c[0] == '\n') continue;
        if(c[0] == '\\')
        {
            i++;
            c[0] = chaine[i];
            if(c[0] == '\\')
             strcat(valeur,c);
            if(c[0] == 'n')
                strcat(valeur,"\n");
             if(c[0] == '\"')
                strcat(valeur,"\"");
             if(c[0] == 't')
                strcat(valeur,"\t");
            continue;
        }
         strcat(valeur,c);
    }//fin for
    return valeur;
}//fin de la fonction





/*
    Cette fonction en plus de calculerExpressionNv2 
        on peut concatener une chiane de caractere et calculer un truc ddans
            Entree:
                chaine la chaine à traiter
                valeur le tampon
            Sortie:
                le resultat bien concatene
*/
char *calculerExpressionNv1(char *chaine,char *valeur)
{
    int taille = strlen(chaine);
    char lecteur[1000];
    char result[1000];//ou on va stocker le resultat a chaque fois 
    strcpy(lecteur,"");//itini 
    strcpy(result,"");//init
    char c[2] = {' ','\0'};//le caractere de compa
    int e = 0;
    for(int i=0;i<taille;i++)
    {
        c[0] = chaine[i] ;//prendre le caracetere
        if(c[0] == '\"' && e == 0)
            {
                e = 1;//en entre dans la chiane de caractere
                strcat(lecteur,c);//concatenation
            }
        else  if(c[0] == '\"' && e == 1)
            {
                if(chaine[i-1] != '\\')
                    {
                        strcat(lecteur,c);//concatenation
                        strcpy(valeur,"");
                        strcat(result,formaterUneChaine(lecteur,valeur));//on concatene la partie due la chaine
                        strcpy(lecteur,"");// on reiniatioalisation
                        e = 0;
                        continue;//passer à l iteration suivante
                    }//si on on a fini la chaine de carac
                    strcat(lecteur,c);//sinon on concatenation
            }
           else {
                if(strcmp(c,"+") == 0 && chaine[i+1] == '\"')
                {
                    strcat(result,calculerExpressionNv2(lecteur,valeur));
                    strcpy(lecteur,"");// on reiniatioalisation
                    continue;
                }
                strcat(lecteur,c);//lecture
                    
            }//si c est un nombre
    }//fin for
   
    if(e == 0)
        strcat(result,calculerExpressionNv2(lecteur,valeur));

    strcpy(valeur,result);
    return valeur;
}//fin de la fonction
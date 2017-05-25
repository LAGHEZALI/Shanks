

/*
    Cette fonction verifie si une chaine de caractere à la forme
    d'une fonction
        Entree:
            chaine la chaine à traiter
        Sortie:
            1   vrai
            0   vaux
*/
int estMotFonction(char *chaine)
{
    int taille = strlen(chaine);//la taille de la  chaine
    int e = 0;  //etat initial
           //   1   etat (
            //  2  etat )         
            //  3   si apres ) on a quelque chose
    char *m = (char *)malloc(sizeof(char)*2);//la chaine ou on va stocker le prefix de la fonction
    strcpy(m,"");//on initialise m à vide
    char c[2] = {' ','\0'};  //la variable ou on va mettre la carac
    for(int i = 0;i<taille;i++)
    {
        c[0] = chaine[i]; //lecture de caractere
        if(e == 1 && chaine[i]!=')')
            continue;
        if(chaine[i] == '(')    
            {
                e = 1;
                continue;
            }
        if(chaine[i] == ')')    
            {
                e = 2;
                continue;
            }
        if(e == 2)//si apres avoir rencontrer ) on a un autre caractere ex :function(x)e
            e =3;
        if(e == 0)//si on a pas encore rencontrer le ( on concatene le prefixe
            {
                strcat(m,c);//concatenation
                m = realloc(m,i+2);//reallocation de memoire
            }//fin de if
    }//fin de la boucle
    if(e !=2)
        return 0;
    return estMotValide(m) && !estMotCle(m);// le prefixe doit etre un mot valide et ne doit pas etre un mot clee
}//fin de la fonction
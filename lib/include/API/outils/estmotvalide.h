

/*
    Cette fonction verifie si un mot est valide
        Entree:
            chaine la chaine en question
        Sortie:
            1   vrai
            0   faux
*/
int estMotValide(char *chaine)
{
    int taille = strlen(chaine);
    if(taille   ==1 && !('a'<=(*chaine) && (*chaine)<='z' ) && !('A'<=(*chaine) && (*chaine)<='Z' ))
        return 0;//si la chaine est un caractere mais il est diffrent a une lettre dans c est faux
    if(!('a'<=(*chaine) && (*chaine)<='z' ) && !('A'<=(*chaine) && (*chaine)<='Z' ))
        return 0;
    for(int i =0;i<taille;i++)
            if(!('a'<=chaine[i] && chaine[i]<='z' ) && !('A'<=chaine[i] && chaine[i]<='Z' ) 
               && chaine[i]!='_'
               &&     !('0'<=chaine[i] && chaine[i]<='9'))
                            return 0;   //faux
    return 1;
}//fin de la fonction
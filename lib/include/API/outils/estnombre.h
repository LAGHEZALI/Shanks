

/*
    Cette fonction verifie si une chaine donne est nombre
        Entree :
            chaine la chaine qu on veut voir 
        Sortie :
            1   vrai
            0   faux
*/
int estNombre(char *chaine)
{
    int taille = strlen(chaine);
    if(taille == 1 && chaine[0] == '.')
        return 0;//faux
    for(int i = 0;i<taille;i++)
        if(!('0'<=chaine[i] && chaine[i]<='9') && chaine[i]!='.')
            return 0;//faux
    return 1;//vrai
}//fin de la fonction
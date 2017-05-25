


/*
    Cette fonction verifie si une chaine de caractere est une operation
        Entree:
            chaine la chaine qu on veut traiter
        Sorite:
        0   faux
        1   +
        2   -  
        3   *
        4   /
        5   %
        6   =
*/
int estOperation(char *chaine)
{
    int taille = strlen(chaine);//la taille de la chaine
    if(taille>2)
        return 0;
    if(  strcmp(chaine,"+") == 0)    return 1;
    if(  strcmp(chaine,"-") == 0)    return 2;
    if(  strcmp(chaine,"*") == 0)    return 3;
    if(  strcmp(chaine,"/") == 0)    return 4;
    if(  strcmp(chaine,"%") == 0)    return 5;

    if(  strcmp(chaine,"=") == 0)    return 6;
    if(  strcmp(chaine,"==") == 0)    return 16;
    if(  strcmp(chaine,"!=") == 0)    return 17;
    if(  strcmp(chaine,"!") == 0)    return 9;
    if(  strcmp(chaine,"&&") == 0)    return 10;
    if(  strcmp(chaine,"||") == 0)    return 11;
    
    if(  strcmp(chaine,"<") == 0)    return 12;
    if(  strcmp(chaine,"<=") == 0)    return 13;
    if(  strcmp(chaine,">") == 0)    return 14;
    if(  strcmp(chaine,">=") == 0)    return 15;

            
    return 0;
}//fin de la fonction
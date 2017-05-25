





int estType(char *chaine)
{
    if(strcmp(chaine,"string") == 0 || strcmp(chaine,"var") == 0 || strcmp(chaine,"Fenetre") == 0 || strcmp(chaine,"List") == 0
        || strcmp(chaine,"Queue") == 0 || strcmp(chaine,"Stack") == 0)
            return 1;
    return 0;
}


        /*               
        Cette fonction lit tour les truc dans un fichier et le mets
        dans une chaine de caractere source

            Entree : 
                nomF le nom du fichier
                source @de lachine ou on va inserer le contenu
           */
char *readFromFile(char *nomF,char *source)
{
    char c[2] = {' ','\0'};//le caractere de lecture
    int taille = 2;//la taille de la chaine
    FILE *f = fopen(nomF,"r");
    if(f == NULL)
        return NULL;
    source =(char *) malloc(sizeof(char)*2);//allocation
    strcpy(source,"");//initialisation

    while((c[0]=fgetc(f))!=EOF)//lecture caractere par caractere
    {
        strcat(source,c);//concatenation de la chaine avec le nouveau caractere
        taille = taille +1;//agrandir la taille
        source = (char *)realloc(source,taille);
    }//fin de la boucle
    fclose(f);//fermeture du fichier
    return source;
}//fin de la fonction


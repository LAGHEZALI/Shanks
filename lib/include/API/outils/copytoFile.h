


/*
    Cette fonction prend une chaine de caractere et 
    elle a mets dans un fichier 

    Entree :  
        nomF le nom du fichier ou on veut mettre la chaine 
        source la chaine en question


*/

void copyToFile(char *nomF,char *source)
{
    FILE *f = fopen(nomF,"w");//ouverture du fichier
    if(f == NULL)
        return ;
    fprintf(f,"%s",source);//metre la chaine dans le fichier
    fclose(f);//fermeture du fichier


}//fin de la fonction
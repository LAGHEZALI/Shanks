



/*
    Cette fonction cree une nouvelle Pile de valeur NULL;
        Sortie:
            NULL
*/
Pile *new_Pile()
{return NULL;}//fin de la fonction



/*
    Cette fonction empile dans la Pile
        Entree:
            pile la pile ou on va mettre l element
            element l'element qu on veut mettre dans le projet
        Sortie:
            la pile avec l element empiler
*/
Pile *Pile_empiler(Pile *pile,elementPile element)
{
    Pile *p = (Pile *)malloc(sizeof(Pile));//allocation
    p->contenu = element;
    p->svt = NULL;
    //on empile
    p->svt = pile;
    return p;
}//fin de la fonction






/*
    Cette fonction depile un element de la pile 
        Entree: 
            pile la pile à depiler
        Sortie:
            une pile depiler
*/
Pile *Pile_depiler(Pile *pile)
{
    if(pile == NULL)
        return NULL;//si la pile est NULL
    Pile *tmp = pile;
    pile = pile ->svt;
    free(tmp);//recuperation memoire
    return pile;
}//fin de la fonction
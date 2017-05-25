



/*
    La structure de donnees Pile
    de type Element 
*/

typedef  char elementPile;//le type des element de la Pile
typedef struct Pile
{
    elementPile contenu;//le conteneu de la variable
    struct Pile *svt;//le suivant
}Pile;


/*

      C est une strucutre d element est une chaine de caratere 
*/
typedef struct ArbreStr{
   struct ArbreStr  *fg,//fils gauche de ce noued
                    *fd;//fils droit de ce noeud
    char *contenu;// l'element ou l information que contient ce noeud
}ArbreStr;
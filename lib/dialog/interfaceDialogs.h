//  creation Fenetre Dialog
void interfaceDialog_fenetre(GtkWidget *widget,gpointer data)
{
    All *all = data;
    GtkWidget *parent = all->f->this , *content_area ;
    int rep;
    GtkWidget   *titre, *titreVal, *longueur, *longueurVal,*largeur, *largeurVal;

    GtkWidget *dialog = gtk_dialog_new_with_buttons( utf8("Creation d'une Fenêtre") ,
                                                    GTK_WINDOW(parent)               ,
                                                    GTK_DIALOG_MODAL                ,
                                                    "_Creer",GTK_RESPONSE_OK        ,
                                                    "_Annuler",GTK_RESPONSE_CANCEL  ,
                                                    NULL);
    cssDataToWidget(dialog, "color :#DDDDDD;background-color:#252526;");
    if(!all->isDark)    
        cssDataToWidget(dialog, "color : #222;background-color:#CCCEDB;");

    //  recuperer contenaire du dialog                                                    
    content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
    cssDataToWidget(content_area, "color :#DDDDDD;background-color:#252526;");
    if(!all->isDark)    
        cssDataToWidget(content_area, "color : #222;background-color:#CCCEDB;");
    //  creation d'un  grid où on va mettre nos element
    Container *grid = new_Grid();
    //  creation des elements
    titre		 =gtk_label_new("Titre");
    titreVal     =gtk_entry_new();
    longueur 	 =gtk_label_new("Longueur");
    longueurVal	 =gtk_entry_new();
    largeur 	 =gtk_label_new("Largeur");
    largeurVal	 =gtk_entry_new();
    //  ajout des elements au grid
    grid = Grid_add(grid,titre          ,0,0,1,1);		 
    grid = Grid_add(grid,titreVal       ,1,0,1,1);		 
    grid = Grid_add(grid,longueur       ,0,1,1,1); 	 
    grid = Grid_add(grid,longueurVal    ,1,1,1,1);	 
    grid = Grid_add(grid,largeur        ,0,2,1,1); 	 
    grid = Grid_add(grid,largeurVal     ,1,2,1,1);	 

    //  Ajouter des espacement
    gtk_grid_set_row_spacing (GTK_GRID(grid->this), 10);
    gtk_grid_set_column_spacing (GTK_GRID(grid->this), 10);
    gtk_container_set_border_width ( GTK_CONTAINER(content_area), 10);
    gtk_container_set_border_width ( GTK_CONTAINER(grid->this), 20);

    gtk_container_add(GTK_CONTAINER(content_area),grid->this);
    gtk_widget_show_all (dialog);

    //  execution du dialog    
    rep = gtk_dialog_run (GTK_DIALOG (dialog));
    //  creer la fenetre si la reponse est oui
    if(rep == GTK_RESPONSE_OK)
    {
        const gchar *titre = gtk_entry_get_text(GTK_ENTRY(titreVal));
        const gchar *lon = gtk_entry_get_text(GTK_ENTRY(longueurVal));
        const gchar *lar = gtk_entry_get_text(GTK_ENTRY(largeurVal));
       
        gchar *fullCode = g_strconcat( "Fenetre globale;globale.creerFenetre(\"",titre,"\",",lon,",",lar,");globale.montrer();", NULL);
        
        char m[10000];
        FILE *output = fopen("lib/include/TEST/out","w+");
        Tokens *toks = Lexer(fullCode);
        Trees    *trs   = Parser(toks);
        Evalutor(trs,&global,m,output);
        fclose(output);
        char *azz = readFromFile("lib/include/TEST/out",azz);

        gtk_widget_destroy (dialog);
    }
    else
        gtk_widget_destroy (dialog);
}

//  creation Bouton dialog
void interfaceDialog_bouton(GtkWidget *widget,gpointer data)
{
    All *all = data;
    GtkWidget *parent = all->f->this , *content_area ;
    int rep;
    GtkWidget   *titre, *titreVal, *longueur, *longueurVal,*largeur, *largeurVal;

    GtkWidget *dialog = gtk_dialog_new_with_buttons( utf8("Creation d'un Bouton") ,
                                                    GTK_WINDOW(parent)               ,
                                                    GTK_DIALOG_MODAL                ,
                                                    "_Creer",GTK_RESPONSE_OK        ,
                                                    "_Annuler",GTK_RESPONSE_CANCEL  ,
                                                    NULL);
    cssDataToWidget(dialog, "color :#DDDDDD;background-color:#252526;");
    if(!all->isDark)    
        cssDataToWidget(dialog, "color : #222;background-color:#CCCEDB;");

    //  recuperer contenaire du dialog                                                    
    content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
    cssDataToWidget(content_area, "color :#DDDDDD;background-color:#252526;");
    if(!all->isDark)    
        cssDataToWidget(content_area, "color : #222;background-color:#CCCEDB;");
    //  creation d'un  grid où on va mettre nos element
    Container *grid = new_Grid();
    //  creation des elements
    titre		 =gtk_label_new("Libelé");
    titreVal     =gtk_entry_new();
    longueur 	 =gtk_label_new("Position X");
    longueurVal	 =gtk_entry_new();
    largeur 	 =gtk_label_new("Position Y");
    largeurVal	 =gtk_entry_new();
    //  ajout des elements au grid
    grid = Grid_add(grid,titre          ,0,0,1,1);		 
    grid = Grid_add(grid,titreVal       ,1,0,1,1);		 
    grid = Grid_add(grid,longueur       ,0,1,1,1); 	 
    grid = Grid_add(grid,longueurVal    ,1,1,1,1);	 
    grid = Grid_add(grid,largeur        ,0,2,1,1); 	 
    grid = Grid_add(grid,largeurVal     ,1,2,1,1);	 

    //  Ajouter des espacement
    gtk_grid_set_row_spacing (GTK_GRID(grid->this), 10);
    gtk_grid_set_column_spacing (GTK_GRID(grid->this), 10);
    gtk_container_set_border_width ( GTK_CONTAINER(content_area), 10);
    gtk_container_set_border_width ( GTK_CONTAINER(grid->this), 20);

    gtk_container_add(GTK_CONTAINER(content_area),grid->this);
    gtk_widget_show_all (dialog);

    //  execution du dialog    
    rep = gtk_dialog_run (GTK_DIALOG (dialog));
    //  creer la fenetre si la reponse est oui
    if(rep == GTK_RESPONSE_OK)
    {
        const gchar *titre = gtk_entry_get_text(GTK_ENTRY(titreVal));
        const gchar *lon = gtk_entry_get_text(GTK_ENTRY(longueurVal));
        const gchar *lar = gtk_entry_get_text(GTK_ENTRY(largeurVal));
       
        gchar *fullCode = g_strconcat( "globale.ajouterBoutton(\"",titre,"\",",lon,",",lar,");globale.actualiser();", NULL);
        
        char m[10000];
        FILE *output = fopen("lib/include/TEST/out","w+");
        Tokens *toks = Lexer(fullCode);
        Trees    *trs   = Parser(toks);
        Evalutor(trs,&global,m,output);
        fclose(output);
        char *azz = readFromFile("lib/include/TEST/out",azz);

        gtk_widget_destroy (dialog);
    }
    else
        gtk_widget_destroy (dialog);
}

//  creation input dialog
void interfaceDialog_input(GtkWidget *widget,gpointer data)
{
    All *all = data;
    GtkWidget *parent = all->f->this , *content_area ;
    int rep;
    GtkWidget   *titre, *titreVal, *longueur, *longueurVal,*largeur, *largeurVal;

    GtkWidget *dialog = gtk_dialog_new_with_buttons( utf8("Creation d'un Entry") ,
                                                    GTK_WINDOW(parent)               ,
                                                    GTK_DIALOG_MODAL                ,
                                                    "_Creer",GTK_RESPONSE_OK        ,
                                                    "_Annuler",GTK_RESPONSE_CANCEL  ,
                                                    NULL);
    cssDataToWidget(dialog, "color :#DDDDDD;background-color:#252526;");
    if(!all->isDark)    
        cssDataToWidget(dialog, "color : #222;background-color:#CCCEDB;");

    //  recuperer contenaire du dialog                                                    
    content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
    cssDataToWidget(content_area, "color :#DDDDDD;background-color:#252526;");
    if(!all->isDark)    
        cssDataToWidget(content_area, "color : #222;background-color:#CCCEDB;");
    //  creation d'un  grid où on va mettre nos element
    Container *grid = new_Grid();
    //  creation des elements
    titre		 =gtk_label_new("Position X");
    titreVal     =gtk_entry_new();
    longueur 	 =gtk_label_new("Position Y");
    longueurVal	 =gtk_entry_new();
    //  ajout des elements au grid
    grid = Grid_add(grid,titre          ,0,0,1,1);		 
    grid = Grid_add(grid,titreVal       ,1,0,1,1);		 
    grid = Grid_add(grid,longueur       ,0,1,1,1); 	 
    grid = Grid_add(grid,longueurVal    ,1,1,1,1);	 

    //  Ajouter des espacement
    gtk_grid_set_row_spacing (GTK_GRID(grid->this), 10);
    gtk_grid_set_column_spacing (GTK_GRID(grid->this), 10);
    gtk_container_set_border_width ( GTK_CONTAINER(content_area), 10);
    gtk_container_set_border_width ( GTK_CONTAINER(grid->this), 20);

    gtk_container_add(GTK_CONTAINER(content_area),grid->this);
    gtk_widget_show_all (dialog);

    //  execution du dialog    
    rep = gtk_dialog_run (GTK_DIALOG (dialog));
    //  creer la fenetre si la reponse est oui
    if(rep == GTK_RESPONSE_OK)
    {
        const gchar *titre = gtk_entry_get_text(GTK_ENTRY(titreVal));
        const gchar *lon = gtk_entry_get_text(GTK_ENTRY(longueurVal));
       
        gchar *fullCode = g_strconcat( "globale.ajouterEntry(\"",titre,"\",",lon,");globale.actualiser();", NULL);
        
        char m[10000];
        FILE *output = fopen("lib/include/TEST/out","w+");
        Tokens *toks = Lexer(fullCode);
        Trees    *trs   = Parser(toks);
        Evalutor(trs,&global,m,output);
        fclose(output);
        char *azz = readFromFile("lib/include/TEST/out",azz);

        gtk_widget_destroy (dialog);
    }
    else
        gtk_widget_destroy (dialog);
}
//  creation label dialog
void interfaceDialog_label(GtkWidget *widget,gpointer data)
{
    All *all = data;
    GtkWidget *parent = all->f->this , *content_area ;
    int rep;
    GtkWidget   *titre, *titreVal, *longueur, *longueurVal,*largeur, *largeurVal;

    GtkWidget *dialog = gtk_dialog_new_with_buttons( utf8("Creation d'un Label") ,
                                                    GTK_WINDOW(parent)               ,
                                                    GTK_DIALOG_MODAL                ,
                                                    "_Creer",GTK_RESPONSE_OK        ,
                                                    "_Annuler",GTK_RESPONSE_CANCEL  ,
                                                    NULL);
    cssDataToWidget(dialog, "color :#DDDDDD;background-color:#252526;");
    if(!all->isDark)    
        cssDataToWidget(dialog, "color : #222;background-color:#CCCEDB;");

    //  recuperer contenaire du dialog                                                    
    content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
    cssDataToWidget(content_area, "color :#DDDDDD;background-color:#252526;");
    if(!all->isDark)    
        cssDataToWidget(content_area, "color : #222;background-color:#CCCEDB;");
    //  creation d'un  grid où on va mettre nos element
    Container *grid = new_Grid();
    //  creation des elements
    titre		 =gtk_label_new("Libelé");
    titreVal     =gtk_entry_new();
    longueur 	 =gtk_label_new("Position X");
    longueurVal	 =gtk_entry_new();
    largeur 	 =gtk_label_new("Position Y");
    largeurVal	 =gtk_entry_new();
    //  ajout des elements au grid
    grid = Grid_add(grid,titre          ,0,0,1,1);		 
    grid = Grid_add(grid,titreVal       ,1,0,1,1);		 
    grid = Grid_add(grid,longueur       ,0,1,1,1); 	 
    grid = Grid_add(grid,longueurVal    ,1,1,1,1);	 
    grid = Grid_add(grid,largeur        ,0,2,1,1); 	 
    grid = Grid_add(grid,largeurVal     ,1,2,1,1);	 

    //  Ajouter des espacement
    gtk_grid_set_row_spacing (GTK_GRID(grid->this), 10);
    gtk_grid_set_column_spacing (GTK_GRID(grid->this), 10);
    gtk_container_set_border_width ( GTK_CONTAINER(content_area), 10);
    gtk_container_set_border_width ( GTK_CONTAINER(grid->this), 20);

    gtk_container_add(GTK_CONTAINER(content_area),grid->this);
    gtk_widget_show_all (dialog);

    //  execution du dialog    
    rep = gtk_dialog_run (GTK_DIALOG (dialog));
    //  creer la fenetre si la reponse est oui
    if(rep == GTK_RESPONSE_OK)
    {
        const gchar *titre = gtk_entry_get_text(GTK_ENTRY(titreVal));
        const gchar *lon = gtk_entry_get_text(GTK_ENTRY(longueurVal));
        const gchar *lar = gtk_entry_get_text(GTK_ENTRY(largeurVal));
       
        gchar *fullCode = g_strconcat( "globale.ajouterLabel(\"",titre,"\",",lon,",",lar,");globale.actualiser();", NULL);
        
        char m[10000];
        FILE *output = fopen("lib/include/TEST/out","w+");
        Tokens *toks = Lexer(fullCode);
        Trees    *trs   = Parser(toks);
        Evalutor(trs,&global,m,output);
        fclose(output);
        char *azz = readFromFile("lib/include/TEST/out",azz);

        gtk_widget_destroy (dialog);
    }
    else
        gtk_widget_destroy (dialog);
}

//  creation textview dialog
void interfaceDialog_textview(GtkWidget *widget,gpointer data)
{
    All *all = data;
    GtkWidget *parent = all->f->this , *content_area ;
    int rep;
    GtkWidget   *titre, *titreVal, *longueur, *longueurVal,*largeur, *largeurVal,*posX,*posXVal,*posY,*posYVal;

    GtkWidget *dialog = gtk_dialog_new_with_buttons( utf8("Creation d'un TextView") ,
                                                    GTK_WINDOW(parent)               ,
                                                    GTK_DIALOG_MODAL                ,
                                                    "_Creer",GTK_RESPONSE_OK        ,
                                                    "_Annuler",GTK_RESPONSE_CANCEL  ,
                                                    NULL);
    cssDataToWidget(dialog, "color :#DDDDDD;background-color:#252526;");
    if(!all->isDark)    
        cssDataToWidget(dialog, "color : #222;background-color:#CCCEDB;");

    //  recuperer contenaire du dialog                                                    
    content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
    cssDataToWidget(content_area, "color :#DDDDDD;background-color:#252526;");
    if(!all->isDark)    
        cssDataToWidget(content_area, "color : #222;background-color:#CCCEDB;");
    //  creation d'un  grid où on va mettre nos element
    Container *grid = new_Grid();
    //  creation des elements
    titre		 =gtk_label_new("Titre");
    titreVal     =gtk_entry_new();
    longueur 	 =gtk_label_new("Longueur");
    longueurVal	 =gtk_entry_new();
    largeur    	 =gtk_label_new("Largeur");
    largeurVal	 =gtk_entry_new();
    posX    	 =gtk_label_new("Position X");
    posXVal 	 =gtk_entry_new();
    posY     	 =gtk_label_new("Position Y");
    posYVal	     =gtk_entry_new();
    //  ajout des elements au grid
    grid = Grid_add(grid,titre          ,0,0,1,1);		 
    grid = Grid_add(grid,titreVal       ,1,0,1,1);		 
    grid = Grid_add(grid,longueur       ,0,1,1,1); 	 
    grid = Grid_add(grid,longueurVal    ,1,1,1,1);	
    grid = Grid_add(grid,largeur       ,0,2,1,1); 	 
    grid = Grid_add(grid,largeurVal    ,1,2,1,1);	
    grid = Grid_add(grid,posX           ,0,3,1,1); 	 
    grid = Grid_add(grid,posXVal        ,1,3,1,1);	 
    grid = Grid_add(grid,posY           ,0,4,1,1); 	 
    grid = Grid_add(grid,posYVal        ,1,4,1,1);
    //  Ajouter des espacement
    gtk_grid_set_row_spacing (GTK_GRID(grid->this), 10);
    gtk_grid_set_column_spacing (GTK_GRID(grid->this), 10);
    gtk_container_set_border_width ( GTK_CONTAINER(content_area), 10);
    gtk_container_set_border_width ( GTK_CONTAINER(grid->this), 20);

    gtk_container_add(GTK_CONTAINER(content_area),grid->this);
    gtk_widget_show_all (dialog);

    //  execution du dialog    
    rep = gtk_dialog_run (GTK_DIALOG (dialog));
    //  creer la fenetre si la reponse est oui
    if(rep == GTK_RESPONSE_OK)
    {
        const gchar *titre = gtk_entry_get_text(GTK_ENTRY(titreVal));
        const gchar *ty = gtk_entry_get_text(GTK_ENTRY(longueurVal));
        const gchar *tx = gtk_entry_get_text(GTK_ENTRY(largeurVal));
        const gchar *x = gtk_entry_get_text(GTK_ENTRY(posXVal));
        const gchar *y = gtk_entry_get_text(GTK_ENTRY(posYVal));
       
        gchar *fullCode = g_strconcat( "globale.ajouterTextview(\"",titre,"\",",tx,",",ty,",",x,",",y,");globale.actualiser();", NULL);
        
        char m[10000];
        FILE *output = fopen("lib/include/TEST/out","w+");
        Tokens *toks = Lexer(fullCode);
        Trees    *trs   = Parser(toks);
        Evalutor(trs,&global,m,output);
        fclose(output);
        char *azz = readFromFile("lib/include/TEST/out",azz);

        gtk_widget_destroy (dialog);
    }
    else
        gtk_widget_destroy (dialog);
}
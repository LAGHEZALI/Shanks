Container* left_body(All *all)
{
    //  creation du frame
    Container *left = new_Frame("  Interface  ",10);
    all->leftFrame=left->this;
    cssDataToWidget(left->this, "color : #23D18B;background-color: #252526;padding:10px;");
    
    //  edition du titre
    GtkWidget *titre = Frame_get_label(left);
    all->leftTitre=titre;
    cssDataToWidget(titre, "color : #0098FF;font-size:30px;font-weight:bolder;");
    
    //  Creation Flow Container
    Container *flow     =   new_FlowBox(10);  
    cssDataToWidget(flow->this,"background-color:#FFF;font-size:25px;font-weight:bolder;");
    
    //  creation des boutons
    Component *iterface_fenetre = new_Button(" Fenêtre");
    Component *iterface_bouton = new_Button(" Bouton");
    Component *iterface_input = new_Button(" Entry");
    Component *iterface_label = new_Button(" Label");
    Component *iterface_textview = new_Button(" TextView");
    Component *iterface_checkBox = new_Button(" CheckBox");
    Component *iterface_radio = new_Button(" Radio");
    Component *iterface_combo = new_Button(" ComboBox");
    Component *iterface_menu = new_Button(" MenuBar");
    
    //Ajout des bouton au Flow 
    FlowBox_add(flow,iterface_fenetre->this,-1);
    FlowBox_add(flow,iterface_bouton->this,-1);
    FlowBox_add(flow,iterface_input->this,-1);
    FlowBox_add(flow,iterface_label->this,-1);
    FlowBox_add(flow,iterface_textview->this,-1);
    FlowBox_add(flow,iterface_checkBox->this,-1);
    FlowBox_add(flow,iterface_radio->this,-1);
    FlowBox_add(flow,iterface_combo->this,-1);
    FlowBox_add(flow,iterface_menu->this,-1);
    
    //  Ajout du Flow au left Frame
    left = Frame_add(left,flow->this);

    //  SIGNAUX
    g_signal_connect(G_OBJECT(iterface_fenetre->this)   , "clicked", G_CALLBACK(interfaceDialog_fenetre)    , all);
    g_signal_connect(G_OBJECT(iterface_bouton->this)    , "clicked", G_CALLBACK(interfaceDialog_bouton)     , all);
    g_signal_connect(G_OBJECT(iterface_input->this)     , "clicked", G_CALLBACK(interfaceDialog_input)      , all);
    g_signal_connect(G_OBJECT(iterface_label->this)     , "clicked", G_CALLBACK(interfaceDialog_label)      , all);
    g_signal_connect(G_OBJECT(iterface_textview->this)  , "clicked", G_CALLBACK(interfaceDialog_textview)   , all);
    g_signal_connect(G_OBJECT(iterface_checkBox->this)  , "clicked", G_CALLBACK(interfaceDialog_checkbox)   , all);
    g_signal_connect(G_OBJECT(iterface_radio->this)     , "clicked", G_CALLBACK(interfaceDialog_radios)     , all);
    g_signal_connect(G_OBJECT(iterface_combo->this)     , "clicked", G_CALLBACK(interfaceDialog_combobox)   , all);
    g_signal_connect(G_OBJECT(iterface_menu->this)      , "clicked", G_CALLBACK(interfaceDialog_menu)       , all);

    return (left);
}
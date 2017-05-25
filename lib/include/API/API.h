#include "SD/SD.h"





//  transforme chaine en format utf8
char* utf8(char *chaine)
{
    return(g_locale_to_utf8 (chaine,-1,0,0,0));
}
#include "SD1/Structures.h"
#include "SD1/Taille.h" 
#include "Prototypes.h"

//  Containers

#include "Containers/Container.h"
#include "Containers/Box.h"
#include "Containers/Grid.h"
#include "Containers/FlowBox.h"
#include "Containers/Stack.h"
#include "Containers/Fixed.h"
#include "Containers/Paned.h"
#include "Containers/Frame.h"
#include "Containers/Scroll.h"

//all the windows
#include "Windows/Fenetre.h"

//all the component
#include "Components/Component.h"
#include "Components/Label.h"
#include "Components/Image.h"
#include "Components/infoBar.h"
#include "Components/statusBar.h"
#include "Components/Button.h"
#include "Components/TextView.h"
#include "Components/Entry.h"
#include "Components/ComboBox.h"
#include "Components/CheckBox.h"
#include "Components/Radio.h"


#include "outils/outils.h"
#include "implementationSD/implementationSD.h"
#include "analyse/analyse.h"
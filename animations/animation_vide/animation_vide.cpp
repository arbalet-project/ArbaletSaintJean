#include <Animation.h>

#ifndef ANIMATION_VIDE
#define ANIMATION_VIDE

// "AnimationVide" est un exemple vide, ne pas copier bêtement
// TODO Remplacer tous les "Vide" par le nom de votre animation

using namespace std;

class AnimationVide : public Animation {
    public:
        AnimationVide() {
            // Le constructeur. Si j'ai des valeurs par défaut à donner aux variables membres, c'est ici
        }

        int setup(int height, int width, int loops) {
            // Les paramètres d'entrée et de sortie de cette méthode doivent 
            //    correspondre avec l'interface dans Animation.h
            
            // TODO Mon code de setup
        }

        void loop() {
            // Les paramètres d'entrée et de sortie de cette méthode doivent 
            //    correspondre avec l'interface dans Animation.h
            
            // TODO Mon code de loop
        }

    private:
        // J'ai le droit d'ajouter des méthodes privées ici pour
        //   découper correctement mon code.
};

#endif

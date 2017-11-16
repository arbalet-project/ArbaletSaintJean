# Dossier des animations

Dans ce dossier se trouvent les 12 animations des étudiants. Chaque animation étant au sous-dossier ici, avec l'exemple vide on doit donc avoir 13 sous-dossiers ici.  

## Description générale
Chaque animation est une classe, qui contient des méthodes (fonctions) et d'éventuels attributs (variables) qui sont spécifiques aux besoins de l'animation.

Elles doivent toutes respecter la même interface que la classe [`Animation`](../Animation.h), c'est à dire d'implémenter au moins les fonctions dans `Animation` avec les mêmes paramètres, bien qu'elles puissent en impleménter plus.

## Comment créer ma propre animation ?
Dupliquer le dossier `AnimationVide` et lui attribuer un nom en remplaçant tous les "Vide" par votre nom.
Ensuite ajouter tous les fichiers ainsi créés avec `git add`, valider l'ajout de fichiers avec `git commit` et inscrire un message "Ajout de l'animation <MON NOM D'ANIMATION>" puis envoyer les modifications sur le serveur avec `git push`. Il ne doit pas y avoir de message d'erreur.

Ensuite, vous pouvez éditer le code de votre animation. Peu importe ce qu'elle fait visuellement parlant, elle devra forcément mettre à jour le tableau en variable globale `PIXELS` à chaque `loop()`.
Comme d'habitude la fonction `setup()` est exécutée une seule fois au démarrage de l'animation et vous permet d'initialiser les variables dont vous avez besoin.
L'équipe chargé de l'interface logicielle vous donnera plus de détails sur ce que vous devez ou pouvez faire dans votre code pour qu'il convienne à l'interface qu'ils ont décidé.

## Attention
Code code est une ébauche, il ne permet pas en l'état de contrôler les LEDs.

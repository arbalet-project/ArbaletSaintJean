# Dossier des animations

Dans ce dossier se trouvent les 12 animations des étudiants. Chaque animation étant un sous-dossier ici, avec l'exemple vide on doit donc avoir 13 sous-dossiers.  

## Description générale
Chaque animation est une classe, qui contient des méthodes (fonctions) et d'éventuels attributs (variables) qui sont spécifiques aux besoins de l'animation.

Elles doivent toutes respecter la même interface que la classe [`Animation`](../Animation.h), c'est à dire implémenter au moins les fonctions dans `Animation` avec les mêmes paramètres, bien qu'elles puissent en impleménter plus. A ce jour le minimum est `setup` et `loop`.

Attention : ce code n'est qu'une ébauche, il ne permet pas en l'état de séquencer tous vos programmes, une sous-équipe se chargera de la partie séquençage, ce seront les architectes logiciels, et ils seront amenés à changer les interfaces en cours de route, impliquant des changements que vous devrez impacter vous-même à chacune de vos animations.

** Chaque étudiant est responsable de son animation.** Si elle ne compile pas, c'est de votre devoir de la faire marcher ou demander de l'aide. Vous travaillez tous sur le même programme, ne cassez pas le travail des autres. La commande `git blame` suivie d'un nom de fichier permet de savoir qui est responsable de chaque ligne de code, dans le cas où elle contient un bug par exemple.

## 1. Récupérer le dépôt
Sous Linux, clôner la bilbiothèque dans `~/sketchbook/libraries` puis ouvrir l'IDE Arduino :
```
cd ~/sketchbook/libraries
git clone https://github.com/arbalet-project/ArbaletSaintJean.git
# Si l'IDE Arduino est ouvert, le fermer puis le rouvrir pour prendre en compte les changements :
arduino
```

Si le clônage a réussi, le code correspondant apparait `Fichier > Exemples > ArbaletSaintJean > Sequencer`.
Le fichier qui se charge correspond au séquenceur, le programme qui se chargera de parcourir toutes vos animations et les séquencer tour à tour sur le mur.
A n'importe quel moment, ce programme doit compiler avec succès en cliquant sur "Vérifier"

## 2. Créer ma propre animation

* Dupliquer le dossier `animations/AnimationVide` et lui attribuer un nom en remplaçant tous les "Vide" par votre nom d'animation.
* Dans le séquenceur dupliquer la ligne `#include <animations/animation_vide/animation_vide.cpp>` et remplacer `vide` par votre nom d'animation. Le chemin spécifié doit exister.
* Enregistrez les fichiers modifiés. Le fichier `sequencer.ino` ne peut pas être enregistré depuis l'IDE car c'est un exemple, donc utilisez un autre éditeur (Gedit, Pluma, Kate, ...)
* Cliquer sur "Vérifier" pour vérifier que ça compile. La compilation avec succès est impérative pour ne pas casser le code des autres !! Ne passez pas à l'étape suivante si la compilation échoue.
* Ensuite ajouter tous les fichiers ainsi créés ou modifiés avec `git add`, valider l'ajout de fichiers avec `git commit -m "Ajout de l'animation <MON NOM D'ANIMATION>"` puis envoyer les modifications sur le serveur avec `git push`. Il ne doit pas y avoir de message d'erreur durant l'envoi, sinon votre animation n'est pas partagée et votre répertoire de travail n'est plus synchronisé avec le serveur.

## 3. Editer mon animation jusqu'à ce qu'elle donne le résultat escompé

Ensuite, vous pouvez éditer le code de votre animation. Peu importe ce qu'elle fait visuellement parlant, elle devra forcément mettre à jour le tableau en variable globale `PIXELS` à chaque `loop()`.
Comme d'habitude sur Arduino, la fonction `setup()` est exécutée une seule fois au démarrage de l'animation et vous permet d'initialiser les variables dont vous avez besoin.
L'équipe chargé de l'interface logicielle vous donnera plus de détails sur ce que vous devez ou pouvez faire dans votre code pour qu'il convienne à l'interface qu'ils ont décidé.

Toutes les animations sont orchestrées par le séquenceur, c'est donc le fichier d'exemple nommé `sequencer.ino` qu'il faut utiliser comme point d'entrée et cliquer sur "Vérifier".
Votre animation ne sera pas compilée si vous n'avez pas ajouté le `#include` en début de `sequencer.ino`.
Si l'animation d'un de vos camarade échoue à compiler et vous bloque, vous pouvez commenter son `#include` pour poursuivre, et lui envoyer un mail pour qu'il débogue son code.

Ne modifiez jamais l'exemple vide `AnimationVide`, il servira de référence pour les évolutions de l'interface.

## 4. A chaque travail sur mon animation, je me synchronise avec le serveur
* **Avant** chaque modification, récupérez les derniers changements avec `git pull`. Il ne doit pas y avoir d'erreur !
* Editez votre animation 
  * **Si elle compile**, validez les modifications : `git commit -am "J'ai changé XYZXYZ dans mon animation"` puis envoyez-les au serveur avec `git push`
  * **Si elle ne compile pas**, déboguez, mais n'envoyez pas les modifications sur le serveur, vous casseriez le code des autres.
* Demandez de l'aide en séance et/ou par mail si la compilation échoue et que vous ne vous en sortez pas mais n'essayez pas de `push`.
* Ne laissez pas cela trainer, sans `pull` ni `push` votre répaertoire de travail local risque de ne plus être synchronisé au serveur. Une désynchronisation trop longue est plus complexe à resynchroniser, à cause de conflits. 



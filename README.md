# lemin_2017
Projet de 1ère année, réalisé en groupe de 4. Le but était de faire parcourir une fourmilière à une colonie de fourmies.

## Usage
Pour lancer le programme il suffit d'écrire chaque éléments sur l'entrée standard.

La première ligne correspond au nombre de fourmis de la colonie.

- commentaire -> *##*
- salle -> *nomDeSalle:String coordonnéeX coordonnéeY*
- tunnel -> *nomDeSalle-nomDeSalle*

**EXEMPLE** (antill.txt):
```
10
## rooms
## start
S 0 0
## end
E 124 1241
2 1 0
3 0 1
4 1 1
## tunnels
S-2
2-3
2-4
3-E
4-E
```
```bash
./lem_in < anthill.txt
```

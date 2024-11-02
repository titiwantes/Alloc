# Alloc - Allocateur de Mémoire Personnalisé en C

**Alloc** est un projet d'implémentation d'un allocateur de mémoire personnalisé en C, qui imite les fonctions de gestion de mémoire `malloc`, `calloc`, `realloc` et `free`. L'objectif de ce projet est de mieux comprendre le fonctionnement de la gestion de mémoire dynamique à bas niveau et d'apprendre à manipuler des blocs de mémoire.

## Structure du Projet

```
Alloc
├── lib
│   └── alloc.h            # En-têtes et déclarations de structures et de fonctions
├── main.c                 # Point d'entrée pour tester les fonctionnalités
├── Makefile               # Script de compilation et de gestion de projet
├── README.md              # Documentation du projet
└── src
    ├── c_alloc.c          # Implémentation de la fonction calloc
    ├── free_alloc.c       # Implémentation de la fonction free
    ├── m_alloc.c          # Implémentation de la fonction malloc
    └── re_alloc.c         # Implémentation de la fonction realloc
```

## Fonctionnalités

L'allocateur fournit les fonctions suivantes :

- **`m_alloc(size_t size)`** : Alloue un bloc de mémoire de la taille spécifiée.
- **`c_alloc(size_t num, size_t size)`** : Alloue un bloc de mémoire initialisé à zéro, capable de stocker `num` éléments de taille `size`.
- **`re_alloc(void *ptr, size_t size)`** : Redimensionne un bloc de mémoire alloué précédemment.
- **`free_alloc(void *ptr)`** : Libère un bloc de mémoire précédemment alloué.

Toutes les fonctions reposent sur une gestion de mémoire personnalisée utilisant des blocs chaînés pour suivre les zones allouées et libres.

## Installation et Compilation

1. Clone le dépôt ou copie les fichiers dans un dossier local.
2. Utilise `make` pour compiler le projet.

```bash
make
```

Cela génère un exécutable nommé `main` pour tester les fonctions d'allocation personnalisées.

### Exécution avec Valgrind

Pour vérifier les fuites de mémoire et s'assurer que la gestion de la mémoire est correcte, utilise Valgrind :

```bash
make valgrind
```

## Utilisation

Le fichier `main.c` contient des exemples d'utilisation des fonctions d'allocation. Après compilation, exécute le programme pour tester le fonctionnement de l'allocateur :

```bash
./main
```

Modifie `main.c` pour tester différents cas et observer le comportement des fonctions.

## Nettoyage

Pour supprimer les fichiers objets et l'exécutable, utilise la commande :

```bash
make clean
```

# push_swap

Trier une pile d'entiers en utilisant un ensemble limite d'operations, avec le moins de mouvements possibles.

---

## Algorithme

Le projet utilise le **Turkish sort** (insertion par cout minimal) pour les grands inputs :

1. **Push vers B** -- On pousse les elements de A vers B en choisissant a chaque fois l'element le moins couteux a deplacer. B est maintenue triee en ordre decroissant (circulaire). Le cout = rotations sur A + rotations sur B, avec optimisation `rr`/`rrr` quand les deux piles tournent dans le meme sens.
2. **Tri des 3 restants** -- Les 3 derniers elements dans A sont tries avec `sort_3`.
3. **Push vers A** -- On renvoie chaque element de B vers A (du plus grand au plus petit), en tournant A vers la bonne position d'insertion.
4. **Rotation finale** -- On tourne A pour mettre le minimum en haut.

Pour 5 elements ou moins, des algorithmes dedies (`sort_2`, `sort_3`, `sort_4`, `sort_5`) sont utilises.

Une passe d'optimisation fusionne les operations redondantes (`ra`+`rb` -> `rr`, annulation de paires comme `ra`+`rra`, etc.).

---

## Performance

Benchmark sur 100 runs aleatoires par taille :

| Taille | Avg ops | Max ops | Seuil 42 |
|--------|---------|---------|----------|
| 3      | 1       | 2       | 3        |
| 5      | 6       | 10      | 12       |
| 100    | 559     | 650     | 700      |
| 500    | 5107    | 5419    | 5500     |

---

## Compilation

```bash
make        # compile push_swap
make bonus  # compile le checker
make re     # recompilation complete
make clean  # supprime les .o
make fclean # supprime les .o et les binaires
```

---

## Utilisation

```bash
./push_swap 4 2 6 3 1 5
```

Affiche la liste des operations sur stdout, une par ligne.

### Checker (bonus)

Lit les operations depuis stdin et verifie que la pile est triee :

```bash
./push_swap 4 2 6 3 1 5 | ./checker 4 2 6 3 1 5
# OK
```

---

## Operations

| Op    | Effet                                           |
|-------|-------------------------------------------------|
| `sa`  | Swap les deux premiers elements de A            |
| `sb`  | Swap les deux premiers elements de B            |
| `ss`  | `sa` + `sb`                                     |
| `pa`  | Push le sommet de B sur A                       |
| `pb`  | Push le sommet de A sur B                       |
| `ra`  | Rotation de A vers le haut (top va en bas)      |
| `rb`  | Rotation de B vers le haut                      |
| `rr`  | `ra` + `rb`                                     |
| `rra` | Rotation inverse de A (bottom va en haut)       |
| `rrb` | Rotation inverse de B                           |
| `rrr` | `rra` + `rrb`                                   |

---

## Structures

| Struct    | Role                                              |
|-----------|---------------------------------------------------|
| `t_stack` | Pile dynamique (tableau de `t_elem` : value+index) |
| `t_ops`   | Tableau dynamique d'operations (strings)           |
| `t_cost`  | Cout d'un move (cost_a, cost_b, total)             |

---

## Structure du projet

```
push_swap.h        Header (structs, prototypes)
main.c             Point d'entree, dispatch vers le tri
turk_sort.c        Orchestration du Turkish sort
turk_cost.c        Calcul du cout, position cible dans B
turk_exec.c        Execution des moves avec optimisation rr/rrr
sort_small.c       Tris dedies pour 2-5 elements
sort_utils.c       Helpers (min_pos, rotate_to_top, push_max)
ops.c              Operations sur les piles (swap, push, rotate, revrotate)
ops_utils.c        Gestion de la liste d'operations
optimize_ops.c     Fusion/annulation post-tri des operations
parsing.c          Parsing des arguments
parsing_utils.c    Validation, gestion d'erreurs
indexing.c         Indexation valeur -> rang
checker.c          Bonus : verificateur d'operations
```

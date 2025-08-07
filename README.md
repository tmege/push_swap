# 🧩 push_swap

## 🎯 Objectif

Le projet `push_swap` a pour but de trier une pile d'entiers en utilisant **le moins d'opérations possibles**, parmi un ensemble d'opérations limitées.

Ce projet est une excellente introduction à l'algorithmique, à la gestion de la mémoire, et à l'optimisation.

---

## ⚙️ Fonctionnement

### 1. **Parsing des arguments**

- Vérifie que chaque argument est :
  - Un **entier valide**
  - Dans la plage `int`
  - **Non dupliqué**
- Les valeurs sont stockées dans la pile `a`.

### 2. **Indexation**

- Chaque valeur est remplacée par son **index trié**.
  - Exemple : `[9, 3, 7]` devient `[2, 0, 1]`
- Cette indexation facilite le tri par comparaison simple.

### 3. **Choix de la stratégie**

- Si la pile contient :
  - `2` à `5` éléments → tri spécifique (`sort_2`, `sort_3`, `sort_4`, `sort_5`)
  - Plus de `5` éléments → **tri par chunks** (`chunk_sort`)

### 4. **Tri par chunks**

- Les éléments sont triés par groupes (chunks) selon leurs index.
- On pousse les éléments de chaque chunk dans la pile `b`.
- Ensuite, on les replace dans la pile `a` dans l’ordre décroissant.
- Stratégie inspirée du **Bucket Sort**.

### 5. **Optimisation des opérations**

- Suppression des **paires inutiles** (`ra` + `rra`, `pa` + `pb`, etc.).
- Fusion des opérations combinables (`sa` + `sb` → `ss`, etc.).
- Réduction du nombre total d'instructions.

---

## 🧱 Structures utilisées

- `t_stack` : pile dynamique contenant les valeurs à trier
- `t_ops` : tableau dynamique d'opérations
- `t_chunk` : structure de travail pour le tri par groupes

---
## Algorithme a O(n√n)

![Courbe de representation big O](assets/push_swap_perf.png)


---

## 🛠️ Compilation

```bash
make


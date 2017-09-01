# Amylum

Amylum est un gestionnaire de membre open source, créer pour l'Adem.
Toutes les informations sont stockés dans une base de donnnées SQLite.

Adem (Amicale des étudiants en mathématiques, Strasbourg)

## Fonctionnalités
* Ajouts de membre
* Recherche de membre
* Fiche d'information membre
* Génération de mailing (aliases)

## Base de donnnées
* Member
  * idMember
  * lastName
  * firstName
  * email
  * status
    * L1  (0x10)
    * L2I (0x21)
    * L2M (0x22)
    * L3I (0x31)
    * L3M (0x32)
    * M1I (0x41)
    * M1M (0x42)
    * M2I (0x51)
    * M2M (0x52)
    * DOC (0x60)
    * PROF (0x70)
    * AUTRE (0xF0)

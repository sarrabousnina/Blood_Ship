#ifndef V3_H_INCLUDED
#define V3_H_INCLUDED
#include<gtk/gtk.h>
#include <stdio.h>
typedef struct
{
    char  id_utilisateur[10];
    char nom_utilisateur[40],prenom_utilisateur[40];
    char cin_utilisateur[20];
    int age_utilisateur;
    char annees_carriere_utilisateur[40],role_utilisateur[70],sexe_utilisateur[20];
} utilisateur;
//le type de  retour int c'est pour indiquer si la tache a été réalisée avec succés ou non// pour afficher des lsg plus tard exemple erreur d'ouverture de fichier, element introuvable
int ajouter_utilisateur(char *, utilisateur );
int modifier_utilisateur( char *, utilisateur );
int supprimer_utilisateur(char *, char id[10] );
utilisateur chercher_utilisateur(char *, char id[10]);
void sexe_u(int sexe, utilisateur u);
void annees_utilisateur(int annees[10] , utilisateur u);
int idExiste_utilisateur(char id[10]);
void afficher_utilisateur(GtkWidget *liste , char *filename);
void UserRole(char nomFichier[50], int role);
//void pourcentageUSer(char nomFichier[50], float * nbHomme, float * nbFemme);
float pourcentageF();
float pourcentageH();

typedef struct
{
    char nom [20],prenom [20],sexe[6],typs[20], cin[20], age[10];
     
} donneur;


typedef struct {

int JJ, MM ,AA ;
char cin[9] , cre[6];
int idetabs;
}rdv ;

int ajouter(char *, donneur );
int modifier( char *, char *, donneur );
int supprimer(char *, char *);
donneur chercher(char *, char *);

void typesangradio(int i , char msg[]);
void posneg(int choix[],char text[]);

void afficher(GtkWidget *liste);
void vider(GtkWidget *liste);

int listeRDV(char* filename, char ETS[], int jour, int mois , int annee);
int nbETS( char * filename);
float moyRDV_ETS (char * filename, int jour, int mois , int annee);
void afficherrdv(GtkWidget *liste);
void viderrdv(GtkWidget *liste);


#endif // V3_H_INCLUDED

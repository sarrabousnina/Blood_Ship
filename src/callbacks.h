#include <gtk/gtk.h>


void
on_plus20_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_moins20_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_homme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femme__toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_confirmationajout_utilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_afficherajout_utilisateur_clicked   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_plus202_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_moins202_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femme2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_homme2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_affichermodification_utilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_confirmationmodification_utilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_confirmer_suppression_utilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_affichersuppression_utilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeviewutilisateur_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ajouterutilisateurafficher_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_modifierutilisateurafficher_clicked (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_supprimerutilisateurafficher_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_consultation_modification_utilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retourner_ajouterutilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retourner_modifierutilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retourner_supprimerutilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_actualiser_afficherutilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_liste_infirmier_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_liste_medecinbilogiste_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_utilisateurs_parsexe_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview_medecins_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_retourmedecins_clicked       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview_infirmiers_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retourner_infirmiers_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview_responsables_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retourner_responsable_clicked       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_liste_responsableETS_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_actualiser_medecins_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_actualiser_infirmier_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_actualiser_responsable_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retourner_sexe_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_actualiser_sexe_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_ajouterdonneursarra_clicked  (GtkWidget *objet_graphique, gpointer user_data);

void
on_confirmermodifsarra_clicked (GtkWidget *objet_graphique, gpointer user_data);

void
on_sarraajouterafficher_clicked (GtkWidget *objet_graphique, gpointer user_data);

void
on_sarramodifierafficher_clicked  (GtkWidget *objet_graphique, gpointer user_data);

void
on_sarrasupprimerafficher_clicked  (GtkWidget *objet_graphique, gpointer user_data);

void
on_confirmationsupprimersarra_clicked  (GtkWidget *objet_graphique, gpointer user_data);


void
on_hommesarra_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femmesarra_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_positif_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_negatif_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_hommesarramodif_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femmesarramodif_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_positifmodif_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_negatifmodif_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_afficherajout_clicked               (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_buttonactualiser_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeviewsarra_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_sarrasupprimeraffiche_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_boutontriafficher_clicked           (GtkButton       *objet,
                                        gpointer         user_data);

void
on_treeviewtri_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_Trier_clicked                       (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_retour_clicked                      (GtkButton       *objet,
                                        gpointer         user_data);

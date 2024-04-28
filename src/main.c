/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *zeinebajouter;
  GtkWidget *zeinebmodifier;
  GtkWidget *zeinebsupprimer_;
  GtkWidget *zeinebafficher;
  GtkWidget *liste_medecins;
  GtkWidget *liste_infirmiers;
  GtkWidget *liste_responsables;
  GtkWidget *utilisateurs_sexe;
  GtkWidget *sarramodifier;
  GtkWidget *sarraajouter;
  GtkWidget *sarrasupprimer;
  GtkWidget *sarratri;
  GtkWidget *sarraaffichage;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  zeinebajouter = create_zeinebajouter ();
  //gtk_widget_show (zeinebajouter);
  zeinebmodifier = create_zeinebmodifier ();
  //gtk_widget_show (zeinebmodifier);
  zeinebsupprimer_ = create_zeinebsupprimer_ ();
  //gtk_widget_show (zeinebsupprimer_);
  zeinebafficher = create_zeinebafficher ();
  gtk_widget_show (zeinebafficher);
  liste_medecins = create_liste_medecins ();
  //gtk_widget_show (liste_medecins);
  liste_infirmiers = create_liste_infirmiers ();
  //gtk_widget_show (liste_infirmiers);
  liste_responsables = create_liste_responsables ();
  //gtk_widget_show (liste_responsables);
  utilisateurs_sexe = create_utilisateurs_sexe ();
  //gtk_widget_show (utilisateurs_sexe);
  sarramodifier = create_sarramodifier ();
  //gtk_widget_show (sarramodifier);
  sarraajouter = create_sarraajouter ();
  //gtk_widget_show (sarraajouter);
  sarrasupprimer = create_sarrasupprimer ();
  //gtk_widget_show (sarrasupprimer);
  sarratri = create_sarratri ();
  //gtk_widget_show (sarratri);
  sarraaffichage = create_sarraaffichage ();
  gtk_widget_show (sarraaffichage);

  gtk_main ();
  return 0;
}


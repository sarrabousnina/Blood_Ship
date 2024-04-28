#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"v3.h"
#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
int sexe=1;
int annees[]={0,0};
int i,x;
int i=1 ,i2=1;
int choix[]={0,0},choix2[]={0,0};


void
on_confirmationajout_utilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	utilisateur u;
	GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *output ;
	GtkWidget *zeinebajouter;

	input1=lookup_widget(objet,"idutilisateur");
	input2=lookup_widget(objet,"nomutilisateur");
	input3=lookup_widget(objet,"prenomutilisateur");
	input4=lookup_widget(objet,"cinutilisateur");
	input5=lookup_widget(objet,"ageutilisateur");
	input6=lookup_widget(objet,"combobox1");
	output=lookup_widget(objet,"affiche_confirmationajoututilisateur");

	strcpy(u.id_utilisateur,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(u.nom_utilisateur,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(u.prenom_utilisateur,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(u.cin_utilisateur,gtk_entry_get_text(GTK_ENTRY(input4)));
	u.age_utilisateur=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
	if(annees[0]==1){
		strcpy(u.annees_carriere_utilisateur,"+20ans");
	}
	if(annees[1]==1){
		strcpy(u.annees_carriere_utilisateur,"-20ans");
	}
	
	strcpy(u.role_utilisateur,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));
	if(sexe==1){
		strcpy(u.sexe_utilisateur,"femme");
	}
	else if(sexe==2){
		strcpy(u.sexe_utilisateur,"homme");
	}
	
	
	if((strlen(u.cin_utilisateur)==8) && (idExiste_utilisateur(u.id_utilisateur) == 0)  )
	{
		i=ajouter_utilisateur("utilisateur.txt",u);
		if(i==1)
			gtk_label_set_text(GTK_LABEL(output),"ajout avec succes!");
		else
			gtk_label_set_text(GTK_LABEL(output),"echec d'ajout !");
	}
	else
	{
		if((strlen(u.cin_utilisateur)!=8))
			gtk_label_set_text(GTK_LABEL(output),"echec d'ajout ! CIN incorrecte");
		if((idExiste_utilisateur(u.id_utilisateur) == 1))
			gtk_label_set_text(GTK_LABEL(output),"echec d'ajout ! ID existe");
	}
	
		
	
			
	
	
	
}
void
on_afficherajout_utilisateur_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	
	GtkWidget *window1 , *window2 , *treeview1;
	window1=lookup_widget(objet,"zeinebajouter");

	gtk_widget_destroy(window1);
	window2=lookup_widget(objet,"zeinebafficher");
	window2= create_zeinebafficher();

	gtk_widget_show(window2);

	treeview1=lookup_widget(window2,"treeviewutilisateur");
	afficher_utilisateur(treeview1,"utilisateur.txt");
	

}
void
on_femme__toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
		sexe=1;
}


void
on_homme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
		sexe=2;
}


void
on_moins20_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if( gtk_toggle_button_get_active(togglebutton))
		annees[1]=1;
}


void
on_plus20_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if( gtk_toggle_button_get_active(togglebutton))
		annees[0]=1;
}


void
on_retourner_ajouterutilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *window2;
	window1=lookup_widget(objet,"zeinebajouter");
	window2= create_zeinebafficher();
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}


void
on_consultation_modification_utilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *output;
	GtkWidget *input1;
	char id[10];
	input1 = lookup_widget(objet,"idutilisateur3");
	output = lookup_widget(objet,"label_id_modificationutilisateur");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));

	if(idExiste_utilisateur(id) == 0){	
		gtk_label_set_text(GTK_LABEL(output),"identifiant introuvable !");
	}
	else{
		gtk_label_set_text(GTK_LABEL(output),"veuillez effectuer votre modification");
		
	}
}

void
on_moins202_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if( gtk_toggle_button_get_active(togglebutton))
		annees[1]=1;
}


void
on_plus202_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if( gtk_toggle_button_get_active(togglebutton))
		annees[0]=1;
}



void
on_femme2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
		sexe=1;
}



void
on_homme2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
		sexe=2;
}


void
on_affichermodification_utilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *window2 , *treeview1;
	window1=lookup_widget(objet,"zeinebmodifier");

	gtk_widget_destroy(window1);
	window2=lookup_widget(objet,"zeinebafficher");
	window2= create_zeinebafficher();

	gtk_widget_show(window2);

	treeview1=lookup_widget(window2,"treeviewutilisateur");
	afficher_utilisateur(treeview1,"utilisateur.txt");
	
}


void
on_retourner_modifierutilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *window2;
	window1=lookup_widget(objet,"zeinebmodifier");
	window2= create_zeinebafficher();
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}

void
on_confirmationmodification_utilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *output;
	GtkWidget *input1,*input2,*input3,*input4,*input5,*input6;

	utilisateur p;
	input1=lookup_widget(objet,"idutilisateur2");
	input2=lookup_widget(objet,"nomutilisateur2");
	input3=lookup_widget(objet,"prenomutilisateur2");
	input4=lookup_widget(objet,"cinutilisateur2");
	input5=lookup_widget(objet,"ageutilisateur2");
	input6=lookup_widget(objet,"combobox2");
	output=lookup_widget(objet,"label_resultatmodification_utilisateur");

	if(annees[0]==1){
		strcpy(p.annees_carriere_utilisateur,"+20ans");
	}
	if(annees[1]==1){
		strcpy(p.annees_carriere_utilisateur,"-20ans");
	}
	
	strcpy(p.role_utilisateur,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));
	if(sexe==1){
		strcpy(p.sexe_utilisateur,"femme");
	}
	else if(sexe==2){
		strcpy(p.sexe_utilisateur,"homme");
	}
	
	strcpy(p.id_utilisateur,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(p.nom_utilisateur,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(p.prenom_utilisateur,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(p.cin_utilisateur,gtk_entry_get_text(GTK_ENTRY(input4)));
	p.age_utilisateur=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));

	if(idExiste_utilisateur(p.id_utilisateur)!=1){
		gtk_label_set_text(GTK_LABEL(output),"echec de modification ! identifiant introuvable");
	}
	else{
		if((strlen(p.cin_utilisateur)==8)   )
		{ 	x=modifier_utilisateur("utilisateur.txt",p);
			if(x==1){
				gtk_label_set_text(GTK_LABEL(output),"modification avec succes !");
			}
			else{
				gtk_label_set_text(GTK_LABEL(output),"echec de modification !");
			}
		}
		else
			gtk_label_set_text(GTK_LABEL(output),"echec de modification ! CIN incorrecte ");
	}

	
}

void
on_confirmer_suppression_utilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *input, *output;
	char id[10];
	input=lookup_widget(objet,"idsupprimer_utilisateur");
	output=lookup_widget(objet,"afficher_confimationsuppression_utilisateur");

	strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
	if (idExiste_utilisateur(id) == 1){
		int x= supprimer_utilisateur("utilisateur.txt",  id);
		if(x==1){
			gtk_label_set_text(GTK_LABEL(output),"suppression avec succes!");
		}
	}
	else
		gtk_label_set_text(GTK_LABEL(output),"echec de suppression ! Identifiant introuvable");
		                                                                                                                                                 
		
	
}

void
on_affichersuppression_utilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *window2 , *treeview1;
	window1=lookup_widget(objet,"zeinebsupprimer");

	gtk_widget_destroy(window1);
	window2=lookup_widget(objet,"zeinebafficher");
	window2= create_zeinebafficher();

	gtk_widget_show(window2);

	treeview1=lookup_widget(window2,"treeviewutilisateur");
	afficher_utilisateur(treeview1,"utilisateur.txt");
		
}

void
on_retourner_supprimerutilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *window2;
	window1=lookup_widget(objet,"zeinebsupprimer");
	window2= create_zeinebafficher();
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}


void
on_treeviewutilisateur_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* id;
	gchar* nom;
	gchar* prenom;
	gchar* cin;
	gchar* age;
	gchar* annees_carriere;
	gchar* role;
	gchar* sexe;
	utilisateur u;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter, path))
	{
		//obtention des valeurs de la ligne selectionnée
		gtk_tree_model_get(GTK_LIST_STORE(model) , &iter , 0 ,&id,1,&nom,2,&prenom,3,&cin,4,&age,5,&annees_carriere,6,&role,7,&sexe,-1);
		strcpy(u.id_utilisateur,id);
		strcpy(u.nom_utilisateur,nom);
		strcpy(u.prenom_utilisateur,prenom);
		strcpy(u.cin_utilisateur,cin);
		strcpy(u.age_utilisateur,age);
		strcpy(u.annees_carriere_utilisateur,annees_carriere);
		strcpy(u.role_utilisateur,role);
		strcpy(u.sexe_utilisateur,sexe);
		afficher_utilisateur(treeview,"utilisateur.txt");
	}
		
}

void
on_supprimerutilisateurafficher_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *window2;
	window1=lookup_widget(objet,"zeinebafficher");
	window2= create_zeinebsupprimer_();
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}

void
on_ajouterutilisateurafficher_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *window2;
	window1=lookup_widget(objet,"zeinebafficher");
	window2= create_zeinebajouter();
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}

void
on_liste_infirmier_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *window2;
	window1=lookup_widget(objet,"zeinebafficher");
	window2= create_liste_infirmiers();
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);

}

void
on_liste_medecinbilogiste_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *window2;
	window1=lookup_widget(objet,"zeinebafficher");
	window2= create_liste_medecins();
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}

void
on_utilisateurs_parsexe_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *window2;
	window1=lookup_widget(objet,"zeinebafficher");
	window2= create_utilisateurs_sexe();
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}

void
on_button_actualiser_afficherutilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *treeview1;
	window1=lookup_widget(objet,"zeinebafficher");
	treeview1=lookup_widget(window1,"treeviewutilisateur");
	afficher_utilisateur(treeview1,"utilisateur.txt");
}


void
on_modifierutilisateurafficher_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *window2;
	window1=lookup_widget(objet,"zeinebafficher");
	window2= create_zeinebmodifier();
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}




void
on_liste_responsableETS_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *window2;
	window1=lookup_widget(objet,"zeinebafficher");
	window2= create_liste_responsables();
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}



void
on_treeview_medecins_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	
	GtkTreeIter iter;
	gchar* id;
	gchar* nom;
	gchar* prenom;
	gchar* cin;
	gchar* age;
	gchar* annees_carriere;
	gchar* role;
	gchar* sexe;
	utilisateur u;
	
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter, path))
	{
		//UserRole( "utilisateur.txt",1);
		//obtention des valeurs de la ligne selectionnée
		gtk_tree_model_get(GTK_LIST_STORE(model) , &iter , 0 ,&id,1,&nom,2,&prenom,3,&cin,4,&age,5,&annees_carriere,6,&role,7,&sexe,-1);
		strcpy(u.id_utilisateur,id);
		strcpy(u.nom_utilisateur,nom);
		strcpy(u.prenom_utilisateur,prenom);
		strcpy(u.cin_utilisateur,cin);
		strcpy(u.age_utilisateur,age);
		strcpy(u.annees_carriere_utilisateur,annees_carriere);
		strcpy(u.role_utilisateur,role);
		strcpy(u.sexe_utilisateur,sexe);
		afficher_utilisateur(treeview,"medecins_biologistes.txt");
	}
		
}


void
on_button_retourmedecins_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *window2;
	window1=lookup_widget(objet,"liste_medecins");
	window2= create_zeinebafficher();
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}


void
on_actualiser_medecins_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *treeview1;
	window1=lookup_widget(objet,"liste_medecins");
	treeview1=lookup_widget(window1,"treeview_medecins");
	UserRole( "utilisateur.txt",2);
	afficher_utilisateur(treeview1,"medecins_biologistes.txt");
}



void
on_treeview_infirmiers_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* id;
	gchar* nom;
	gchar* prenom;
	gchar* cin;
	gchar* age;
	gchar* annees_carriere;
	gchar* role;
	gchar* sexe;
	utilisateur u;
	
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter, path))
	{
		//UserRole( "utilisateur.txt",2);
		//obtention des valeurs de la ligne selectionnée
		gtk_tree_model_get(GTK_LIST_STORE(model) , &iter , 0 ,&id,1,&nom,2,&prenom,3,&cin,4,&age,5,&annees_carriere,6,&role,7,&sexe,-1);
		strcpy(u.id_utilisateur,id);
		strcpy(u.nom_utilisateur,nom);
		strcpy(u.prenom_utilisateur,prenom);
		strcpy(u.cin_utilisateur,cin);
		strcpy(u.age_utilisateur,age);
		strcpy(u.annees_carriere_utilisateur,annees_carriere);
		strcpy(u.role_utilisateur,role);
		strcpy(u.sexe_utilisateur,sexe);
		afficher_utilisateur(treeview,"infirmiers.txt");
	}
		
}


void
on_retourner_infirmiers_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *window2;
	window1=lookup_widget(objet,"liste_infirmiers");
	window2= create_zeinebafficher();
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}


void
on_actualiser_infirmier_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *treeview1;
	window1=lookup_widget(objet,"liste_infirmiers");
	treeview1=lookup_widget(window1,"treeview_infirmiers");
	UserRole( "utilisateur.txt",3);
	afficher_utilisateur(treeview1,"infirmiers.txt");
}
void
on_treeview_responsables_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* id;
	gchar* nom;
	gchar* prenom;
	gchar* cin;
	gchar* age;
	gchar* annees_carriere;
	gchar* role;
	gchar* sexe;
	utilisateur u;
	
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter, path))
	{
		//UserRole( "utilisateur.txt",3);
		//obtention des valeurs de la ligne selectionnée
		gtk_tree_model_get(GTK_LIST_STORE(model) , &iter , 0 ,&id,1,&nom,2,&prenom,3,&cin,4,&age,5,&annees_carriere,6,&role,7,&sexe,-1);
		strcpy(u.id_utilisateur,id);
		strcpy(u.nom_utilisateur,nom);
		strcpy(u.prenom_utilisateur,prenom);
		strcpy(u.cin_utilisateur,cin);
		strcpy(u.age_utilisateur,age);
		strcpy(u.annees_carriere_utilisateur,annees_carriere);
		strcpy(u.role_utilisateur,role);
		strcpy(u.sexe_utilisateur,sexe);
		afficher_utilisateur(treeview,"responsables_ets.txt");
	}
		
}

void
on_retourner_responsable_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *window2;
	window1=lookup_widget(objet,"liste_responsables");
	window2= create_zeinebafficher();
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}

void
on_actualiser_responsable_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *treeview1;
	window1=lookup_widget(objet,"liste_responsables");
	treeview1=lookup_widget(window1,"treeview_responsables");
	UserRole( "utilisateur.txt",1);
	afficher_utilisateur(treeview1,"responsables_ets.txt");
}


void
on_retourner_sexe_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 , *window2;
	window1=lookup_widget(objet,"utilisateurs_sexe");
	window2= create_zeinebafficher();
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}


void
on_actualiser_sexe_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
 	
	float i,j;
	char women[20] , men[20];
	GtkWidget *output1 , *output2;
	
	output1=lookup_widget(objet,"label_pourcentage_femme");
	output2=lookup_widget(objet,"label_pourcentage_homme");
	i= pourcentageF();
	sprintf(women,"%.0f",i);
	strcat(women,"%");
	j=pourcentageH(),
	sprintf(men,"%.0f",j);
	strcat(men,"%");
	gtk_label_set_text(GTK_LABEL(output1),women);
	gtk_label_set_text(GTK_LABEL(output2),men);
	

}


void
on_femmesarramodif_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) i2=2;
}

void
on_hommesarramodif_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) i2=1;
}



void
on_negatifmodif_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) choix2[1]=1;
}


void
on_positifmodif_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) choix2[0]=1;
}



void
on_confirmermodifsarra_clicked (GtkWidget *objet, gpointer user_data)
{

GtkWidget * nom , *prenom , *age ,*homme ,*femme ,*typs ,*pos , *neg, *output , *cin;

donneur d ;
int x ,a;
char sang[20] ,agee[20];
nom= lookup_widget(objet, "nommodifsarra1") ;
prenom= lookup_widget(objet, "prenommodifsarra1") ;
cin= lookup_widget(objet, "cinmodifsarra1") ;
age= lookup_widget(objet, "agemodifsarra1") ;
homme= lookup_widget(objet, "hommesarramodif") ;
femme= lookup_widget(objet, "femmesarramodif") ;
typs= lookup_widget(objet, "listesangsarramodif") ;
pos= lookup_widget(objet, "positifmodif") ;
neg= lookup_widget(objet, "negatifmodif") ;
output= lookup_widget(objet, "labelmodif") ;

strcpy(d.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(d.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(d.cin, gtk_entry_get_text(GTK_ENTRY(cin)));
typesangradio(i2 ,d.sexe);
strcpy(d.typs, gtk_combo_box_get_active_text(GTK_COMBO_BOX(typs)));
posneg(choix2,d.typs);
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(age));
sprintf(agee,"%d",a);
strcpy(d.age,agee);

x=modifier("donneur.txt",d.cin,d );

if(x==1)
	gtk_label_set_text(GTK_LABEL(output),"modification avec succés");
       
    else gtk_label_set_text(GTK_LABEL(output),"echec de modification");




}


void
on_retour_clicked                      (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1 , *window2;
 window1=lookup_widget(objet,"sarramodifier"); 
window2= create_sarraaffichage();

 gtk_widget_show(window2); gtk_widget_destroy(window1); 

}


void
on_femmesarra_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) i=2;
}

void
on_hommesarra_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) i=1;
}


void
on_negatif_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) choix[1]=1;
}



void
on_positif_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) choix[0]=1;
}


void
on_ajouterdonneursarra_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget * nom , *prenom , *cin , *age ,*homme ,*femme ,*typs ,*pos , *neg, *output;

donneur d ;
int x ,a;
char sang[20] ,agee[20];
nom= lookup_widget(objet_graphique, "Nomsarra1") ;
prenom= lookup_widget(objet_graphique, "prenomsarra1") ;
homme= lookup_widget(objet_graphique, "hommesarra") ;
femme= lookup_widget(objet_graphique, "femmesarra") ;
typs= lookup_widget(objet_graphique, "listesangsarra") ;
pos= lookup_widget(objet_graphique, "positif") ;
neg= lookup_widget(objet_graphique, "negatif") ;
cin= lookup_widget(objet_graphique, "CINsarra1") ;
age= lookup_widget(objet_graphique, "agesarra1") ;
output= lookup_widget(objet_graphique, "labelajout") ;


strcpy(d.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(d.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
typesangradio(i ,d.sexe);
strcpy(d.typs, gtk_combo_box_get_active_text(GTK_COMBO_BOX(typs)));
posneg(choix,d.typs);
strcpy(d.cin, gtk_entry_get_text(GTK_ENTRY(cin)));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(age));
sprintf(agee,"%d",a);
strcpy(d.age,agee);

x= ajouter("donneur.txt",d );

if(x==1)
	gtk_label_set_text(GTK_LABEL(output),"ajout du donneur avec succés");
       
    else gtk_label_set_text(GTK_LABEL(output),"echec d'ajout");



}


void
on_afficherajout_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

fenetre_ajout=lookup_widget(objet,"sarraajouter");
gtk_widget_destroy(fenetre_ajout);

fenetre_afficher=lookup_widget(objet,"sarraaffichage");
fenetre_afficher=create_sarraaffichage();

gtk_widget_show(fenetre_afficher);
gtk_widget_destroy(fenetre_ajout); 

treeview1=lookup_widget(fenetre_afficher,"treeviewsarra");
afficher(treeview1);






}


void
on_confirmationsupprimersarra_clicked   (GtkWidget *objet_graphique, gpointer user_data)
{

int x ;
char c[20];
GtkWidget *window1 , *window2;
GtkWidget * cin , *output ; 

window1=lookup_widget(objet_graphique,"sarrasupprimer"); 
cin= lookup_widget(objet_graphique, "cinsarrasupprimer2") ;
output= lookup_widget(objet_graphique, "labelsupprimer") ;

strcpy(c, gtk_entry_get_text(GTK_ENTRY(cin)));

x=supprimer("donneur.txt",c);

    if(x==1)
	gtk_label_set_text(GTK_LABEL(output),"suppression avec succés");
       
    else gtk_label_set_text(GTK_LABEL(output),"echec de suppression");


 
gtk_widget_destroy(window1);
window2=lookup_widget(objet_graphique,"sarraaffichage"); 
window2= create_sarraaffichage();

gtk_widget_show(window2); 
 





}


void
on_treeviewtri_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter;
gchar* Jour ;
gchar* Mois ;
gchar* Annee ;
gchar* CIN ;
gchar* cre;
gchar* IdEtab;

rdv r;

GtkTreeModel *model =gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model , &iter , path))
{ gtk_tree_model_get(GTK_LIST_STORE(model), &iter , 0, &Jour , 1 , &Mois ,2,&Annee,3,&CIN,4,&cre,5,&IdEtab ,-1);


r.JJ=Jour;
r.MM=Mois;
r.AA=Annee;
strcpy(r.cin,CIN);
strcpy(r.cre,cre);
r.idetabs=IdEtab;

afficher(treeview);
}
}


void
on_Trier_clicked                       (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget * jour, *mois , *annee , *idetab , *output1, *output2 ;
GtkWidget *fenetre_afficher,*w1;
GtkWidget *treeview1;

int nb ,aa;
float moy ;
char j[4] ,m[4],a[4],id[10] ,nbtxt[5],moytxt[20];
jour= lookup_widget(objet_graphique, "entryjour") ;
mois= lookup_widget(objet_graphique, "entrymois") ;
annee= lookup_widget(objet_graphique, "entryannee") ;
idetab= lookup_widget(objet_graphique, "entryetab") ;
output1= lookup_widget(objet_graphique, "labelmoy") ;
output2= lookup_widget(objet_graphique, "labelnbrdv") ;


strcpy(j, gtk_entry_get_text(GTK_ENTRY(jour)));
strcpy(m, gtk_entry_get_text(GTK_ENTRY(mois)));
strcpy(a, gtk_entry_get_text(GTK_ENTRY(annee)));
strcpy(id, gtk_entry_get_text(GTK_ENTRY(idetab)));

aa = atoi (j);
int b = atoi (m);
int c = atoi (a);


nb= listeRDV("rdv.txt", id, aa,b,c);
moy =moyRDV_ETS ("rdv.txt",aa,b,c);

sprintf(nbtxt, "%d" , nb);
sprintf(moytxt, "%f" ,moy);

gtk_label_set_text(GTK_LABEL(output2),nbtxt);
gtk_label_set_text(GTK_LABEL(output1),moytxt);








w1=lookup_widget(objet_graphique,"sarratri");
fenetre_afficher=create_sarratri();

gtk_widget_show(fenetre_afficher);

gtk_widget_hide(w1);
treeview1=lookup_widget(fenetre_afficher,"treeviewtri");


viderrdv(treeview1);
afficherrdv(treeview1);



}


void
on_treeviewsarra_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter;

gchar* nom ;
gchar* prenom ;
gchar* sexe ;
gchar* typs ;
gchar* cin ;
gchar* age ;

donneur d;

GtkTreeModel *model =gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model , &iter , path))
{ gtk_tree_model_get(GTK_LIST_STORE(model), &iter , 0, &nom , 1 , &prenom ,2,&sexe,3,&typs,4,&cin,5,&age ,-1);

/*
strcpy(d.nom,nom);
strcpy(d.prenom,prenom);
strcpy(d.sexe,sexe);
strcpy(d.typs,typs);
strcpy(d.cin,cin);
strcpy(d.age,age);*/
strcpy(d.nom,nom);
strcpy(d.prenom,prenom);
strcpy(d.sexe,cin);
strcpy(d.typs,age);
strcpy(d.cin,sexe);
strcpy(d.age,typs);

afficher(treeview);
}
}


void
on_sarrasupprimeraffiche_clicked       (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *window1 , *window2; 
window1=lookup_widget(objet,"sarraaffichage"); 
window2= create_sarrasupprimer();

gtk_widget_show(window2); 
gtk_widget_destroy(window1); 



}


void
on_sarraajouterafficher_clicked  (GtkWidget *objet, gpointer user_data)
{
GtkWidget *window1 , *window2; 
window1=lookup_widget(objet,"sarraaffichage"); 
window2= create_sarraajouter();
gtk_widget_destroy(window1); 

gtk_widget_show(window2); 




}


void
on_buttonactualiser_clicked            (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;
GtkWidget *treeview1;



w1=lookup_widget(objet,"sarraaffichage");
fenetre_afficher=create_sarraaffichage();

gtk_widget_show(fenetre_afficher);

gtk_widget_hide(w1);
treeview1=lookup_widget(fenetre_afficher,"treeviewsarra");


vider(treeview1);
afficher(treeview1);




}



void
on_sarramodifierafficher_clicked  (GtkWidget *objet, gpointer user_data)
{
GtkWidget *window1 , *window2; 
window1=lookup_widget(objet,"sarraaffichage"); 
window2=create_sarramodifier();
gtk_widget_destroy(window1); 

gtk_widget_show(window2); 



}


void
on_boutontriafficher_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1 , *window2; 
window1=lookup_widget(objet,"sarraaffichage"); 
window2= create_sarratri();

gtk_widget_show(window2); 

}


#include "v3.h"
#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include<gtk/gtk.h>

enum
{
NOM ,
PRENOM,
SEXE ,
TYPS,
CIN ,
AGE,
SCOLUMNS,
};

enum
{

JJ,
MM,
AA,
CIND,
CRE,
IDETAB,
SECOLUMNS

};
enum{
	UID,
	UNOM,
	UPRENOM,
	UCIN,
	UAGE,
	UANNEES_CARRIERE,
	UROLE,
	USEXE,
	UCOLUMNS,
};

void afficherrdv(GtkWidget *liste)
{
GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;

int jj;
int mm;
int aa ;
char cin[9];
char cre[6];
int idetab;
store=NULL;

FILE *f ;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
	{
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("    Jour    ",renderer,"text",JJ,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("    Mois    ",renderer,"text",MM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("    Annee    ",renderer,"text",AA,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("    CIN     ",renderer,"text",CIND,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);


	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("    cre    ",renderer,"text",CRE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);


	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("    IdEtab    ",renderer,"text",IDETAB,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);
	}

store=gtk_list_store_new(SECOLUMNS,G_TYPE_INT ,G_TYPE_INT ,G_TYPE_INT ,G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_INT );

f=fopen("rdv.txt","r");
if(f==NULL) { return ; }
else
	{f=fopen("rdv.txt","a+");
		while(fscanf(f,"%d %d %d %s %s %d\n",&jj,&mm,&aa,cin,cre,&idetab)!=EOF)
		{ gtk_list_store_append(store ,&iter);
		gtk_list_store_set(store ,&iter,JJ,jj,MM,mm,AA,aa,CIND,cin,CRE,cre,IDETAB,idetab,-1);
		}

	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
}

}




void viderrdv(GtkWidget *liste)
{

GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter;
GtkListStore *store;

int jj;
int mm;
int aa ;
char cin[9];
char cre[6];
int idetab;
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if (store==NULL)
	{

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("    Jour    ",renderer,"text",JJ,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("    Mois    ",renderer,"text",MM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("    Annee    ",renderer,"text",AA,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("    CIN     ",renderer,"text",CIND,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);


	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("    cre    ",renderer,"text",CRE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);


	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("    IdEtab    ",renderer,"text",IDETAB,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);

	}


store=gtk_list_store_new(SECOLUMNS,G_TYPE_INT ,G_TYPE_INT ,G_TYPE_INT ,G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_INT );
gtk_list_store_append(store,&iter);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));


}










void afficher(GtkWidget *liste)
{
GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;


char nom[20];
char prenom[20];
char sexe[20];
char typs[20];
char cin[20];
char age[20];
store=NULL;

FILE *f ;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
	{
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("    nom    ",renderer,"text",NOM,NULL);
	column = gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("    prenom    ",renderer,"text",PRENOM,NULL);
	column = gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("    sexe    ",renderer,"text",SEXE,NULL);
	column = gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);


	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("    typs    ",renderer,"text",TYPS,NULL);
	column = gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("    cin    ",renderer,"text",CIN,NULL);
	column = gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);


	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("   age    ",renderer,"text",AGE,NULL);
	column = gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);
	}

store=gtk_list_store_new(SCOLUMNS,G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_STRING );

f=fopen("donneur.txt","r");
if(f==NULL) { return ; }
else
	{f=fopen("donneur.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s \n",nom,prenom,sexe,typs,cin,age)!=EOF)
		{ gtk_list_store_append(store ,&iter);
		gtk_list_store_set(store ,&iter,NOM,nom,PRENOM,prenom,SEXE,sexe,TYPS,typs,CIN,cin,AGE,age,-1);
		}

	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
}

}


void vider(GtkWidget *liste)
{

GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter;
GtkListStore *store;


char nom[20];
char prenom[20];
char sexe[20];
char typs[20];
char cin[20];
char age[20];
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if (store==NULL)
	{

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);


	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("typs",renderer,"text",TYPS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);


	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("age",renderer,"text",AGE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste) , column);

	}


store=gtk_list_store_new(SCOLUMNS,G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_STRING );
gtk_list_store_append(store,&iter);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));


}






int ajouter(char * filename, donneur d )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %s\n",d.nom,d.prenom,d.cin,d.age,d.sexe,d.typs);
        fclose(f);
        return 1;
    }
    else return 0;
}



int modifier( char * filename, char * id, donneur nouv )
{
    int tr=0;
    donneur d ;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if((f!=NULL) && (f2!=NULL))
    {
        while(fscanf(f,"%s %s %s %s %s %s\n",d.nom,d.prenom,d.cin,d.age,d.sexe,d.typs)!=EOF)
        {
            if(strcmp(d.cin, id)==0)
            {
                fprintf(f2,"%s %s %s %s %s %s\n",nouv.nom,nouv.prenom,nouv.cin,nouv.age,nouv.sexe,nouv.typs);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %s %s %s\n",d.nom,d.prenom,d.cin,d.age,d.sexe,d.typs);

        }
    }
fclose(f);
fclose(f2);
remove(filename);
rename("nouv.txt", filename);
return tr;

}


int supprimer(char * filename, char * cin)
{
    int tr=0;
    donneur d ;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s\n",d.nom,d.prenom,d.cin,d.age,d.sexe,d.typs)!=EOF)
        {
            if(strcmp(d.cin, cin)==0)
                tr=1;
            else
                fprintf(f2,"%s %s %s %s %s %s\n",d.nom,d.prenom,d.cin,d.age,d.sexe,d.typs);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}




donneur chercher(char * filename, char * cin)
{
    donneur d;
    int tr=0 ;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %s %s %s\n",d.nom,d.prenom,d.cin,d.age,d.sexe,d.typs)!=EOF)
        {
            if(strcmp(d.cin, cin)==0)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
       strcpy( d.cin,"-1");
    return d;

}

void typesangradio(int i , char msg[])
{if (i==1) strcpy(msg,"Homme");
if(i==2) strcpy(msg,"Femme");
}


void posneg(int choix[], char text[])

{

if (choix[0]==1) {strcat(text,"+");}
else if (choix[1]==1) {strcat(text,"-");}


}



int listeRDV(char* filename, char ETS[], int jour, int mois , int annee)
{rdv r ;
int tr=0;
char ch[20];
 FILE * f=fopen(filename, "r");
 FILE * g=fopen("rdvaffichage.txt", "a");
  if(f!=NULL)

	{
	while(fscanf(f,"%d %d %d %s %s %d\n",&r.JJ,&r.MM,&r.AA,r.cin,r.cre,&r.idetabs)!=EOF)

		{	sprintf(ch, "%d" , r.idetabs);	
			if(r.JJ==jour && r.MM==mois && r.AA==annee && strcmp(ETS,ch)==0)

				{
				fprintf(g,"%d %d %d %s %s %d\n",&r.JJ,&r.MM,r.AA,r.cin,r.cre,&r.idetabs);
				tr++;
				}

		}

 fclose(f);
 fclose(g);

	}

return tr ;
}

int nbETS( char * filename)
{
rdv r ;

char ch[20] ,ch1[20];
int tr=0, c =0;
FILE * f=fopen( filename, "r");
FILE * g=fopen("listetab.txt", "a");
if(f!=NULL)
{	
	while(fscanf(f,"%d %d %d %s %s %d\n",&r.JJ,&r.MM,&r.AA,r.cin,r.cre,&r.idetabs)!=EOF)

		{	sprintf(ch, "%d" , r.idetabs);	
			while(fscanf(g,"%s",ch1)!=EOF )

				{
				if(strcmp(ch,ch1)==0)
				
				tr=1;
				}
			if(tr==0) fprintf(g,"%s\n",ch);

		}

	while(fscanf(g,"%s",ch)!=EOF ) c++;

}
fclose(f);
fclose(g);
return c;

}


float moyRDV_ETS (char * filename, int jour, int mois , int annee)
{rdv r ;
int c=0, nb;
char ch;

FILE * f=fopen(filename, "r");

 if(f!=NULL)

	{
	while(fscanf(f,"%d %d %d %s %s %d\n",&r.JJ,&r.MM,r.AA,r.cin,r.cre,&r.idetabs)!=EOF)

		{	sprintf(ch, "%d" , r.idetabs);	
			if(r.JJ==jour && r.MM==mois && r.AA==annee)

				{
				c++;
				}

		}
	}



fclose(f);
nb=nbETS(filename);

return (c/nb);
}

////////////////////////////////////////zeineb////////////////////////////////////


int ajouter_utilisateur(char * filename, utilisateur u )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %d %s %s %s\n",u.id_utilisateur,u.nom_utilisateur,u.prenom_utilisateur,u.cin_utilisateur,u.age_utilisateur,u.annees_carriere_utilisateur,u.role_utilisateur,u.sexe_utilisateur);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier_utilisateur( char * filename, utilisateur nouv )
{
    int tr=0;
    utilisateur u;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
	tr=0;
        while(fscanf(f,"%s %s %s %s %d %s %s %s\n",u.id_utilisateur,u.nom_utilisateur,u.prenom_utilisateur,u.cin_utilisateur,&u.age_utilisateur,u.annees_carriere_utilisateur,u.role_utilisateur,u.sexe_utilisateur)!=EOF)
        {
            if(strcmp(u.id_utilisateur,nouv.id_utilisateur)==0)
            {
                fprintf(f2,"%s %s %s %s %d %s %s %s\n",nouv.id_utilisateur,nouv.nom_utilisateur,nouv.prenom_utilisateur,nouv.cin_utilisateur,nouv.age_utilisateur,nouv.annees_carriere_utilisateur,nouv.role_utilisateur,nouv.sexe_utilisateur);
                tr=1;
		break;
            }
            else
                fprintf(f2,"%s %s %s %s %d %s %s %s\n",u.id_utilisateur,u.nom_utilisateur,u.prenom_utilisateur,u.cin_utilisateur,u.age_utilisateur,u.annees_carriere_utilisateur,u.role_utilisateur,u.sexe_utilisateur);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int supprimer_utilisateur(char * filename,  char id[])
{
    int tr=0;
    utilisateur u;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %d %s %s %s\n",u.id_utilisateur,u.nom_utilisateur,u.prenom_utilisateur,u.cin_utilisateur,&u.age_utilisateur,u.annees_carriere_utilisateur,u.role_utilisateur,u.sexe_utilisateur)!=EOF)
        {
            if(strcmp(u.id_utilisateur,id)==0){
                tr=1;
		break;
		}
            else
                fprintf(f2,"%s %s %s %s %d %s %s %s\n",u.id_utilisateur,u.nom_utilisateur,u.prenom_utilisateur,u.cin_utilisateur,u.age_utilisateur,u.annees_carriere_utilisateur,u.role_utilisateur,u.sexe_utilisateur);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
utilisateur chercher_utilisateur(char * filename,  char id[])
{
    utilisateur u;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %s %d %s %s %s\n",u.id_utilisateur,u.nom_utilisateur,u.prenom_utilisateur,u.cin_utilisateur,&u.age_utilisateur,u.annees_carriere_utilisateur,u.role_utilisateur,u.sexe_utilisateur)!=EOF)
        {
            if(strcmp(u.id_utilisateur,id)==0)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
	strcpy(u.id_utilisateur,"-1");
    return u;
}
void sexe_u(int sexe , utilisateur u)
{
	if(sexe==1)
		strcpy(u.sexe_utilisateur,"femme");
	if(sexe==2)
		strcpy(u.sexe_utilisateur,"homme");
}
void annees_utilisateur(int annees[] , utilisateur u)
{
	if(annees[0]==1)
		strcpy(u.annees_carriere_utilisateur,"+20ans de carriere");
	if(annees[1]==1)
		strcpy(u.annees_carriere_utilisateur,"-20ans de carriere");
}

int idExiste_utilisateur(char id[]){
    utilisateur u;
    FILE *f;
    f = fopen("utilisateur.txt","r");
    if(f != NULL){
    	while(fscanf(f,"%s %s %s %s %d %s %s %s\n",u.id_utilisateur,u.nom_utilisateur,u.prenom_utilisateur,u.cin_utilisateur,&u.age_utilisateur,u.annees_carriere_utilisateur,u.role_utilisateur,u.sexe_utilisateur) != EOF){
        	if(strcmp(u.id_utilisateur,id) == 0){
       		     return 1;
        	}
    	}
}
    fclose(f);
    return 0;

}

void afficher_utilisateur(GtkWidget *liste , char *filename)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char id[10];
	char nom[40];
	char prenom[40];
	char cin[20];
	int age;
	char annees_carriere[40];
	char role[40];
	char sexe[20];
	store=NULL;

	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new();
        	column = gtk_tree_view_column_new_with_attributes("   id   ",renderer,"text",UID,NULL);
        	column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
        	column = gtk_tree_view_column_new_with_attributes("   nom   ",renderer,"text",UNOM,NULL);
        	column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
        	column = gtk_tree_view_column_new_with_attributes("   prenom   ",renderer,"text",UPRENOM,NULL);
        	column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
        	column = gtk_tree_view_column_new_with_attributes("   cin   ",renderer,"text",UCIN,NULL);
		column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
        	column = gtk_tree_view_column_new_with_attributes("   age   ",renderer,"text",UAGE,NULL);
        	column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
        	column = gtk_tree_view_column_new_with_attributes("   	annees_carriere   ",renderer,"text",UANNEES_CARRIERE,NULL);
        	column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
        	column = gtk_tree_view_column_new_with_attributes("   				role				   ",renderer,"text",UROLE,NULL);
        	column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
        	column = gtk_tree_view_column_new_with_attributes("   sexe   ",renderer,"text",USEXE,NULL);
        	column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}
	store=gtk_list_store_new (UCOLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	f = fopen(filename, "r");
	if(f==NULL){
        	return;
    	}
	else
	{
		while(fscanf(f,"%s %s %s %s %d %s %s %s \n",id,nom,prenom,cin,&age,annees_carriere,role,sexe)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter, UID, id, UNOM, nom, UPRENOM, prenom, UCIN, cin, UAGE ,age ,UANNEES_CARRIERE ,annees_carriere ,UROLE ,role ,USEXE ,sexe, -1);
			
        	}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
    	}
    
}
void UserRole(char nomFichier[], int role)
{
	FILE * f=fopen(nomFichier, "r");
	FILE * f2=fopen("responsables_ets.txt", "a");
	FILE * f3=fopen("medecins_biologistes.txt", "a");
	FILE * f4=fopen("infirmiers.txt", "a");
	utilisateur u;	
	if(f!=NULL && f2!=NULL && f3!=NULL && f4!=NULL){
		while(fscanf(f,"%s %s %s %s %d %s %s %s\n",u.id_utilisateur,u.nom_utilisateur,u.prenom_utilisateur,u.cin_utilisateur,&u.age_utilisateur,u.annees_carriere_utilisateur,u.role_utilisateur,u.sexe_utilisateur)!=EOF)
        	{
			if(role==1)
			{
				if(strcmp(u.role_utilisateur,"Responsable-ETS")==0)
				{
					fprintf(f2,"%s %s %s %s %d %s %s %s\n",u.id_utilisateur,u.nom_utilisateur,u.prenom_utilisateur,u.cin_utilisateur,u.age_utilisateur,u.annees_carriere_utilisateur,u.role_utilisateur,u.sexe_utilisateur);
        		
				}
			}
			if(role==2)
			{
				if(strcmp(u.role_utilisateur,"Medecin-Biologiste")==0)
				{
					fprintf(f3,"%s %s %s %s %d %s %s %s\n",u.id_utilisateur,u.nom_utilisateur,u.prenom_utilisateur,u.cin_utilisateur,u.age_utilisateur,u.annees_carriere_utilisateur,u.role_utilisateur,u.sexe_utilisateur);
       
				}
			}
			if(role==3)
			{
				if(strcmp(u.role_utilisateur,"Infirmier(e)")==0)
				{
					fprintf(f4,"%s %s %s %s %d %s %s %s\n",u.id_utilisateur,u.nom_utilisateur,u.prenom_utilisateur,u.cin_utilisateur,u.age_utilisateur,u.annees_carriere_utilisateur,u.role_utilisateur,u.sexe_utilisateur);
				}
			}
		}
	}
	
    	fclose(f2);
	fclose(f3);
	fclose(f4);
	fclose(f);

}

float pourcentageF()
{
	utilisateur u;
	int nbt=0 , nbf=0 ;
	FILE * f=fopen("utilisateur.txt", "r");
	if(f!=NULL)
    	{
		while(fscanf(f,"%s %s %s %s %d %s %s %s\n",u.id_utilisateur,u.nom_utilisateur,u.prenom_utilisateur,u.cin_utilisateur,&u.age_utilisateur,u.annees_carriere_utilisateur,u.role_utilisateur,u.sexe_utilisateur)!=EOF)
        {
		if(strcmp(u.sexe_utilisateur,"femme")==0)
			nbf++;
		nbt++;
	}
	}
	fclose(f);
	return (float)nbf/nbt*100;
}
float pourcentageH()
{
	utilisateur u;
	int nbt=0 , nbh=0 ;
	FILE * f=fopen("utilisateur.txt", "r");
	if(f!=NULL)
    	{
		while(fscanf(f,"%s %s %s %s %d %s %s %s\n",u.id_utilisateur,u.nom_utilisateur,u.prenom_utilisateur,u.cin_utilisateur,&u.age_utilisateur,u.annees_carriere_utilisateur,u.role_utilisateur,u.sexe_utilisateur)!=EOF)
        {
		if(strcmp(u.sexe_utilisateur,"homme")==0)
			nbh++;
		nbt++;
	}
	}
	fclose(f);
	return (float)nbh/nbt*100;
}








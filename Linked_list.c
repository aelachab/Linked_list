


                 #include <stdio.h>
                 #include <stdlib.h>
                 #include <string.h>


        typedef struct etudiant
        {
            char nom[50];
            int  age;
            float moyenne ;
            struct etudiant *suivant ;
        }etudiant;

         // creer Neaud
        
        etudiant *creeNeaud(char _nom[50] ,int _age ,float _moyenne) {
            etudiant *new = (etudiant*)malloc(sizeof(etudiant))  ;
            new->age = _age ;
            strcpy(new->nom, _nom);
            new->moyenne = _moyenne ;
            new -> suivant = NULL ;
            return new;
        }

        // afiichage 
        void _affichNeaud(etudiant *debut) {
            etudiant *temps = debut ;
            while (temps != NULL ){
            printf("le nom : %s  | l age : %d  | le moyenne : %.2f\n ",temps->nom,temps->age,temps->moyenne);
            temps = temps->suivant;
            }
        }
        // taille liste 
        int tailleList( etudiant * debut ) {

           int compteur = 0;
           etudiant *temp = debut ;
           while ( temp != NULL )
           {
              temp = temp -> suivant;
              compteur++;
           }
           return compteur;
         }
        // ajouter au debut 
        etudiant *AjouterAudebut(etudiant *debut, char _nom[50] ,int _age ,float _moyenne) {
            etudiant *AjoutDebut = creeNeaud(_nom,_age,_moyenne);
            if(debut != NULL )
            AjoutDebut->suivant = debut ;
            debut = AjoutDebut ;
            return AjoutDebut;
        }
        // ajouter a la fin 
        etudiant *_AjouterFin(etudiant *debut, char _nom[50] ,int _age ,float _moyenne) {
            etudiant *Fin = creeNeaud(_nom,_age,_moyenne);
            if (debut == NULL)
            return Fin ;

            etudiant *temps = debut ;
            while (temps->suivant != NULL)
            temps = temps->suivant;
                temps->suivant = Fin ;
                Fin = temps->suivant;
                return debut ;
        }
        // ajouter au milieu 
        etudiant *_AjoutPosition(etudiant *debut, char _nom[50] ,int _age ,float _moyenne ,int _position) {
            etudiant *NeaMIlieu = creeNeaud(_nom,_age,_moyenne);
            // est ce que debut egale a NULL 
            if (debut == NULL )
            { return NeaMIlieu ; }
            // affect la taille de la lise 
            int taille = tailleList(debut);
             // est que le position est invalide pour librer NeaMIlieu 
            if( _position < 1 || _position < taille -1)
            {
              printf(" Position Invalise!!");
              free(NeaMIlieu);
              return debut ;
             }
             // pour que l'utilisateur affect une position = 1 ont ajout  au debut 
             if (_position == 1 )
             {
               NeaMIlieu = AjouterAudebut(debut,  _nom , _age , _moyenne);
             }
             // ajout ou potition 
             etudiant *temp = debut;
             for (int i = 1; i < _position - 1 ; i++)
               temp = temp->suivant ;
               NeaMIlieu->suivant = temp->suivant;
               temp->suivant = NeaMIlieu;
             
             return debut ;
        }
        
        void affectDonne(char nom[50], int *age, float *moyenne ) {
            printf(" Entrez Votre Nom s il vous plait : ");
            scanf("%s",nom);
            printf(" \n");
            printf(" Entrez Votre Age s il vous plait : \n");
            scanf("%d",age);
            printf(" \n");
            printf(" Entrez Votre Moyenne s il vous plait : \n");
            scanf("%f",moyenne);
            printf(" \n");
            
        }









        int main() {

            char nom[50];
            int age ;
            float moyenne;

            int choix ;
            int position ;
            int taille ;
            etudiant *tete = NULL ;

            do
            {

                printf(" [0] Pour sortir \n");
                printf(" [1] Ajouter au Debut \n");
                printf(" [2] Ajouter a la fin \n");
                printf(" [3] Ajouter au Une position \n");
                printf(" [4] Calculer la Taille de la liste \n");

                printf("Entrez votre choix :");
                scanf("%d",&choix);

            
             switch (choix)

                   {
                case 1 :
                affectDonne(nom,&age,&moyenne);
                tete = AjouterAudebut(tete,nom,age,moyenne);
                _affichNeaud(tete);
                break;

                case 2 : 
                affectDonne(nom,&age,&moyenne);
                tete = _AjouterFin(tete,nom,age,moyenne);
                _affichNeaud(tete);
                break;

                case 3 : 
                affectDonne(nom,&age,&moyenne);
                printf(" Entrez votre position : ");
                scanf("%d",&position);
                tete = _AjoutPosition(tete,nom,age,moyenne,position);
                _affichNeaud(tete);
                break;

                case 4 : 
                 tailleList(tete);
                break;

                case 0 : 
                printf(" See uu ");
                break;

             default:
             printf(" La liste est invalide!!!");
                break;
             }

              } while ( choix != 0);
            
        
            


            
      


        }


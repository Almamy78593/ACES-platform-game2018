#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void init_carte(int map_initial[22][22]) {
	//on initialise la map 22*22
	int i, j;
	// i = y et j = x
	for(i=0;i<22;i++){
		for(j=0;j<22;j++){
			map_initial[i][j] = 0;
			// toutes les cases prennent la valeur 0 
		}
	}
	int valeur_case;

	for(i=0;i<22;i++){
		for(j=0;j<22;j++){
			valeur_case = rand()%100;
			// on parcourt map_initial et valeur_case prend une valeur aléatoire entre 0 et 99
			if(valeur_case<50) {
				valeur_case = 0;
			}
			else {
				valeur_case = rand()%9;
				//on parcourt de nouveau map_initial et valeur_case prend une valeur aléatoire entre 0 et 8
			}
			map_initial[i][j] = valeur_case;
			// chaques case de map_initial prend la valeur donné par valeur_case
			map_initial[1][9] = 0;
			// la valeur initial de la case contenant le personnage est 0
		}
	}
}

void affiche_carte(int affiche_map[22][22], int affiche_perso[2]){
	//le void où l'on va afficher la carte et le perso initalement 
	int i, j; 
	printf("légende:\n fleur:🌻\t arbre:🌳\n rocher:🔺\t cle:🔑\n or:$\t\t cadenas:📦\n piège:💥\t monstre:👽\n");

		for(i=0;i<22;i++){
			printf(" \n");
			for(j=0;j<22;j++){
				if((i==1)&&(j==9)) {
				/* on initialise l'emplacement du perso*/
					printf("😀");//le personnage
					affiche_perso[0] = i;//la coordonné en ordonné du personnage dans la carte
					affiche_perso[1] = j;//la coordonné en abcisse du personnage dans la carte
				}
				else if ((i==0)||(i==21)){
				//les extrémités de la map sont affichés avec un "_"
					printf("- ");
				}
				else if (j==21){
				//les extrémité de la map sont affichés avec un "|"
					printf("  |");
				}
				else if (j==0){
				//les extrémité de la map sont affichés avec un "|"
					printf("|");
				}

				else if (affiche_map[i][j]==1){
				//si la case vaut 1, on affiche  "🌻"
				printf("🌻");
				}
				else if (affiche_map[i][j]==2){
				//si la case vaut 2, on affiche "🌳"
				printf("🌳");
				}
				else if (affiche_map[i][j]==3){
				//si la case vaut 3, on affiche "🔺"
				printf("🔺");
				}
				else if (affiche_map[i][j]==4){
				//si la case vaut 4, on affiche  "🔑"
				printf("🔑");
				}
				else if (affiche_map[i][j]==5){
				//si la case vaut 5, on affiche "$"
				printf("$");
				}
				else if (affiche_map[i][j]==6){
				//si la case vaut 6, on affiche "📦"
				printf("📦");
				}
				else if (affiche_map[i][j]==7){
				//si la case vaut 7, on affiche "💥"
				printf("💥");
				}
				else if (affiche_map[i][j]==8){
				//si la case vaut 8, on affiche "👽"
				printf("👽");
				}
				else if ((affiche_map[i][j]==0)&&((i!=0)&&(i!=21)&&(j!=0)&&(j!=21))){
					printf("  ");
				}
				else {
				printf("%d ", affiche_map[i][j]);
				}
		}
	}
	printf(" \n");
}

void printcarte(int carte_actuel[22][22], int perso_actuel[2]) {
	//affichage de la carte et du pero en temps réel
	int i, j;
	// val y et x de la carte 
	printf("légende:\n fleur:🌻\t arbre:🌳\n rocher:🔺\t cle:🔑\n or:$\t\t cadenas:📦\n piège:💥\t monstre:👽\n");

		for(i=0;i<22;i++){
			printf(" \n");
			for(j=0;j<22;j++){
				if((i == perso_actuel[0])&&(j == perso_actuel[1])) {
				/* on actualise l'emplacement du perso*/
					printf("😀 ");
				}
				else if ((i==0)||(i==21)){
				//les extrémités du tableau sont affichés avec un "_"
					printf("- ");
				}
				else if ((j==0)||(j==21)){
				//les extrémités du tableau sont affichés avec un "|"
					printf("|");
				}
				else if (carte_actuel[i][j]==1){
				//si la case vaut 1, on affiche  "🌻"
				printf("🌻 ");
				}
				else if (carte_actuel[i][j]==2){
				//si la case vaut 2, on affiche "🌳"
				printf("🌳 ");
				}
				else if (carte_actuel[i][j]==3){
				//si la case vaut 3, on affiche "🔺"
				printf("🔺 ");
				}
				else if (carte_actuel[i][j]==4){
				//si la case vaut 4, on affiche  "🔑"
				printf("🔑 ");
				}
				else if (carte_actuel[i][j]==5){
				//si la case vaut 5, on affiche "$"
				printf("$ ");
				}
				else if (carte_actuel[i][j]==6){
				//si la case vaut 6, on affiche "📦"
				printf("📦 ");
				}
				else if (carte_actuel[i][j]==7){
				//si la case vaut 7, on affiche "💥"
				printf("💥 ");
				}
				else if (carte_actuel[i][j]==8){
				//si la case vaut 8, on affiche "👽"
				printf("👽 ");
				}
				else if ((carte_actuel[i][j]==0)&&((i!=0)&&(i!=21)&&(j!=0)&&(j!=21))){
					printf("  ");
				}
				else {
				printf("%d ", carte_actuel[i][j]);
				// on affiche la carte avec l'emplacement du perso
				}
			}
		}
	printf(" \n");

}
int deplace_personnage(int mapp[22][22], int cperso[2]) {
	// la partie sur la saisie du deplacement du perso
	int i, j, direction;
	int $, hp, cle, coffre, sword;
	//variable utilisées pour stocker le nombre de pièces d'or: $ , de points de vie: HP et de clé: cle
	//sword est une épée
	cperso [0] = 1;
	cperso [1] = 9;
	$ = 0;
	hp = 10;
	cle = 0;
	sword = 0;

	do {
			printf("\n");
			printf("Où vas le personnage? (déplacez le avec 4, 6, 2 ou 8)\n");
			scanf("%d", &direction);
			printf("\n\n $ = %d\t hp = %d\t clé=%d\t épée=%d\n", $, hp, cle, sword);

			switch (direction) {		
			case 2 : cperso[0] = cperso[0]+1;/*en bas*/
				 if((cperso[0]>20) || (mapp[cperso[0]][cperso[1]] == 2) || (mapp[cperso[0]][cperso[1]] == 3)) { 
					/*si on heurte un rocher, un arbre, ou si on dépasse les les limites de la carte*/
					printf("le personnage ne peut pas aller dans cette direction\n");
					cperso[0] = cperso[0]-1;
				}
				else if(mapp[cperso[0]][cperso[1]] == 5) {
					/*si le joueur passe sur une piece d'or*/
					$ = $+1;
					mapp[cperso[0]][cperso[1]] = 0;
					// la pièce disparait
				}
				else if(mapp[cperso[0]][cperso[1]] == 8) {
					/*si le joueur passe sur un monstre*/
					if(sword > 0) {
						sword = sword-1;
						//on utilise l'épée sur le monstre
						mapp[cperso[0]][cperso[1]] = 0;
						//le monstre disprait
						}
					else {
						hp = hp-1;
						// le joueur perd une vie
					}
				}
				else if(mapp[cperso[0]][cperso[1]] == 7) {
					/*si le joueur passe sur un piège*/
					hp = hp-1;
					mapp[cperso[0]][cperso[1]] = 0;
					// le piège disparait
				}
				else if(mapp[cperso[0]][cperso[1]] == 4) {
					/*si le joueur passe sur une clé*/
					cle= cle+1;
					mapp[cperso[0]][cperso[1]] = 0;
					// la clé disparait et laisse place à de l'herbe
				}
				else if((mapp[cperso[0]][cperso[1]] == 6)&&(cle!=0)) {
					cle= cle-1;
					//on perd une clé
					coffre = rand()%30;
					if(coffre<10) {
						$= $+1;
						// on gagne une pièce	
						mapp[cperso[0]][cperso[1]] = 0;
						// le cadenas disparait et laisse place à de l'herbe
					}
					else if(coffre < 20){
						sword = 10;
						//on gagne une épée utilisable 10 fois
						mapp[cperso[0]][cperso[1]] = 0;
						//le cadenas disparait
					}
					else {
						hp = hp-2;
						//on perd 2 vies
						mapp[cperso[0]][cperso[1]] = 0;
						//le cadenas disparait
					}
				}
				for(i = 1;i < 21;i++) {
					for (j = 1; j < 21 ; j++) {
						if(($>0)&&(mapp[i][j] == 8)&&(i < cperso[0])&&((mapp[i+1][j]==1)||(mapp[i+1][j]==0))) {
							mapp[i+1][j] = mapp[i][j];
							// le monstre descend d'une case
							mapp [i][j] = 0;
						}
						else if(($>0)&&(mapp[i][j] == 8)&&(i >= cperso[0])&&((mapp[i-1][j]==1)||(mapp[i-1][j]==0))) {
							mapp[i-1][j] = mapp[i][j];
							// le monstre monte d'une case
							mapp [i][j] = 0;
						}
						else if(($>0)&&(mapp[i][j] == 8)&&(j < cperso[1])&&((mapp[i][j+1]==1)||(mapp[i][j+1]==0))) {
							mapp[i][j+1] = mapp[i][j];
							// le monstre va sur la case de droite
							mapp [i][j+1] = 0;
						}
						else if(($>0)&&(mapp[i][j] == 8)&&(j >= cperso[1])&&((mapp[i][j-1]==1)||(mapp[i][j-1]==0))) {
							mapp[i][j-1] = mapp[i][j];
							// le monstre va sur la case de gauche
							mapp [i][j] = 0;
						}
					}
				}			
			break;

			case 8 :  cperso[0] = cperso[0]-1;/*en haut*/
				 if((cperso[0]<1) || (mapp[cperso[0]][cperso[1]] == 2) || (mapp[cperso[0]][cperso[1]] == 3)) {
					/*si on heurte un rocher, un arbre, ou si on dépasse les les limites de la carte*/
					printf("le personnage ne peut pas aller dans cette direction\n");
					cperso[0] = cperso[0]+1;
				}
				else if(mapp[cperso[0]][cperso[1]] == 5) {
					/*si le joueur passe sur une piece d'or*/
					$ = $+1;
					mapp[cperso[0]][cperso[1]] = 0;
					// la pièce disparait
				}
				else if(mapp[cperso[0]][cperso[1]] == 8) {
					/*si le joueur passe sur un monstre*/
					if(sword > 0) {
						sword = sword-1;
						//on utilise l'épée sur le monstre
						mapp[cperso[0]][cperso[1]] = 0;
						//le monstre disprait
						}
					else {
						hp = hp-1;
						// le joueur perd une vie
					}
				}
				else if(mapp[cperso[0]][cperso[1]] == 7) {
					/*si le joueur passe sur un piège*/
					hp = hp-1;
					mapp[cperso[0]][cperso[1]] = 0;
					// le piège disparait
				}
				else if(mapp[cperso[0]][cperso[1]] == 4) {
					cle= cle+1;
					mapp[cperso[0]][cperso[1]] = 0;
					// la clé disparit et laisse place à de l'herbe
				}
				else if((mapp[cperso[0]][cperso[1]] == 6)&&(cle!=0)) {
					cle= cle-1;
					//on perd une clé
					coffre = rand()%30;
					if(coffre<10) {
						$= $+1;
						// on gagne une pièce	
						mapp[cperso[0]][cperso[1]] = 0;
						// le cadenas disparait et laisse place à de l'herbe
					}
					else if(coffre < 20){
						sword = 10;
						//on gagne une épée utilisable 10 fois
						mapp[cperso[0]][cperso[1]] = 0;
						//le cadenas disparait
					}
					else {
						hp = hp-2;
						//on perd 2 vies
						mapp[cperso[0]][cperso[1]] = 0;
						//le cadenas disparait
					}
				}
				for(i = 1;i < 21;i++) {
					for (j = 1; j < 21 ; j++) {
						if(($>0)&&(mapp[i][j] == 8)&&(i < cperso[0])&&((mapp[i+1][j]==1)||(mapp[i+1][j]==0))) {
							mapp[i+1][j] = mapp[i][j];
							// le monstre descend d'une case
							mapp [i][j] = 0;
						}
						else if(($>0)&&(mapp[i][j] == 8)&&(i >= cperso[0])&&((mapp[i-1][j]==1)||(mapp[i-1][j]==0))) {
							mapp[i-1][j] = mapp[i][j];
							// le monstre monte d'une case
							mapp [i][j] = 0;
						}
						else if(($>0)&&(mapp[i][j] == 8)&&(j < cperso[1])&&((mapp[i][j+1]==1)||(mapp[i][j+1]==0))) {
							mapp[i][j+1] = mapp[i][j];
							// le monstre va sur la case de droite
							mapp [i][j+1] = 0;
						}
						else if(($>0)&&(mapp[i][j] == 8)&&(j >= cperso[1])&&((mapp[i][j-1]==1)||(mapp[i][j-1]==0))) {
							mapp[i][j-1] = mapp[i][j];
							// le monstre va sur la case de gauche
							mapp [i][j] = 0;
						}
					}
				}
			break;

	
			case 4 : cperso[1] = cperso[1]-1;/*à gauche*/
				 if((cperso[1]<1) || (mapp[cperso[0]][cperso[1]] == 2) || (mapp[cperso[0]][cperso[1]] == 3)) {
					/*si on heurte un rocher, un arbre, ou si on dépasse les les limites de la carte*/
					printf("le personnage ne peut pas aller dans cette direction\n");
					cperso[1] = cperso[1]+1;
				}
				else if(mapp[cperso[0]][cperso[1]] == 5) {
					/*si le joueur passe sur une piece d'or*/
					$ = $+1;
					mapp[cperso[0]][cperso[1]] = 0;
					// la pièce disparait
				}
				else if(mapp[cperso[0]][cperso[1]] == 8) {
					/*si le joueur passe sur un monstre*/
					if(sword > 0) {
						sword = sword-1;
						//on utilise l'épée sur le monstre
						mapp[cperso[0]][cperso[1]] = 0;
						//le monstre disprait
						}
					else {
						hp = hp-1;
						// le joueur perd une vie
					}
				}
				else if(mapp[cperso[0]][cperso[1]] == 7) {
					/*si le joueur passe sur un piège*/
					hp = hp-1;
					mapp[cperso[0]][cperso[1]] = 0;
					// le piège disparait
				}
				else if(mapp[cperso[0]][cperso[1]] == 4) {
					cle= cle+1;
					mapp[cperso[0]][cperso[1]] = 0;
					// la clé disparait et laisse place à de l'herbe
				}
				else if((mapp[cperso[0]][cperso[1]] == 6)&&(cle!=0)) {
					cle= cle-1;
					//on perd une clé
					coffre = rand()%30;
					if(coffre<10) {
						$= $+1;
						// on gagne une pièce	
						mapp[cperso[0]][cperso[1]] = 0;
						// le cadenas disparait et laisse place à de l'herbe
					}
					else if(coffre < 20){
						sword = 10;
						//on gagne une épée utilisable 10 fois
						mapp[cperso[0]][cperso[1]] = 0;
						//le cadenas disparait
					}
					else {
						hp = hp-2;
						//on perd 2 vies
						mapp[cperso[0]][cperso[1]] = 0;
						//le cadenas disparait
					}
				}
				for(i = 1;i < 21;i++) {
					for (j = 1; j < 21 ; j++) {
						if(($>0)&&(mapp[i][j] == 8)&&(i < cperso[0])&&((mapp[i+1][j]==1)||(mapp[i+1][j]==0))) {
							mapp[i+1][j] = mapp[i][j];
							// le monstre descend d'une case
							mapp [i][j] = 0;
						}
						else if(($>0)&&(mapp[i][j] == 8)&&(i >= cperso[0])&&((mapp[i-1][j]==1)||(mapp[i-1][j]==0))) {
							mapp[i-1][j] = mapp[i][j];
							// le monstre monte d'une case
							mapp [i][j] = 0;
						}
						else if(($>0)&&(mapp[i][j] == 8)&&(j < cperso[1])&&((mapp[i][j+1]==1)||(mapp[i][j+1]==0))) {
							mapp[i][j+1] = mapp[i][j];
							// le monstre va sur la case de droite
							mapp [i][j+1] = 0;
						}
						else if(($>0)&&(mapp[i][j] == 8)&&(j >= cperso[1])&&((mapp[i][j-1]==1)||(mapp[i][j-1]==0))) {
							mapp[i][j-1] = mapp[i][j];
							// le monstre va sur la case de gauche
							mapp [i][j] = 0;
						}
					}
				}
			break;
	
			case 6 : cperso[1] = cperso[1]+1;/*à droite*/
				 if((cperso[1]>20) || (mapp[cperso[0]][cperso[1]] == 2) || (mapp[cperso[0]][cperso[1]] == 3)) {
					/*si on heurte un rocher, un arbre, ou si on dépasse les les limites de la carte*/
					printf("le personnage ne peut pas aller dans cette direction\n");
					cperso[1] = cperso[1]-1;
				}
				else if(mapp[cperso[0]][cperso[1]] == 5) {
					/*si le joueur passe sur une piece d'or*/
					$ = $+1;
					mapp[cperso[0]][cperso[1]] = 0;// la pièce disparait
				}
				else if(mapp[cperso[0]][cperso[1]] == 8) {
					/*si le joueur passe sur un monstre*/
					if(sword > 0) {
						sword = sword-1;
						//on utilise l'épée sur le monstre
						mapp[cperso[0]][cperso[1]] = 0;
						//le monstre disprait
						}
					else {
						hp = hp-1;
						// le joueur perd une vie
					}
				}
				else if(mapp[cperso[0]][cperso[1]] == 7) {
					/*si le joueur passe sur un piège*/
					hp = hp-1;
					mapp[cperso[0]][cperso[1]] = 0;
					// le piège disparait
				}
				else if(mapp[cperso[0]][cperso[1]] == 4) {
					cle= cle+1;
					mapp[cperso[0]][cperso[1]] = 0;
					// la clé disparait et laisse place à de l'herbe
				}
				else if((mapp[cperso[0]][cperso[1]] == 6)&&(cle!=0)) {
					cle= cle-1;
					//on perd une clé
					coffre = rand()%30;
					if(coffre<10) {
						$= $+1;
						// on gagne une pièce	
						mapp[cperso[0]][cperso[1]] = 0;
						// le cadenas disparait et laisse place à de l'herbe
					}
					else if(coffre < 20){
						sword = 10;
						//on gagne une épée utilisable 10 fois
						mapp[cperso[0]][cperso[1]] = 0;
						//le cadenas disparait
					}
					else {
						hp = hp-2;
						//on perd 2 vies
						mapp[cperso[0]][cperso[1]] = 0;
						//le cadenas disparait
					}
				}
				for(i = 1;i < 21;i++) {
					for (j = 1; j < 21 ; j++) {
						if(($>0)&&(mapp[i][j] == 8)&&(i < cperso[0])&&((mapp[i+1][j]==1)||(mapp[i+1][j]==0))) {
							mapp[i+1][j] = mapp[i][j];
							// le monstre descend d'une case
							mapp [i][j] = 0;
						}
						else if(($>0)&&(mapp[i][j] == 8)&&(i >= cperso[0])&&((mapp[i-1][j]==1)||(mapp[i-1][j]==0))) {
							mapp[i-1][j] = mapp[i][j];
							// le monstre monte d'une case
							mapp [i][j] = 0;
						}
						else if(($>0)&&(mapp[i][j] == 8)&&(j < cperso[1])&&((mapp[i][j+1]==1)||(mapp[i][j+1]==0))) {
							mapp[i][j+1] = mapp[i][j];
							// le monstre va sur la case de droite
							mapp [i][j] = 0;
						}
						else if((mapp[i][j] == 8)&&(j >= cperso[1])&&((mapp[i][j-1]==1)||(mapp[i][j-1]==0))) {
							mapp[i][j-1] = mapp[i][j];
							// le monstre va sur la case de gauche
							mapp [i][j] = 0;
						}
					}
				}
			break;
			case 0 : printf("vous avez quitté le jeu\n");
				 return -1;
				 // sortie du jeu
				 break;
			default : printf("erreur de saisie, le personnage ne bouge plus,mais les monstres si\n");
				/* caractère invalide*/ 

			}


		printcarte(mapp, cperso);
	} 	while (($ != 10)&&(hp > 0));
			//condition pour sortir du jeu
		if ($==10){
			printf("bien joué, vous avez gagné\n");
			printf("\n\n $ = %d\t hp = %d\t clé=%d\n", $, hp, cle);

		}
		else if(hp==0){
			printf("regarde dehors, il fait beau, c'est peut-être le moment de sortir! de toute façon tu as perdu! YOU LOOSE AGAIN!!!, le jeu s'arrete\n");
			printf("\n\n $ = %d\t hp = %d\t clé=%d\n", $, hp, cle);

		}
	return mapp[i][j];
}





int main () {
	int carte[22][22];
	int i,j, deplacement;
	int perso[2];

	init_carte(carte);
	affiche_carte(carte, perso);
	deplacement = deplace_personnage(carte, perso);
	return 0;
}	

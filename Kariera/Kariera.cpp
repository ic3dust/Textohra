// Kariera.cpp : Defines the entry point for the application.
//

#include "Kariera.h"
#include "Otazky_1.h"
#include "Struct.h"
#include <stdio.h>

#include <time.h>	// rand()
#include <stldib.h> // rand()

using namespace std;

int main()
{

	// ETAPA JMENA A POSTAVY
	struct postava postava;
	int vlastnost;

	printf("Vitame ve hre kariera! Jak se jmenujete? (Jmeno < 20 pismen) ");
	scanf_s("%19s\n", postava.jmeno, (unsigned)sizeof(postava.jmeno)); //pro pochopeni delky jmena proto, aby
																	// pretypovani, protoze vrati size_t - int data typ urceny pro vyjadrovani velikosti objektu v pameti
	printf("Super, pane %s", postava.jmeno, "! \nPojdme si zvolit vlastnost postavy!\n");
	printf("Jste spise moudry (1), aktivni (2) anebo drzy (3) hrac? -> ");
	scanf_s("%d\n", &vlastnost);

	int chyba = 0;
	switch (vlastnost) {
	case 1:
		postava.vlastnost = moudry;
		printf("Rikate chytry, co? Tak to prokazete behem hry!\n");
		break;
	case 2:
		postava.vlastnost = aktivni;
		printf("Komu se neleni, tomu se zeleni! Aktivní lidi u nás vítáme.\n");
		break;
	case 3:
		postava.vlastnost = drzy;
		printf("Sebevedomi Vam pomuze, ale u odpovedi moc nespehejte!\n");
		break;
	default:
		printf("Hra narazila na chybu na etape vyberu vlastnosti postavy. Overte hodnotu a spustte hru znovu.\n");
		chyba = 1; //potom v main if(chyba=1) return 1 a ukonci chybove vytvoreni postavy bezpecne;
		break;

	}

	enum vzhled;
	int uces;
	int vlasy;

	printf("Dale si vybereme rysy atraktivity: \n");
	printf("Mate vlasy (1 - Ano, 0 - Ne) -> ");
	scanf_s("%d\n", &uces);
	switch (uces) {
	case 0:
		postava.vzhled = plesaty;
		break;
	case 1:
		printf("Jste cernovlasy? (1 - Ano, 0 - Ne) -> ");
		scanf_s("%d\n", &vlasy);
		switch (vlasy) {
		case 0:
			postava.vzhled = blondyn;
			break;
		case 1:
			postava.vzhled = cernovlasy;
			break;
		default:
			printf("Neco se nepodarilo u volby vlasu. Zkontrolujte hodnoty a spustte hru znovu.\n");
		}
		break;
	default:
		printf("Neco se nepodarilo u volby ucesu. Zkontrolujte hodnoty a spustte hru znovu.\n");
		chyba = 1; //potom v main if(chyba=1) return 1 a ukonci chybove vytvoreni postavy bezpecne;
		break;
	}

	// OPRAVA TISKU TEXTOVE HODNOTY ZE STRUKT + CHYBA V ZANORENEM CYKLU + PRIDEJ BARVY 
	// 
	// const char* vlastnostToText(enum vlastnost v) {
	//switch (v) {
	//case moudry:
		//return "moudry";
	//case aktivni:
		//return "aktivni";
	//case drzy:
		//return "drzy";
	//default:
		//return "neznamy";
	//}
//}
	// const char* vlastnost_text = vlastnostToText(postava.vlastnost); //predani textu (ukazuje na text)
	// printf(vlastnost_text)
	// NE 
	//char[] vlastnost_text = vlastnostToText(); // protoze vlastnost.moudry da 1
	//char[] vzhled_text = vzhledToText(); // protoze vzhled.plesaty da 1
	// 

	

	printf("Smeju se nahlas! ", vlastnost_text, vzhled_text, jmeno" ? Fakt? \n No dobre, Vas obor si zvolime sami ... \n");

	srand(time(NULL));//predat srand() time bez ulozeni do promenne = NULL
	enum obor rand_obor = (enum obor)(rand() % 3 + 1) //time var %3 dava hodnoty [0,1,2], pricteme +1 = [1,2,3]
													// pretypovani z int na enum obor pro ulozeni	
	postava.obor = obor;

	char[] obor_text = vzhledToText(); // protoze kryptograf.plesaty da 1

	printf("Vas obor je ", obor_text, ", ", jmeno, "! \n");
	printf("Prejeme ti nezapomenutelne dobrodruzstvi, " vlastnost_text, vzhled_text, obor_text, " !\n");


	// DALSI ETAPA

	return 0;
    /*int vek = 1;

	

    while (vek < 10)
    {
         //  vracet iq + spravna/ne?
		vek++;
	}
    otazka(vek);
    otazka(vek);
    // PRCACE
    // if (vek >=10){
    // 	while (vek != 80){


    // 		//neco//
    // 		vek ++;
    // 	}
    // }*/

	







	/*
	* 
	* TEST VERZE 0
	* 
	printf("Empty choices node test " YEL "TXT " WHI "(id: 0)\n");
	printQuestion(story[0]);
	printf("[0]: %p\n", (void *)story[0].choices[0].player_choice);
	printf("[1]: %p\n", (void*)story[0].choices[1].player_choice);
	printf("[2]: %p\n", (void*)story[0].choices[2].player_choice);

	printf("Empty neutral choice test " YEL "YESNO " WHI "(id: 1)\n");
	printQuestion(story[1]);
	printf("[0]: %p\n", (void*)story[1].choices[0].player_choice);
	printf("[1]: %p\n", (void*)story[1].choices[1].player_choice);
	printf("[2]: " RED "%p" WHI "\n", (void*)story[1].choices[2].player_choice);

	printf("3 options question test " YEL "OPT, EXAM " WHI "(id: 2)\n");
	printQuestion(story[2]);
	printf("[0]: %p\n", (void*)story[2].choices[0].player_choice);
	printf("[1]: %p\n", (void*)story[2].choices[1].player_choice);
	printf("[2]: %p\n", (void*)story[2].choices[2].player_choice);

	// NEXT STEP: build real questions and print iq score after some steps;
	// MOVE choice-related structures to the separate file. Move all structures to the separate file. Clear unnecesarry comments.

	*/
}

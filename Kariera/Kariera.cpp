// Kariera.cpp : Defines the entry point for the application.
//

#include "Kariera.h"
#include "Etapa_1.h"

#include <time.h>	// rand()
#include <stdlib.h> // rand()

using namespace std;

int main()
{
	srand(time(NULL));//predat srand() time bez ulozeni do promenne = NULL; seed - time
	vlastnost_postavy();
	vzhled_postavy();
	obor_postavy();

	/*
	// ETAPA JMENA A POSTAVY
	struct postava postava;
	int vlastnost;

	printf("Vitame ve hre kariera! Jak se jmenujete? (Jmeno < 20 pismen) ");
	scanf_s("%19s\n", postava.jmeno, (unsigned)sizeof(postava.jmeno)); //pro pochopeni delky jmena proto, aby
																	// pretypovani, protoze vrati size_t - int data typ urceny pro vyjadrovani velikosti objektu v pameti
	printf("Super, pane %s", postava.jmeno, "! \nPojdme si zvolit vlastnost postavy!\n");
	printf("Jste spise moudry (1), aktivni (2) anebo drzy (3) hrac? -> ");
	scanf_s("%d\n", &vlastnost);

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
		break;
	}


	
	char[] vlastnost_text = vlastnost_to_text(postava.vlastnost); // prevede cislo na vlastnost otextovanim
	char[] vzhled_text = vzhled_to_text(postava.vzhled); // prevede cislo na vlastnost otextovanim
	printf("Smeju se nahlas! ", vlastnost_text, vzhled_text, postava.jmeno" ? Fakt? \n No dobre, Vas obor si zvolime sami ... \n");
	
	
	srand(time(NULL));//predat srand() time bez ulozeni do promenne = NULL; seed - time
	int rand_obor = rand_range(1,3);
	(enum obor)rand_obor;
	postava.obor = rand_obor;

	char[] obor_text = obor_to_text(postava.obor); // prevede cislo na obor otextovanim

	printf("Vas obor je ", obor_text, ", ", postava.jmeno, "! \n");
	printf("Prejeme ti nezapomenutelne dobrodruzstvi, " vlastnost_text, vzhled_text, obor_text, " !\n");


	// DALSI ETAPA
	*/
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

}

#include "Struct.h"
#include "Random.h"
#include "Textove_funkce.h"
#include <cctype> // toUpper()
#include "Colors.h"

struct postava postava;
void vlastnost_postavy() {

	int vlastnost;

	// JMENO + VELKE PISMENO 
	printf("Vitame ve hre adventure! Budete resit nejakou %smatiku%s ! Jak se jmenujete ? (Jmeno < 20 pismen) --> ", RED, WHI);
	scanf_s("%19s", postava.jmeno, (unsigned)(sizeof(postava.jmeno)))	; //pro pochopeni delky jmena proto, aby
	// pretypovani, protoze vrati size_t - int data typ urceny pro vyjadrovani velikosti objektu v pameti
	postava.jmeno[0] = (char)toupper((unsigned char)postava.jmeno[0]);
	printf("Super, pane/pani %s %s %s !\nPojd'me si zvolit %svlastnost%s postavy !\n\n",GR, postava.jmeno, WHI, CYA, WHI);

	// VLASTNOST
	printf("Jste spise moudry (1), aktivni (2) anebo drzy (3) hrac? --> ");
	if (scanf_s("%d", &vlastnost)!=1) {
		printf("%sChyba u naskenovani hodnoty vlastnosti !\n\n%s", RED, WHI);
		return;
	} // kontrola

	switch (vlastnost) {
	case 1:
		postava.vlastnost = moudry;
		printf("Rikate %schytry%s ? Tak to prokazeme behem hry !\n\n", CYA, WHI);
		break;
	case 2:
		postava.vlastnost = aktivni;
		printf("Komu se neleni, tomu se zeleni! %sAktivní%s lidi u nás vítáme.\n\n", YEL, WHI);
		break;
	case 3:
		postava.vlastnost = drzy;
		printf("%sSebevedomi%s mate, ale u odpovedi moc nespehejte !\n\n", ORA, WHI);
		break;
	default:
		printf("%sHra narazila na chybu na etape vyberu vlastnosti postavy. Overte hodnotu a spustte hru znovu.%s\n\n", RED, WHI);
		return;

	}
}

void vzhled_postavy() {

	// VZHLED 
	int uces;
	int vlasy;

	printf("Dale si vybereme rysy atraktivity: \n");
	printf("Mate %svlasy%s ? (1 - Ano, 0 - Ne) --> ", PIN, WHI);

	if (scanf_s("%d", &uces)!=1) {
		printf("%sChyba u naskenovani hodnoty ucesu !\n\n%s", RED, WHI);
		return;
	} // kontrola

	switch (uces) {
	case 0:
		postava.vzhled = plesaty;
		break;
	case 1:
		printf("Jste cernovlasy? (1 - Ano, 0 - Ne) -> ");

		if (scanf_s("%d", &vlasy)!=1) {
			printf("%sChyba u naskenovani hodnoty vlasu !\n\n%s", RED, WHI);
			return;
		} // kontrola

		switch (vlasy) {
		case 0:
			postava.vzhled = blondyn;
			break;
		case 1:
			postava.vzhled = cernovlasy;
			break;
		default:
			printf("%sNeco se nepodarilo u volby vlasu. Zkontrolujte hodnoty a spustte hru znovu.%s\n\n", RED, WHI);
			return;
		}
		break;
	default:
		printf("%sNeco se nepodarilo u volby ucesu. Zkontrolujte hodnoty a spustte hru znovu.%s\n\n", RED, WHI);
		return;
	}
}

void obor_postavy() {

	// VLASTNOST, VZHLED TEXT
	const char* vlastnost_text = vlastnost_to_text(postava.vlastnost); // prevede cislo na vlastnost otextovanim
	const char* vzhled_text = vzhled_to_text(postava.vzhled); // prevede cislo na vlastnost otextovanim

	// SMEJU SE 
	printf("\nSmeju se z Vas! Jste fakt %s%s %s %s%s ? \n"
		"No dobre! Vas obor vsak zvolime %sNAHODNE%s ! \n"
		"... \n... \n... \n",
		GR, vlastnost_text, vzhled_text, postava.jmeno, WHI, CYA, WHI);

	// RAND OBOR, SEED = TIME in main
	int rand_obor = rand_range(1, 3);
	postava.obor = (enum obor)rand_obor;

	// OBOR TEXT
	const char* obor_text = obor_to_text(postava.obor); // prevede cislo na obor otextovanim

	// PREJEME TI NEZAPOMENUTELNE DOBRODRUZSTVI
	printf("\nVas obor je %s %s %s !\n\n", CYA, obor_text, WHI);
	printf("Prejeme ti nezapomenutelne dobrodruzstvi, "
		"%s%s %s, %s %s%s !\n\n",
		GR, vlastnost_text, vzhled_text,
		obor_text, postava.jmeno, WHI);
}

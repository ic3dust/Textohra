#pragma once
#include <stdio.h>

// Ve vysledku nam objevi fajne jmeno jako "krasny moudry trichu nizky a smutny Bob"
enum vlastnost { moudry = 1, aktivni, drzy};
enum vzhled { plesaty = 1, cernovlasy, blondyn};
enum  obor { kryptograf = 1, advokat, podnikatel };
struct postava {
	char jmeno[20];
	enum vlastnost vlastnost;
	enum vzhled vzhled;
	enum obor obor;
};



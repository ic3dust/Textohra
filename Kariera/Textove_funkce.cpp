
#include "Struct.h"
#include "Textove_funkce.h"

const char* vlastnost_to_text(enum vlastnost v) {
	switch (v) {
	case moudry:
		return "moudry";
	case aktivni:
		return "aktivni";
	case drzy:
		return "drzy";
	default:
			return "neznama vlastnost postavy";
	}
}
const char* vzhled_to_text(enum vzhled v) {
	switch (v) {
	case plesaty:
		return "plesaty";
	case cernovlasy:
		return "cernovlasy";
	case blondyn:
		return "blondyn";
	default:
		return "neznamy vzhled postavy";
	}
}
const char* obor_to_text(enum obor o) {
	switch (o) {
	case kryptograf:
		return "kryptograf";
	case advokat:
		return "advokat";
	case podnikatel:
		return "podnikatel";
	default:
		return "neznamy obor postavy";
	}
}
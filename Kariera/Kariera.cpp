// Kariera.cpp : Defines the entry point for the application.
//

#include "Kariera.h"

using namespace std;

#define DEFAULT_IQ 1 // to then use rules like: Hard question answered correctly? Add 1/4 of current iq to iq_score;
					//							Simple question answered incorrectly? -5 from DEFAULT_IQ

// enum - user defined type that only holds ONE feature;
typedef enum {
	TXT, // regular node without questions (0)
	YESNO, // yes/no question node (1 or 0)
	OPT, // "choose option" question node (1, 0 or neutral answer)
	EXAM, // (1, 0 or neutral answer)
	LAST // like TXT, but is declared only once at the end of game for better identification
} NodeType;

typedef enum {
	CORRECT,
	NEUTRAL,
	WRONG
} AnswerType;

typedef struct {
	int input; // Correct, Wrong or Neutral answer. 1 - wrong column; 2 - correct column; 3- reserved column (for third answers);
	int next_id; // next node id based on answer;
} Endpoint;

// struct - user defined type that holds SEVERAL features;
typedef struct {
	const char *player_choice; // what the player typed as an answer
	AnswerType answer_type; // for development simplification (we see wrong, we see correct)
	Endpoint endpoint; // for choice map build when the game is finished;
	const char *choice_reaction; // to simulate dialogue + development simplification  
	int iq_score;
} Choice;
// IMPORTANT NOTE: COPYPASTE. We always explicitly say .player_choice = x; .answer_type = y in choices {}, not just {"his choice text", CORRECT, ...}
// because we can forget to define some feature, which may cause problems in C. I can't just say !important iq_score
// so that it won't run code if we missed this. Example:
// choice = {
	// {"Yes", CORRECT, {2,x} },
	// {"No ", WRONG, {1,x} }
	//					  ^^^
	// Where is char choice_reaction and int iq value? Looking for error for 2 hours.

typedef struct {
	int id;
	NodeType type;
	const char *text; 

	Choice choices[3]; // 3 choices max, so unused slot is '\0' if we have a 2-choice node	
} Node;

Node story[] = {
	{
		.id = 0,
		.type = TXT,
		.text = "Welcome to the game!"
	},
	{
		.id = 1,
		.type = YESNO,
		.text = "Like the game?",
		// Answers: sudá noda = CORRECT; lichá noda = WRONG;
		// YESNO is a binary answer type (correct or incorrect) and OPT,EXAM types have 2+ answers which includes
		// neutral answer. I'd say it's easier to write node answers by hand, NOT by formulas like
		// CORRECT -> sudá -> last answer + 2, because we need to consider neutral answers in future. So 
		// if we will have time we can think about this optimization later.
		.choices = {
			{
				.player_choice = "Yes",
				.answer_type = CORRECT,
				.endpoint = { 2,0 },
				.choice_reaction = "Thanks!",
				.iq_score = DEFAULT_IQ
			},
			{
				.player_choice = "No",
				.answer_type = WRONG,
				.endpoint = { 2,0 },
				.choice_reaction = "We will make game better!",
				.iq_score = DEFAULT_IQ /* kašlu, a ne davám - 5 protože je to úvodní otázka */
			}
		}
	},
	{
		.id = 2,
		.type = OPT,
		.text = "Does Jimmie look good??",
		.choices = {
			{
				.player_choice = "Not really.",
				.answer_type = WRONG,
				.endpoint = { 1,1 },
				.choice_reaction = "\n How dare you >:( \n",
				.iq_score = DEFAULT_IQ - 0 // first questions need to be built the way that lets the player earn some iq
			},
			{
				.player_choice = "Kind of.",
				.answer_type = NEUTRAL,
				.endpoint = { 3,1 },
				.choice_reaction = "\n Thanks! :) \n", // {3, 0} was skipped so to keep connection just use current WRONG/CORRECT id point {3, 1}
				.iq_score = DEFAULT_IQ + 5
			},
			{
				.player_choice = "Absolutely.",
				.answer_type = CORRECT,
				.endpoint = { 2,1 },
				.choice_reaction = "\n Broo man, appreciate that!  \n",
				.iq_score = DEFAULT_IQ + 15
			}
		}
	}
};

void printQuestion(Node node) {
	const char* color =
		(node.type == TXT) ? WHI :
		(node.type == YESNO) ? GR :
		(node.type == OPT || node.type == EXAM) ? CYA :
		WHI;
	printf(" % s % s % s\n", color, node.text, WHI);
}
int main()
{
	printf("Empty choices node test " YEL "TXT " WHI "(id: 0)\n");
	printQuestion(story[0]);
	printf("[0]: %p\n", (void *)story[0].choices[0].player_choice);
	printf("[1]: %p\n", (void*)story[0].choices[1].player_choice);
	printf("[2]: %p\n", (void*)story[0].choices[2].player_choice);

	printf("Empty neutral choice test " YEL "YESNO " WHI "(id: 1)\n");
	printQuestion(story[1]);
	printf("[1]: %p\n", (void*)story[1].choices[1].player_choice);
	printf("[2]: " RED "%p" WHI "\n", (void*)story[1].choices[2].player_choice);

	printf("3 options question test " YEL "OPT, EXAM " WHI "(id: 2)\n");
	printQuestion(story[2]);
	printf("[0]: %p\n", (void*)story[2].choices[0].player_choice);
	printf("[1]: %p\n", (void*)story[2].choices[1].player_choice);
	printf("[2]: %p\n", (void*)story[2].choices[2].player_choice);

	// NEXT STEP: build real questions and print iq score after some steps;
	// MOVE choice-related structures to the separate file. Move all structures to the separate file. Clear unnecesarry comments.

	return 0;
}

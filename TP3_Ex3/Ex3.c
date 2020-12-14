#include <stdint.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define NBMAXNOTES 30

int main() {
	float tableauNotes[NBMAXNOTES];
	float Note = 12;
	int O = 1;
	int i = 0;
	char Reponse;
	int NotesValides = 0;
	int Absence = 0;
	float Min = 20;
	float Max = 0;
	float Sum = 0;
	float Moyenne;
	while ((i < NBMAXNOTES) && (O == 1)) {
		printf("Entrer la note no %d: ", (i + 1));
		scanf_s("%f", &Note);
		i += 1;
		NotesValides += 1;
		if ((Note > 20) || (Note < 0)) {
			printf("\nEleve absent ? ou voulez - vous arreter la saisie des notes ? A / O / N\n");
			Reponse = _getch();
			switch (Reponse) {
			case 'A':
				Absence += 1;
				NotesValides -= 1;
				Note = 0;
				tableauNotes[i] = -1;
				break;
			case 'O':
				printf("\nRessaisissez la note: ");
				scanf_s("%f", &Note);
				tableauNotes[i] = Note;
				if (Note < Min) {
					Min = Note;
				}
				break;
			default:
				i = i - 1;
				NotesValides -= 1;
				O = 0;
				Note = 0;
				break;
			}
		}
		else {
			tableauNotes[i] = Note;
			if (Note < Min) {
				Min = Note;
			}
		}
		Sum += Note;
		if (Note > Max) {
			Max = Note;
		}
	}
	Moyenne = Sum / NotesValides;
	printf("\n Nbr de notes: %d \n Absences: %d\n Moyenne des notes: %f\n Plus haute: %f \n Plus basse: %f\n", NotesValides, Absence, Moyenne, Max, Min);
	for (int e = 0; e < 30; e++) {
		printf("%f     ", tableauNotes[e]);
	}
}
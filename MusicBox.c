/*
Read the duration and pitch of notes from the file into memory.
Then play them using the speaker on the computer.
*/

#include <stdio.h>
#include "Music.h"

#pragma warning(disable : 4996)


int main(void)
{
	Note note_ary[MAX_SONG_SIZE]; // Array of Note structures

	FILE* fPtr = NULL;

	// Open the song file. On error, report and exit.
	if ((fPtr = fopen(SONG_FILE, "r")) == NULL)
	{
		printf("Error in opening the song file %s.\n", SONG_FILE);
		return ERROR_EXIT;
	}

	// Read the notes into the note structure array

	int num_notes = 0;	// number of notes


	// Stay in the loop until all notes are read or the array is full
	while( num_notes < MAX_SONG_SIZE)
	{
		fscanf(fPtr, "%hu %hu", &note_ary[num_notes].frequency, &note_ary[num_notes].duration);    //Unsigned short : %hu
		num_notes++;
		if (feof(fPtr))  // feof: check if the file is ended.
			break;
	}
       


	// When finished with the file, close it
	fclose(fPtr);

	for (int i = 0; i < num_notes; i++)
	{
		if (note_ary[i].frequency != 0)
		{
			note_ary[i].fPlay = Sound;

		}
		else
			note_ary[i].fPlay = Rest;
	}
	// Report it the song file is empty and exit
	

	// Play the song from memory

	for (int i=0 ; i< num_notes;i++,noteptr++)
	{
		note_ary[i].fPlay(note_ary+i);
	}

	printf("Hope you liked the song!..\n");

	return SUCCESS_EXIT;
}

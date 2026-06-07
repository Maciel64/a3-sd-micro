#include "music.h"

// Frequencies: C4=262, D4=294, E4=330, F4=349, G4=392, A4=440, B4=494, C5=523

const int SUCCESS_NOTES[] = {262, 330, 392, 523, 0};
const size_t SUCCESS_NOTES_LEN = sizeof(SUCCESS_NOTES) / sizeof(SUCCESS_NOTES[0]);

const int FAILURE_NOTES[] = {392, 330, 294, 262, 0};
const size_t FAILURE_NOTES_LEN = sizeof(FAILURE_NOTES) / sizeof(FAILURE_NOTES[0]);

//soglia di silenzio 600
//durata abbaio su pin 150ms -200ms -250ms

#include "Arduino.h"
#include <avr/wdt.h>

#include "ram.h"
#include "pin.h"

#define SENSE_VAL  15 //prova
//#define ALL_SECONDI  5

void initializations(void);
void CalibrazioneMic(void);
void AscoltoIdle(void);
void GestioneDeterrente(void);
void gestione_ingressi(void);
void encoder(void);
void gestione_led(void);
void TriggerMicrofoni(void);
void MenuRegolazioni(void);

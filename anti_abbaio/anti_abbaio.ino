#include "header.h"

void setup() {
  initializations();
}


void loop() {

  switch (set_mode) {
    case MODE_ASCOLTO:
      AscoltoIdle();
      break;
    case MODE_TRIGGER:
      TriggerMicrofoni();
      break;
    case MODE_DETERRENTE:
      GestioneDeterrente();
      break;
    case MODE_TEST_MIC:
      CalibrazioneMic();
      break;
    case MODE_REGOLAZIONI:
      MenuRegolazioni();
      break;
  }

        // Serial.print(durata_rumore);
      //  Serial.print(" ");
      // Serial.print(diff_peak_mic_1);
      //  Serial.print(" ");
      // Serial.println(diff_peak_mic_2);
 //     Serial.print(" ");
//    Serial.print(debug1);
//    Serial.print(" ");
//
  // Serial.print(Trigger_mic1);
  // Serial.print(" ");
  // Serial.print(peak_mic_1);
  // Serial.print(" ");
//  Serial.println(mic_1_Level);
//  Serial.print(" ");
//  Serial.print(Trigger_mic2);
 //Serial.print(" ");
  //Serial.println(peak_mic_2);
//  Serial.print(" ");
//  Serial.println(mic_2_Level);

  gestione_led();
  //gestione_ingressi();
  //encoder();

  wdt_reset();  //timeout di 2s per watchdog
}

//-------------------------------------------------------------
//ho superato la soglia e sto aspettando che finisca il rumore
void TriggerMicrofoni(void) {
  
  mic_1_Level = analogRead(mic_1);                                                        // leggo ingresso microfono 1 (A0)
  mic_2_Level = analogRead(mic_2);                                                        // leggo ingresso microfono 1 (A2)

  if (mic_1_Level > peak_mic_1 ){
    peak_mic_1 = mic_1_Level;
    diff_peak_mic_1=peak_mic_1-Trigger_mic1;
  }                                                           //devo misurare il picco
    
  if (mic_2_Level > peak_mic_2 ){
    peak_mic_2 = mic_2_Level;
    diff_peak_mic_2=peak_mic_2-Trigger_mic2;
  }
    
 
  // diff_peak_mic_1=peak_mic_1-Trigger_mic1;
  // diff_peak_mic_2=peak_mic_2-Trigger_mic2;

  if (diff_peak_mic_1 > diff_peak_mic_2)                                                            // controllo quale dei due ha il picco più alto
    microfono_piu_alto = 100;
  if (diff_peak_mic_2 > diff_peak_mic_1)
    microfono_piu_alto = 200;

  if (mic_1_Level < Trigger_mic1 || mic_2_Level < Trigger_mic2)                                                         // quando finisce il rumore con picco più alto
    set_mode = MODE_DETERRENTE;
 

}



//-------------------------------------------------------------

void AscoltoIdle(void)
{

  mic_1_Level = analogRead(mic_1);                                                        // leggo ingresso microfono 1 (A0)
  mic_2_Level = analogRead(mic_2);                                                        // leggo ingresso microfono 1 (A2)

  if (mic_1_Level > Trigger_mic1 || mic_2_Level > Trigger_mic2)             //qua parto se sento un rumore
    set_mode = MODE_TRIGGER;
  /*
    // timer per calibrare ogni 2 minuti
    if (timer_attesa_calib == 0){
    timer_attesa_calib = 20; // 120 secondi
    set_mode = MODE_TEST_MIC;
    }
  */
}
// ------------------------------------------------------------------
// ------------------------------------------------------------------

//-------------------------------------------------------------

void GestioneDeterrente(void)
{
  //debug1++;
  peak_mic_1 = 0;
  peak_mic_2 = 0;
  diff_peak_mic_1 = 0;
  diff_peak_mic_2 = 0;

  if (durata_rumore > T_MIN_RUMORE && durata_rumore < T_MAX_RUMORE)
  { // durata ok
    deterrente_in_azione = true;
    durata_rumore = 0;
  }
  else
  { // se rumore troppo lungo o troppo breve
    deterrente_in_azione = false;
    durata_rumore = 0;
    microfono_piu_alto = 0;
    set_mode = MODE_ASCOLTO;
    
  }

  if (deterrente_in_azione)
  {
    //if ( start_allarme == 0 )
      // start_allarme = ALL_SECONDI;                                                             // 9 secondi

    if (microfono_piu_alto == 100)
    {
      pin_rele_k1_on;
      valore_led = 10;
      delay(7000);
    }
    else if (microfono_piu_alto == 200)
    {
      pin_rele_k2_on;
      valore_led = 20;
      delay(7000);
    }
    // if ( start_allarme == 1 )
    // {
      // durata_rumore = 0;
      pin_rele_k1_off;
      pin_rele_k2_off;
      microfono_piu_alto = 0;
      valore_led = 0;
      deterrente_in_azione = false;
      start_allarme = 0;
      delay(500);
      set_mode = MODE_ASCOLTO;
      
    // }
  }


}//fine funzione
//-------------------------------------------------------------
//-------------------------------------------------------------

void CalibrazioneMic(void)
{
  if (++fase_calib < 100)
  {
    somma_calib_mic1 = somma_calib_mic1 + analogRead(mic_1);
    somma_calib_mic2 = somma_calib_mic2 + analogRead(mic_2);
  }
  else {
    Trigger_mic1 = somma_calib_mic1 / 100;
    somma_calib_mic1 = 0;
    Trigger_mic2 = somma_calib_mic2 / 100;
    somma_calib_mic2 = 0;
    fase_calib = 0;
    Trigger_mic1 = Trigger_mic1 + SENSE_VAL;                                                                       // +sensibilità
    Trigger_mic2 = Trigger_mic2 + SENSE_VAL;                                                                         // +sensibilit

    //Serial.print("livello quiete mic 1  ");
    //Serial.print(Trigger_mic1);
    // Serial.print("livello quiete mic 2  ");
    // Serial.println(Trigger_mic2);

    //delay (1000);
    set_mode = MODE_ASCOLTO;
  }

}



//-------------------------------------------------------------
//----------------------------------------------------

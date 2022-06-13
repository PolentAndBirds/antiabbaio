ISR(TIMER1_COMPA_vect)
{


  // timer 1 ms ------------------------------------------------

  if (set_mode == MODE_TRIGGER)
    durata_rumore++;



  //-----------------------------------------------------------
  if (++clock_10ms > 9) {
    clock_10ms = 0;
    // timer 10 ms --------------------------------------------

    //meglio azzerare i valori di pulsante e encoder
    enc_turn = 0;
    button_state = 0;







    // end timer 10 ms --------------------------------------------
    if (++clock_1s > 99) {
      clock_1s = 0;
      // timer 1s --------------------------------------------

      if (start_allarme > 1)
        start_allarme--;
      if (valore_led)
        valore_led = 0;
      //if (timer_attesa_calib > 1)
      //  timer_attesa_calib--;

      //Serial.print("set_mode "); Serial.println(set_mode);
      //Serial.print("set_mode "); Serial.println(set_mode);

      //   Serial.print("debug1 "); Serial.println(debug1);
      //      Serial.print("debug2 "); Serial.println(debug2);
      //      Serial.print("debug3 "); Serial.println(debug3);
      //      Serial.print("debug4 "); Serial.println(debug4);
      //      Serial.print("debug5 "); Serial.println(debug5);

      //Serial.print("mic_1_Level ");Serial.println(mic_1_Level);
      //Serial.print("debug1 ");Serial.println(debug1);
      //Serial.print("debug1 ");Serial.println(debug1);
      //Serial.print("debug1 ");Serial.println(debug1);




      //end timer 1s --------------------------------------------
    }
    //--------------------------------------------------------
  }


}












//digitalWrite(11, digitalRead(11) ^ 1);

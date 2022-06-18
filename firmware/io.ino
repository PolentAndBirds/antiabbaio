void gestione_ingressi(void)
{

  bool stato_pin_pulsante = digitalRead(2);




}//fine funzione

//-------------------------------------------------------------

void encoder(void)
{

  bool n = digitalRead(3);
  if ((letturaPrecedente == 1) && (n == 0))
  {
    if (digitalRead(4) == 1) {
      valore_enc++;
      if (valore_enc == 2)
      {
        valore_enc = 0;
        // segno piu ---------------
        enc_turn = CW_TURN;
        //Serial.println("piu");
      }
    }
    else
    {
      valore_enc--;
      if (valore_enc == -2)
      {
        valore_enc = 0;
        // segno meno ---------------
        enc_turn = CCW_TURN;
        //Serial.println("meno");
      }
    }
    //Serial.println(valore_enc);
  }
  letturaPrecedente = n;
}//fine funzione
//-------------------------------------------------------------
//-------------------------------------------------------------

void MenuRegolazioni(void)
{
  switch (menu) {
    case MENU_TEST_EVA:

      break;
    case MENU_T_ALARM:

      break;
    case MENU_SENSE:

      break;
  }
}

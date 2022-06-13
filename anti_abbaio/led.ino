void gestione_led(void)
{


  if (set_mode == MODE_TEST_MIC)
  {
     
     
  }
  if(set_mode == MODE_ASCOLTO)
  {
     valore_led = 0;     
  }

  if (valore_led == 0)
  {
    pin_led_0_off;    pin_led_1_off;    pin_led_2_off;    pin_led_3_off;    pin_led_4_off;    pin_led_5_off;    pin_led_6_off;
  }
  if (valore_led == 1)
  {
    pin_led_0_on;    pin_led_1_off;    pin_led_2_off;    pin_led_3_off;    pin_led_4_off;    pin_led_5_off;    pin_led_6_off;
  }
  if (valore_led == 2)
  {
    pin_led_0_on;    pin_led_1_on;    pin_led_2_off;    pin_led_3_off;    pin_led_4_off;    pin_led_5_off;    pin_led_6_off;
  }
  if (valore_led == 3)
  {
    pin_led_0_on;    pin_led_1_on;    pin_led_2_on;    pin_led_3_off;    pin_led_4_off;    pin_led_5_off;    pin_led_6_off;
  }
  if (valore_led == 4)
  {
    pin_led_0_on;    pin_led_1_on;    pin_led_2_on;    pin_led_3_on;    pin_led_4_off;    pin_led_5_off;    pin_led_6_off;
  }
  if (valore_led == 5)
  {
    pin_led_0_on;    pin_led_1_on;    pin_led_2_on;    pin_led_3_on;    pin_led_4_on;    pin_led_5_off;    pin_led_6_off;
  }
  if (valore_led == 6)
  {
    pin_led_0_on;    pin_led_1_on;    pin_led_2_on;    pin_led_3_on;    pin_led_4_on;    pin_led_5_on;    pin_led_6_off;
  }
  if (valore_led == 7)
  {
    pin_led_0_on;    pin_led_1_on;    pin_led_2_on;    pin_led_3_on;    pin_led_4_on;    pin_led_5_on;    pin_led_6_on;
  }
  if (valore_led == 20)
  {
    pin_led_0_on;    pin_led_1_on;    pin_led_2_on;    pin_led_3_off;    pin_led_4_off;    pin_led_5_off;    pin_led_6_off;
  }
  if (valore_led == 10)
  {
    pin_led_0_off;    pin_led_1_off;    pin_led_2_off;    pin_led_3_off;    pin_led_4_on;    pin_led_5_on;    pin_led_6_on;
  }











}

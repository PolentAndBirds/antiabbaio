
void initializations(void)
{

  void setupTimer1(void);
  void initialize_GPIO(void);
  pin_led_1_on;
  Serial.begin(19200);

  wdt_disable();        //disabilita watchdog
  wdt_enable(WDTO_8S);  //abilita watchdog x 2s

 // CalibrazioneMic();
  setupTimer1();
  initialize_GPIO();
  set_mode = MODE_TEST_MIC;
  pin_led_1_off;
}






void initialize_GPIO(void)
{
  init_pin_debug;
  init_pin_led_0;
  init_pin_led_1;
  init_pin_led_2;
  init_pin_led_3;
  init_pin_led_4;
  init_pin_led_5;
  init_pin_led_6;
  init_pin_rele_k1;
  init_pin_rele_k2;
  /*
    //IN pin D2 pulsante pd2
    DDRD &= B00001000;
    //IN pin D3 encoder pd3
    DDRD &= B00001000;
    //IN pin D4 encoder pd4
    DDRD &= B00010000;
  */
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
}



void setupTimer1()
{
  noInterrupts();
  // Clear registers
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;

  // 1000 Hz (16000000/((249+1)*64))
  OCR1A = 249;
  // CTC
  TCCR1B |= (1 << WGM12);
  // Prescaler 64
  TCCR1B |= (1 << CS11) | (1 << CS10);
  // Output Compare Match A Interrupt Enable
  TIMSK1 |= (1 << OCIE1A);
  interrupts();
}

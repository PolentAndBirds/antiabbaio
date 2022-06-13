
//OUT pin D0 pd0 pin debug
#define init_pin_debug    DDRD |= B00000001
#define pin_debug_on      PORTD |= B00000001
#define pin_debug_off     PORTD &= B11111110



//IN pin D2 pulsante pd2

//IN pin D3 encoder pd3

//IN pin D4 encoder pd4

//OUT pin D5 pd5 led0 D3
#define init_pin_led_0    DDRD |= B00100000
#define pin_led_0_on      PORTD |= B00100000
#define pin_led_0_off     PORTD &= B11011111

//OUT pin D6 pd6 led1 D4
#define init_pin_led_1    DDRD |= B01000000
#define pin_led_1_on      PORTD |= B01000000
#define pin_led_1_off     PORTD &= B10111111

//OUT pin D7 pd7 led2 D5
#define init_pin_led_2    DDRD |= B10000000
#define pin_led_2_on      PORTD |= B10000000
#define pin_led_2_off     PORTD &= B01111111

//OUT pin D8 pb0 led3 D6
#define init_pin_led_3    DDRB |= B00000001
#define pin_led_3_on      PORTB |= B00000001
#define pin_led_3_off     PORTB &= B11111110

//OUT pin D9 pb1 led4 D7
#define init_pin_led_4   DDRB |= B00000010
#define pin_led_4_on      PORTB |= B00000010
#define pin_led_4_off     PORTB &= B11111101

//OUT pin D10 pb2 led5 D8
#define init_pin_led_5    DDRB |= B00000100
#define pin_led_5_on      PORTB |= B00000100
#define pin_led_5_off     PORTB &= B11111011

//OUT pin D11 pb3 led6 D9
#define init_pin_led_6    DDRB |= B00001000
#define pin_led_6_on      PORTB |= B00001000
#define pin_led_6_off     PORTB &= B11110111

//OUT pin D1 pb4 rele K2
#define init_pin_rele_k2    DDRB |= B00010000
#define pin_rele_k2_on      PORTB |= B00010000
#define pin_rele_k2_off     PORTB &= B11101111

//OUT pin D13 pb5 rele K1
#define init_pin_rele_k1    DDRB |= B00100000
#define pin_rele_k1_on      PORTB |= B00100000
#define pin_rele_k1_off     PORTB &= B11011111

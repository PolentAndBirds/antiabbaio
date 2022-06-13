

#define T_MIN_RUMORE   100 //100
#define T_MAX_RUMORE   300

// Microphone input
#define mic_1  A0
#define mic_2  A2


// Voltage on pin that determines a bark
unsigned long Trigger_mic1;
unsigned long Trigger_mic2;

bool deterrente_in_azione;

unsigned long start_allarme;
int16_t mic_1_Level;
int16_t mic_2_Level;
int16_t peak_mic_1;
int16_t peak_mic_2;
int16_t diff_peak_mic_1;
int16_t diff_peak_mic_2;

uint8_t microfono_piu_alto;

uint16_t debug1;
uint16_t debug2;
uint16_t debug3;
uint16_t debug4;
uint16_t debug5;
uint16_t debug6;

unsigned long somma_calib_mic1;
unsigned long somma_calib_mic2;

//per encoder
int8_t valore_enc = 0;
bool letturaPrecedente = 1;

uint8_t enc_turn;
#define NO_TURN     0
#define CW_TURN     1
#define CCW_TURN    2

//per led
uint8_t valore_led;

//pulsante
#define SHORT_PRESS_TIME  500
#define LONG_PRESS_TIME  2000

uint8_t button_state;
#define OFF_BUTTON    0
#define ON_BUTTON     1
#define LONG_BUTTON   2

uint8_t set_mode, set_mode_precedente;
#define MODE_ASCOLTO        0
#define MODE_TRIGGER        1
#define MODE_DETERRENTE     2
#define MODE_TEST_MIC       3
#define MODE_REGOLAZIONI    4


//timers
uint8_t clock_10ms, clock_1s;
uint8_t fase_calib;
int16_t durata_rumore;
uint8_t timer_attesa_calib;

//MENU
uint8_t    menu;
#define MENU_TEST_EVA  0
#define MENU_T_ALARM   1
#define MENU_SENSE     2

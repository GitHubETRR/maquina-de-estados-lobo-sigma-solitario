#define BUTTON_PIN 2
#define OUTPUT_LED_PIN 3
#define PRESS_LED_PIN 4
#define RELEASE_LED_PIN 5

#define BUTTON digitalRead(BUTTON_PIN)
#define OUT_LED digitalWrite(OUTPUT_LED_PIN, out_led_var)
#define PR_LED digitalWrite(PRESS_LED_PIN, press_led_var)
#define RE_LED digitalWrite(RELEASE_LED_PIN, release_led_var)


typedef enum{
BUTTON_UP,
BUTTON_FALLING,
BUTTON_DOWN,
BUTTON_RAISING,
} debounceState_t;

debounceState_t current_state;


debounceState_t debounceFSM_init(){
    current_state = BUTTON_UP;
}		// debe cargar el estado inicial


void setup(){
    pinMode(BUTTON_PIN, INPUT);
    pinMode(OUTPUT_LED_PIN, OUTPUT);
    pinMode(PRESS_LED_PIN, OUTPUT);
    pinMode(RELEASE_LED_PIN, OUTPUT);
    debounceFSM_init();
}


void loop(){
    switch (current_state){
        case BUTTON_UP{
            if(BUTTON)
        }
    }

}



void debounceFSM_update();	// debe leer las entradas, resolver la lógica de
					// transición de estados y actualizar las salidas
void buttonPressed();			// debe invertir el estado del LED1
void buttonReleased();		// debe invertir el estado del LED2 







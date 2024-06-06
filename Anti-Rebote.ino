#define DELAY 40

#define BUTTON_PIN 2
#define PRESS_LED_PIN 3
#define RELEASE_LED_PIN 4

#define BUTTON digitalRead(BUTTON_PIN)


typedef enum{
    BUTTON_UP,
    BUTTON_FALLING,
    BUTTON_DOWN,
    BUTTON_RAISING,
} debounceState_t;
debounceState_t current_state;


debounceState_t debounceFSM_init(){
    current_state = BUTTON_UP;
}


void buttonReleased(){
    char state = digitalRead(RELEASE_LED_PIN);
    digitalWrite(RELEASE_LED_PIN, !state);
}


void buttonPressed(){
    char state = digitalRead(PRESS_LED_PIN);
    digitalWrite(PRESS_LED_PIN, !state);
}


void debounceFSM_update(){
    switch (current_state){
        case BUTTON_UP:
            if (BUTTON){
                current_state = BUTTON_FALLING;
                time = millis();
            }

        case BUTTON_FALLING:
            if (BUTTON){
                if (time + DELAY >= millis()){
                    current_state = BUTTON_DOWN;
                    buttonPressed();
                }
            }
            else current_state = BUTTON_UP;

        case BUTTON_DOWN:
            if (!BUTTON){
                current_state = BUTTON_RAISING;
                time = millis();
            }
        
        case BUTTON_RAISING:
            if (!BUTTON){
                if (time + DELAY >= millis()){
                    current_state = BUTTON_UP;
                    buttonReleased;
                }
            }
            else current_state = BUTTON_DOWN;
    }
}


void setup(){
    pinMode(BUTTON_PIN, INPUT);
    pinMode(PRESS_LED_PIN, OUTPUT);
    pinMode(RELEASE_LED_PIN, OUTPUT);
    debounceFSM_init();
    static unsigned long time = 0;
}


void loop(){
    debounceFSM_update();
}

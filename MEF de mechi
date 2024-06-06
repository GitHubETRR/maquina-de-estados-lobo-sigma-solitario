#define LED1 3
#define LED2 8
#define BUTTON 2
#define DELAY 40

typedef enum{
  BUTTON_UP,
  BUTTON_FALLING,
  BUTTON_DOWN,
  BUTTON_RAISING,
} debounceState_t;

void debounceFSM_init(void);		// debe cargar el estado inicial
void debounceFSM_update(void);	// debe leer las entradas, resolver la lógica de
// transición de estados y actualizar las salidas
void buttonPressed();			// debe invertir el estado del LED1
void buttonReleased();		// debe invertir el estado del LED2 

debounceState_t estadoActual;
unsigned long int TIME;

void setup() {
  debounceFSM_init();
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  debounceFSM_update();

}

void debounceFSM_init(void){
  estadoActual=BUTTON_UP;
}

void debounceFSM_update(void){
  switch (estadoActual){
    case BUTTON_UP: 
      
      if(digitalRead(BUTTON)==HIGH){
        TIME=millis();
        estadoActual=BUTTON_FALLING;
      }
      break;

    case BUTTON_FALLING:
      
      if(digitalRead(BUTTON)==HIGH){
        if(millis()>=TIME+DELAY){
          buttonPressed();
          estadoActual=BUTTON_DOWN;
        }
      }else{
        estadoActual=BUTTON_UP;
      }
      break;

    case BUTTON_DOWN:

      if(digitalRead(BUTTON)==LOW){
        TIME=millis();
        estadoActual=BUTTON_RAISING;
      }

      break;

    case BUTTON_RAISING:

      if(digitalRead(BUTTON)==LOW){
        if(millis()>=TIME+DELAY){
          buttonReleased();
          estadoActual=BUTTON_UP;
        }      
      }else{
        estadoActual=BUTTON_DOWN;
      }
      break;
  }
}

void buttonPressed(){
  digitalWrite(LED1, !digitalRead(LED1));
}

void buttonReleased(){
  digitalWrite(LED2, !digitalRead(LED2));
}

#define NOTE_C4  262 // DO
#define NOTE_D4  294 // RE
#define NOTE_E4  330 // MI
#define NOTE_F4  349 // FA
#define NOTE_G4  392 // SOL
#define NOTE_A4  440 // LA
#define NOTE_B4  494 // SI

int modificatoreOttava = 1; // Moltiplicatore utilizzato per alzare o abbassare l'ottava riprodotta
const int Speaker = 10; // Il pin dove andrà il buzzer o lo speaker
int Melodia[] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4};
int Tasto[] = {2, 3, 4, 5, 6, 7, 8}; // I pin dove andranno collegati i 7 pulsanti
int val_Tasto[7]; // Array per la memorizzazione dei valori dei pulsanti



void setup(){
  for(int i=0; i<7; i++){
    pinMode(Tasto[i], INPUT);} // Setta i pulsanti come input
}
 
void loop(){
    
  for(int pin=0; pin<7; pin++){ 
     val_Tasto[pin]=digitalRead(Tasto[pin]);} // Legge lo stato dei pulsanti e li memorizza nell'array val_Tasto[]
      
     modificatoreOttava = map(analogRead(A0),500,1023,1,5); // Assegazione del valore del modificatore in base al potenziometro (5 ottave possibili)
    
    // Se un pulsante è alto, lo speaker, riprodurrà la corrispondente nota musicale  
    if(val_Tasto[0] == HIGH) tone(Speaker, Melodia[0] * modificatoreOttava, 100); // C4 (DO)
    if(val_Tasto[1] == HIGH) tone(Speaker, Melodia[1] * modificatoreOttava, 100); // D4 (RE)
    if(val_Tasto[2] == HIGH) tone(Speaker, Melodia[2] * modificatoreOttava, 100); // E4 (MI)
    if(val_Tasto[3] == HIGH) tone(Speaker, Melodia[3] * modificatoreOttava, 100); // F4 (FA)
    if(val_Tasto[4] == HIGH) tone(Speaker, Melodia[4] * modificatoreOttava, 100); // G4 (SOL)
    if(val_Tasto[5] == HIGH) tone(Speaker, Melodia[5] * modificatoreOttava, 100); // A4 (LA)
    if(val_Tasto[6] == HIGH) tone(Speaker, Melodia[6] * modificatoreOttava, 100); // B4 (SI)
}
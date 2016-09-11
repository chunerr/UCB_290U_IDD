

#if defined(ARDUINO) 
SYSTEM_MODE(MANUAL); 
#endif

//State Counter
int state = 1;

//Button Pins
const int AbuttonPin = D3;
const int BbuttonPin = D4;
const int CbuttonPin = D5;
const int DbuttonPin = D6;
const int EbuttonPin = D7;
const int FbuttonPin = D8;
const int GbuttonPin = D9;
const int SpacebuttonPin = D1;
const int EnterbuttonPin = D2;
const int ChangePin = D0;

//Led Pins
const int led1 = D10;
const int led2 = D11;
const int led3 = D12;
const int led4 = D13;

// Variables will change:

int AbuttonState;
int BbuttonState;
int CbuttonState;
int DbuttonState;
int EbuttonState;
int FbuttonState;
int GbuttonState;
int SpacebuttonState;
int EnterbuttonState;
int ChangebuttonState;

int led1State = HIGH;
int led2State = LOW;
int led3State = LOW;
int led4State = LOW;
  
int AlastButtonState = LOW;
int BlastButtonState = LOW; 
int ClastButtonState = LOW; 
int DlastButtonState = LOW; 
int ElastButtonState = LOW; 
int FlastButtonState = LOW; 
int GlastButtonState = LOW; 
int SpacelastButtonState = LOW; 
int EnterlastButtonState = LOW;    
int ChangelastButtonState = LOW;

long AlastDebounceTime = 0;
long BlastDebounceTime = 0;
long ClastDebounceTime = 0;
long DlastDebounceTime = 0;
long ElastDebounceTime = 0;
long FlastDebounceTime = 0;
long GlastDebounceTime = 0;
long SpacelastDebounceTime = 0;
long EnterlastDebounceTime = 0;
long ChangelastDebounceTime = 0;// the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(AbuttonPin, INPUT_PULLDOWN);
  pinMode(BbuttonPin, INPUT_PULLDOWN);
  pinMode(CbuttonPin, INPUT_PULLDOWN);
  pinMode(DbuttonPin, INPUT_PULLDOWN);
  pinMode(EbuttonPin, INPUT_PULLDOWN);
  pinMode(FbuttonPin, INPUT_PULLDOWN);
  pinMode(GbuttonPin, INPUT_PULLDOWN);
  pinMode(SpacebuttonPin, INPUT_PULLDOWN);
  pinMode(EnterbuttonPin, INPUT_PULLDOWN);
  pinMode(ChangePin, INPUT_PULLDOWN);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  if (state == 1){
    //Reading
  int a = digitalRead(AbuttonPin);
  int b = digitalRead(BbuttonPin);
  int c = digitalRead(CbuttonPin);
  int d = digitalRead(DbuttonPin);
  int e = digitalRead(EbuttonPin);
  int f = digitalRead(FbuttonPin);
  int g = digitalRead(GbuttonPin);
  int Space = digitalRead(SpacebuttonPin);
  int Enter = digitalRead(EnterbuttonPin);
  int Change = digitalRead(ChangePin);

  //DebounceTime Update
  if (a != AlastButtonState) {
    AlastDebounceTime = millis();
  }
  if (b != BlastButtonState) {
    BlastDebounceTime = millis();
  }
  if (c != ClastButtonState) {
    ClastDebounceTime = millis();
  }
  if (d != DlastButtonState) {
    DlastDebounceTime = millis();
  }
  if (e != ElastButtonState) {
    ElastDebounceTime = millis();
  }
  if (f != FlastButtonState) {
    FlastDebounceTime = millis();
  }
  if (g != GlastButtonState) {
    GlastDebounceTime = millis();
  }
  if (Space != SpacelastButtonState) {
    SpacelastDebounceTime = millis();
  }
  if (Enter != EnterlastButtonState) {
    EnterlastDebounceTime = millis();
  }
  if (Change != ChangelastButtonState) {
    ChangelastDebounceTime = millis();
  }

  //Execution
  if ((millis() - AlastDebounceTime) > debounceDelay) {
    if (a != AbuttonState) {
      AbuttonState = a;

      if (AbuttonState == HIGH) {
        Serial.print("a");
      }
    }
  }
    if ((millis() - BlastDebounceTime) > debounceDelay) {
    if (b != BbuttonState) {
      BbuttonState = b;

      if (BbuttonState == HIGH) {
        Serial.print("b");
      }
    }
  }
    if ((millis() - ClastDebounceTime) > debounceDelay) {
    if (c != CbuttonState) {
      CbuttonState = c;

      if (CbuttonState == HIGH) {
        Serial.print("c");
      }
    }
  }
    if ((millis() - DlastDebounceTime) > debounceDelay) {
    if (d != DbuttonState) {
      DbuttonState = d;

      if (DbuttonState == HIGH) {
        Serial.print("d");
      }
    }
  }
    if ((millis() - ElastDebounceTime) > debounceDelay) {
    if (e != EbuttonState) {
      EbuttonState = e;

      if (EbuttonState == HIGH) {
        Serial.print("e");
      }
    }
  }
    if ((millis() - FlastDebounceTime) > debounceDelay) {
    if (f != FbuttonState) {
      FbuttonState = f;

      if (FbuttonState == HIGH) {
        Serial.print("f");
      }
    }
  }
  if ((millis() - GlastDebounceTime) > debounceDelay) {
    if (g != GbuttonState) {
      GbuttonState = g;

      if (GbuttonState == HIGH) {
        Serial.print("g");
      }
    }
  }
  if ((millis() - SpacelastDebounceTime) > debounceDelay) {
    if (Space != SpacebuttonState) {
      SpacebuttonState = Space;

      if (SpacebuttonState == HIGH) {
        Serial.print(" ");
      }
    }
  }
  if ((millis() - EnterlastDebounceTime) > debounceDelay) {
    if (Enter != EnterbuttonState) {
      EnterbuttonState = Enter;

      if (EnterbuttonState == HIGH) {
        Serial.println();
      }
    }
  }
  if ((millis() - ChangelastDebounceTime) > debounceDelay) {
    if (Change != ChangebuttonState) {
      ChangebuttonState = Change;

      if (ChangebuttonState == HIGH) {
        state = 2;
        led1State = !led1State;
        led2State = !led2State;
      }
    }
  }

  digitalWrite(led1,led1State);
  digitalWrite(led2,led2State);
  digitalWrite(led3,led3State);
  digitalWrite(led4,led4State);

  AlastButtonState = a;
  BlastButtonState = b;  
  ClastButtonState = c;  
  DlastButtonState = d;  
  ElastButtonState = e;  
  FlastButtonState = f;  
  GlastButtonState = g;  
  SpacelastButtonState = Space;  
  EnterlastButtonState = Enter;    
  ChangelastButtonState = Change;  
  //Serial.println("State 1");
  }

  if (state ==2){
    //Reading
  int a = digitalRead(AbuttonPin);
  int b = digitalRead(BbuttonPin);
  int c = digitalRead(CbuttonPin);
  int d = digitalRead(DbuttonPin);
  int e = digitalRead(EbuttonPin);
  int f = digitalRead(FbuttonPin);
  int g = digitalRead(GbuttonPin);
  int Space = digitalRead(SpacebuttonPin);
  int Enter = digitalRead(EnterbuttonPin);
  int Change = digitalRead(ChangePin);

  //DebounceTime Update
  if (a != AlastButtonState) {
    AlastDebounceTime = millis();
  }
  if (b != BlastButtonState) {
    BlastDebounceTime = millis();
  }
  if (c != ClastButtonState) {
    ClastDebounceTime = millis();
  }
  if (d != DlastButtonState) {
    DlastDebounceTime = millis();
  }
  if (e != ElastButtonState) {
    ElastDebounceTime = millis();
  }
  if (f != FlastButtonState) {
    FlastDebounceTime = millis();
  }
  if (g != GlastButtonState) {
    GlastDebounceTime = millis();
  }
  if (Space != SpacelastButtonState) {
    SpacelastDebounceTime = millis();
  }
  if (Enter != EnterlastButtonState) {
    EnterlastDebounceTime = millis();
  }
  if (Change != ChangelastButtonState) {
    ChangelastDebounceTime = millis();
  }

  //Execution
  if ((millis() - AlastDebounceTime) > debounceDelay) {
    if (a != AbuttonState) {
      AbuttonState = a;

      if (AbuttonState == HIGH) {
        Serial.print("h");
        state = 1;
        led1State = !led1State;
        led2State = !led2State;
      }
    }
  }
    if ((millis() - BlastDebounceTime) > debounceDelay) {
    if (b != BbuttonState) {
      BbuttonState = b;

      if (BbuttonState == HIGH) {
        Serial.print("i");
        state = 1;
        led1State = !led1State;
        led2State = !led2State;
      }
    }
  }
    if ((millis() - ClastDebounceTime) > debounceDelay) {
    if (c != CbuttonState) {
      CbuttonState = c;

      if (CbuttonState == HIGH) {
        Serial.print("j");
        state = 1;
        led1State = !led1State;
        led2State = !led2State;
      }
    }
  }
    if ((millis() - DlastDebounceTime) > debounceDelay) {
    if (d != DbuttonState) {
      DbuttonState = d;

      if (DbuttonState == HIGH) {
        Serial.print("k");
        state = 1;
        led1State = !led1State;
        led2State = !led2State;
      }
    }
  }
    if ((millis() - ElastDebounceTime) > debounceDelay) {
    if (e != EbuttonState) {
      EbuttonState = e;

      if (EbuttonState == HIGH) {
        Serial.print("l");
        state = 1;
        led1State = !led1State;
        led2State = !led2State;
      }
    }
  }
    if ((millis() - FlastDebounceTime) > debounceDelay) {
    if (f != FbuttonState) {
      FbuttonState = f;

      if (FbuttonState == HIGH) {
        Serial.print("m");
        state = 1;
        led1State = !led1State;
        led2State = !led2State;
      }
    }
  }
  if ((millis() - GlastDebounceTime) > debounceDelay) {
    if (g != GbuttonState) {
      GbuttonState = g;

      if (GbuttonState == HIGH) {
        Serial.print("n");
        state = 1;
        led1State = !led1State;
        led2State = !led2State;
      }
    }
  }
  if ((millis() - SpacelastDebounceTime) > debounceDelay) {
    if (Space != SpacebuttonState) {
      SpacebuttonState = Space;

      if (SpacebuttonState == HIGH) {
        Serial.print(" ");
        led1State = !led1State;
        led2State = !led2State;
      }
    }
  }
  if ((millis() - EnterlastDebounceTime) > debounceDelay) {
    if (Enter != EnterbuttonState) {
      EnterbuttonState = Enter;

      if (EnterbuttonState == HIGH) {
        Serial.println();
        led1State = !led1State;
        led2State = !led2State;
      }
    }
  }
  if ((millis() - ChangelastDebounceTime) > debounceDelay) {
    if (Change != ChangebuttonState) {
      ChangebuttonState = Change;

      if (ChangebuttonState == HIGH) {
        state = 3;
        led2State =!led2State;
        led3State =!led3State;
      }
    }
  }

  digitalWrite(led1,led1State);
  digitalWrite(led2,led2State);
  digitalWrite(led3,led3State);
  digitalWrite(led4,led4State);

  AlastButtonState = a;
  BlastButtonState = b;  
  ClastButtonState = c;  
  DlastButtonState = d;  
  ElastButtonState = e;  
  FlastButtonState = f;  
  GlastButtonState = g;  
  SpacelastButtonState = Space;  
  EnterlastButtonState = Enter;    
  ChangelastButtonState = Change;  
  //Serial.println("State 2");
}
if (state ==3){
    //Reading
  int a = digitalRead(AbuttonPin);
  int b = digitalRead(BbuttonPin);
  int c = digitalRead(CbuttonPin);
  int d = digitalRead(DbuttonPin);
  int e = digitalRead(EbuttonPin);
  int f = digitalRead(FbuttonPin);
  int g = digitalRead(GbuttonPin);
  int Space = digitalRead(SpacebuttonPin);
  int Enter = digitalRead(EnterbuttonPin);
  int Change = digitalRead(ChangePin);

  //DebounceTime Update
  if (a != AlastButtonState) {
    AlastDebounceTime = millis();
  }
  if (b != BlastButtonState) {
    BlastDebounceTime = millis();
  }
  if (c != ClastButtonState) {
    ClastDebounceTime = millis();
  }
  if (d != DlastButtonState) {
    DlastDebounceTime = millis();
  }
  if (e != ElastButtonState) {
    ElastDebounceTime = millis();
  }
  if (f != FlastButtonState) {
    FlastDebounceTime = millis();
  }
  if (g != GlastButtonState) {
    GlastDebounceTime = millis();
  }
  if (Space != SpacelastButtonState) {
    SpacelastDebounceTime = millis();
  }
  if (Enter != EnterlastButtonState) {
    EnterlastDebounceTime = millis();
  }
  if (Change != ChangelastButtonState) {
    ChangelastDebounceTime = millis();
  }

  //Execution
  if ((millis() - AlastDebounceTime) > debounceDelay) {
    if (a != AbuttonState) {
      AbuttonState = a;

      if (AbuttonState == HIGH) {
        Serial.print("o");
        state = 1;
        led1State = !led1State;
        led3State = !led3State;
      }
    }
  }
    if ((millis() - BlastDebounceTime) > debounceDelay) {
    if (b != BbuttonState) {
      BbuttonState = b;

      if (BbuttonState == HIGH) {
        Serial.print("p");
        state = 1;
        led1State = !led1State;
        led3State = !led3State;
      }
    }
  }
    if ((millis() - ClastDebounceTime) > debounceDelay) {
    if (c != CbuttonState) {
      CbuttonState = c;

      if (CbuttonState == HIGH) {
        Serial.print("q");
        state = 1;
        led1State = !led1State;
        led3State = !led3State;
      }
    }
  }
    if ((millis() - DlastDebounceTime) > debounceDelay) {
    if (d != DbuttonState) {
      DbuttonState = d;

      if (DbuttonState == HIGH) {
        Serial.print("r");
        state = 1;
        led1State = !led1State;
        led3State = !led3State;
      }
    }
  }
    if ((millis() - ElastDebounceTime) > debounceDelay) {
    if (e != EbuttonState) {
      EbuttonState = e;

      if (EbuttonState == HIGH) {
        Serial.print("s");
        state = 1;
        led1State = !led1State;
        led3State = !led3State;
      }
    }
  }
    if ((millis() - FlastDebounceTime) > debounceDelay) {
    if (f != FbuttonState) {
      FbuttonState = f;

      if (FbuttonState == HIGH) {
        Serial.print("t");
        state = 1;
        led1State = !led1State;
        led3State = !led3State;
      }
    }
  }
  if ((millis() - GlastDebounceTime) > debounceDelay) {
    if (g != GbuttonState) {
      GbuttonState = g;

      if (GbuttonState == HIGH) {
        Serial.print("u");
        state = 1;
        led1State = !led1State;
        led3State = !led3State;
      }
    }
  }
  if ((millis() - SpacelastDebounceTime) > debounceDelay) {
    if (Space != SpacebuttonState) {
      SpacebuttonState = Space;

      if (SpacebuttonState == HIGH) {
        Serial.print(" ");
        led1State = !led1State;
        led3State = !led3State;
      }
    }
  }
  if ((millis() - EnterlastDebounceTime) > debounceDelay) {
    if (Enter != EnterbuttonState) {
      EnterbuttonState = Enter;

      if (EnterbuttonState == HIGH) {
        Serial.println();
      }
    }
  }
  if ((millis() - ChangelastDebounceTime) > debounceDelay) {
    if (Change != ChangebuttonState) {
      ChangebuttonState = Change;

      if (ChangebuttonState == HIGH) {
        state = 4;
        led3State = !led3State;
        led4State = !led4State;
      }
    }
  }
  
  digitalWrite(led1,led1State);
  digitalWrite(led2,led2State);
  digitalWrite(led3,led3State);
  digitalWrite(led4,led4State);

  AlastButtonState = a;
  BlastButtonState = b;  
  ClastButtonState = c;  
  DlastButtonState = d;  
  ElastButtonState = e;  
  FlastButtonState = f;  
  GlastButtonState = g;  
  SpacelastButtonState = Space;  
  EnterlastButtonState = Enter;    
  ChangelastButtonState = Change; 
  //Serial.println("State 3"); 
}
if (state ==4){
    //Reading
  int a = digitalRead(AbuttonPin);
  int b = digitalRead(BbuttonPin);
  int c = digitalRead(CbuttonPin);
  int d = digitalRead(DbuttonPin);
  int e = digitalRead(EbuttonPin);
  int f = digitalRead(FbuttonPin);
  int g = digitalRead(GbuttonPin);
  int Space = digitalRead(SpacebuttonPin);
  int Enter = digitalRead(EnterbuttonPin);
  int Change = digitalRead(ChangePin);

  //DebounceTime Update
  if (a != AlastButtonState) {
    AlastDebounceTime = millis();
  }
  if (b != BlastButtonState) {
    BlastDebounceTime = millis();
  }
  if (c != ClastButtonState) {
    ClastDebounceTime = millis();
  }
  if (d != DlastButtonState) {
    DlastDebounceTime = millis();
  }
  if (e != ElastButtonState) {
    ElastDebounceTime = millis();
  }
  if (f != FlastButtonState) {
    FlastDebounceTime = millis();
  }
  if (g != GlastButtonState) {
    GlastDebounceTime = millis();
  }
  if (Space != SpacelastButtonState) {
    SpacelastDebounceTime = millis();
  }
  if (Enter != EnterlastButtonState) {
    EnterlastDebounceTime = millis();
  }
  if (Change != ChangelastButtonState) {
    ChangelastDebounceTime = millis();
  }

  //Execution
  if ((millis() - AlastDebounceTime) > debounceDelay) {
    if (a != AbuttonState) {
      AbuttonState = a;

      if (AbuttonState == HIGH) {
        Serial.print("v");
        state = 1;
        led1State = !led1State;
        led4State = !led4State;
      }
    }
  }
    if ((millis() - BlastDebounceTime) > debounceDelay) {
    if (b != BbuttonState) {
      BbuttonState = b;

      if (BbuttonState == HIGH) {
        Serial.print("w");
        state = 1;
        led1State = !led1State;
        led4State = !led4State;
      }
    }
  }
    if ((millis() - ClastDebounceTime) > debounceDelay) {
    if (c != CbuttonState) {
      CbuttonState = c;

      if (CbuttonState == HIGH) {
        Serial.print("x");
        state = 1;
        led1State = !led1State;
        led4State = !led4State;
      }
    }
  }
    if ((millis() - DlastDebounceTime) > debounceDelay) {
    if (d != DbuttonState) {
      DbuttonState = d;

      if (DbuttonState == HIGH) {
        Serial.print("y");
        state = 1;
        led1State = !led1State;
        led4State = !led4State;
      }
    }
  }
    if ((millis() - ElastDebounceTime) > debounceDelay) {
    if (e != EbuttonState) {
      EbuttonState = e;

      if (EbuttonState == HIGH) {
        Serial.print("z");
        state = 1;
        led1State = !led1State;
        led4State = !led4State;
      }
    }
  }
    if ((millis() - FlastDebounceTime) > debounceDelay) {
    if (f != FbuttonState) {
      FbuttonState = f;

      if (FbuttonState == HIGH) {
      }
    }
  }
  if ((millis() - GlastDebounceTime) > debounceDelay) {
    if (g != GbuttonState) {
      GbuttonState = g;

      if (GbuttonState == HIGH) {
      }
    }
  }
  if ((millis() - SpacelastDebounceTime) > debounceDelay) {
    if (Space != SpacebuttonState) {
      SpacebuttonState = Space;

      if (SpacebuttonState == HIGH) {
        Serial.print(" ");
        state = 1;
        led1State = !led1State;
        led4State = !led4State;
      }
    }
  }
  if ((millis() - EnterlastDebounceTime) > debounceDelay) {
    if (Enter != EnterbuttonState) {
      EnterbuttonState = Enter;

      if (EnterbuttonState == HIGH) {
        Serial.println();
        state = 1;
        led1State = !led1State;
        led4State = !led4State;
      }
    }
  }
  if ((millis() - ChangelastDebounceTime) > debounceDelay) {
    if (Change != ChangebuttonState) {
      ChangebuttonState = Change;

      if (ChangebuttonState == HIGH) {
        state = 1;
        led4State =!led4State;
        led1State =!led1State;
        
      }
    }
  }

  digitalWrite(led1,led1State);
  digitalWrite(led2,led2State);
  digitalWrite(led3,led3State);
  digitalWrite(led4,led4State);

  AlastButtonState = a;
  BlastButtonState = b;  
  ClastButtonState = c;  
  DlastButtonState = d;  
  ElastButtonState = e;  
  FlastButtonState = f;  
  GlastButtonState = g;  
  SpacelastButtonState = Space;  
  EnterlastButtonState = Enter;    
  ChangelastButtonState = Change;  
  //Serial.println("State 4");
}

}





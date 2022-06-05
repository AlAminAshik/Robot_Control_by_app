
#define ENA 10  //Define Arduino_PWM_PIN-10 as ENA

#define IN1 9  //Define Arduino_PIN-9 as IN1
#define IN2 8  //Define Arduino_PIN-8 as IN2 
#define IN3 7  //Define Arduino_PIN-7 as IN3 
#define IN4 6  //Define Arduino_PIN-6 as IN4 

#define ENB 5  //Define Arduino_PWM_PIN-5 as ENB

#define SPK A2

#define Middle_Light A0  

#define Sensor A1  

float Robot_Speed = 255.00;

void setup()
{
  
  Serial.begin(9600);   // Start serial monitor for Serial Communication 
  
  pinMode(IN1,OUTPUT); //IN1 Pin set for MotorA Output-1.
  pinMode(IN2,OUTPUT); //IN2 Pin set for MotorA Output-2.
  
  pinMode(ENA,OUTPUT); //ENA Pin set for PWM of MotorA Output.
  
  pinMode(IN3,OUTPUT); //IN3 Pin set for MotorB Output-3.
  pinMode(IN4,OUTPUT); //IN4 Pin set for MotorB Output-4.
  
  pinMode(ENB,OUTPUT); //ENB Pin set for PWM of MotorB Output.

  pinMode(SPK,OUTPUT);
  
  pinMode(Sensor, OUTPUT); 
  pinMode(Middle_Light, OUTPUT); 
  
  Robot_Speed = 255.00;
  Serial.println(Robot_Speed);

  
}


 
void forward()
{
     digitalWrite(IN1,HIGH);  //turn DC Motor A move clockwise
     digitalWrite(IN2,LOW);   
     digitalWrite(IN3,HIGH);  //turn DC Motor B move clockwise
     digitalWrite(IN4,LOW);   
}


void backward() 
{
     digitalWrite(IN1,LOW);   
     digitalWrite(IN2,HIGH);  //turn DC Motor A move anticlockwise
     digitalWrite(IN3,LOW);   
     digitalWrite(IN4,HIGH);  //turn DC Motor B move anticlockwise
}


void quick_left()
{
     digitalWrite(IN1,HIGH);  //turn DC Motor A move clockwise
     digitalWrite(IN2,LOW);
     digitalWrite(IN3,LOW);   //turn DC Motor B move anticlockwise
     digitalWrite(IN4,HIGH);
}


void quick_right() 
{
     digitalWrite(IN1,LOW);    //turn DC Motor A move anticlockwise
     digitalWrite(IN2,HIGH);
     digitalWrite(IN3,HIGH);   //turn DC Motor B move clockwise
     digitalWrite(IN4,LOW);
}

void slow_left_forward() 
{
     digitalWrite(IN1,HIGH);  //turn DC Motor A move clockwise
     digitalWrite(IN2,LOW);
     digitalWrite(IN3,LOW);   //stop DC Motor B.
     digitalWrite(IN4,LOW);
}

void  slow_right_forward()
{
     digitalWrite(IN1,LOW);    //stop DC Motor A.
     digitalWrite(IN2,LOW);    
     digitalWrite(IN3,HIGH);   //turn DC Motor B move clockwise
     digitalWrite(IN4,LOW);
}

void slow_left_backward() 
{
     digitalWrite(IN1,LOW);  //turn DC Motor A move anticlockwise
     digitalWrite(IN2,HIGH);
     digitalWrite(IN3,LOW);   //stop DC Motor B.
     digitalWrite(IN4,LOW);
}

void  slow_right_backward()
{
     digitalWrite(IN1,LOW);    //stop DC Motor A.
     digitalWrite(IN2,LOW);    
     digitalWrite(IN3,LOW);   //turn DC Motor B move anticlockwise
     digitalWrite(IN4,HIGH);
}

void Sensor_on()
{
     digitalWrite(Sensor, HIGH);
}

void Sensor_off()
{
  digitalWrite(Sensor, LOW);
}

void Middle_on()
{
     digitalWrite(Middle_Light, HIGH);
}

void Middle_off()
{
  digitalWrite(Middle_Light, LOW);
}

void Stop() 
{
     digitalWrite(IN1,LOW);    // stop DC Motor A.
     digitalWrite(IN2,LOW);
     digitalWrite(IN3,LOW);    // stop DC Motor B.        
     digitalWrite(IN4,LOW);
}






void loop()
{
  analogWrite(ENA, Robot_Speed); //Generate PWM Signal for MotorA 
  analogWrite(ENB, Robot_Speed); //Generate PWM Signal for MotorB 
  
  
  if (Serial.available()>0) 
  {
    delay(3);
    char NewData = Serial.read();
    
    Serial.println(NewData);
        
    if(NewData == 'F')
     { 
       forward(); //ROBOT Move to Forward Direction . 
       Serial.print("*T"+String("Going forward")+"*");
     }
     
     else if(NewData == 'B')
     {
       
       backward(); //ROBOT Move to Backward Direction . 
       Serial.print("*T"+String("Going Backward")+"*");
     }
     
     else if(NewData == 'L')
     {
        
       quick_left(); //ROBOT Fast Move to Left turn.    
       Serial.print("*T"+String("Quick left")+"*");
     }
     
     else if(NewData == 'R')
     {
       
       quick_right(); //ROBOT Fast Move to Right turn.  
       Serial.print("*T"+String("Quick right")+"*");
     }
     
     else if(NewData == 'I')
     {
        
       slow_right_forward(); //ROBOT Slow Move to Right turn with motor forward movement.  
       Serial.print("*T"+String("Turning Right")+"*");
     }
     
     else if(NewData == 'G')
     {
       
       slow_left_forward(); //ROBOT Slow Move to Left turn with motor forward movement.  
       Serial.print("*T"+String("Turning left")+"*");
     }
     
     else if(NewData == 'H') 
     {
    
       slow_left_backward(); //ROBOT Slow Move to left turn with motor backward movement.   
       Serial.print("*T"+String("Turning left")+"*");
     }
     
     else if(NewData == 'J') 
     {
      
       slow_right_backward(); //ROBOT Slow Move to Right turn with motor backward movement.  
       Serial.print("*T"+String("Turning right")+"*");
     }
     
     else if(NewData == 'W')
     { 
     
       Middle_on();
       Serial.print("*T"+String("Light on")+"*");
     }
     
       else if(NewData == 'w')
     { 
     
       Middle_off();
       Serial.print("*T"+String("Light off")+"*");
     }
     
     else if(NewData == 'U')
     { 
       Sensor_on();   
       Serial.print("*T"+String("Sensor on")+"*");
     }
     
     
     else if(NewData == 'u')
     {
       Sensor_off(); 
       Serial.print("*T"+String("Sensor off")+"*");
     }
     
     
     else if(NewData == 'V')
     {
      digitalWrite(SPK, HIGH);
       Serial.println(NewData);
     }
     
     else if(NewData == 'v')
     {
       
            digitalWrite(SPK, LOW); //If You already use any sound module then active it to turn OFF your sound system. 
            Serial.println("None v");

     }
     
     
     else if(NewData == '1')  
     {

        Robot_Speed = 0.00; //Robot Speed OFF
        Serial.println(Robot_Speed);
     }
        
        
      else if(NewData == '2')   
      {
        Robot_Speed = 28.33; //Robot Speed 
        Serial.println(Robot_Speed);
      }
        
      else if(NewData == '3')  
      {
        Robot_Speed = 56.66; //Robot Speed 
        Serial.println(Robot_Speed);
      }
        
      else if(NewData == '4') 
      {
        Robot_Speed = 84.99; //Robot Speed 
        Serial.println(Robot_Speed);
      }
        
      else if(NewData == '5')
      {
        Robot_Speed = 113.32; //Robot Speed 
        Serial.println(Robot_Speed);
      }
        
      else if(NewData == '6')
      {
        Robot_Speed = 141.65; //Robot Speed 
        Serial.println(Robot_Speed);
      }
        
      else if(NewData == '7')
      {
        Robot_Speed = 169.66; //Robot Speed 
        Serial.println(Robot_Speed);
      }
        
      else if(NewData == '8') 
      {
        Robot_Speed = 198.31; //Robot Speed 
        Serial.println(Robot_Speed);
      }
        
      else if(NewData == '9')
      {
        Robot_Speed = 255.00; //Robot Speed 
        Serial.println(Robot_Speed);
      }
        
     
     else
     {
      Stop(); 
      Serial.print("*T"+String("Bluetooth on")+"*");
     }
    
    
    }
    
  }


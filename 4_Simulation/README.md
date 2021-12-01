## Activity Codes

## Activity 1 Code 
```
void peripheral_init(void)
{	
	DDRD |= (1<<PD2); // set PD2=1 for LED
    DDRD &= ~(1<<PD0); //clear bit
    PORTD |= (1<<PD0); //set bit PD0 for SeatSwitch
    DDRD &= ~(1<<PD1); //clear bit
    PORTD |= (1<<PD1); //set bit PD0 for HeaterSwitch
}

void TurnLED_ON(){
    LED_PORT |= (1<<LED_PIN); 
}

void TurnLED_OFF(){
    LED_PORT &= ~(1<<LED_PIN);
}

int act1=0;
int activity1_LED(void)
{
       peripheral_init();
        if(!(PIND&(1<<BUTTON_SENSOR )) && !(PIND&(1<<TEMP_SENSOR))) //both the switches are pressed
        { 
            act1=1;
        }
        else  //in all other cases
        {
            act1=0;
        }
    return act1;
}
  
```


## Activity 2 Code 
```
void InitADC()
{
    ADMUX=(1<<REFS0);
    ADCSRA= (1<<ADEN)|(7<<ADPS0);
}

uint16_t ReadADC(uint8_t ch)
{
    ADMUX&=0xf8;
    ch=ch&0b00000111;
    ADMUX|=ch;

    ADCSRA|=(1<<ADSC);
    while(!(ADCSRA & (1<<ADIF)));
    ADCSRA|=(1<<ADIF);
    return(ADC);
}

uint16_t activity2_GetADC(void)
{
      InitADC();
      uint16_t temp;
      temp=ReadADC(0);
      return temp;
}
  
```



## Activity 3 Code 
```
void InitTimer()
{
    TCCR1A |= (1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
    TCCR1B |= (1<<WGM12)|(1<<CS11)|(1<<CS10);
    DDRB |=(1<<PB1);
}

void activity3_PWM(uint16_t temp)
{
    InitTimer();
    if(temp>=0 && temp<=200){
            OCR1A = PWM_20_PERCENT;
            _delay_ms(200);
        }
        else if(temp>=210 && temp<=500){
             OCR1A = PWM_40_PERCENT;
            _delay_ms(200);
        }
        else if(temp>=510 && temp<=700){
             OCR1A = PWM_70_PERCENT;
            _delay_ms(200);
        }
        else if(temp>=710 && temp<=1024){
             OCR1A = PWM_95_PERCENT;
            _delay_ms(200);
        }
        else{
            OCR1A=0;
            _delay_ms(200);
        }

}

```


## Activity 4 Code 
```
void USARTInit()
{
    UBRR0H = (uint8_t)(UBRR_VALUE>>8);
    UBRR0L = (uint8_t)UBRR_VALUE;
    UCSR0C=(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);
    UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}

int USARTRead()
{
    while(!(UCSR0A &(1<<RXC0)))
    {
        //Do nothing
    }
    return UDR0;
}

void USARTInit()
{
    UBRR0H = (uint8_t)(UBRR_VALUE>>8);
    UBRR0L = (uint8_t)UBRR_VALUE;
    UCSR0C=(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);
    UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}

int USARTRead()
{
    while(!(UCSR0A &(1<<RXC0)))
    {
        //Do nothing
    }
    return UDR0;
}

void activity4_USARTWrite(uint16_t temp)
{ 
    int i=0;
        if(temp>=0 && temp<=200){
            unsigned char data1[]="Temperature: 20 degree C\n";
            i=0;
            while(data1[i]!=0){
            while (!( UCSR0A & (1<<UDRE0)));  // Wait for empty transmit buffer
            UDR0 = data1[i];        // Put data into buffer, sends the data
            i++;
            }
            _delay_ms(2000);
        }
        else if(temp>=210 && temp<=500){
            unsigned char data2[]="Temperature: 25 degree C\n";
            i=0;
            while(data2[i]!=0){
            while (!( UCSR0A & (1<<UDRE0)));  // Wait for empty transmit buffer
            UDR0 = data2[i];        // Put data into buffer, sends the data
            i++;
            }
            _delay_ms(2000);
        }
        else if(temp>=510 && temp<=700){        
             unsigned char data3[]="Temperature: 29 degree C\n";
            i=0;
            while(data3[i]!=0){
            while (!( UCSR0A & (1<<UDRE0)));  // Wait for empty transmit buffer
            UDR0 = data3[i];        // Put data into buffer, sends the data
            i++;
            }
            _delay_ms(2000);
        }
        else if(temp>=710 && temp<=1024){         
            unsigned char data4[]="Temperature: 33 degree C\n";     
            i=0;
            while(data4[i]!=0){
            while (!( UCSR0A & (1<<UDRE0)));  // Wait for empty transmit buffer
            UDR0 = data4[i];        // Put data into buffer, sends the data
            i++;
            }
            _delay_ms(2000);
        }
        else{
              unsigned char data5[]="Temperature: 0 degree C\n";
            i=0;
            while(data5[i]!=0){
            while (!( UCSR0A & (1<<UDRE0)));  // Wait for empty transmit buffer
            UDR0 = data5[i];        // Put data into buffer, sends the data
            i++;
            }
            _delay_ms(2000);
            
        }
}
  
```

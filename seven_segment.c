// Configuration bits for PIC16F887 (you can adjust based on your setup)
#pragma config FOSC = INTRC_NOCLKOUT  // Internal oscillator, no clock output
#pragma config WDTE = OFF             // Watchdog timer disabled
#pragma config PWRTE = OFF            // Power-up timer disabled
#pragma config MCLRE = OFF            // RA5/MCLR pin function is digital input
#pragma config CP = OFF               // Code protection disabled
#pragma config CPD = OFF              // Data code protection disabled
#pragma config BOREN = OFF            // Brown-out reset disabled
#pragma config IESO = OFF             // Internal/External Switchover disabled
#pragma config FCMEN = OFF            // Fail-Safe Clock Monitor disabled
#pragma config LVP = OFF              // Low-Voltage Programming disabled


unsigned char segmentCodes[10] = {
    0b00111111,  // 0
    0b00000110,  // 1
    0b01011011,  // 2
    0b01001111,  // 3
    0b01100110,  // 4
    0b01101101,  // 5
    0b01111101,  // 6
    0b00000111,  // 7
    0b01111111,  // 8
    0b01101111   // 9
};

void main() {
     int i;
    TRISB = 0x00;  // Set PORTB as output
    PORTB = 0x00;  // Clear PORTB (turn off all segments)

    while (1) {
        for ( i = 0; i < 10; i++) {  // Loop through digits 0 to 9
            PORTB = segmentCodes[i];
            Delay_ms(500);
        }
    }
}
#include "stm32f407xx.h"

void SystemClock_8MHz(void);
void USART2_Init(void);
void USART2_SendChar(char c);
char USART2_ReceiveChar(void);
void USART2_SendString(char *str);

int main(void)
{
    char rx;

    SystemClock_8MHz();     // Configure system clock to use external 8 MHz crystal
    USART2_Init();          // Initialize USART2 peripheral

    USART2_SendString("USART2 @8MHz\r\n");  // Send message to PC

    while (1)
    {
        rx = USART2_ReceiveChar();  // Wait for character from PC
        USART2_SendChar(rx);        // Echo received character back
    }
}

void SystemClock_8MHz(void)
{
    RCC->CR |= RCC_CR_HSEON;               // Enable external crystal (HSE)
    while (!(RCC->CR & RCC_CR_HSERDY));    // Wait until HSE becomes ready

    RCC->CFGR |= RCC_CFGR_SW_HSE;          // Select HSE as system clock
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE); // Wait until switch complete
}

void USART2_Init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;   // Enable clock for GPIOA
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;  // Enable clock for USART2

    GPIOA->MODER |= (2 << 4) | (2 << 6);   // Set PA2 and PA3 to Alternate Function mode
    GPIOA->AFR[0] |= (7 << 8) | (7 << 12); // Select AF7 (USART2) for PA2 and PA3

    USART2->BRR = 0x0342;                  // Set baud rate (9600 for 8MHz clock)

    USART2->CR1 = USART_CR1_TE | USART_CR1_RE | USART_CR1_UE; 
    // Enable transmitter, receiver, and USART
}

void USART2_SendChar(char c)
{
    while (!(USART2->SR & USART_SR_TXE));  // Wait until transmit buffer empty
    USART2->DR = c;                        // Write data to transmit register
}

char USART2_ReceiveChar(void)
{
    while (!(USART2->SR & USART_SR_RXNE)); // Wait until data received
    return USART2->DR;                     // Read received data
}

void USART2_SendString(char *str)
{
    while (*str)
        USART2_SendChar(*str++);           // Send characters one by one
}

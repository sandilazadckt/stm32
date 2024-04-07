#include "systrick.h"
#include "uart.h"

int main(){
   HAL_Init();
   SystemClock_Config();
   uart_init();
   while(1){
   put_char('u');

   }
}

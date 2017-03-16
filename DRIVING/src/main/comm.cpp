#include"comm.h"
#include <printf.h>
#include <RF24_config.h>
#include <RF24.h>
#include <nRF24L01.h>

#define CE 9
#define CSN 10
#define TX_ADDRESS 0xFFFFFFFFFFAA
#define RX_ADDRESS 0xFFFFFFFFFFBB

RF24 rf(CE, CSN);

void connect(){
  
}

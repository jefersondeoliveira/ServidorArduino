// A simple web server that always just says "Hello World"

#include "etherShield.h"
#include "ETHER_28J60.h"

int pino = 0;
int valor;

static uint8_t mac[6] = {0x54, 0x55, 0x58, 0x10, 0x00, 0x24};
static uint8_t ip[4] = {192, 168, 1, 15}; 
static uint16_t port = 80; 

ETHER_28J60 ethernet;

void setup()
{ 
  Serial.begin(9600);
  ethernet.setup(mac, ip, port);
}

void loop()
{
  valor = analogRead(pino);
  Serial.println(valor);

  if (ethernet.serviceRequest())
  {
    ethernet.print("<div style='padding: 10px;margin: 5px;'>");
    ethernet.print("<span style='color: red'>");
    ethernet.print(valor);
    ethernet.print("</span>");
    ethernet.print("</div>");
    ethernet.print("<meta http-equiv='refresh' content='5'>");
    
    ethernet.respond();
  }else{
    Serial.println("erro");
  }
  delay(1000);
}


#include <Arduino.h>
//---Variaveis---pra definir os pinos 
const int pinoSensor = 34;
//funcoes de calculo

  float converterLeitura(int leitura)
  {
    float rawMin = 0;
    float rawMax = 4095;
    float fisMin = 0;
    float fisMax = 1000;

    return ((float)(leitura - rawMin) / (rawMax - rawMin)) * (fisMax - fisMin) + fisMin;
  }

//funcao principal
void processarSalinizacao()
{
  int leitura = analogRead(pinoSensor);

float valorFinal = converterLeitura(leitura);

Serial.print("Valor Final: ");
    Serial.println(valorFinal);
    Serial.println(" mg/L");

}
//Funcao de conversa entre o codigo e o Arduino

void setup()
{
    Serial.begin(115200);//inicia a conversa
    pinMode(pinoSensor, INPUT);
}

void loop()
{
  //executa um loop infinito
  processarSalinizacao();
  delay(1000);//espera 1 segundo entre as leituras
}


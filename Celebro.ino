#include <Arduino.h>
//---Variaveis---pra definir os pinos 
const int pinoSalinidade = 34;
const int pinoPH = 35;//novo pino adicionado
//funcoes de calculo

  float converterLeitura(int leitura)
  {
    float rawMin = 0;
    float rawMax = 4095;
    float fisMin = 0;
    float fisMax = 1000;

    return ((float)(leitura - rawMin) / (rawMax - rawMin)) * (fisMax - fisMin) + fisMin;
  }

//----calculo de PH da agua----
//definicoes para o sensor
const float PH_Neutro = 2.5;//voltagem para quando o ph for 7.0
const float PH_Passo = 0.18;//Sensibilidade do sensor por unidade de PH

float CalcularPH(int leituraBruta)
{
  //Converter a leitura do ADC para Voltagem
  float voltagem = (leituraBruta * 3.3) / 4095.0;

  //Calcula o valor de PH 
  float valorPH = 7.0 + ((PH_Neutro - voltagem) / PH_Passo);

  return valorPH;
}

//funcao principal
void processarMonitoramento()
{
  int leituraSal = analogRead(pinoSalinidade);
  int leituraPH = analogRead(pinoPH); 

float valorSal = converterLeitura(leituraSal);
float valorPH = CalcularPH(leituraPH);
//trava de seguraca de PH para evitar valores loucos * novo
if (valorPH > 14.0) valorPH = 14.0;
if (valorPH < 0.0) valorPH = 0.0;


Serial.print("Valor Final: ");
    Serial.println(valorSal);
    Serial.println(" mg/L");
    Serial.println ("Nivel de PH");
    Serial.println (valorPH);
}
//Funcao de conversa entre o codigo e o Arduino

void setup()
{
    Serial.begin(115200);//inicia a conversa
    pinMode(pinoSalinidade, INPUT);
    pinMode(pinoPH, INPUT);
}

void loop()
{
  //executa um loop infinito
  processarMonitoramento();
  delay(1000);//espera 1 segundo entre as leituras
}

























//criado por: Flix codes.

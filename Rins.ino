#include <Arduino.h>
//
struct Sensor 
{
  int pinoSalinidade;
  int pinoPH;
  const char* nome;
};

Sensor tanques[] = {
  {34,35, "Tanque-A"},
  {36, 39, "Tanque-B"}
};
const int NUM_TANQUES = sizeof(tanques) / sizeof(tanques[0]);

//---Variaveis---pra definir os pinos*Removidas 
//--Configuracao da medida ADC.
const int NUM_AMOSTRAS = 10;

//funcao: medida de leitura ADC.
int lerMedidaADC(int pino)
{

  long soma = 0;
  for (int c = 0; c < NUM_AMOSTRAS; c++)
  {
    soma += analogRead(pino);
    delay(5);
  }
  return (int)(soma / NUM_AMOSTRAS);
}

//--- Fator de conversao para sensor generico ---
// Sem calibracao, os valores sao estimativas relativas, nao medicoes absolutas.
const float PPM_MAX_ESTIMADO = 1000.0;

//funcoes de calculo

  float converterLeitura(int leitura)
  {
    return ((float)leitura / 4095.0) * PPM_MAX_ESTIMADO;//*novo: calculo simplificado
  }

//----calculo de PH da agua----
//definicoes para o sensor
const float PH_Neutro = 2.5; // voltagem (V) quando pH = 7.0
const float PH_Passo = 0.18;// variacao de voltagem por unidade de pH

float CalcularPH(int leituraBruta)
{

  //Converter a leitura do ADC para Voltagem
  float voltagem = (leituraBruta * 3.3) / 4095.0;
  //Calcula o valor de PH 
  float valorPH = 7.0 + ((PH_Neutro - voltagem) / PH_Passo);
  return valorPH;

}

//funcao principal
void processarMonitoramento(Sensor tanque)
{

  int leituraSal = lerMedidaADC(tanque.pinoSalinidade);
  int leituraPH = lerMedidaADC(tanque.pinoPH); 


float valorSal = converterLeitura(leituraSal);
float valorPH = CalcularPH(leituraPH);


//trava de seguraca de PH para evitar valores loucos
if (valorPH > 14.0) valorPH = 14.0;
if (valorPH < 0.0) valorPH = 0.0;


    Serial.printf("--- %s ---\n", tanque.nome);
    Serial.printf("Salinidade: %.2f mg/L\n", valorSal);
    Serial.printf("Nivel de PH: %.2f\n", valorPH);
    Serial.println ("---");
}
//Funcao de conversa entre o codigo e o Arduino

void setup()
{
    Serial.begin(115200);//inicia a conversa
    for (int p = 0; p < NUM_TANQUES; p++ )
    {
    pinMode(tanques[p].pinoSalinidade, INPUT);
    pinMode(tanques[p].pinoPH, INPUT);
    }
}

void loop()
{
  for (int pi = 0; pi < NUM_TANQUES; pi++)
  {
  processarMonitoramento(tanques[pi]);
  }
  delay(1000);//espera 1 segundo entre as leituras
}
//criado por: Flix codes.

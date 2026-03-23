# 🧠 Usina Monitor

> "Monitorar água manualmente é coisa do século passado. Deixe o ESP32 trabalhar por você."

Firmware para monitoramento em tempo real de salinidade e pH da água,
desenvolvido para ESP32. Processa sinais analógicos de múltiplos sensores,
suaviza ruído via média ADC e transmite os dados pela porta serial.

---

## 🚀 Funcionalidades

- **Salinidade** — conversão de sinal analógico para ppm via mapeamento ADC 12-bit
- **pH** — cálculo por voltagem com calibração configurável
- **Suavização de ruído** — média de 10 amostras por ciclo de leitura
- **Clamping de segurança** — pH travado entre 0.0 e 14.0, sem valores impossíveis
- **Dual-channel** — dois sensores simultâneos nos pinos 34 e 35

---

## 🛠️ Stack

| Camada | Tecnologia |
|---|---|
| Hardware | ESP32 |
| Linguagem | C++ / Arduino Framework |
| Build | arduino-cli / PlatformIO |
| Simulação | [Wokwi](https://wokwi.com/projects/457864289491458049) |
| Editor | Neovim (Arch Linux) |

---

## 🔬 Simulação

Experimente o circuito em funcionamento sem hardware físico:

**[▶ Abrir simulação no Wokwi](https://wokwi.com/projects/457864289491458049)**

---

## ⚙️ Como usar

**1. Clone o repositório**
```bash
git clone https://github.com/flixgamerd/usina-monitor
cd usina-monitor
```

**2. Compile e suba para o ESP32**
```bash
arduino-cli compile --fqbn esp32:esp32:esp32 .
arduino-cli upload -p /dev/ttyUSB0 --fqbn esp32:esp32:esp32 .
```

**3. Monitore a saída serial**
```bash
arduino-cli monitor -p /dev/ttyUSB0 --config baudrate=115200
```

---

## 📡 Saída serial esperada
```
---Valores Finais---
Salinidade: 734.56 ppm
Nivel de PH: 7.23
---
```

---

## 🔧 Calibração

Os valores padrão são estimativas genéricas para sensores analógicos comuns.
**Sem calibração, o pH pode ter erro de ± 1.5 unidades.**

**Sensor de pH:**
1. Mergulhe o sensor em solução buffer pH 7.0
2. Meça a voltagem de saída com multímetro
3. Atualize `PH_Neutro` com o valor medido
4. Repita com buffer pH 4.0 e recalcule `PH_Passo`

**Sensor de salinidade:**
- Ajuste `PPM_MAX_ESTIMADO` com uma solução de referência conhecida

---

## ⚠️ Aviso

Projeto desenvolvido e testado em ambiente simulado (Wokwi).
Certifique-se de proteger adequadamente o hardware antes de qualquer
contato com água real. A física não aceita pull requests.

---

## Autor

**Flix codes** — [github.com/flixgamerd](https://github.com/flixgamerd) e sua **Equipa**

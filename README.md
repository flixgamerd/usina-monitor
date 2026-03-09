
🧠 Usina-Monitor: O Cérebro Eletrônico

 "Porque monitorar a água manualmente é tão 1990. Deixe o ESP32 sofrer por você."

Este projeto é o núcleo de processamento para monitoramento de salinização e pH, desenvolvido com o rigor técnico de quem usa Arch Linux e a paciência de quem configura o Neovim do zero.

🚀 Funcionalidades (ou "O que o cérebro faz")

1. Cálculo de Salinização: Conversão precisa de dados analógicos para mg/L.

2. Monitoramento de pH: Algoritmo com calibração de voltagem e sensibilidade.

3. Lógica de Clamping: Travas de segurança para evitar que o pH desafie as leis da química (0-14).

4. Dual-Channel: Suporte a múltiplos sensores via ADC de 12 bits.

🛠️ Stack Tecnológica

 1. Hardware: ESP32 (O hospedeiro).

 2. Linguagem: C++/Arduino (A alma do negócio).

 3. Editor: Neovim (Porque o VS Code é pesado demais para o meu Arch) .

 4. Simulação: Wokwi (Onde nenhum sensor morre de verdade).

⚙️ Como rodar (Se você for corajoso)

    1. Clone o repositório: git clone https://github.com/flixgamerd/usina-monitor.

 2. Abra no seu Neovim ou VS Code (tanto faz).

 3. Use o arduino-cli para compilar e subir para o seu ESP32.

    Nota do Dev: "Aviso: Este código foi testado em um ambiente controlado (Wokwi). Se você mergulhar o seu ESP32 na água sem proteção e ele começar a soltar fumaça, a culpa é da física, não da minha matemática

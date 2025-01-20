# Controle de Pinos GPIO com Teclado Matricial

Este projeto utiliza um teclado matricial para controlar os LEDs RGB e um buzzer em uma simulação de microcontrolador RP2040 (Raspberry Pi Pico W). O objetivo é acender os LEDs e ativar o buzzer com comandos específicos do teclado matricial. O projeto foi desenvolvido para ser executado tanto no simulador **Wokwi** integrado ao **VS Code** quanto no hardware real.

---

## **Pré-requisitos**

### **Softwares Necessários**
1. **VS Code** com a extensão **Raspberry Pi Pico** instalada.
2. **CMake** e **Ninja** configurados.
3. **SDK do Raspberry Pi Pico** corretamente configurado.
4. Simulador **Wokwi** instalado e integrado ao VS Code.

### **Clonando o Repositório**
Para começar, clone o repositório no seu computador:
```bash
git clone https://github.com/GabrielSampa1o/Controle-de-Pinos-GPIO-com-Teclado-Matricial.git
cd Controle-de-Pinos-GPIO-com-Teclado-Matricial
```

---

## **Execução no Simulador Wokwi do VS Code**

### **1. Importar o Projeto**
Após clonar o repositório:
1. Abra o **VS Code**.
2. No menu **Raspberry Pi Pico**, selecione **Import Project**.
3. Escolha a pasta clonada e clique em **Import**.

### **2. Configurar o Simulador Wokwi**
1. Abra o arquivo `diagram.json` incluído no repositório.
2. Certifique-se de que o arquivo JSON está configurado corretamente para a simulação do hardware necessário:
   - LEDs conectados aos pinos GPIO 11, 12 e 13.
   - Buzzer conectado ao GPIO 21.
   - Teclado matricial configurado.

### **3. Compilar o Código**
1. Clique no ícone **Raspberry Pi Pico** no lado esquerdo do VS Code.
2. Escolha a opção **Compile Project** para compilar o código.

### **4. Executar a Simulação**
1. Abra o painel do simulador Wokwi no VS Code.
2. Clique em **Play** para iniciar a simulação.
3. Interaja com o teclado matricial para acionar os LEDs e o buzzer:
   - `A`, `B`, `C`, `D`: Acendem os LEDs.
   - `#`: Liga o buzzer.
   - `*`: Desliga o buzzer.

---

## **Funcionamento**

### **Comandos do Teclado Matricial**
- **A**: Liga o LED verde.
- **B**: Liga o LED azul.
- **C**: Liga o LED vermelho.
- **D**: Aciona o buzzer por 2 segundos.
- **#**: Liga todos os LEDs (luz branca).



### **Outros Detalhes**
- O projeto utiliza as bibliotecas padrão do SDK do Raspberry Pi Pico para manipulação de GPIOs.
- O simulador Wokwi é configurado para refletir o comportamento real do hardware.

---

## **Requisitos de Hardware (para execução real)**
1. Placa **Raspberry Pi Pico W**.
2. Teclado matricial conectado aos GPIOs indicados no código.
3. LEDs RGB e resistores conectados aos GPIOs 11, 12 e 13.
4. Buzzer conectado ao GPIO 21.
5. Cabo USB para alimentação e comunicação.

---

## **Contribuições**
Sinta-se à vontade para abrir issues ou pull requests no repositório: [GitHub Repository](https://github.com/GabrielSampa1o/Controle-de-Pinos-GPIO-com-Teclado-Matricial).

---

## **Desenvolvedores**
- Vinícius Ramos de Araújo
- Décio Francis da Silva
- Gabriel Silva Sampaio
- Maic de Oliveira Santos
- Kaique Almeida Barbosa
- Humberto Bandeira Costa
- [Nome do desenvolvedor]
- [Nome do desenvolvedor]

## Vídeo de Demonstração

[Assista ao vídeo de demonstração aqui](https://www.dropbox.com/scl/fi/z0v2e9is15czq3508h7c4/2025-01-19-20-21-49.mkv?rlkey=xszp4lvgrpryekcvdroszjmjj&st=326dgohf&dl=0)



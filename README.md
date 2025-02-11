# PWM-control
Repositório criado a fim de armazenar uma aplicação prática do módulo PWM. <br>
__Autora:__ Ana Karolina Disigant Reis

## Controle de servomotor por PWM
O emprego do módulo PWM (do inglês, Pulse Width Modulation) se faz presente na simulação de controle do ângulo de um servomotor.<br>

__Componentes necessários:__ <br>
1) Microcontrolador Raspberry Pi Pico W;
2) Servomotor – motor micro servo padrão – Wokwi.

__Requisitos de desenvolvimento:__
1) Considerando a GPIO 22, defina a sua frequência de PWM para, aproximadamente, 50Hz – período de 20ms. 
2) Defina o ciclo ativo do módulo PWM para 2.400µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,12%. isto ajustará a flange (braço) do servomotor para a posição de, aproximadamente, 180 graus. Aguarde 05 segundos nesta posição.
3) Defina o ciclo ativo do módulo PWM para 1.470µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,0735%. Isto ajustará a flange do servomotor para a posição de, aproximadamente, 90 graus. Aguarde 05 segundos nesta posição.
4) Defina o ciclo ativo do módulo PWM para 500µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,025%. Isto ajustará a flange do servomotor para a posição de, aproximadamente, 0 graus. Aguarde 05 segundos nesta posição.
5) Após a realização das proposições anteriores, crie uma rotina para movimentação periódica do braço do servomotor entre os ângulos de 0 e 180 graus. Obs.: a movimentação da flange deve ser suave, recomenda-se o incremento de ciclo ativo de ±5µs, com um atraso de ajuste de 10ms. 
6) Com o emprego da Ferramenta Educacional BitDogLab, faça um experimento com o código deste exercício utilizando o LED RGB – GPIO 12.  

__Configuração e Compilação:__

1. Clone o repositório:
   ```sh
   git clone https://github.com/anadisigant/PWM-control.git
   cd PWM-control
   ```
2. Configure o ambiente:
   ```sh
   export PICO_SDK_PATH=</caminho/para/o/pico-sdk>
   ```
3. Crie e entre no diretório de build:
   ```sh
   mkdir build && cd build
   ```
4. Execute o CMake:
   ```sh
   cmake ..
   ```
5. Compile o projeto:
   ```sh
   make
   ```
6. Após a compilação, conecte o Raspberry Pi Pico no modo BOOTSEL e arraste o arquivo `.uf2` gerado para o dispositivo.

__Uso__

1. Após carregar o firmware no Raspberry Pi Pico, o temporizador será inicializado.
2. O código está configurado para acionar eventos em intervalos regulares.
3. Para modificar o tempo do temporizador, ajuste os parâmetros no código-fonte.

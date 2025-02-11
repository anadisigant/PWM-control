# PWM-control
Repositório criado a fim de armazenar uma aplicação prática do módulo PWM.

__Configuração e Compilação:__

1. Clone o repositório:
   ```sh
   git clone https://github.com/anadisigant/Temporizador-periodico.git
   cd Temporizador-periodico
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

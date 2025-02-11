# PWM-control
Repositório criado a fim de armazenar uma aplicação prática do módulo PWM. <br>
__Autora:__ Ana Karolina Disigant Reis
__Vídeo:__ [Controle de servomotor por PWM]
## Controle de servomotor por PWM
O emprego do módulo PWM (do inglês, Pulse Width Modulation) se faz presente na simulação de controle do ângulo de um servomotor.<br>

__Componentes necessários:__ <br>
1) Microcontrolador Raspberry Pi Pico W;
2) Servomotor – motor micro servo padrão – Wokwi.

__Requisitos de desenvolvimento:__ <br>

__1) Considerando a GPIO 22, defina a sua frequência de PWM para, aproximadamente, 50Hz – período de 20ms. ✅__
```c
const uint16_t WRAP_PERIOD = 65535; // Valor máximo do contador - WRAP
const float PWM_DIVISER = 38.16;    // Divisor do clock para o PWM (frequência de PWM para aproximadamente 50Hz)

void pwm_setup()
{
    gpio_set_function(PWM_SERVO, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(PWM_SERVO);
    pwm_set_clkdiv(slice, PWM_DIVISER);   // Define o divisor de clock do PWM
    pwm_set_wrap(slice, WRAP_PERIOD);     // Define o valor de wrap para 50Hz
    pwm_set_gpio_level(PWM_SERVO, 0);
    pwm_set_enabled(slice, true);         // Habilita o PWM
}
```
- A frequência do PWM é ajustada para aproximadamente **50Hz** com um divisor de clock de **38.16** e um **WRAP_PERIOD** de **65535**.
- Essa configuração garante que o PWM tenha um período de **20ms (50Hz)**, essencial para o controle do servo.

__2) Defina o ciclo ativo do módulo PWM para 2.400µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,12%. isto ajustará a flange (braço) do servomotor para a posição de, aproximadamente, 180 graus. Aguarde 05 segundos nesta posição. ✅__
```c
set_duty_cycle(0.12); // 2.400µs → 180º
sleep_ms(5000);
```
- **0.12** representa **12%** do ciclo ativo, o que equivale a **2400µs**.
- O código mantém essa posição por **5 segundos** com `sleep_ms(5000)`.

__3) Defina o ciclo ativo do módulo PWM para 1.470µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,0735%. Isto ajustará a flange do servomotor para a posição de, aproximadamente, 90 graus. Aguarde 05 segundos nesta posição. ✅__
```c
set_duty_cycle(0.0735); // 1.470µs → 90º
sleep_ms(5000);
```
- **0.0735** representa **7.35%** do ciclo ativo, o que equivale a **1470µs**.
- O código mantém essa posição por **5 segundos**.

__4) Defina o ciclo ativo do módulo PWM para 500µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,025%. Isto ajustará a flange do servomotor para a posição de, aproximadamente, 0 graus. Aguarde 05 segundos nesta posição. ✅__
```c
set_duty_cycle(0.025); // 500µs → 0º
sleep_ms(5000);
```
- **0.025** representa **2.5%** do ciclo ativo, o que equivale a **500µs**.
- O código mantém essa posição por **5 segundos**.

__5) Após a realização das proposições anteriores, crie uma rotina para movimentação periódica do braço do servomotor entre os ângulos de 0 e 180 graus. Obs.: a movimentação da flange deve ser suave, recomenda-se o incremento de ciclo ativo de ±5µs, com um atraso de ajuste de 10ms. ✅__

```c
for (int i = 0; i < 380; i++) {  // De 0 a 180 graus
    set_duty_cycle(0.025 + i * 0.00025); // Incrementos suaves de ±5µs
    sleep_ms(10);
}

for (int i = 0; i < 380; i++) {  // De 180 a 0 graus
    set_duty_cycle(0.12 - i * 0.00025); // Decrementos suaves de ±5µs
    sleep_ms(10);
}
```
- O código implementa **incrementos e decrementos de ±5µs** a cada **10ms**, garantindo um **movimento suave** do servo entre **0° e 180°** e vice-versa.
- **O total de 380 incrementos** permite cobrir o intervalo entre os extremos.

__6) Com o emprego da Ferramenta Educacional BitDogLab, faça um experimento com o código deste exercício utilizando o LED RGB – GPIO 12. ✅__
<br>
- O experimento pode ser conferido na branch teste-BitDogLab

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

1. Após carregar o firmware no Raspberry Pi Pico e dar o play no wokwi simulator, o trabalho do servomotor será inicializado.
2. O código está configurado para acionar eventos em intervalos regulares.
3. Para modificar o tempo das ações, ajuste os parâmetros no código-fonte.

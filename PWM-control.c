#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22
#define LED_PIN 12
#define PWM_FREQ 50
#define WRAP_VALUE 65535
#define PWM_DIVISER 38.16

// Configuração do PWM para Servo e LED
void pwm_setup(uint gpio) {
    gpio_set_function(gpio, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(gpio);
    pwm_set_clkdiv(slice, PWM_DIVISER);
    pwm_set_wrap(slice, WRAP_VALUE);
    pwm_set_gpio_level(gpio, 0);
    pwm_set_enabled(slice, true);
}

// Define o ângulo do servo motor via Duty Cycle
void set_servo_angle(uint pin, float duty_cycle) {
    int level = WRAP_VALUE * duty_cycle;
    pwm_set_gpio_level(pin, level);
}

// Ajusta o brilho do LED baseado no duty cycle do servo
void set_led_brightness(uint pin, float duty_cycle) {
    int level = WRAP_VALUE * duty_cycle;
    pwm_set_gpio_level(pin, level);
}

int main() {
    stdio_init_all();
    
    pwm_setup(SERVO_PIN);
    pwm_setup(LED_PIN);

    while (true) {
        // Posição 180° (2.4ms / 20ms ≈ 0.12)
        set_servo_angle(SERVO_PIN, 0.12);
        set_led_brightness(LED_PIN, 0.12);
        sleep_ms(5000);

        // Posição 90° (1.47ms / 20ms ≈ 0.0735)
        set_servo_angle(SERVO_PIN, 0.0735);
        set_led_brightness(LED_PIN, 0.0735);
        sleep_ms(5000);

        // Posição 0° (0.5ms / 20ms ≈ 0.025)
        set_servo_angle(SERVO_PIN, 0.025);
        set_led_brightness(LED_PIN, 0.025);
        sleep_ms(5000);

        // Movimento suave entre 0° e 180°
        for (int i = 0; i < 380; i++) {
            float duty = 0.025 + i * 0.00025;
            set_servo_angle(SERVO_PIN, duty);
            set_led_brightness(LED_PIN, duty);
            sleep_ms(10);
        }

        for (int i = 0; i < 380; i++) {
            float duty = 0.12 - i * 0.00025;
            set_servo_angle(SERVO_PIN, duty);
            set_led_brightness(LED_PIN, duty);
            sleep_ms(10);
        }
    }
}
#include <stdio.h>

#include "hardware/timer.h"
#include "pico/stdlib.h"

// define o numero do pino para cada led
#define BLUE_LED_PIN 11
#define RED_LED_PIN 12
#define GREEN_LED_PIN 13
// define o numero do pino do botao
#define BUTTON_PIN 5
// define tempo de espera entre cada acionamento
#define INTERVAL_DURATION 3000

volatile bool is_running = false;

void define_all_components() {
  // inicia e define o led o tipo do pino do led azul
  gpio_init(BLUE_LED_PIN);
  gpio_set_dir(BLUE_LED_PIN, GPIO_OUT);
  // inicia e define o led o tipo do pino do led vermelho
  gpio_init(RED_LED_PIN);
  gpio_set_dir(RED_LED_PIN, GPIO_OUT);
  // inicia e define o led o tipo do pino do led verde
  gpio_init(GREEN_LED_PIN);
  gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);
  // inicia e define o led o tipo do pino do botao
  gpio_init(BUTTON_PIN);
  gpio_set_dir(BUTTON_PIN, GPIO_IN);
  // ativa a resistencia de pull-up interna
  gpio_pull_up(BUTTON_PIN);
}

int64_t turn_off_blue(alarm_id_t id, void *user_data) {
  gpio_put(BLUE_LED_PIN, 0);
  return 0;
}

int64_t turn_off_red(alarm_id_t id, void *user_data) {
  gpio_put(RED_LED_PIN, 0);
  return 0;
}

int64_t turn_off_green(alarm_id_t id, void *user_data) {
  gpio_put(GREEN_LED_PIN, 0);
  is_running = false;
  return 0;
}

void handle_button() {
  if (!is_running) {
    is_running = true;
    gpio_put(BLUE_LED_PIN, 1);
    gpio_put(RED_LED_PIN, 1);
    gpio_put(GREEN_LED_PIN, 1);
    add_alarm_in_ms(INTERVAL_DURATION, turn_off_blue, NULL, false);
    add_alarm_in_ms(INTERVAL_DURATION * 2, turn_off_red, NULL, false);
    add_alarm_in_ms(INTERVAL_DURATION * 3, turn_off_green, NULL, false);
  }
}

int main() {
  stdio_init_all();
  define_all_components();

  while (true) {
    if (gpio_get(BUTTON_PIN) == 0) {
      handle_button();
    }
    sleep_ms(100);
  }
}

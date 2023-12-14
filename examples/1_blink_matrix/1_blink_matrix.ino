// Blink Matrix - Liga e desliga todos os LEDs da matriz simultaneamente
// Arthur L. Castro
// Dezembro de 2023

// ---------- Importacao de bibliotecas ----------
#include <ALC_LED_Matrix.h>

// ---------- Definindo macros ----------
#define INTERVALO_PISCA_MS 1000

// ---------- Declaracao de variaveis para matriz de LEDs ----------
uint8_t matrix_pins[5][5] = {
  {2,3,4,5,6},    // linhas
  {7,8,9,10,11},  // colunas
};

// ---------- Instanciando objetos ----------
ALC_LED_Matrix matriz5x5(matrix_pins);

// ---------- Configuracoes de inicializacao ----------
void setup() {
  matriz5x5.begin();    // Inicializa matriz de LEDs
  matriz5x5.clear();    // Apaga todos os LEDs da matriz
}

// ---------- Loop infinito ----------
void loop() {
  matriz5x5.fill();     // Acende todos os LEDs da matriz
  delay(INTERVALO_PISCA_MS);
  matriz5x5.clear();    // Apaga todos os LEDs da matriz
  delay(INTERVALO_PISCA_MS/2);
}

// Print Matrix - Imprime uma figura na matriz de LEDs
// Arthur L. Castro
// Dezembro de 2023

// ---------- Importacao de bibliotecas ----------
#include <ALC_LED_Matrix.h>
#include <ALC_LED_Matrix_Figures.h>

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

  matriz5x5.select_figure(quadrado_3x3);   // Atualiza 'matriz_buffer'
}

// ---------- Loop infinito ----------
void loop() {
  matriz5x5.update();     // Percorre todas as linhas da matriz atualizando os estados dos LEDs
}

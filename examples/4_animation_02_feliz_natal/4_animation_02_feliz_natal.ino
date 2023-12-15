// Animation 02 - Feliz Natal
// Arthur L. Castro
// Dezembro de 2023

// ---------- Importacao de bibliotecas ----------
#include <ALC_LED_Matrix.h>
#include <ALC_LED_Matrix_Figures.h>

// ---------- Definindo macros ----------
#define INTERVALO_ENTRE_FIGURAS_MS 500

// ---------- Declaracao de variaveis para matriz de LEDs ----------
uint8_t matrix_pins[5][5] = {
  {2,3,4,5,6},    // linhas
  {7,8,9,10,11},  // colunas
};

// ---------- Declaracao de variaveis para animacoes ----------
const byte* animacao[13] = {
  letra_F[0], letra_E[0], letra_L[0], letra_I[0], letra_Z[0],
  vazio[0],
  letra_N[0], letra_A[0], letra_T[0], letra_A[0], letra_L[0], ponto_de_exclamacao[0],
  vazio[0]
};

unsigned long previousTime=0;
unsigned int frame_idx=0;

// ---------- Instanciando objetos ----------
ALC_LED_Matrix matriz5x5(matrix_pins);

// ---------- Configuracoes de inicializacao ----------
void setup() {
  matriz5x5.begin();    // Inicializa matriz de LEDs
  matriz5x5.clear();    // Apaga todos os LEDs da matriz
}

// ---------- Loop infinito ----------
void loop() {

  if (millis() - previousTime >= INTERVALO_ENTRE_FIGURAS_MS){
    previousTime = millis();
    
    matriz5x5.select_figure(animacao[frame_idx]);   // Atualiza a matriz de buffer
    
    if (frame_idx >= (sizeof(animacao)/sizeof(const byte*) - 1)) {
      frame_idx = 0;
    } else {
      frame_idx++;
    }
  }

  matriz5x5.update();     // Percorre todas as linhas da matriz atualizando os estados dos LEDs
}


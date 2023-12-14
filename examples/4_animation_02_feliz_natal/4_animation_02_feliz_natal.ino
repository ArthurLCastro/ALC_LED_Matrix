// Animation 02 - Feliz Natal
// Arthur L. Castro
// Dezembro de 2023

// ---------- Importacao de bibliotecas ----------
#include <ALC_LED_Matrix.h>
#include <ALC_LED_Matrix_Figures.h>

// ---------- Definindo macros ----------
#define INTERVALO_ENTRE_FIGURAS_MS 250

// ---------- Declaracao de variaveis para matriz de LEDs ----------
uint8_t matrix_pins[5][5] = {
  {2,3,4,5,6},    // linhas
  {7,8,9,10,11},  // colunas
};

// ---------- Declaracao de variaveis para animacoes ----------
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
  switch (frame_idx) {
    case 0:
      matriz5x5.select_figure(letra_F);   // Atualiza 'matriz_buffer'
      break;
    case 1:
      matriz5x5.select_figure(letra_E);   // Atualiza 'matriz_buffer'
      break;
    case 2:
      matriz5x5.select_figure(letra_L);   // Atualiza 'matriz_buffer'
      break;
    case 3:
      matriz5x5.select_figure(letra_I);   // Atualiza 'matriz_buffer'
      break;
    case 4:
      matriz5x5.select_figure(letra_Z);   // Atualiza 'matriz_buffer'
      break;
    case 5:
      matriz5x5.select_figure(vazio);   // Atualiza 'matriz_buffer'
      break;
    case 6:
      matriz5x5.select_figure(letra_N);   // Atualiza 'matriz_buffer'
      break;
    case 7:
      matriz5x5.select_figure(letra_A);   // Atualiza 'matriz_buffer'
      break;
    case 8:
      matriz5x5.select_figure(letra_T);   // Atualiza 'matriz_buffer'
      break;
    case 9:
      matriz5x5.select_figure(letra_A);   // Atualiza 'matriz_buffer'
      break;
    case 10:
      matriz5x5.select_figure(letra_L);   // Atualiza 'matriz_buffer'
      break;
    case 11:
      matriz5x5.select_figure(ponto_de_exclamacao);   // Atualiza 'matriz_buffer'
      break;
    case 12:
      matriz5x5.select_figure(vazio);   // Atualiza 'matriz_buffer'
      break;
  }

  if (millis() - previousTime >= INTERVALO_ENTRE_FIGURAS_MS + 500){
    previousTime = millis();
    
    if (frame_idx >= 12) {
      frame_idx = 0;
    } else {
      frame_idx++;
    }
  }

  matriz5x5.update();     // Percorre todas as linhas da matriz atualizando os estados dos LEDs
}

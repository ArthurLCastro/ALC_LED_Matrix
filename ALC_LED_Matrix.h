/*
  ALC_LED_Matrix.h - Biblioteca para controle de Matriz de LEDs
  Arthur L. Castro
  Dezembro de 2023
*/

#ifndef ALC_LED_Matrix_h
#define ALC_LED_Matrix_h

#include <Arduino.h>

// Macros para Debug:
#define DEBUG_MATRIZ_BUFFER

// Macros:
#define TEMPO_POR_LINHA_MS 1    // Tempo maximo para atualizar cada uma das 5 linhas (para 24Hz) seria 8ms
/*
  Para uma taxa de atualização de 24Hz:

  tempo_min_por_frame_em_seg = 1 / 24
  tempo_min_por_frame_em_seg = 40ms

  tempo_max_por_linha = 40ms / 5 linhas
  tempo_max_por_linha = 8ms
*/

class ALC_LED_Matrix {
  public:
    ALC_LED_Matrix(uint8_t pins[5][5]);
    void begin();
    void clear();
    void fill();
    void update();
    void select_figure(const byte figure[5][5]);

  private:
    uint8_t _pins[5][5];
    byte _buffer[5][5] = {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
    };

};

#endif
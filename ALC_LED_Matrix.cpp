/*
  ALC_LED_Matrix.cpp - Biblioteca para controle de Matriz de LEDs
  Arthur L. Castro
  Dezembro de 2023
*/

#include "Arduino.h"
#include "ALC_LED_Matrix.h"

// Construtor
ALC_LED_Matrix::ALC_LED_Matrix(uint8_t pins[5][5]) {
  for (int i=0; i<=4; i++) {
    for (int j=0; j<=4; j++) {
      _pins[i][j] = pins[i][j];
    }
  }
}

// Inicializa Matriz de LEDs
void ALC_LED_Matrix::begin() {
  // Definindo pinos da matriz como saidas
  for (int i=0; i<=4; i++) {
    pinMode(_pins[0][i], OUTPUT);
  }
  for (int i=0; i<=4; i++) {
    pinMode(_pins[1][i], OUTPUT);
  }
}

// Desliga todos os LEDs da Matriz
void ALC_LED_Matrix::clear() {
  // Catodos dos LEDs para HIGH
  for (int i=0; i<=4; i++) {
    digitalWrite(_pins[0][i], HIGH);
  }
  // Anodos dos LEDs para LOW
  for (int i=0; i<=4; i++) {
    digitalWrite(_pins[1][i], LOW);
  }
}

// Liga todos os LEDs da Matriz
void ALC_LED_Matrix::fill() {
  // Catodos dos LEDs para HIGH
  for (int i=0; i<=4; i++) {
    digitalWrite(_pins[0][i], LOW);
  }
  // Anodos dos LEDs para LOW
  for (int i=0; i<=4; i++) {
    digitalWrite(_pins[1][i], HIGH);
  }
}

// Percorre todos os LEDs da matriz atualizando seus estados
void ALC_LED_Matrix::update() {
  /*
    Funcionamento:
      Configura os niveis logicos nos anodos de todos os LEDs de uma linha simultaneamente, habilita apenas
      esta linha (catodos comum), espera um tempo, desabilita a linha e faz o mesmo para a proxima linha
  */

  for (int i=0; i<=4; i++) {
    // Controle das colunas
    for (int j=0; j<=4; j++) {
      digitalWrite(_pins[1][j], _buffer[i][j]);   // Configurando valores do buffer nos anodos dos LEDs (colunas)
    }

    // Controle das linhas
    digitalWrite(_pins[0][i], LOW);    // Habilita linha (em nivel logico baixo)
    delay(TEMPO_POR_LINHA_MS);         // Gasta tempo
    digitalWrite(_pins[0][i], HIGH);   // Desabilita linha (em nivel logico alto)
  }
}

// Funcoes para controle das figuras
void ALC_LED_Matrix::select_figure(const byte* figure) {
    // Copia todos os elementos da matriz figura para a matriz buffer

    for (int i=0; i<=4; i++) {
        for (int j=0; j<=4; j++) {
            _buffer[i][j] = figure[i * 5 + j];
            /*
              Passa o conteudo de figure[0] para _buffer[0][0]
              Passa o conteudo de figure[1] para _buffer[0][1]
              Passa o conteudo de figure[2] para _buffer[0][2]
              Passa o conteudo de figure[3] para _buffer[0][3]
              Passa o conteudo de figure[4] para _buffer[0][4]
              Passa o conteudo de figure[5] para _buffer[1][0]
              Passa o conteudo de figure[6] para _buffer[1][1]
              ...
              Passa o conteudo de figure[23] para _buffer[4][3]
              Passa o conteudo de figure[24] para _buffer[4][4]
            */

            #ifdef DEBUG_MATRIZ_BUFFER
                Serial.print("_buffer[");
                Serial.print(i);
                Serial.print("][");
                Serial.print(j);
                Serial.print("]: ");
                Serial.println(_buffer[i][j]);
            #endif
        }
    }
}
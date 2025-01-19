#include <stdio.h>
#include "pico/stdlib.h"

#define LED_VERDE 11
#define LED_AZUL 12
#define LED_VERMELHO 13 // Definição do pino do LED vermelho
#define BUZZER 14       // Definição do pino do buzzer

// Mapa de teclas
char KEY_MAP[16] = {
    '1', '2', '3', 'A',
    '4', '5', '6', 'B',
    '7', '8', '9', 'C',
    '*', '0', '#', 'D'};

// Define os pinos do teclado com as portas GPIO
uint columns[4] = {4, 3, 2, 1};
uint rows[4] = {8, 7, 6, 5};

// Função para inicializar o teclado
void init_teclado()
{
    // Configura as colunas como saída
    for (int i = 0; i < 4; i++)
    {
        gpio_init(columns[i]);              // Inicializa as colunas
        gpio_set_dir(columns[i], GPIO_OUT); // Configura como saída
        gpio_put(columns[i], 1);            // Inicializa como HIGH (1)
    }

    // Configura as linhas como entrada com pull-up
    for (int i = 0; i < 4; i++)
    {
        gpio_init(rows[i]);             // Inicializa as linhas
        gpio_set_dir(rows[i], GPIO_IN); // Configura como entrada
        gpio_pull_up(rows[i]);
    }
}

// Função para verificar teclas pressionadas
char detectar_tecla()
{
    for (int col = 0; col < 4; col++)
    {
        // Ativa a coluna atual
        gpio_put(columns[col], 0);

        // Verifica as linhas
        for (int row = 0; row < 4; row++)
        {
            if (gpio_get(rows[row]) == 0)
            { // Tecla pressionada
                // Desativa a coluna antes de retornar
                gpio_put(columns[col], 1);
                return KEY_MAP[row * 4 + col];
            }
        }

        // Desativa a coluna atual
        gpio_put(columns[col], 1);
    }

    // Nenhuma tecla pressionada
    return '\0';
}

int main()
{
    stdio_init_all();

    // Inicializa o teclado
    init_teclado();

    // Inicializa os periféricos
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);

    printf("Teclado inicializado.\n");

    char tecla;

    while (true)
    {
        // Detecta a tecla pressionada
        gpio_put(LED_VERDE, 0);       // Mantém o LED verde desligado
        gpio_put(LED_AZUL, 0);        // Mantém o LED azul desligado
        gpio_put(LED_VERMELHO, 0);    // Mantém o LED vermelho desligado
        gpio_put(BUZZER, 0);          // Mantém o buzzer desligado
        tecla = detectar_tecla();
        if (tecla != '\0')
        {
            printf("Tecla pressionada: %c\n", tecla);
            if (tecla == 'A')
            {
                gpio_put(LED_VERDE, 1); // Liga o LED verde
                printf("LED verde ligado\n");
            }
            else if (tecla == 'B')
            {
                gpio_put(LED_AZUL, 1); // Liga o LED azul
                printf("LED azul ligado\n");
            }
            else if (tecla == 'C')
            {
                gpio_put(LED_VERMELHO, 1); // Liga o LED vermelho
                printf("LED vermelho ligado\n");
            }
            else if (tecla == 'D')
            {
                gpio_put(BUZZER, 1); // Liga o buzzer
                printf("Buzzer ativado\n");
                sleep_ms(500);       // Buzzer ligado por 500 ms
                gpio_put(BUZZER, 0); // Desliga o buzzer
                printf("Buzzer desativado\n");
            }
        }

        sleep_ms(100);
    }
}

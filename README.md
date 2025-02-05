# Temporizador de Um Disparo (One Shot) - Raspberry Pi Pico W

## Descrição do Projeto

Esse é um projeto feito em C para simular um sistema de temporizado com acionamento manual, usando o Wokwi para emular a placa Raspberry Pi Pico W.

## Componentes Utilizados

- **Microcontrolador**: Raspberry Pi Pico W
- **LEDs**: Azul, Vermelho e Verde
- **Resistores**: 3x de 330 Ω
- **Botão (Pushbutton)**

## Funcionamento

1. Ao pressionar o botão, todos os LEDs são ligados simultaneamente.
2. Após um atraso de **3 segundos**, um LED é desligado.
3. Após mais **3 segundos**, outro LED é desligado.
4. Após mais **3 segundos**, o último LED é desligado.
5. O sistema fica pronto para uma nova ativação apenas quando todos os LEDs estiverem apagados.

## Regras de Operação

- O botão **só pode ativar o ciclo de LEDs novamente após o último LED ser desligado**.
- Durante o ciclo de temporização, o botão não pode interromper ou reiniciar a sequência.
- A mudança de estado dos LEDs é feita por meio de **funções call-back do temporizador**.

### Simulação no Wokwi

Caso deseje testar a simulação no Wokwi, siga os seguintes passos:

1. Acesse o [Wokwi](https://wokwi.com/)
2. Crie um novo projeto com o Raspberry Pi Pico
3. Configure os LEDs e o botão conforme a descrição acima
4. Carregue o código para testar a funcionalidade

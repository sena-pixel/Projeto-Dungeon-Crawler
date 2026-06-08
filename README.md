# Projeto-Dungeon-Crawler
# 🛡️ Aethelgard: O Abismo Sombrio

Um RPG de aventura em modo texto desenvolvido inteiramente em **C**, rodando direto no terminal. Escolha sua arma, explore labirintos perigosos, encontre chaves e enfrente o terrível Arauto da Ruína antes que seu tempo acabe!

---

## 📜 A História do Jogo (Lore)

> *"A névoa do Abismo consome o mundo... mas as lendas dizem que um viajante trará a luz de volta."*

A pacata **Vila da Superfície** é o último refúgio seguro de um reino corrompido pelas trevas. Anos atrás, a terra se partiu, revelando uma estrutura colossal conhecida como **O Abismo**. De lá, emana uma magia sombria que drena a vida de quem ousa entrar.

Você é um guerreiro escolhido pelo destino. Ao falar com o **Ancião da Vila**, você receberá uma das três relíquias sagradas para iniciar sua descida ao Labirinto do Esquecimento. Seu objetivo final? Derrotar o **Arauto da Ruína**, uma entidade ancestral de pura corrupção que aguarda no nível mais profundo. Mas cuidado: o ar na sala do chefe é tão tóxico que sua própria vida se esvairá a cada segundo!

---

## 🧠 Co-criação e Uso de IA

Este projeto utilizou ferramentas de **Inteligência Artificial** como um copiloto de desenvolvimento. A IA foi aplicada estrategicamente para:
* **Construção de Wordbuilding:** Expandir a atmosfera do jogo, transformando os caracteres simples do terminal em elementos com peso narrativo (como a justificativa para a mecânica de perda de vida passiva na sala do chefe).
* **Agregação de Conhecimento:** Auxiliar na estruturação do código, boas práticas de documentação e organização do fluxo de jogo.

Essa integração permitiu focar na lógica de programação principal em C, enquanto a IA ajudou a dar vida e profundidade ao universo do jogo.

---

## 🗺️ Guia de Elementos (Legenda do Mapa)

Para entender o que está acontecendo no terminal, aqui está o significado de cada símbolo místico do jogo:

| Símbolo | Entidade / Objeto | Descrição |
| :---: | :--- | :--- |
| **`A` / `<` / `V` / `>`** | **O Jogador** | Representa você e a direção para onde está olhando. |
| **`*`** | **Paredes** | Obstáculos intransponíveis. |
| **`N`** | **Ancião (NPC)** | Encontrado na Vila. Interaja com ele para escolher sua arma. |
| **`L`** | **Portais / Escadas** | Passagem para a próxima fase (Vila ➔ Masmorra ➔ Sala do Chefe). |
| **`M`** | **Monstros** | Espíritos corrompidos no Andar 1. Tocá-los drena sua vida instantaneamente! |
| **`@`** | **Chave** | Item essencial para abrir as portas trancadas. |
| **`D`** | **Porta Trancada** | Só se abre se você estiver carregando uma Chave (`@`). |
| **`k`** | **Caixotes antigos** | Destrua-os para ter a chance de encontrar Poções de Cura. |
| **`B`** | **O Chefe (Boss)** | O terrível Arauto da Ruína. Possui 30 pontos de vida. |
| **`#`, `X`, `O`, `Y`, `Z`** | **Ruínas** | Escombros e obstáculos dentro da masmorra e da sala do chefe. |

---

## 🎮 Como Jogar & Controles

O jogo utiliza inputs em tempo real (sem precisar apertar Enter a cada movimento). 

* **`W`, `A`, `S`, `D`**: Movimentam o herói (Cima, Esquerda, Baixo, Direita).
* **`I`**: Interagir (Falar com o Ancião, abrir portas, revistar caixas).
* **`O`**: Atacar (Dispara um golpe contra inimigos ou o chefe diretamente à sua frente).
* **`P`**: Usar Poção (Restaura completamente suas 3 vidas, se tiver uma guardada).
* **`Q`**: Sair do jogo e voltar ao menu principal.

> ⚠️ **Alerta de Sobrevivência:** Na Sala do Chefe (Fase 2), o ambiente é hostil. Cada comando executado drena 1 de vida passivamente devido ao miasma tóxico. Seja rápido para atacar o Chefe (`B`)!

---

## 🛠️ Tecnologias e Compilação

Este projeto foi desenvolvido utilizando a linguagem **C** padrão, com foco em sistemas Windows devido ao uso da biblioteca `<conio.h>`.

### Pré-requisitos
* Um compilador C (como o `GCC` através do MinGW, ou o ambiente do VS Code / Code::Blocks).
* Sistema Operacional Windows (necessário para a função `_getch()` e `system("cls")`).

### Como rodar o código:
1. Baixe o arquivo `.c` do repositório.
2. Abra o terminal na pasta do arquivo e compile usando o GCC:
   ```bash
   gcc jogo.c -o jogo.exe

Lógica Super Trunfo Países (por Roberto)
Esse projeto é o desafio da Estácio que fiz para criar um sistema pra cadastrar e comparar cartas de cidades no jogo Super Trunfo. O tema é “Lógica do Jogo” e o desafio tem 3 níveis: Novato, Aventureiro e Mestre, com complexidade crescente em cada um.

Tudo foi feito no VSCode, compilando com gcc (MinGW) no Windows. Cada nível tá num arquivo separado pra facilitar o teste e a organização.

Níveis implementados e arquivos
🟢 Nível Novato
Arquivo: logica_super_trunfo_novato.c

Cadastro de 2 cartas com atributos básicos (código da cidade, nome, população, área, PIB e pontos turísticos).

Leitura simples com scanf, exibição com printf.

Comparação básica entre as cartas por um atributo fixo usando if/else.

Resultado mostra qual carta venceu na comparação.

🟡 Nível Aventureiro
Arquivo: logica_super_trunfo_aventureiro.c

Além dos atributos básicos, calcula e exibe:

Densidade populacional (população/área)

PIB per capita (PIB convertido de bilhões para reais / população)

Menu interativo com switch para escolher o atributo de comparação.

Lógica de comparação com if-else-if, tratando empates e entradas inválidas.

Uso de limites no scanf e fgets para garantir segurança na leitura.

🔴 Nível Mestre
Arquivo: logica_super_trunfo_mestre.c

Permite ao usuário escolher dois atributos diferentes para comparar numa rodada.

Usa funções pra modularizar: exibir cartas, calcular densidade, comparar atributos e mostrar nomes dos atributos.

Utiliza operadores ternários para deixar o código mais limpo e elegante.

Contabiliza vitórias por atributo e decide o vencedor da rodada considerando as duas comparações, tratando empates.

População é unsigned long int para suportar grandes números.

Código da carta é string de 3 caracteres, lido com segurança.

Cálculo do PIB per capita considera conversão correta de bilhões para reais.

Previne divisão por zero na densidade e no PIB per capita.

Valida que os dois atributos escolhidos são diferentes e válidos.

Como compilar e rodar
No terminal (Windows com gcc instalado tipo MinGW), rode linha por linha pra cada nível:

bash
Copiar
Editar
gcc logica_super_trunfo_novato.c -o logica_super_trunfo_novato.exe
./logica_super_trunfo_novato.exe

gcc logica_super_trunfo_aventureiro.c -o logica_super_trunfo_aventureiro.exe
./logica_super_trunfo_aventureiro.exe

gcc logica_super_trunfo_mestre.c -o logica_super_trunfo_mestre.exe
./logica_super_trunfo_mestre.exe
Os .exe são só pra teste local mesmo, não subi eles no repositório.

Observações finais
O código está comentado no meu estilo, focando em clareza e simplicidade.

Evitei complicar demais pra manter o foco nos requisitos do desafio.

Foi um baita aprendizado passar do básico até a lógica avançada do nível Mestre, aplicando estruturas, funções, operadores ternários e validação robusta.

Essa jornada ajudou muito a consolidar conceitos de programação em C e lógica de jogos.

Análise e Desenvolvimento de Sistemas (1º semestre)
Por Roberto
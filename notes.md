# Guia de Compilação e Execução C++

## 1. Compilando um Arquivo C++ (`g++`)

```bash
g++ -std=c++17 -O2 -Wall -Wextra arquivo.cpp -o executavel
```

### Significado das Flags

- `-std=c++17`: Define o padrão da linguagem C++17.
- `-O2`: Nível de otimização de código (padrão em juízes online / programação competitiva).
- `-Wall -Wextra`: Ativa avisos (*warnings*) do compilador para detectar potenciais erros.
- `-o executavel`: Define o nome do arquivo binário/executável de saída.

---

## 2. Executando o Programa

```bash
./executavel
```

---

## 3. Passando Entradas de Arquivo (`input.txt`)

Para redirecionar a entrada padrão (`std::cin`) a partir de um arquivo de texto:

```bash
./executavel < input.txt
```

---

## Compilando Usando `make`

Com as flags pré-configuradas no arquivo `Makefile` (`CXXFLAGS = -std=c++17 -O2 -Wall -Wextra`), você pode usar a regra implícita do GNU Make para compilar qualquer arquivo sem digitar as flags manualmente.

Basta passar o nome do programa **sem** a extensão `.cpp`:

```bash
make hello
```

Isso compilará automaticamente `hello.cpp` gerando o executável `hello`.

### Compilar e Executar em um Único Comando

```bash
make hello && ./hello
```

Ou com entrada via arquivo:

```bash
make basic-structure && ./basic-structure < input.txt
```

---

- **endl** = \n + flush
Serve para imprimir uma nova linha e limpar o buffer de saída, garantindo que tudo seja exibido imediatamente.

- **flush**
Limpa o buffer de saída, útil para garantir que mensagens sejam exibidas antes de uma pausa ou espera por entrada do usuário.

---

## 4. Otimização de I/O (Fast I/O em C++)

Em códigos de maratona (como visto em `basic-structure.cpp`), é muito comum usar as seguintes linhas no início da função `main`:

```cpp
ios_base::sync_with_stdio(false); // ou ios_base::sync_with_stdio(0);
cin.tie(NULL);                    // ou cin.tie(0);
```

### Quando usar?

- **Sempre em Maratonas de Programação / Juízes Online:** Quando o problema tem uma quantidade massiva de entradas/saídas (ex: ler mais de $10^5$ variáveis). O `cin` e o `cout` nativos do C++ são lentos porque mantêm sincronia com os fluxos do C. Essas linhas "quebram" essa sincronia, deixando o I/O do C++ incrivelmente rápido, quase no mesmo nível do `scanf` e `printf`.

### Quando NÃO usar?

- **Se você for usar I/O de C e C++ juntos:** Nunca misture `scanf`/`printf`/`puts` com `cin`/`cout` no mesmo código após usar `sync_with_stdio(false)`. Como a sincronia foi quebrada, a ordem da saída no console será bizarra e imprevisível. Escolha usar um ou outro.
- **Aplicações Interativas / CLI Tradicionais:** O comando `cin.tie(0)` solta a trava (untie) entre o `cin` e o `cout`. Normalmente, sempre que você faz um `cin >>`, o C++ dá um *flush* automático no `cout` para garantir que mensagens anteriores (ex: `cout << "Digite seu nome: ";`) apareçam na tela antes de pausar esperando a entrada. Se você quebrar essa trava, a mensagem pode não aparecer para o usuário até que o programa termine. Em maratonas isso não importa pois os juízes não leem mensagens interativas, apenas a saída final de dados brutos.

---

## 5. Leitura de Entradas (Input) no C++

### Entrada Padrão sem Espaços (`cin >>`)

O operador `>>` do `cin` lê a entrada e **para automaticamente em qualquer espaço em branco** (espaço, tabulação ou quebra de linha).

```cpp
string nome, sobrenome;
cin >> nome >> sobrenome; 
```

**Exemplo de Entrada:** `João Silva`

- O `cin` guarda `"João"` na variável `nome`.
- O `cin` guarda `"Silva"` na variável `sobrenome`.

- **Ideal para:** Ler números (`int`, `float`), caracteres isolados e palavras soltas.

### Entrada com Espaços (`getline`)

Quando você precisa ler uma linha inteira de texto que contenha espaços, use a função `getline()`. O `getline` consome os caracteres até encontrar uma quebra de linha (`\n`).

```cpp
string frase;
getline(cin, frase);
```

**Exemplo de Entrada:** `Eu amo programar em C++`

- O `getline` guarda `"Eu amo programar em C++"` inteiro na variável `frase`.

- **Ideal para:** Ler frases completas, nomes compostos ou textos com formatação própria por linha.

### ⚠️ O Problema de misturar `cin >>` e `getline`

Se você usar `cin >>` (para ler um número, por exemplo) e logo em seguida usar `getline()`, o `cin` deixará a quebra de linha (`\n`) sobrando no buffer. O `getline` vai engolir imediatamente esse `\n` e resultar em uma string vazia!
Para evitar isso, use `cin.ignore()` após o `cin >>` para limpar o buffer:

```cpp
int idade;
string nome;

cin >> idade;
cin.ignore(); // Ignora o 'Enter' (\n) deixado pelo 'cin >>'
getline(cin, nome);
```

**Exemplo de Entrada:**

```text
25
Maria Eduarda
```

- `cin >> idade` lê apenas o `25`.

- `cin.ignore()` descarta o Enter invisível que ficou após o 25.
- `getline` lê `"Maria Eduarda"` perfeitamente.

### Leitura Múltipla Até o Fim (EOF - End Of File)

Em maratonas, muitas vezes não é dita a quantidade de dados. Devemos ler até não haver mais nada a ser lido (no terminal, testando manualmente, aperte `Ctrl+D` para simular o fim da entrada).

**Exemplo A: Lendo vários números ou palavras soltas:**

```cpp
int x;
while (cin >> x) {
    cout << "Li o numero: " << x << "\n";
}
```

**Exemplo de Entrada:**

```text
10 20
30
```

- **Comportamento:** O código roda 3 vezes ignorando todas as quebras de linha e espaços. Ele imprime os números 10, 20 e 30 individualmente e então o laço acaba.

**Exemplo B: Lendo múltiplas linhas completas (textos grandes):**

```cpp
string linha;
while (getline(cin, linha)) {
    cout << "Li uma linha inteira: " << linha << "\n";
}
```

**Exemplo de Entrada:**

```text
Primeira linha de texto
E aqui vem a segunda!
```

- **Comportamento:** O código roda 2 vezes. Na 1ª iteração guarda `"Primeira linha de texto"`, na 2ª guarda `"E aqui vem a segunda!"`, preservando todos os espaços, e depois encerra.

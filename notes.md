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

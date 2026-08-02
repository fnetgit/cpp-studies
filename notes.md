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

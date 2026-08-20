#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // 1. Declarations
    // C-style arrays (tradicionais)
    int rawArray[5];                      // Declara array de tamanho 5 (não inicializado)
    int initRawArray[] = {1, 2, 3, 4, 5}; // Array com tamanho deduzido automaticamente

    // std::array (C++ moderno) - Mais seguro, contém os mesmos métodos de um container
    array<int, 5> stdArray;
    array<int, 5> initStdArray = {10, 20, 30, 40, 50};

    // Preenche todo o array com um valor específico O(N)
    stdArray.fill(0);

    // 2. Insertion and Deletion
    // Não existem funções como push_back ou pop_back.
    // Você só pode sobrescrever valores existentes.
    initStdArray[0] = 99;

    // 3. Access and Capacity
    int currentSize = initStdArray.size();    // Obtém o tamanho O(1)
    bool isArrayEmpty = initStdArray.empty(); // Sempre falso para N > 0

    // Acesso direto O(1)
    int firstElement = initStdArray[0];  // Acesso sem checagem de limites
    int safeAccess = initStdArray.at(1); // Acesso seguro (lança std::out_of_range se fora do limite)
    int frontElement = initStdArray.front();
    int backElement = initStdArray.back();

    // 4. Common Algorithms (requerem iteradores)
    array<int, 6> numbers = {5, 2, 9, 1, 5, 6};

    // Ordenação Crescente O(N log N)
    sort(numbers.begin(), numbers.end());

    // Ordenação Decrescente O(N log N)
    sort(numbers.rbegin(), numbers.rend());

    // Inversão do array O(N)
    reverse(numbers.begin(), numbers.end());

    // Busca Binária O(log N) - lower_bound retorna iterador para o 1º elemento >= valor
    sort(numbers.begin(), numbers.end());
    auto lowerBoundIt = lower_bound(numbers.begin(), numbers.end(), 5);

    // NOTA SOBRE REMOÇÃO DE DUPLICATAS:
    // Como arrays têm tamanho fixo, não podemos usar .erase() como no vector.
    // O std::unique funcionaria apenas para mover os elementos duplicados para o final da estrutura,
    // retornando um iterador para o novo "fim" lógico, mas o array continua com a mesma capacidade.

    // 5. Iteration
    cout << "Valores processados: ";
    for (const auto &num : numbers)
    { // Uso de referência constante para evitar cópias desnecessárias
        cout << num << " ";
    }
    cout << "\n";

    // Iterando no array tradicional (C-style)
    cout << "Valores do C-style array: ";
    for (int i = 0; i < 5; ++i)
    {
        cout << initRawArray[i] << " ";
    }
    cout << "\n";

    return 0;
}

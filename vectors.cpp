#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // 1. Declarations
    vector<int> emptyVector;
    vector<int> sizedVector(10);
    vector<int> initializedVector(10, 5); // initialize with 10 elements, each of value 5

    // 2. Insertion and Deletion
    emptyVector.push_back(42);    // Adiciona um elemento ao final do vetor
    emptyVector.emplace_back(15); // Ligeiramente mais rápido que push_back para objetos
    emptyVector.pop_back();       // Remove o último elemento do vetor

    // 3. Access and Capacity
    int currentSize = emptyVector.size();     // Obtém o tamanho atual do vetor
    bool isVectorEmpty = emptyVector.empty(); // Verifica se o vetor está vazio

    // Acesso direto O(1)
    emptyVector.push_back(10);
    emptyVector.push_back(20);
    int firstElement = emptyVector[0];
    int frontElement = emptyVector.front();
    int backElement = emptyVector.back();

    // 4. Common Algorithms (requerem iteradores)
    vector<int> numbers = {5, 2, 9, 1, 5, 6};

    // Ordenação Crescente O(N log N)
    sort(numbers.begin(), numbers.end());

    // Ordenação Decrescente O(N log N)
    sort(numbers.rbegin(), numbers.rend());

    // Inversão do vetor O(N)
    reverse(numbers.begin(), numbers.end());

    // Remoção de duplicatas O(N) - O vetor DEVE estar ordenado antes
    sort(numbers.begin(), numbers.end());
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());

    // Busca Binária O(log N) - lower_bound retorna iterador para o 1º elemento >= valor
    auto lowerBoundIt = lower_bound(numbers.begin(), numbers.end(), 5);

    // 5. Iteration
    cout << "Valores processados: ";
    for (const auto &num : numbers)
    { // Uso de referência para evitar cópias na memória
        cout << num << " ";
    }
    cout << "\n";

    // 6. Cleanup
    numbers.clear();         // Zera o tamanho, mas mantém a capacidade alocada
    numbers.shrink_to_fit(); // Força a liberação da memória não utilizada

    return 0;
}

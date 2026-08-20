#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // 1. Declarations
    // std::map - Armazena pares de Chave-Valor ORDENADOS pela chave (Árvore Red-Black)
    // Operações base: O(log N)
    map<string, int> orderedMap;
    
    // std::unordered_map - Dicionário NÃO ORDENADO (Tabela Hash)
    // Operações base: média O(1) - Ideal quando a ordem não importa e performance é crítica
    unordered_map<string, int> hashMap;

    // Inicialização com valores
    map<int, string> idToName = {
        {3, "Charlie"},
        {1, "Alice"},
        {2, "Bob"}
    };

    // 2. Insertion and Deletion
    // Inserção com operador [] (se a chave existir, SOBRESCREVE o valor)
    orderedMap["Maca"] = 5;
    orderedMap["Banana"] = 10;
    orderedMap["Pera"] = 3;
    
    // Inserção com .insert() ou .emplace() (NÃO SOBRESCREVE se a chave já existir)
    orderedMap.insert({"Laranja", 7});
    orderedMap.emplace("Uva", 12); // Ligeiramente mais eficiente

    // Remoção baseada na chave
    orderedMap.erase("Banana"); 

    // 3. Access and Capacity
    int currentSize = orderedMap.size();
    bool isEmpty = orderedMap.empty();

    // Acesso seguro: .at() lança exceção (std::out_of_range) se a chave não existir
    int appleCount = orderedMap.at("Maca");

    // ATENÇÃO: Se usar o operador [] para uma chave INEXISTENTE, 
    // ele insere a chave automaticamente com um valor padrão (0 para int, "" para string, etc.)
    int kiwiCount = orderedMap["Kiwi"]; // Cria "Kiwi" com valor 0 silenciosamente

    // Verificação de existência da chave de forma segura
    if (orderedMap.count("Uva") > 0) {
        // "Uva" existe. count() retorna 1 ou 0.
    }
    // Em C++20 em diante também é possível usar: orderedMap.contains("Uva")

    // 4. Common Algorithms (Busca)
    // .find() é a maneira ideal de buscar sem risco de inserir acidentalmente
    auto it = orderedMap.find("Maca");
    if (it != orderedMap.end()) { // Verifica se chegou no "final" (não achou)
        // it->first é a chave, it->second é o valor
        cout << "Busca: Encontrou " << it->second << " macas.\n\n";
    }

    // Apenas std::map possui .lower_bound e .upper_bound (pois é ordenado)
    // Retorna um iterador para o primeiro elemento com chave >= 2
    auto lbIt = idToName.lower_bound(2); 

    // 5. Iteration
    // No std::map a iteração ocorre na ordem crescente das CHAVES.
    // Em um std::unordered_map a ordem de iteração seria aleatória.
    cout << "Conteudo do orderedMap (Ordenado Alfabeticamente):\n";
    for (const auto& pair : orderedMap) {
        cout << pair.first << " -> " << pair.second << "\n";
    }
    
    // Iteração mais elegante usando Structured Binding (a partir do C++17)
    cout << "\nConteudo de idToName (Ordenado pelo ID numérico):\n";
    for (const auto& [id, name] : idToName) {
        cout << "ID: " << id << " | Nome: " << name << "\n";
    }

    // 6. Cleanup
    // Remove todos os elementos e desaloca a memória interna associada aos nós
    orderedMap.clear(); 
    idToName.clear();

    return 0;
}
